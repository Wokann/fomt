# Mary 脚本编译器

`mary.exe` 是本项目用于编译 `data/scripts/<region>` 中 Mary-C 脚本的 Windows 工具。

当前二进制的构建来源：

- 上游仓库：[Wokann/mary](https://github.com/Wokann/mary)
- 分支：`Enhanced`
- 提交：`e57546a2ead4e244f75390c34c1f615d4813b435`

该二进制由上述提交以 `cargo build --release` 构建。FOMT 的构建规则以 `bundle --layout packed`
调用它，并显式传入根目录的 `charmap.txt`、区域脚本头文件及
`include/fomt_constants.mary.h`。
