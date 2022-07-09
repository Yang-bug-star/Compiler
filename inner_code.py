from symbolTable import Variable, Function, Constant

class Inner_code:
  fout = None

  inner_code_list=[]

  def write(self):
    for inner_code in self.inner_code_list:
      self.fout.write(inner_code+'\n')

  def __init__(self, path):
    self.fout = open(path,"w")

  def translate_label(self, label):
    inner_code='LABEL '+label+':'
    self.inner_code_list.append(inner_code)

  def assignment(self, dest, src):
    inner_code = str(dest) + ' := ' + str(src)
    self.inner_code_list.append(inner_code)

  def unary_operation(self, dest, operand, src):
    self.assignment(
      dest,
      operand + ' ' + str(src)
    )

  def binary_op(self, dest, src1, operand, src2):
    self.assignment(
      dest,
      str(src1) + ' ' + operand + ' ' + str(src2)
    )

  def function_declare(self,function):
    inner_code='Function '+function.name+'('
    param_list=''
    for param in function.arguments:
      param_list += str(param) + ','
    param_list=param_list[:-1]
    inner_code=inner_code+param_list+')'+':'
    self.inner_code_list.append(inner_code)

  def call_function(self, function:Function, arguments, save_to:Variable=None):
    arguments_str = ''
    for argument in arguments:
      arguments_str += str(argument) + ','
    arguments_str = arguments_str[:-1]
    inner_code = 'CALL '+str(function)+'('+arguments_str+')'
    if save_to is not None:
      inner_code = str(save_to) + ' := ' + inner_code
    self.inner_code_list.append(inner_code)

  def malloc_array(self,src):
    inner_code='MALLOC '+str(src)
    self.inner_code_list.append(inner_code)

  def goto(self, label:str):
    inner_code = 'GOTO '+label
    self.inner_code_list.append(inner_code)

  def if_goto(self, condition: Constant or Variable, label:str):
    inner_code = 'IF '+str(condition)+' GOTO '+label
    self.inner_code_list.append(inner_code)

  def if_not_goto(self, condition: Constant or Variable, label:str):
    inner_code = 'IFNOT '+str(condition)+' GOTO '+label
    self.inner_code_list.append(inner_code)

  def return_null(self):
    inner_code='RETURN'
    self.inner_code_list.append(inner_code)

  def return_value(self,value):
    inner_code='RETURN '+str(value)
    self.inner_code_list.append(inner_code)
