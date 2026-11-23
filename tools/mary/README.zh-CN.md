# Mary

本目录来自 Wokann/mary 的 `c++` 分支，提交
`a7fccf142b5c6d02cd83a612a1ceea591168cdfc`。
FoMT 通过正常 Makefile 从源码构建本工具。编译使用
`include/fomt_constants.mary.h` 及各区域脚本旁的两个头文件；
`goodies/` 只用于可选的原版反编译命名适配。

[English](README.md) | [简体中文](README.zh-CN.md)

Mary 是使用 C++17 编写的跨平台剧情脚本编译器、反编译器及 ROM 导入工具。
支持《矿石镇的伙伴们》JP／US／EU／DE 和女孩版 JP／US。
正常构建只需主机 C++ 编译器和 GNU Make，无需 Rust、Cargo、解析器生成器或第三方库。

## 构建

```sh
make -j4
make check
```

Linux 可用 GCC／Clang，macOS 可用 Apple 命令行 C++ 工具，Windows 可在 MSYS2 环境中
使用 MinGW-w64 和 Make。Unix 生成 `mary`，Windows 生成 `mary.exe`。
Windows 构建静态链接 GCC／C++ 运行库。

```sh
make CXX=clang++ CXXFLAGS="-O2 -Wall -Wextra"
make clean
```

Makefile 采用普通宿主工具的组织：`src/*.cc` 与 `src/*.hh` 编译成一个程序。
`make check` 另外构建 C++ 回归检查程序，不需要 ROM。
迁移在 `c++` 分支开发；旧 Rust 实现可从 `Enhanced` 的历史追溯。

## 编译文本源码

Mary-C 是主要维护格式。`.mary.c`／`.mary.h` 后缀用于 C 语法高亮，实际必须交给 Mary
编译，不能交给普通 C 编译器。旧 DSL 的编译功能也保留。

```sh
./mary compile decompiled_text/fomt_us/script_1.mary.c --mary-c \
  --charmap charmap.txt --binary -o script.riff

./mary compile script.mary --binary -o script.riff
./mary compile script.mary --print-ir -o script_arrays.c
```

不加 `--binary` 时输出 C 数组；二进制模式要求输入恰好包含一个脚本。
不提供文件名时读取标准输入。`--library`、`--script-table`、`--constants`
可以指定表头。Mary-C 的引号 include 先相对于发出引用的文件查找，再按命令行
`-I` 的顺序搜索。相对命令行路径以当前工作目录为准。

`--mary-c --binary --source-map script.tsv` 可同时导出调试映射，RIFF 字节保持一致。`--source-map -` 将映射写到标准错误，标准输出仍可用来传输二进制。映射记录实际 CODE 偏移、预处理前的源码行、条件计算起点和跳转真值，以及本次编译使用的 callable 原型、变量号和区域字符表解出的 STR 文本。`mary_ir` 原始指令块没有 Mary-C 语句行映射。

共享常量头支持有溢出检查的 64 位整数表达式、对象宏、函数宏、续行、嵌套条件和区域宏。
脚本运行期的 VM 算术不会被擅自常量折叠；脚本中的位运算要求操作数为常量。
不支持宏字符串化、token 拼接和可变参数宏。

## 反编译：默认使用通用编号

```sh
./mary decompile rom/fomt_us.gba --all --mary-c --charmap charmap.txt \
  -o decompiled_text/fomt_us
```

默认不加载原版命名或常量适配表，使用 `script_N` 等通用名称，并通过 `mary_ir`
显式列出编号指令。文本仍由选定码表转为可编辑内容。
这样不会假设改版的调用编号、常量和脚本顺序仍具有原版含义。

```c
mary_script(1) void script_1(void)
{
    mary_ir
    {
        String("Example text")
        PushInt(0)
        Call(33)
    }
}
```

编号形式保留物理 STR 表、标签、跳转、switch 分支及栈指令，不猜测函数参数和用途。
旧 DSL 用 `ir` 表示同一套无损指令。

若显式提供 `--library`，可以根据其调用形状生成结构化的通用源码；函数名称仍会转为
`func_N`／`proc_N`，不会套用原版常量名。

### 显式启用原版适配

```sh
./mary decompile rom/fomt_us.gba --all --mary-c --vanilla-names \
  --charmap charmap.txt -o decompiled_text/fomt_us
```

只有确认是原版，或相关定义未被大幅修改的改版，才使用 `--vanilla-names`。
此时才读取工具 `goodies/` 下的对应适配，包括函数签名、类型化常量、脚本／文本名及
局部变量类型提示，导出带语义名称的结构化 Mary-C。

可以用 `--library`、`--constants`、`--script-table`、`--symbols` 指定适配文件；
`--text-names` 是 `--symbols` 的别名。适配不符时报告错误，不会静默套上错误名称。
独立 RIFF 不带可识别的 ROM 头，导出 Mary-C 或使用原版名称时需指定
`-D MARY_FOMT_US` 等目标。

`--script-id N` 选择一个 ROM 表项，`--offset 0xADDRESS` 从明确的文件偏移／GBA 地址
读取 RIFF；它们不能与 `--all` 混用。改版可通过
`--pointer-table ADDRESS --pointer-count COUNT` 指定脚本总表。
没有选择器时，输入视为一个独立 RIFF。`--print-ir` 可以附带指令清单。

## 为反编译工程生成链接输入

```sh
./mary bundle data/scripts/us -o build/us/data/scripts --layout packed \
  --library data/scripts/us/fomt_callables.mary.h \
  --script-table data/scripts/us/fomt_scripts.mary.h \
  --constants include/fomt_constants.mary.h \
  -I include -I text/us/script \
  --charmap charmap.txt -D MARY_FOMT_US
```

packed 模式生成 `scripts.bin`、`scripts.s`、`script_table.s` 和 `scripts.d`。
汇编为普通汇编器／链接器提供脚本、各条文本及总指针表的符号。
`--layout split` 则将每个 RIFF 写入 `riff/`。依赖路径按 Make 规则转义。
空指针槽位、同内容但独立声明的字符串均保留；项目提供修复分支时可传入 `-D BUGFIX`。

后续整合 FoMT 时，工具源码放在 `tools/mary/`，采用普通宿主工具构建规则。
编译所用的权威表只维护 FoMT 自身的 `include/fomt_constants.mary.h`，以及各语言
`data/scripts/<region>/fomt_callables.mary.h`／`fomt_scripts.mary.h`。
Mary 从 `text/<region>/script/` 展开编号脚本的同名文本头，并在构建依赖里记录这些头。
Mary 按显式路径读取，不安装另一份表去覆盖它们。
工具自身 `goodies/` 的独立适配仅供主动选择的反编译和测试使用。

## 导入 ROM 副本

```sh
./mary import rom/fomt_us.gba decompiled_text/fomt_us -o edited.gba \
  --charmap charmap.txt --dry-run

./mary import rom/fomt_us.gba decompiled_text/fomt_us -o edited.gba \
  --charmap charmap.txt
```

目录输入按照完整的有序表导入；单文件需同时指定 `--script-id N`。
默认必须放得进原来的对齐分配空间。`--address ADDRESS` 可以明确指定脚本块的新位置；
`--relocate-pointer-table ADDRESS` 可以移动总表，并更新已知的原生代码引用。
迁移后的表使用 `MARYTAB1` 元数据记录当前数量和位置，便于再次反编译。
输入 ROM 不会被覆盖。

导入会检查边界、重叠、空槽、表引用及目标区已有内容。
`--force` 授权提示过的覆盖，`--dry-run` 不写输出。
输出先写入独占创建的临时文件，再原子替换目标文件。
工具不会自动扩容 ROM，也不会猜测任意新增的原生代码引用。

## 字符码表

使用 `HEX=TEXT`，保留末尾空格；同一文本的第一种编码作为规范编码。
重复字节键和嵌入 STR 结束符的映射会被拒绝。无法唯一还原的字节用 `\xNN` 导出，
字符串可以混用映射文本与原始字节转义。

`\r`、`\n`、`\p`、`{Press}`、`{Player}` 等名称由码表定义。
生成源码在 `\n`／`\p` 后分行，不添加实际字节。
普通 `#` 注释继续有效；区域 `#if` 仅筛选映射，不把映射中的引号、斜杠当作 C 语法。

## 辅助分析

原有辅助程序的功能整合为同一可执行文件内的命令：

```sh
./mary analyse-callable-shapes rom/fomt_us.gba
./mary generate-script-table goodies/fomt_scripts_text.mary.sym MARY_FOMT_US scripts.mary.h
./mary generate-symbols rom/fomt_jp.gba rom/fomt_us.gba rom/fomt_eu.gba rom/fomt_de.gba \
  rom/mfomt_jp.gba rom/mfomt_us.gba generated_symbols
```

符号生成只建立编号起始表，不推断语义名；除非显式选择已有适配目录，否则不会覆盖人工维护的表。

## 验证

迁移使用六个原版 ROM，分别验证原版命名和通用编号两种模式：
ROM → 导出源码 → 原生编译／bundle／导入 → ROM，输出 SHA-1 均与输入一致。
原版语料共 8,142 个非空脚本。FoMT 现有四语言源码在 BUGFIX 开、关两种状态下，
生成的 RIFF 字节也均与 Rust 对照版本一致。
ROM 和本地验证产物不是构建依赖，也不随仓库发布。
