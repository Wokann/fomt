# 安装说明

[English](INSTALL.md) | 简体中文

本教程介绍如何安装 **FoMT** 所需的工具，并将工程源码编译成 ROM。

先按操作系统完成环境配置，再进入[安装](#安装)部分。点击 **说明……** 可以展开补充说明。

## Windows

选择以下一种终端环境：

- [Windows 10/11（WSL）](#windows-1011wsl)
- [Windows（MSYS2）](#windowsmsys2)

MSYS2 部分以 devkitPro 安装在 `C:\devkitPro` 为例，使用其他目录时请相应调整路径。

## Windows 10/11（WSL）

### 安装 WSL

1. 以**管理员身份**打开 PowerShell，运行：

   ```powershell
   wsl --install -d Ubuntu
   ```

2. 按提示重启 Windows，然后从开始菜单打开 **Ubuntu**。
3. 首次运行时，按提示设置 Linux 用户名和密码。

<details>
<summary>说明……</summary>

输入密码时，终端不会显示输入的字符。
其他安装方式可参阅微软的 [WSL 安装说明](https://learn.microsoft.com/zh-cn/windows/wsl/install)。

</details>

### 配置 WSL

1. 打开 **Ubuntu**，更新软件包：

   ```sh
   sudo apt update
   sudo apt upgrade
   ```

2. 安装编译 FoMT 所需的软件包：

   ```sh
   sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
       gcc-arm-none-eabi binutils-arm-none-eabi
   ```

### 选择 FoMT 存放位置（WSL）

创建用于存放 FoMT 和 agbcc 的文件夹，并进入该目录：

```sh
mkdir -p ~/projects
cd ~/projects
```

<details>
<summary>说明……</summary>

将工程放在 Linux 文件系统中可提高编译速度。
Windows 磁盘也可以通过 `/mnt/c`、`/mnt/d` 等路径访问。

</details>

继续阅读[安装](#安装)。

## Windows（MSYS2）

### 安装 devkitARM

1. 下载并运行 [devkitPro 安装程序](https://github.com/devkitPro/installer/releases)。
2. 选择 **GBA Development**，安装到 `C:\devkitPro`。

### 配置 MSYS2

1. 安装 [MSYS2](https://www.msys2.org/)，打开 **MSYS2 MINGW64** 终端。
2. 更新软件包：

   ```sh
   pacman -Syu
   ```

   如果提示关闭终端，重新打开 MINGW64，再执行一次上述命令。

3. 安装编译 FoMT 和 agbcc 所需的软件包：

   ```sh
   pacman -S --needed make git mingw-w64-x86_64-gcc \
       mingw-w64-x86_64-pkgconf mingw-w64-x86_64-libpng \
       mingw-w64-x86_64-zlib mingw-w64-i686-gcc
   ```

4. 将以下内容加入 `~/.bashrc`，然后重新打开 MINGW64 终端：

   ```sh
   export DEVKITPRO=/c/devkitPro
   export DEVKITARM="$DEVKITPRO/devkitARM"
   export PATH="$DEVKITARM/bin:$PATH"
   ```

5. 启用 Windows 开发者模式，或在克隆编译器时以**管理员身份**打开 MINGW64。
   克隆前运行：

   ```sh
   export MSYS=winsymlinks:nativestrict
   ```

<details>
<summary>关于符号链接的说明……</summary>

agbcc 中包含符号链接。克隆仓库时需要有创建链接的权限；完成克隆后，
可以在普通终端中使用这些文件。详见 [MSYS2 符号链接说明](https://www.msys2.org/docs/symlinks/)。

</details>

### 选择 FoMT 存放位置（MSYS2）

创建用于存放 FoMT 和 agbcc 的文件夹，并进入该目录：

```sh
mkdir -p ~/projects
cd ~/projects
```

<details>
<summary>说明……</summary>

请选择不含空格的路径。在 MSYS2 中，`D:\projects` 写作 `/d/projects`。
后续安装和编译命令均在 MINGW64 终端中执行。

</details>

继续阅读[安装](#安装)。

## macOS

### 安装所需工具

1. 打开终端，安装 Apple 命令行工具：

   ```sh
   xcode-select --install
   ```

2. 安装 [Homebrew](https://brew.sh/)，完成它提示的终端环境配置，然后安装所需软件包：

   ```sh
   brew install git make coreutils pkgconf libpng zlib gcc@14 arm-none-eabi-gcc
   ```

3. 将以下内容加入 `~/.zprofile`，然后重新打开终端：

   ```sh
   export PATH="$(brew --prefix make)/libexec/gnubin:$(brew --prefix coreutils)/libexec/gnubin:$(brew --prefix)/bin:$PATH"
   export PKG_CONFIG_PATH="$(brew --prefix zlib)/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
   ```

<details>
<summary>说明……</summary>

如果使用 Bash 而非默认的 zsh，将上述内容加入 `~/.bash_profile`。
这些路径用于选择 Homebrew 的 GNU Make 和命令行工具。

</details>

### 选择 FoMT 存放位置（macOS）

创建用于存放 FoMT 和 agbcc 的文件夹，并进入该目录：

```sh
mkdir -p ~/projects
cd ~/projects
```

继续阅读[安装](#安装)。

## Linux

### Debian / Ubuntu

打开终端，安装所需软件包：

```sh
sudo apt update
sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
    gcc-arm-none-eabi binutils-arm-none-eabi
```

### 选择 FoMT 存放位置（Linux）

创建用于存放 FoMT 和 agbcc 的文件夹，并进入该目录：

```sh
mkdir -p ~/projects
cd ~/projects
```

继续阅读[安装](#安装)。

## 安装

本工程使用以下分支：

| 仓库 | 分支 |
| --- | --- |
| [Wokann/fomt](https://github.com/Wokann/fomt) | `multi-language` |
| [Wokann/agbcc](https://github.com/Wokann/agbcc) | `cp` |

下面的克隆命令会自动选择对应分支。如果已有仓库，请执行对应的分支切换步骤。

1. 如果尚未下载 FoMT，先克隆游戏仓库：

   ```sh
   git -c core.autocrlf=false clone --branch multi-language https://github.com/Wokann/fomt.git
   ```

   如果已有 FoMT，切换到 **multi-language** 并更新：

   ```sh
   cd fomt
   git fetch origin
   git switch multi-language
   git pull --ff-only
   cd ..
   ```

2. 在 FoMT 同级目录中克隆维护中的 agbcc **cp** 分支：

   ```sh
   git -c core.autocrlf=false -c core.symlinks=true clone --branch cp https://github.com/Wokann/agbcc.git
   cd agbcc
   ```

   如果已有 agbcc，则切换到 **cp** 并更新：

   ```sh
   cd agbcc
   git fetch origin
   git switch cp
   git pull --ff-only
   ```

   <details>
   <summary>已有 agbcc 时的说明……</summary>

   如果 agbcc 已经在当前平台编译过，且源码没有变化，可跳过第 3 步，直接按第 4 步安装。

   </details>

3. 按平台选择以下**一条**命令编译 agbcc。

   **Linux / WSL：**

   ```sh
   CC="gcc -std=gnu89 -fcommon" MAKEFLAGS=-j16 bash ./build.sh
   ```

   **Windows / MSYS2：**

   ```sh
   (
       export PATH="/mingw32/bin:$DEVKITARM/bin:/usr/bin"
       CC="gcc -std=gnu89 -fcommon -static" CXX="g++ -static" \
           MAKEFLAGS=-j16 bash ./build.sh
   )
   ```

   **macOS：**

   ```sh
   CC="gcc-14 -std=gnu89 -fcommon" CXX=g++-14 MAKEFLAGS=-j16 bash ./build.sh
   ```

4. 将 agbcc 安装到 FoMT，然后进入游戏目录：

   ```sh
   bash ./install.sh ../fomt
   cd ../fomt
   ```

现在可以开始[编译 FoMT](#编译-fomt)。Mary 等工程内置工具会由 Make 自动编译。

## 编译 FoMT

在 `fomt` 目录中运行：

```sh
make -j16
```

默认编译美版，完成后会在工程目录中生成 **fomt_us.gba**。
若要编译其他区域，选择对应命令：

| 版本 | 命令 | ROM |
| --- | --- | --- |
| 日版 | `make -j16 GAME_REGION=JP` | `fomt_jp.gba` |
| 美版英文 | `make -j16 GAME_REGION=US` | `fomt_us.gba` |
| 欧版英文 | `make -j16 GAME_REGION=EU` | `fomt_eu.gba` |
| 德版 | `make -j16 GAME_REGION=DE` | `fomt_de.gba` |

## 编译说明

### 与原版校验

如需根据原版游戏的 SHA-1 校验编译结果，运行：

```sh
make GAME_REGION=JP compare
```

将 `JP` 换成已编译的区域。日版校验通过时显示 `fomt_jp.gba: OK`，
其他区域显示各自对应的文件名。仓库已包含 SHA-1 清单，编译和此项校验均不需要原版 ROM。

### 可选 BUGFIX

取消 [include/config.h](include/config.h) 中 `#define BUGFIX` 的注释，然后运行：

```sh
make GAME_REGION=JP clean
make -j16 GAME_REGION=JP
```

按前文选择所需区域。具体修复内容见 [BUGFIX.md](BUGFIX.md)。
如需恢复原版，重新注释该定义，清理对应区域后重新编译。

<details>
<summary>说明……</summary>

修改游戏内容或启用 BUGFIX 后，ROM 哈希会与原版不同。
这类构建使用普通 `make`，不添加 `compare` 目标。

</details>

### 清理与更新

重新编译前，可以清理对应区域的构建产物：

```sh
make GAME_REGION=JP clean
```

分别在 FoMT 和 agbcc 目录中执行 `git pull --ff-only` 更新。
更新 agbcc 源码后，重新编译并安装编译器。

<details>
<summary>切换操作系统时的说明……</summary>

为每个主机操作系统使用独立的源码目录和编译器安装目录。
Windows、Linux 和 macOS 使用不同的本机可执行文件。

</details>
