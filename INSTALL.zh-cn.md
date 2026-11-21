# 安装说明

[English](INSTALL.md) | 简体中文

本教程说明如何配置工具并从源码编译 **FoMT**。先配置对应平台，再进入[安装](#安装)。

## Windows

选择一种终端编译 FoMT。

- [Windows 10/11（WSL）](#windows-1011wsl)
- [Windows（MSYS2）](#windowsmsys2)

## Windows 10/11（WSL）

以管理员身份打开 PowerShell，安装 Ubuntu。

```powershell
wsl --install -d Ubuntu
```

如有重启提示，先重启。然后从开始菜单打开 Ubuntu，完成首次设置并在该终端中按
[Linux 步骤](#linux)安装依赖。

## Windows（MSYS2）

### 配置 MSYS2

安装 [MSYS2](https://www.msys2.org/)。x86_64 打开 **UCRT64**，
ARM64 打开 **CLANGARM64**。运行 `pacman -Syu`。如需重开终端，
请在同一环境中再次运行该命令。

**UCRT64（x86_64）**

```sh
pacman -S --needed make mingw-w64-ucrt-x86_64-git mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-pkgconf mingw-w64-ucrt-x86_64-libpng \
    mingw-w64-ucrt-x86_64-zlib mingw-w64-ucrt-x86_64-arm-none-eabi-gcc
```

**CLANGARM64（ARM64）**

```sh
pacman -S --needed make mingw-w64-clang-aarch64-git mingw-w64-clang-aarch64-clang \
    mingw-w64-clang-aarch64-gcc-compat mingw-w64-clang-aarch64-pkgconf \
    mingw-w64-clang-aarch64-libpng mingw-w64-clang-aarch64-zlib \
    mingw-w64-clang-aarch64-arm-none-eabi-binutils
```

克隆 agbcc 前，启用 Windows 开发者模式或以管理员身份打开 MSYS2，
以便 Git 创建所需的符号链接。

## macOS

运行 `xcode-select --install` 安装 Apple 命令行工具，再按 [Homebrew](https://brew.sh/) 的说明配置终端。
Apple Silicon 使用原生 arm64 版 Homebrew。

```sh
brew install git make coreutils pkgconf libpng zlib gcc@14 arm-none-eabi-gcc
export PATH="$(brew --prefix make)/libexec/gnubin:$(brew --prefix coreutils)/libexec/gnubin:$PATH"
export PKG_CONFIG_PATH="$(brew --prefix zlib)/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
```

继续使用当前终端，或将两条 `export` 命令加入 `~/.zprofile`。使用 Bash 时写入
`~/.bash_profile`。

## Linux

### Debian / Ubuntu

Debian 和 Ubuntu（包括 WSL 中的 Ubuntu）安装以下软件包。

```sh
sudo apt update
sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
    gcc-arm-none-eabi binutils-arm-none-eabi
```

## 安装

选择一个路径不含空格的目录，将 FoMT 和 agbcc 放在该目录下的同一级。

1. 克隆 FoMT。

   ```sh
   git -c core.autocrlf=false clone --branch multi-language https://github.com/Wokann/fomt.git
   ```

2. 编译并安装 agbcc。

   ```sh
   git -c core.autocrlf=false -c core.symlinks=true clone --branch cp https://github.com/Wokann/agbcc.git
   cd agbcc
   ./build.sh
   ./install.sh ../fomt
   cd ..
   ```

如果已有仓库，分别执行 `git fetch origin`，在 FoMT 中运行 `git switch multi-language`，
在 agbcc 中运行 `git switch cp`，再分别执行 `git pull --ff-only` 后继续编译和安装。

## 编译 FoMT

进入 `fomt` 目录并运行 `make`。

```sh
cd fomt
make
```

默认生成日版 `fomt_jp.gba`。用 `make jp`、`make us`、`make eu` 或 `make de`
指定版本。也可以继续使用 `REGION` 参数，例如 `make REGION=us`。

# 编译说明

## 并行编译

如需加快编译，先查询终端可用的逻辑 CPU 数量。Linux、WSL 与 MSYS2 运行
`nproc`，macOS 运行 `sysctl -n hw.ncpu`。把得到的数字或更小的值加到
`make -j` 后面。例如查询结果为 8 时，可用 `make -j8 us` 并行编译美版。

## 与原版校验

运行 `make compare` 编译 ROM 并与原版 SHA-1 校验。默认日版通过时显示
`fomt_jp.gba: OK`。也可以用 `make compare_jp`、`make compare_us`、
`make compare_eu` 或 `make compare_de`。若需并行编译再校验，可用
`make -j8 compare_us` 这样的命令。

## 清理构建产物

`make clean` 清理当前版本的 ROM 和构建产物。用 `make clean_jp`、
`make clean_us`、`make clean_eu` 或 `make clean_de` 清理指定版本，
用 `make clean_all` 清理四版产物。要先清理再编译，可用
`make clean_us && make -j8 us`。

## 可选 BUGFIX

可选修复见 [BUGFIX.md](BUGFIX.md)。切换设置后先清理待重新编译的版本，
例如运行 `make clean_jp`。启用 BUGFIX 时使用普通编译命令。
