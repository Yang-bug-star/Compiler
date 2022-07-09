import json
import os
import shutil
from translator import Translator, TranslateError
from inner_code import Inner_code
from log import print_log

if os.path.exists("result"):
  shutil.rmtree("result")
os.makedirs("result") 

with open('syntax-tree.json') as syntax_tree_file:
  syntax_tree = json.load(syntax_tree_file)
inner = Inner_code(path='result/intermediate.txt')
translator = Translator(syntax_tree=syntax_tree, inner_code=inner)
try:
  translator.translate()
except TranslateError as e:
  print_log(e)
  quit(1)
inner.write()
