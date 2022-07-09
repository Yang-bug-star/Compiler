stack_frames = []

class StackFrame:
  use_amount = 0
  params = None
  mips_code = None
  def __init__(self, mips_code):
    self.mips_code = mips_code
  def request_space(self, amount:int):
    self.mips_code.addi('sp', 'sp', -amount)
    self.use_amount += amount
    return self.use_amount - 4
