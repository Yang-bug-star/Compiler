##### 程序使用说明

lex源文件见`clang.l`，Yacc源文件见`clang.y`。依次用flex和bison编译这两个源文件生成`lex.yy.c`和`clang.tab.c`、`clang.tab.h`、`clang.output`

编译命令

```shell
flex clang.l
```

```shell
bison -dv clang.y
```

-d编译参数用于生成包含`clang.y`中定义的所有终结符的常量定义的头文件`clang.tab.h`，-v编译参数指定生成包含语法冲突说明和有关LALR分析表、所有状态的可读描述，据此可以手动演绎语法分析过程

然后联合编译`lex.yy.c`和`clang.tab.c`

```shell
gcc lex.yy.c clang.tab.c -o parser
```

生成的可执行文件`parser`即为语法分析程序



`parser`程序用法

`Usage: <prog_name> <input_file>`

至少提供一个输入文件，否则程序报告如上正确用法

运行命令

```shell
./parser <input_file>
```



样例输出

 <img src="C:\Users\91889\AppData\Roaming\Typora\typora-user-images\image-20220405112355698.png" alt="image-20220405112355698" style="zoom:50%;" />