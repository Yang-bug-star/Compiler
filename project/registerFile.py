from stackframe import stack_frames
import random

class Inner_code_for_one_statement:
  line_num=None    #行号
  function_name=None
  successor=None
  defined_variable_list=None
  used_variable_list=None
  active_var_in=None
  active_var_out=None

  def __init__(self,line_num,function_name,successor_num=None):
    self.line_num=line_num
    self.function_name=function_name
    self.successor = []
    self.defined_variable_list = []
    self.used_variable_list = []
    self.active_var_in = set()
    self.active_var_out = set()

    if successor_num is not None:
      self.successor.append(successor_num)

class Live_variable_analysis:
  code_list=None
  code_lines=None
  label_line=None
  variable_line=None
  def __init__(self,code_lines):
    self.code_lines=code_lines
    self.code_list=[]
    self.label_line={}
    self.variable_line={}

    self.init_code_list()
    self.liveness_calculation()
    self.show_liveness()

  def show_liveness(self):
    for code in self.code_list:
      string='line:'+str(code.line_num+1)
      string=string+' use:'
      for used_variable in code.used_variable_list:
        string=string+used_variable+','
      string = string + ' define:'
      for defined_variable in code.defined_variable_list:
        string = string + defined_variable + ','
      string =string+'in:'
      for active_var in code.active_var_in:
        string =string + active_var +','
      string = string + 'out:'
      for active_var_out in code.active_var_out:
        string = string + active_var_out + ','
      print(string)
  def is_temp(self,item):
    if item[0]=='t':
      return True
    else:
      return False

  def init_code_list(self):
    line_num=0
    for line in self.code_lines:
      if line[0]=='LABEL':
        label=line[1].split(':')[0]
        self.label_line[label]=line_num
      if line[0]=='Function':
        function_name = line[1].split('(')[0]
        self.label_line[function_name]=line_num
      line_num=line_num+1

    line_num=0
    function_name=None
    for line in self.code_lines:
      if line[0]=='LABEL':
        code=Inner_code_for_one_statement(line_num,function_name, line_num + 1)

      elif line[1] == ':=':
        code = Inner_code_for_one_statement(line_num,function_name, line_num + 1)
        if len(line[0].split('['))==1:
          code.defined_variable_list.append(line[0])
          self.variable_line[line[0]]=line_num
        else:#数组
          array_name=line[0].split('[')[0]
          code.used_variable_list.append(array_name)
          size=line[0].split('[')[1].split(']')[0]
          if self.is_temp(size):
            code.used_variable_list.append(size)
        if line[2] !='CALL':
          if len(line) == 3:
            if  self.is_temp(line[-1]):
              code.used_variable_list.append(line[2])
          if len(line) == 5:
            if self.is_temp(line[2]):
              code.used_variable_list.append(line[2])
            if self.is_temp(line[4]):
              code.used_variable_list.append(line[4])
        else:
          function_item=line[3]
          items=function_item.split('(')
          items=items[1].split(')')
          if items[0]!='':
            arguments=items[0].split(',')
            for argument in arguments:
              code.used_variable_list.append(argument)

      elif line[0] == 'GOTO':
        if line_num-1!=0 and self.code_lines[line_num-1][0]=='RETURN':#goto 的上一句是return就没有意义了
            code=Inner_code_for_one_statement(line_num,None)
            line_num=line_num+1
            self.code_list.append(code)
            continue
        code=Inner_code_for_one_statement(line_num,function_name)
        line_id=self.label_line[line[1]]
        code.successor.append(line_id)

      elif line[0] == 'RETURN':
        code=Inner_code_for_one_statement(line_num,function_name)
        if len(line)==2:
          if self.is_temp(line[1]):
            code.used_variable_list.append(line[1])
        function_name=None

      elif line[0] == 'IF' or line[0]=='IFNOT':
        code=Inner_code_for_one_statement(line_num,function_name)
        code.used_variable_list.append(line[1])
        code.successor.append(self.label_line[line[3]])
        if line_num+1!=len(self.code_lines):
          code.successor.append(line_num+1)

      elif line[0] == 'Function':
        function_name=line[1].split('(')[0]
        code=Inner_code_for_one_statement(line_num,function_name)
        if line_num+1!=len(self.code_lines):
          code.successor.append(line_num+1)

      elif line[0] == 'CALL':
        code=Inner_code_for_one_statement(line_num,function_name)
        function_item = line[1]
        items = function_item.split('(')
        items = items[1].split(')')
        if items[0] != '':
          arguments = items[0].split(',')
          for argument in arguments:
            code.used_variable_list.append(argument)
        if line_num+1!=len(self.code_lines):
          code.successor.append(line_num+1)

      elif line[0]=='MALLOC':
        code=Inner_code_for_one_statement(line_num,function_name,line_num+1)
        array_name=line[1].split('[')[0]
        code.defined_variable_list.append(array_name)
        size=line[1].split('[')[1].split(']')[0]
        if self.is_temp(size):
          code.used_variable_list.append(size)
      else:
        code=Inner_code_for_one_statement(line_num,None,None)
        error_message="error: invalid code: line"+str(line_num+1)+'  '
        for item in self.code_lines[line_num]:
          error_message=error_message+item+' '
        print(error_message)
      line_num=line_num+1
      self.code_list.append(code)

  def liveness_calculation(self):
    while(True):
      break_flag=True
      for code in self.code_list:
        active_var_in_final=code.active_var_in.copy()
        active_var_out_final=code.active_var_out.copy()
        code.active_var_in=set(code.used_variable_list)|(code.active_var_out-set(code.defined_variable_list))
        code.active_var_out=set()
        for succ in code.successor:
          code.active_var_out=code.active_var_out|self.code_list[int(succ)].active_var_in
        if code.active_var_in-active_var_in_final==set() and code.active_var_out-active_var_out_final==set():
          pass
        else:
          break_flag=False
      if break_flag==True:
        break

class Register:
  name=None
  available=None
  variable_name=None
  is_spilled=None
  spilled_var=None
  def __init__(self,registerName):
    self.name=registerName
    self.available=True
    self.variable_name=None
    self.is_spilled=False
    self.spilled_var=None

class RegisterFile:
  user_available_registers=[]
  liveness_analysis = None
  mips_code=None
  def __init__(self,code_lines,mips_code):
    for t in range(0,10):
      t_reg=Register('t'+str(t))
      self.user_available_registers.append(t_reg)
    for s in range(8):
      s_reg=Register('s'+str(s))
      self.user_available_registers.append(s_reg)
    self.liveness_analysis = Live_variable_analysis(code_lines)
    self.mips_code=mips_code

  def get_available_register(self,variable,line_num):
    for register in self.user_available_registers:
      if register.variable_name==variable:
        return register.name
    result=self.find_available_register(variable)
    if result!=False:
      return result
    else:
      for register in self.user_available_registers:
        if register.variable_name in self.liveness_analysis.code_list[line_num].active_var_out:
          pass
        else:
          register.available=True
      result_2=self.find_available_register(variable)
      if result_2!=False:
        return result_2
      else: #寄存器溢出
        while True:
          reg_id=random.randint(0,len(self.user_available_registers))
          if self.user_available_registers[reg_id].is_spilled==False:
            break
        offset=stack_frames[-1].request_space(4)
        self.mips_code.addi('fp', 'fp', -offset)
        reg_to_spill=self.user_available_registers[reg_id]
        self.mips_code.sw(reg_to_spill.name, 'fp')
        self.mips_code.addi('fp', 'fp', -offset)

        reg_to_spill.is_spilled=True
        reg_to_spill.spilled_var=reg_to_spill.variable
        reg_to_spill.variable=variable
        return reg_to_spill.name


  def find_available_register(self,variable):
    for register in self.user_available_registers:
      if register.available == True:
        register.variable_name = variable
        register.available=False
        return register.name
    return False




