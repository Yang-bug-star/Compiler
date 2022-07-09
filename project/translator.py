import log
from log import Log
from symbolTable import Scope, Variable, Constant, Function, Identifier, Array_elem
from typing import List
import sys

sys.setrecursionlimit(1000000)


class TranslateError(Exception, Log):
  def __init__(self, node, message):
    self.row = node['row']
    self.col = node['col']
    self.message = message


class Translator:
  inner_code = None
  syntax_tree = None
  scope_stack = []
  function_pool = {}
  temp_counter = 0
  label_counter = 0

  def add_label_to_current_scope(self,label,identifier,node):
    if str(identifier) in self.scope_stack[-1].label_map:
      message='the label has been declared'
      raise TranslateError(node,message)
    self.scope_stack[-1].label_map[str(identifier)]=label

  def lookup_variable(self, identifier,node):
    for scope in reversed(self.scope_stack):
      if str(identifier) in scope.variable_symbol_map:
        return scope.variable_symbol_map[str(identifier)]
    message="can't find the variable "+str(identifier)+" in all scopes"
    raise TranslateError(node,message)

  def lookup_variable_current_scope(self,identifier,node):
    if str(identifier) in self.scope_stack[-1].variable_symbol_map:
      return self.scope_stack[-1].variable_symbol_map[str(identifier)]
    message = "can't find the variable " + str(identifier) + " in the current scope"
    raise TranslateError(node, message)

  def lookup_label(self,identifier,node):
    for scope in reversed(self.scope_stack):
      if str(identifier) in scope.label_map: 
        return scope.label_map[str(identifier)]
    message = "can't find the label " + str(identifier) + " in all scopes"
    raise TranslateError(node, message)


  def lookup_function(self,identifier,node):
    if str(identifier) in self.function_pool:
      return self.function_pool[str(identifier)]
    else:
      message = "can't find the function " + str(identifier) + " in the scope_stack"
      raise TranslateError(node,message)

  def create_temp(self, type):
    self.temp_counter += 1
    temp = Variable(name='temp%d'%self.temp_counter, type=type)
    return temp

  def create_label(self):
    self.label_counter += 1
    return 'label%d'%self.label_counter

  def binary_op(self, src1, operand, src2, type='int'):
    result = self.create_temp(type)
    self.inner_code.binary_op(
      result,
      src1,
      operand,
      src2
    )
    return result

  def __init__(self, syntax_tree, inner_code):
    self.syntax_tree = syntax_tree
    self.inner_code = inner_code
    #预置一个最大的Block
    whole_block=Scope()
    self.scope_stack.append(whole_block)

  def translate(self):
    #预定义两个已有函数
    print_node=Function("print", "void", True)
    param_node=Variable(name='print_value',type="int")
    print_node.arguments.append(param_node)

    read_node=Function("get_input", "int", True)

    self.function_pool["print"]=print_node
    self.function_pool["get_input"]=read_node

    if self.syntax_tree['name'] != 'program':
      err = TranslateError(self.syntax_tree, 'Root node must be an "program"')
      log.print_log(err)
    else:
      self.translate_program(self.syntax_tree)

  """
  program
    : translation_unit
  """
  def translate_program(self, node:dict):
    children = node['children']
    self.translate_translation_unit(children[0])

  """
  translation_unit
    : external_declaration
    | translation_unit external_declaration
  """
  def translate_translation_unit(self, node:dict):
    children = node['children']
    if len(children) == 1:
      self.translate_external_declaration(children[0])
    else:
      self.translate_translation_unit(children[0])
      self.translate_external_declaration(children[1])

  """
  external_declaration
    : function_definition
    | declaration
  """
  def translate_external_declaration(self, node:dict):
    children = node['children']
    if children[0]['name'] == 'function_definition':
      self.translate_function_definition(children[0])
    else:
      self.translate_declaration(children[0])
  '''
  function_definition:
    declaration_specifiers declarator declaration_list compound_statement
    | declaration_specifiers declarator compound_statement
  '''
  def translate_function_definition(self, node:dict):
    children=node['children']
    declaration_specifier=children[0]
    declarator=children[1]

    if children[2]['name']=='declaration_list':
      declaration_list=children[2]
      compound_statement=children[3]
    else:
      compound_statement=children[2]

    #type_specifier
    function_type=declaration_specifier['children'][0]['val']
    function_name=declarator['children'][0]['children'][0]['val']

    is_declared=False
    declared_node=Function()
    #函数名和已有定义函数重复
    if function_name in self.function_pool:
      if self.function_pool[function_name].isDefined :
        log.print_log(TranslateError(node,'The function'+function_name+'has been defined before'))
      else:
        declared_node=self.function_pool[function_name]
    #函数名与同一作用域内变量名冲突
    try:
      if self.lookup_variable_current_scope(function_name,node) is not None:
        log.print_log(TranslateError(node, 'The function' + function_name + 'has been declared as variable before'))
    except TranslateError:
      pass


    function_scope=Scope()
    function_scope.function=Function(name=function_name, return_type=function_type, is_definition=True)


    self.scope_stack.append(function_scope)
    self.function_pool[function_name]=function_scope.function
    #带参函数
    if declarator['children'][2]['name']=='parameter_list':
      self.translate_parameter_list(declarator['children'][2],function_name)


    function=self.function_pool[function_name]
    if is_declared:
      if function.type !=declared_node.type:
        log.print_log(TranslateError(node,'The return types are different between the defined and the declared'))
      if function.arguments.__len__()!=declared_node.arguments.__len__():
        log.print_log(TranslateError(node,'The number of parameters are different between the defined and the declared'))
      for i in range(function.arguments.__len__()):
        if function.arguments[i].type!=declared_node.arguments[i].type:
          log.print_log(TranslateError(node, 'The type of parameters are different between the defined and the declared'))

    self.inner_code.function_declare(function)

    self.translate_compound_statement(compound_statement)

    self.scope_stack.pop(-1)

    return None




  """
  declaration
    : declaration_specifiers ';'
    | declaration_specifiers init_declarator_list
  """
  def translate_declaration(self, node:dict):
    declaration_specifiers=node['children'][0]
    if node['children'][1]['val']==';':
      return None

    var_type=declaration_specifiers['children'][0]['children'][0]['name']
    if var_type=='void':
      message=r"void can't be declaration specifier"
      log.print_log(TranslateError(node,message))
    init_declarator_list=node['children'][1]
    self.translate_init_declarator_list(var_type,init_declarator_list)
    return None

  """
  init_declarator_list:
      init_declarator
    | init_declarator_list ',' init_declarator
  """
  def translate_init_declarator_list(self,var_type,node):
    if node['children'][0]['name'] == 'init_declarator_list':
      self.translate_init_declarator_list(var_type,node['children'][0])
      self.translate_init_declarator(var_type,node['children'][2])
    else:
      self.translate_init_declarator(var_type, node['children'][0])
    return  None

  """
  init_declarator:
      declarator
    | declarator '=' initializer
  """
  def translate_init_declarator(self, var_type, node):
    declarator=node['children'][0]
    if node['children'].__len__()==1:
      if declarator['children'][0]['name']=='identifier':
        id=declarator['children'][0]
        var_name=id['val']
        tmp_node=None
        try:
          tmp_node= self.lookup_variable_current_scope(var_name, node)   # 在当前作用域查找，这个变量不能重复定义
        except TranslateError:
          if tmp_node is None:
            var_element = self.create_temp(var_type)
            self.scope_stack[-1].variable_symbol_map[var_name] = var_element
          else:
            log.print_log(TranslateError(node, r'the IDENTIFIER' + var_name + 'has been declared before'))
      else:
        # 数组(这里还没有考虑int 和 double的问题）
        if declarator['children'][1]['name']=='[':
          #pointer_name=declarator['children'][0]['children'][0]['val']
          var_name=declarator['children'][0]['children'][0]['val']
          var_element=self.create_temp(var_type)
          var_element.is_pointer=True
          self.scope_stack[-1].variable_symbol_map[var_name]=var_element
          assignment_exp=declarator['children'][2]
          #这里返回一个Temp_element
          assignment_element=self.translate_assignment_expression(assignment_exp)
          if assignment_element.type!='int':
            log.print_log(TranslateError(node,r'the size of the array must be integer'))
          array_item_element=Array_elem(var_element,assignment_element)
          self.inner_code.malloc_array(array_item_element)
        # 函数
        if declarator['children'][1]['name']=='(':
          function_name=declarator['children'][0]['children'][0]['val']
          if self.scope_stack.__len__()>1:
            log.print_log(TranslateError(node,"function declaration must be at global scope"))
          #有参函数
          if declarator['children'][2]['name']=='parameter_list':
            parameter_list =declarator['children'][2]
            function=Function(function_name,var_type)
            self.function_pool[function_name]=function
            self.translate_parameter_list(parameter_list,function_name)
    else:
      if node['children'][1]['name']=='=':
        temp = self.create_temp(var_type)
        if declarator['children'][0]['name']=='identifier':
          identifier_node=declarator['children'][0]
          identifier=Identifier(identifier_node['val'])
          try:
            self.lookup_variable_current_scope(identifier,node)
          except TranslateError:
            self.scope_stack[-1].variable_symbol_map[identifier.name]=temp
          else:
            log.print_log(TranslateError(node,"the variable has been declared before"))
        else:
          log.print_log(TranslateError(node, "it's not a variable"))
        if node['children'][2]['children'][0]['name']=='assignment_expression':
          assignment_element=self.translate_assignment_expression(node['children'][2]['children'][0])
          self.inner_code.assignment(temp,assignment_element)

  '''
  compound_statement:
     '{' '}'
    | '{' block_item_list '}'
  '''
  def translate_compound_statement(self,node):
    if node['children'][1]['name']=='block_item_list':
      block_item_list=node['children'][1]
      self.translate_block_item_list(block_item_list)

  '''
  block_item_list:
      block_item
    | block_item_list block_item
  '''
  def translate_block_item_list(self,node):
    if node['children'][0]['name']=='block_item_list':
      self.translate_block_item_list(node['children'][0])
      self.translate_block_item(node['children'][1])
    else:
      self.translate_block_item(node['children'][0])

  '''
  block_item:
      declaration
    | statement
  '''
  def translate_block_item(self,node):
    if node['children'][0]['name']=='statement':
      self.translate_statement(node['children'][0])
    else:
      self.translate_declaration(node['children'][0])

  """
  parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	
	"""

  def translate_parameter_list(self,node,function_name):
    if node['children'][0]['name']=='parameter_list':
      self.translate_parameter_list(node['children'][0],function_name)
      self.translate_parameter_declaration(node['children'][2],function_name)
    else:
      self.translate_parameter_declaration(node['children'][0],function_name)

  """
    parameter_declaration:
      type_specifier declarator
    | type_specifier    //这种情况先不管
  """

  def translate_parameter_declaration(self,node,function_name):
    type_specifier=node['children'][0]
    declarator=node['children'][1]
    var_type=type_specifier['children'][0]['val']
    if var_type=='void':
      message=r"var with type void can't be parameter"
      log.print_log(TranslateError(node,message))

    var_name=declarator['children'][0]['val']
    var_node=self.create_temp(var_type)

    self.function_pool[function_name].arguments.append(var_node)  #把参数写到function_element里的参数列表里
    self.scope_stack[-1].variable_symbol_map[var_name]=var_node


  """
  expression
	  : assignment_expression
	  | expression ',' assignment_expression
  """
  def translate_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'assignment_expression':
      return self.translate_assignment_expression(children[0])
    else:
      self.translate_expression(children[0])
      return self.translate_assignment_expression(children[2])

  """
  assignment_expression
    : logical_or_expression
    | unary_expression assignment_operator assignment_expression
  """
  def translate_assignment_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'logical_or_expression':
      return self.translate_logical_or_expression(children[0])
    else:
      left = self.translate_unary_expression(children[0])
      right = self.translate_assignment_expression(children[2])
      if children[1]['children'][0]['name'] == '=':
        self.inner_code.assignment(
          left,
          right
        )
      else:
        self.inner_code.binary_op(
          left,
          left,
          children[1]['children'][0]['name'][:1],
          right
        )
      return left

  """
  logical_or_expression
    : logical_and_expression
    | logical_or_expression OR_OP logical_and_expression
  """
  def translate_logical_or_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'logical_and_expression':
      return self.translate_logical_and_expression(children[0])
    else:
      return self.binary_op(
        self.translate_logical_or_expression(children[0]),
        '||',
        self.translate_logical_and_expression(children[2])
      )


  """
  logical_and_expression
    : inclusive_or_expression
    | logical_and_expression AND_OP inclusive_or_expression
  """
  def translate_logical_and_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'inclusive_or_expression':
      return self.translate_inclusive_or_expression(children[0])
    else:
      return self.binary_op(
        self.translate_logical_and_expression(children[0]),
        '&&',
        self.translate_inclusive_or_expression(children[2])
      )

  """
  inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression '|' exclusive_or_expression
  """
  def translate_inclusive_or_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'exclusive_or_expression':
      return self.translate_exclusive_or_expression(children[0])
    else:
      return self.binary_op(
        self.translate_inclusive_or_expression(children[0]),
        '|',
        self.translate_exclusive_or_expression(children[2])
      )

  """
  exclusive_or_expression
    : and_expression
    | exclusive_or_expression '^' and_expression
  """
  def translate_exclusive_or_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'and_expression':
      return self.translate_and_expression(children[0])
    else:
      return self.binary_op(
        self.translate_exclusive_or_expression(children[0]),
        '^',
        self.translate_and_expression(children[2])
      )

  """
  and_expression
    : equality_expression
    | and_expression '&' equality_expression
  """
  def translate_and_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'equality_expression':
      return self.translate_equality_expression(children[0])
    else:
      return self.binary_op(
        self.translate_and_expression(children[0]),
        '&',
        self.translate_equality_expression(children[2])
      )

  """
  equality_expression
    : relational_expression
    | equality_expression EQ_OP relational_expression
    | equality_expression NE_OP relational_expression
  """
  def translate_equality_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name'] == 'relational_expression':
      return self.translate_relational_expression(children[0])
    else:
      return self.binary_op(
        self.translate_equality_expression(children[0]),
        children[1]['name'],
        self.translate_relational_expression(children[2])
      )

  """
  relational_expression
    : shift_expression
    | relational_expression '<' shift_expression
    | relational_expression '>' shift_expression
    | relational_expression LE_OP shift_expression
    | relational_expression GE_OP shift_expression
  """
  def translate_relational_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if len(children) == 1:
      return self.translate_shift_expression(children[0])
    else:
      return self.binary_op(
        self.translate_relational_expression(children[0]),
        children[1]['name'],
        self.translate_shift_expression(children[2])
      )

  """
  shift_expression
    : additive_expression
    | shift_expression LEFT_OP additive_expression
    | shift_expression RIGHT_OP additive_expression
  """
  def translate_shift_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if len(children) == 1:
      return self.translate_additive_expression(children[0])
    else:
      return self.binary_op(
        self.translate_relational_expression(children[0]),
        children[1]['name'],
        self.translate_shift_expression(children[2])
      )

  """
  additive_expression
    : multiplicative_expression
    | additive_expression '+' multiplicative_expression
    | additive_expression '-' multiplicative_expression
  """
  def translate_additive_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if len(children) == 1:
      return self.translate_multiplicative_expression(children[0])
    else:
      return self.binary_op(
        self.translate_additive_expression(children[0]),
        children[1]['name'],
        self.translate_multiplicative_expression(children[2])
      )

  """
  multiplicative_expression
    : unary_expression
    | multiplicative_expression '*' unary_expression
    | multiplicative_expression '/' unary_expression
    | multiplicative_expression '%' unary_expression
  """
  def translate_multiplicative_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if len(children) == 1:
      return self.translate_unary_expression(children[0])
    else:
      return self.binary_op(
        self.translate_multiplicative_expression(children[0]),
        children[1]['name'],
        self.translate_unary_expression(children[2])
      )

  """
  unary_expression
    : postfix_expression
    | INC_OP unary_expression
    | DEC_OP unary_expression
    | unary_operator unary_expression
  """
  def translate_unary_expression(self, node:dict) -> Variable or Constant or Array_elem:
    children = node['children']
    if children[0]['name']:
      return self.translate_postfix_expression(children[0])
    else:
      u = self.translate_unary_expression(children[1])
      if isinstance(u, Constant):
        err = TranslateError(node, 'Expression should be modifiable.')
        log.print_log(err)
      if children[0]['name'] == '++' or children[0]['name'] == '++':
        self.inner_code.binary_op(
          u,
          u,
          children[0]['name'][:1],
          1
        )
      else:
        self.inner_code.unary_operation(
          u,
          children[0],
          u
        )
      return u

  """
  postfix_expression
    : primary_expression
    | postfix_expression '[' expression ']'
    | postfix_expression '(' ')'
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression INC_OP
    | postfix_expression DEC_OP
  """
  def translate_postfix_expression(self, node:dict, target_type:str='temp') -> Variable or Constant or Array_elem or Function:
    children = node['children']
    if len(children) == 1:
      e = self.translate_primary_expression(children[0])
      if isinstance(e, Identifier):
        if target_type == 'function':
          return self.lookup_function(e, children[0])
        else:
          return self.lookup_variable(e, children[0])
      else:
        return e
    else:
      if children[1]['name'] == '[':
        v = self.translate_postfix_expression(children[0])
        return Array_elem(v, self.translate_expression(children[2]))
      elif children[1]['name'] == '(':
        f = self.translate_postfix_expression(children[0], 'function')
        if len(children) == 4:
          arguments = self.translate_argument_expression_list(children[2])
        else:
          arguments = []
        if f.return_type == 'void':
          self.inner_code.call_function(f, arguments)
        else:
          t = self.create_temp(f.return_type)
          self.inner_code.call_function(f, arguments, t)
          return t

      else: # ++ and --
        v = self.translate_postfix_expression(children[0])
        result = self.create_temp(v.type)
        self.inner_code.assignment(
          result,
          v
        )
        self.inner_code.binary_op(
          v,
          v,
          children[1]['name'][:1],
          1
        )
        return result


  """
  primary_expression
    : IDENTIFIER
    | CONSTANT_INT
    # | CONSTANT_DOUBLE
    # | STRING_LITERAL
    | '(' expression ')'
  """
  def translate_primary_expression(self, node:dict) -> Variable or Identifier or Constant:
    children = node['children']
    if children[0]['name'] == 'identifier':
      return Identifier(children[0]['val'])
    elif children[0]['name'] == 'int_constant':
      return Constant('int', children[0]['val'])
    else:
      return self.translate_expression(children[1])

  """
  argument_expression_list
    : assignment_expression
    | argument_expression_list ',' assignment_expression
  """
  def translate_argument_expression_list(self, node:dict) -> List[Variable or Constant or Array_elem]:
    children = node['children']
    if len(children) == 1:
      return [self.translate_assignment_expression(children[0])]
    else:
      arguments = self.translate_argument_expression_list(children[0])
      arguments.append(self.translate_assignment_expression(children[2]))
      return arguments

  """
  statement
    : compound_statement
    | labeled_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
  """
  def translate_statement(self, node:dict, switch_res=None):
    child = node['children'][0]
    child_name = child['name']
    if child_name == 'compound_statement':
      self.translate_compound_statement(child)
    elif child_name == 'labeled_statement':
      self.translate_labeled_statement(child, switch_res)
    elif child_name == 'expression_statement':
      self.translate_expression_statement(child)
    elif child_name == 'selection_statement':
      self.translate_selection_statement(child)
    elif child_name == 'iteration_statement':
      self.translate_iteration_statement(child)
    else:
      self.translate_jump_statement(child)

  """
  expression_statement
    : ';'
    | expression ';'
  """
  def translate_expression_statement(self, node:dict) -> None:
    children = node['children']
    if len(children) == 2:
      self.translate_expression(children[0])

  """
  labeled_statement
    : IDENTIFIER ':' statement
    | CASE logical_or_expression ':' statement
    | DEFAULT ':' statement
  """
  def translate_labeled_statement(self, node:dict, switch_res=None) -> None:
    children = node['children']
    if children[0]['name'] == 'case':
      case_end_label = self.create_label()
      condition = self.create_temp('int')
      self.inner_code.binary_op(
        condition,
        switch_res,
        '==',
        self.translate_logical_or_expression(children[1])
      )
      self.inner_code.if_not_goto(condition, case_end_label)
      self.translate_statement(children[-1], switch_res)
      self.inner_code.translate_label(case_end_label)
    elif children[0]['name'] == 'default':
      pass # do nothing
    else:
      label = self.create_label()
      self.add_label_to_current_scope(label, children[0]['val'], children[0])


  """
  selection_statement
    : IF '(' expression ')' statement ELSE statement
    | IF '(' expression ')' statement %prec LOWER_PREC_THAN_ELSE
    | SWITCH '(' expression ')' statement
  """
  def translate_selection_statement(self, node:dict):
    children = node['children']
    condition = self.translate_expression(children[2])
    if children[0]['name'] == 'switch':
      nodes = children[4]['children']
      if nodes[0]['name'] != 'compound_statement':
        raise TranslateError(node[0], 'Compound statement needed.')
      nodes = children[0]['children']
      if len(nodes) == 2:
        return
      nodes = children[1]['children']
      def handle_block_item(n:dict):
        if n['name'] != 'statement':
          raise TranslateError(n, 'Switch block can only contain statements.')
        self.translate_statement(n, condition)
      while len(nodes) == 2:
        handle_block_item(nodes[1])
        nodes = nodes[0]['children']
      handle_block_item(nodes[0])
    elif len(children) == 7:
      else_label = self.create_label()
      if_end_label = self.create_label()
      self.inner_code.if_not_goto(condition, else_label)
      self.translate_statement(children[4])
      self.inner_code.goto(if_end_label)
      self.inner_code.translate_label(else_label)
      self.translate_statement(children[6])
      self.inner_code.translate_label(if_end_label)
    else:
      if_end_label = self.create_label()
      self.inner_code.if_not_goto(condition, if_end_label)
      self.translate_statement(children[4])
      self.inner_code.translate_label(if_end_label)
      





  '''
  iteration_statement:
      WHILE '(' expression ')' statement
    | DO statement WHILE '(' expression ')' ';'
    | FOR '(' expression_statement expression_statement ')' statement
    | FOR '(' expression_statement expression_statement expression ')' statement
  '''
  def translate_iteration_statement(self,node):
    #while 语句
    if node['children'][0]['name']=='while':
      new_scope=Scope()
      self.scope_stack.append(new_scope)

      label1=self.create_label()#while label
      label2=self.create_label()#statement label
      label3=self.create_label()#next label

      new_scope.break_label=label3
      new_scope.continue_label=label1

      self.add_label_to_current_scope(label1, Identifier(label1),node)
      self.add_label_to_current_scope(label2, Identifier(label2), node)
      self.add_label_to_current_scope(label3, Identifier(label3), node)
      expression=node['children'][2]
      statement=node['children'][4]

      self.inner_code.translate_label(label1)
      expression_element=self.translate_expression(expression)
      self.inner_code.if_goto(expression_element,label2)
      self.inner_code.goto(label3)

      self.inner_code.translate_label(label2)
      self.translate_statement(statement)
      self.inner_code.goto(label1)
      self.inner_code.translate_label(label3)

      self.scope_stack.pop(-1)
    else:
      if node['children'][0]['name']=='do':
        new_scope=Scope()
        self.scope_stack.append(new_scope)
        statement=node['children'][1]
        expression=node['children'][4]
        label1=self.create_label()
        label2=self.create_label()
        self.add_label_to_current_scope(label1,Identifier(label1),node)
        self.add_label_to_current_scope(label2,Identifier(label2),node)

        new_scope.continue_label=label1
        new_scope.break_label=label2
        self.inner_code.translate_label(label1)
        self.translate_statement(statement)

        expression_element=self.translate_expression(expression)
        self.inner_code.if_goto(expression_element,label1)
        self.inner_code.translate_label(label2)
        self.scope_stack.pop(-1)
      else:
        if node['children'][0]['name']=='for':
          #FOR '(' expression_statement expression_statement ')' statement
          if node['children'][4]['name']==')':
            new_scope=Scope()
            self.scope_stack.append(new_scope)
            init_statement=node['children'][2]
            condition=node['children'][3]
            do_statement=node['children'][5]

            label1 = self.create_label()
            label2 = self.create_label()
            label3 = self.create_label()
            self.add_label_to_current_scope(label1, Identifier(label1), node)
            self.add_label_to_current_scope(label2, Identifier(label2), node)
            self.add_label_to_current_scope(label3, Identifier(label3), node)

            new_scope.break_label=label3
            new_scope.continue_label=label1

            if init_statement['children'][0]['name']=='expression':
              self.translate_expression(init_statement)

            self.inner_code.translate_label(label1)

            if condition['children'][0]['name']=='expression':
              condition_element=self.translate_expression(condition['children'][0])
              self.inner_code.if_goto(condition_element,label2)
            else:
              self.inner_code.goto(label2)

            self.inner_code.goto(label3)
            self.inner_code.translate_label(label2)

            self.translate_statement(do_statement)
            self.inner_code.goto(label1)
            self.inner_code.translate_label(label3)

            self.scope_stack.pop(-1)
          else:#FOR '(' expression_statement expression_statement expression ')' statement
            new_scope=Scope()
            self.scope_stack.append(new_scope)
            init_statement=node['children'][2]
            condition=node['children'][3]
            action=node['children'][4]
            do_statement=node['children'][6]

            label1 = self.create_label()
            label2 = self.create_label()
            label3 = self.create_label()
            self.add_label_to_current_scope(label1, Identifier(label1), node)
            self.add_label_to_current_scope(label2, Identifier(label2), node)
            self.add_label_to_current_scope(label3, Identifier(label3), node)

            new_scope.break_label=label3
            new_scope.continue_label=label1

            if init_statement['children'][0]['name']=='expression':
              self.translate_expression_statement(init_statement)

            self.inner_code.translate_label(label1)
            if condition['children'][0]['name']=='expression':
              condition_element=self.translate_expression(condition['children'][0])
              self.inner_code.if_goto(condition_element,label2)
            else:
              self.inner_code.goto(label2)

            self.inner_code.goto(label3)
            self.inner_code.translate_label(label2)

            self.translate_statement(do_statement)
            self.translate_expression(action)

            self.inner_code.goto(label1)
            self.inner_code.translate_label(label3)

            self.scope_stack.pop(-1)

  '''
  jump_statement:
      GOTO IDENTIFIER ';'
    | CONTINUE ';'
    | BREAK ';'
    | RETURN ';'
    | RETURN expression ';'
  '''
  def translate_jump_statement(self,node):
    if node['children'][0]['name']=='goto':
      identifier_name=node['children'][1]['name']
      label=self.lookup_label(Identifier(identifier_name),node)
      self.inner_code.goto(label)
    elif node['children'][0]['name']=='continue':
      label=None
      for scope in reversed(self.scope_stack):
        if scope.continue_label is not None:
          label=scope.continue_label
          self.inner_code.goto(label)
          break
      if label is None:
        log.print_log(TranslateError(node,r'can not continue here'))

    elif node['children'][0]['name']=='break':
      label = None
      for scope in reversed(self.scope_stack):
        if scope.break_label is not None:
          label=scope.break_label
          self.inner_code.goto(label)
          break
      if label is None:
        log.print_log(TranslateError(node,r'can not break here'))
    else:
      if node['children'][1]==';':
        self.inner_code.return_null()
      else:
        expression=node['children'][1]
        expression_element=self.translate_expression(expression)
        self.inner_code.return_value(expression_element)











