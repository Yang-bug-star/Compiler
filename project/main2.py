from translate_to_mips import Translate_to_MIPS

filename='result/inner_code.txt'
path='result/result.asm'
translate_to_MIPS=Translate_to_MIPS(filename,path)
translate_to_MIPS.translate()
