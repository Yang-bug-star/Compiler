from prettytable import PrettyTable

class Scope:
  variable_symbol_map=None    #变量符号表  
  function=None               #函数
  label_map=None              #label映射表
  break_label=None            #break跳转到的label
  continue_label=None         #continue跳转到的label
  goto_label=None             #goto跳转到的label

  def __init__(self):
    self.variable_symbol_map={}
    self.label_map={}

class Variable:
  name=None
  type=None
  is_pointer=False

  def __init__(self, name=None, type=None, is_pointer=False):
    self.name=name
    self.type=type
    self.is_pointer=is_pointer

  def __str__(self):
    return self.name


class Constant:
  type = None 
  value = None

  def __init__(self, type=None, value=None):
    self.type = type
    self.value = value

  def __str__(self):
    return self.value


class Array_elem:
  array_name:Variable = None
  index: Variable or Constant = None

  def __init__(self, array_name:Variable=None, index: Variable or Constant=None):
    self.array_name = array_name
    self.index = index

  def __str__(self):
    return str(self.array_name) +'[' + str(self.index) + ']'

class Identifier:
  name = None

  def __init__(self, name=None):
    self.name = name

  def __str__(self):
    return self.name


class Function:
  is_defined=False
  name=None
  return_type=None
  arguments=[]

  def __init__(self, name=None, return_type=None, is_definition=False, arguments=None):
    self.is_defined=is_definition
    self.name=name
    self.type=return_type
    if arguments is not None:
      self.arguments=arguments
    else:
      self.arguments=[]
  def __str__(self):
    return self.name

