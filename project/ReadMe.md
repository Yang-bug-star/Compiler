在code文件夹中运行命令

```shell
flex --outfile=lex.yy.cpp lexer.l
bison -d -y parser.y --output=y.tab.cpp
echo '#include"tree.h"' | cat - y.tab.hpp > y.tab.hpp.temp && rm y.tab.hpp && mv y.tab.hpp.temp y.tab.hpp
g++ -std=c++11 -w lex.yy.cpp y.tab.cpp tree.cpp -o compiler 
./compiler test.c
python3 main1.py
python3 main2.py
```

需要事先用`sudo apt-get install spim`安装MIPS32模拟器，`bison -d -y parser.y --output=y.tab.cpp`可能会有警告，但不影响正确性

所交`compiler`为词法分析和语法分析融合的可执行文件，会生成`syntax-tree.json`，终端显示词法分析结果

运行`main1.py`生成`inner_code.txt`，在result文件夹中，result文件夹自动生成

运行`main2.py`生成目标代码`result.asm`