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
扫描保守地包含所有条件分支，不
根据 ROM 地址或某个资源名特殊处理。C/C++ 的宏 include 继续由
实际 C 预处理器决定，不能用此扫描器替代宏展开。

在 WSL 中可使用 `make -C tools/scaninc` 构建，根 Makefile 自动调用。

根 Makefile 在汇编之前创建并加载 `.d`，递归 include 的修改也会
重新扫描依赖。转换规则仍集中在 `graphics_file_rules.mk`；资源
路径只在实际源码引用处维护，不再为对象重复列出一份资源清单，
也不要求所有对象等待一个单独的整批图形阶段。
