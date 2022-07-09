from mips_code import MIPS_code
from registerFile import Register,RegisterFile,Live_variable_analysis

user_available_registers=['t0', 't1','t2','t3','t4','t5','t6','t7','t8','t9','s0','s1','s2','s3','s4','s5','s6','s7']

class Translate_to_MIPS:
  mips_code=None
  registerFile=None
  code_lines=None
  line_num=None

  def __init__(self,file_name,path):
    self.code_lines=self.Load_Inter(file_name)
    self.mips_code=MIPS_code(path)
    self.registerFile=RegisterFile(self.code_lines,self.mips_code)
    self.line_num=-1

  def Load_Inter(self,filename):
    lines=[]
    file=open(filename,'r',encoding='utf-8')
    for line in file:#中间代码
      line = line.replace('\r','').replace('\n','') #换行分割
      if line == '': #line没有内容 跳过
        continue
      lines.append(line.split(' ')) #放入list里
    return lines


  def function_call(self,function_name, params):
    saved_regs = ['ra'] + user_available_registers

    use_amount = len(saved_regs)*4
    self.mips_code.addi('sp', 'sp', -use_amount)
    count = 0
    for reg in saved_regs:
      self.mips_code.sw(reg, 'sp', count)
      count += 4

    param_count = 0
    for param in params:
      param_count += 1
      if param_count <= 4:
        self.mips_code.addi(
          'a'+str(param_count-1),
          self.registerFile.get_available_register(param, self.line_num)
        )

    self.mips_code.jal(function_name)

    count = 0
    for reg in saved_regs:
      self.mips_code.lw(reg, 'sp', count)
      count += 4
    self.mips_code.addi('sp', 'sp', use_amount)


  def function_return(self, variable=None):
    if variable is not None:
      if variable[0]=='t':
        self.mips_code.addi('v0', self.registerFile.get_available_register(variable,self.line_num))
      else:
        self.mips_code.addi('v0','zero',variable)
    self.mips_code.jr('ra')


  #翻译成汇编
  def translate(self):
    self.line_num=0
    for line in self.code_lines:
      if line[0]=='LABEL': #LABEL n: -> n:
        self.mips_code.write_label(line[1])
      if line[1]==':=': #left := right ->
        dst=self.registerFile.get_available_register(line[0],self.line_num)
        #数组形式 TODO
        src1=self.registerFile.get_available_register(line[2],self.line_num)
        src2=self.registerFile.get_available_register(line[-1],self.line_num)
        constant=line[-1]
        if len(line)==3:# vat *temp &temp array_element
          if line[-1][0]>='0' and line[-1][0]<='9':
            self.mips_code.li(dst,constant)
          else:
            self.mips_code.move(dst, src1)
        if len(line)==4:
          if line[2]=='CALL':
            temp_str = line[3].split('(')
            function_name = temp_str[0]
            params = temp_str[1][:-1].split(',')
            self.function_call(function_name, params)
            self.mips_code.addi(dst, 'v0')

        if len(line)==5: 
          if line[3]=='+':
            if line[-1][0]>='0' and line[-1][0]<='9':
              self.mips_code.addi(dst,src1,constant)
            else:
              self.mips_code.add(dst,src1,src2)
          if line[3]=='-':
            if line[-1][0]>='0' and line[-1][0]<='9':
              self.mips_code.addi(dst,src1, '-'+(constant))
            else:
              self.mips_code.sub(dst,src1,src2)
          if line[3]=='*':
            self.mips_code.mul(dst,src1,src2)
          if line[3]=='/':
            self.mips_code.div(dst,src1,src2)
          if line[3]=='^':
            if line[-1][0]>='0' and line[-1][0]<='9':
              self.mips_code.xori(dst,src1,constant)
            else:
              self.mips_code.xor(dst,src1,src2)
          if line[3]=='<':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.slti(dst,src1,constant)
            else:
              self.mips_code.slt(dst,src1,src2)
          if line[3]=='>':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.gti(dst,src1,constant)
            else:
              self.mips_code.gt(dst,src1,src2)
          if line[3]=='<=':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.lei(dst,src1,constant)
            else:
              self.mips_code.le(dst,src1,src2)
          if line[3]=='>=':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.gei(dst,src1,constant)
            else:
              self.mips_code.ge(dst,src1,src2)
          if line[3]=='&&':
            self.mips_code.and_(dst,src1,src2)

          if line[3]=='||':
              self.mips_code.or_(dst,src1,src2)

          if line[3]=='&':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.andi(dst,src1,constant)
            else:
              self.mips_code.and_(dst,src1,src2)
          if line[3]=='|':
            if line[-1][0] >= '0' and line[-1][0] <= '9':
              self.mips_code.ori(dst, src1, constant)
            else:
              self.mips_code.or_(dst,src1,src2)
          if line[3]=='<<':
            if line[-1][0]>='0' and line[-1][0]<='9':
              self.mips_code.sll(dst,src1,constant)
            else:
              self.mips_code.sllv(dst,src1,src2)
          if line[3]=='>>':
            if line[-1][0]>='0' and line[-1][0]<='9':
              self.mips_code.srl(dst,src1,constant)
            else:
              self.mips_code.srlv(dst,src1,src2)
      if line[0]=='GOTO': #GOTO label1
        self.mips_code.j(line[1])
      if line[0]=='IF': #IF var GOTO label1
        self.mips_code.bne(self.registerFile.get_available_register(line[1],self.line_num),line[-1])
      if line[0]=='IFNOT': #IFNOT var GOTO label1
        self.mips_code.beq(self.registerFile.get_available_register(line[1],self.line_num),line[-1])
      if line[0]=='RETURN': #RETURN var1
        self.function_return(line[1] if len(line)>1 else None)

      if line[0]=='CALL': #CALL f (var1,var2,var3...) 这里不太确定
        temp_str = line[3].split('(')
        function_name = temp_str[0]
        params = temp_str[1][:-1].split(',')

        self.function_call(function_name, params)
      if line[0]=='Function': #FUNCTION f(var1,var2,var3...):
        temp_str = line[1].split('(')
        function_name=temp_str[0]
        params = temp_str[1][:-2].split(',')
        self.mips_code.write_function_label(function_name)
        count = 0
        for param in params:
          self.mips_code.addi(self.registerFile.get_available_register(param, self.line_num), 'a'+str(count))
          count += 1
      self.line_num=self.line_num+1

