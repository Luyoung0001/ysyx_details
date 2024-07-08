make ex1

```bash
第一个命令中你告诉make，“我想创建名为ex1的文件”。于是Make执行下面的动作：

文件ex1存在吗？
没有。好的，有没有其他文件以ex1开头？
有，叫做ex1.c。我知道如何构建.c文件吗？
是的，我会运行命令cc ex1.c -o ex1来构建它。
我将使用cc从ex1.c文件来为你构建ex1。
```
也就是说，如果没有 Makefile,将会使用默认 cc ex1.c -o ex1 来编译程序。



这里是这些函数的简要说明：
fputc(int c, FILE *stream)：将字符 c 写入到指定的文件流 stream 中。
fputs(const char *s, FILE *stream)：将字符串 s 写入到指定的文件流 stream 中，不包括空字符('\0')。
putc(int c, FILE *stream)：功能与 fputc 相同，但在某些系统中可能被实现为宏，而非函数。
putchar(int c)：是 putc 的简化形式，直接将字符写入标准输出。
puts(const char *s)：将字符串 s 写入标准输出，并自动添加一个换行符。

这些函数在语法上看起来类似于“重载”，因为它们的功能都是输出，但每个函数的具体用途、参数和适用场景不同。文档将它们组织在一起，主要是为了展示各种输出函数的用法，而不是因为它们在语法上有重载的关系。