# 牧场物语：矿石镇的伙伴们

[English](README.md) | 简体中文

本工程对 2003 年 Game Boy Advance 游戏 **Harvest Moon: Friends of Mineral Town**
进行字节匹配反编译，涵盖日版、美版英文、欧版英文和德版。

当前开发分支为 **multi-language**。代码、数据、函数和编译单元的覆盖情况见
[反编译进度](PROGRESS.md)。高级语言还原、动态引用审计与字节匹配分别记录。

## ROM

默认配置生成与原版一致的 ROM，其 SHA-1 如下：

| 版本 | 输出文件 | SHA-1 |
| --- | --- | --- |
| 日版 | `fomt_jp.gba` | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` |
| 美版英文 | `fomt_us.gba` | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` |
| 欧版英文 | `fomt_eu.gba` | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` |
| 德版 | `fomt_de.gba` | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` |

可选修复由 [include/config.h](include/config.h) 中的 `BUGFIX` 控制。
[BUGFIX 文档](BUGFIX.md)记录了受影响的版本、原版行为、判断依据和修复方式。

## 安装

Linux/WSL、Windows/MSYS2 和 macOS 的环境配置与编译方法，请参阅
[INSTALL.zh-cn.md](INSTALL.zh-cn.md)。

## 源码组织

- `src/` 和 `include/` 存放游戏模块及其声明，共享代码通过区域条件区分版本差异。
- `asm/` 存放独立汇编。还原中的模块也可以在 C/C++ 定义旁保留文件级汇编。
- `text/<region>/` 存放各版游戏文本，`reference_guide/` 存放图书指南页面，
  `script/` 存放 Mary 脚本文本表。`data/scripts/` 中带文本表的编号脚本
  包含对应区域的同名文本头。
  [include/fomt_constants.mary.h](include/fomt_constants.mary.h) 提供常规代码与脚本共用的常量。
- `graphics/` 存放资源源文件。[图形构建规则](graphics_file_rules.mk)将 PNG 图块和独立调色板
  转为游戏原生格式，并在源文件所在目录生成压缩资源。
- `tools/` 存放本机工具。内置的 C++17 Mary 编译器及其他工程工具由 Make 自动编译。
- `build/<region>/` 存放目标文件和生成代码，由各区域的 LDS 文件控制链接；
  ROM、ELF 和 map 输出到工程根目录。

正常构建使用工程内的源码和资源，原版 ROM 仅作为独立比较基准。

## 文档

| 文档 | 内容 |
| --- | --- |
| [PROGRESS.md](PROGRESS.md) | 反编译覆盖情况与进度记录 |
| [BUGFIX.md](BUGFIX.md) | 原版问题、判断依据与可选修复 |
| [REGIONAL_DIFFERENCES.md](REGIONAL_DIFFERENCES.md) | 各版本的机制、数据及脚本差异 |
| [RELOCATION_AUDIT.md](RELOCATION_AUDIT.md) | 符号引用、读取边界与动态引用审计 |
| [CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md) | 代码布局记录 |
| [TEXT_ROM_LAYOUT.md](TEXT_ROM_LAYOUT.md) | 文本布局记录 |
| [TEXT_SYMBOL_AUDIT.md](TEXT_SYMBOL_AUDIT.md) | 文本、命名及调用审计记录 |
| [Mary](tools/mary/README.zh-CN.md) | 脚本编译、反编译与 ROM 导入 |
| [文本处理](tools/textproc/README.md) | 文本转码与预处理 |
| [scaninc](tools/scaninc/README.md) | 源码与资源依赖扫描 |

## 参与贡献

欢迎参与。待办内容可参阅 [TODO.md](TODO.md)、进度记录和各项审计文档。

本工程基于 [StanHash/fomt](https://github.com/StanHash/fomt) 继续开发。
相关逆向资料见 [StanHash/FOMT-DOC](https://github.com/StanHash/FOMT-DOC)。
引入工具的源码保留了各自的署名与许可声明。
