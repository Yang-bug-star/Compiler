#### ReadMe

- lex源程序`clang.l`到词法分析程序C源文件`lex.yy.c`的编译命令

  ```shell
  flex clang.l
  ```

- `lex.yy.c`到词法分析程序的可执行文件`clang.out`的编译命令

  ```shell
  gcc lex.yy.c -o clang.out
  ```

- 词法分析程序`clang.out`的用法：

   `Usage: <program_name> <input_file> <output_file>(optional)` 

  `program_name`是可执行程序，即`./clang.out`，要求用户必须提供C源程序文件作为输入。本实现假定用户提供的C源程序文件是已经由预处理器处理过的了（包括`#include`、`#define`等预处理指令），当然没有预处理过本程序也能正常分析，只是会将`#`识别为非法字符而已。用户如果没有提供输出文件名，则token序列直接在终端输出；否则，将输出到指定文件中。如果用户没有提供输入文件，程序报错终止。

  <br>

  正确用法示例

  ```shell
  ./clang.out demo.c tokens.txt
  ```

  

