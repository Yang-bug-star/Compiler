程序要求用户运行程序时提供包含若干算术表达式实例的输入文件，否则程序会报告正确用法`Usage: <program_name> <input_file>`。

输入文件格式要求：每个算术表达式实例占一行，不能跨行，每一行都认为是用户提供的一个待分析串（即便是空行）。词法分析输入文件`scanner_infile`和词法分析结果输出文件`scanner_outfile`可以根据需要在程序中手动修改，本实验中`scanner_infile = "input_expr.txt"`，`scanner_outfile = "scan_result.txt"`，程序在运行过程中会自动生成这两个文件。

程序在终端输出对每个输入式子的语法解析结果，对于符合语法规则的算术表达式直接给出语法解析成功；对于不符合语法规则的则给出发生解析错误的位置及错误原因。最终`input_expr.txt`只保留输入文件最后一个表达式，`scan_result.txt`只保留最后一个表达式的词法分析结果。

编译命令

**LL(1)**

```shell
g++ lexer.cpp LL1.cpp -o ll1_parser
```

**SLR(1)**

```shell
g++ lexer.cpp SLR1.cpp -o slr1_parser
```

其中`lexer.cpp`是词法分析部分，改造于实验一的`lex.yy.c`，`LL1.cpp`为本实验的**LL(1)**语法分析程序，`SLR1.cpp`为**SLR(1)**语法分析程序，这两个语法分析程序调用`lexer.cpp`中的`lexer`函数定义得到对每个表达式的词法分析结果用于语法分析。

运行命令

**LL(1)**

```shell
./ll1_parser test.txt
```

**SLR(1)**

```shell
./slr1_parser test.txt
```

`test.txt`为程序测试文件，为了展示程序的正确性，为正确解析和每种错误类型分别构造了测试实例。

其内容如下：

```
a-- + 3 * ( b + c / 10) - 4 % 5
a->id + 3.2e2 * sizeof(const struct id) % *p - b.id  
(-a % !0 + 6 + &a - ~(b * b))
a + 3(b + c / 10)
s)
1 + b.
2%%10
```

前三个为正确样例，后四个为错误样例

