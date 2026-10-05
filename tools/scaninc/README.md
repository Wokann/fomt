# scaninc：源码依赖扫描器

本工具来自 pret/pokeemerald 的 `tools/scaninc`，保留各源文件中的 MIT
许可与署名。导入基准为上游 `master` 分支的提交：

`731ad5bfd6e6f265508d0efcca0ba42f9dcf5881`。

来源：https://github.com/pret/pokeemerald/tree/731ad5bfd6e6f265508d0efcca0ba42f9dcf5881/tools/scaninc

用于在汇编开始之前，递归扫描 `.include` 和 `.incbin`，生成普通
Make `.d` 依赖文件。缺少的生成资源由已有后缀规则生成；不读取
baserom、不转换图像、不补丁 ROM，也不创建额外资源目录。

FoMT 的局部适配只针对通用语法和输入健壮性：C++ 文件后缀、GAS
大小写指令及 `@` 注释、空文件、文件末尾的边界检查和输出失败。
命令行的 `-D NAME`／`-U NAME` 可明确某个汇编符号已定义／未定义，
支持 `.ifdef`、`.ifndef`、`.ifnotdef` 及其嵌套 `.else`／`.endif`。
只排除由这些已知判断证明不启用的分支；未知符号、数值表达式和
`.elseif` 仍保守扫描全部可能分支，不猜测源码里的 `.set` 或宏执行。
不传 `-D`／`-U` 时保留全部可能分支的传统行为。
工具不根据 ROM 地址、语言名字或某个资源名特殊处理。
C/C++ 的宏 include 继续由
实际 C 预处理器决定，不能用此扫描器替代宏展开。

在 WSL 中可使用 `make -C tools/scaninc` 构建，根 Makefile 自动调用。

根 Makefile 在汇编之前创建并加载 `.d`，递归 include 的修改也会
重新扫描依赖。转换规则仍集中在 `graphics_file_rules.mk`；资源
路径只在实际源码引用处维护，不再为对象重复列出一份资源清单，
也不要求所有对象等待一个单独的整批图形阶段。

根 Makefile 将当前区域符号传为 `-D`，另外三个区域传为 `-U`，
因此 JP 不会请求 DE 的归档，DE 也不会误用 JP 的生成参数。
`.d` 同时依赖 Makefile／config.mk，修改构建配置会重新扫描。
这避免已有生成文件曾掩盖的跨区域缓存依赖，不需要资源清单或
新增预处理阶段；未知条件的保守行为仍保证不漏掉潜在依赖。
