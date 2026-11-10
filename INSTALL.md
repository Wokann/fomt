# Installation

## Current toolchain

Build in WSL with an `arm-none-eabi` toolchain on PATH. Keep the maintained
`Wokann/agbcc` `cp` checkout beside FoMT:

```text
parent/
    agbcc/
    fomt/
```

This branch starts from `notyourav/agbcc` cp commit
`1caa6becde5e4676b59c31c74d68f45ced79557c`. The generic compiler corrections
are recorded locally in cp commit `b24094061ea76525206db659d6cdac853512bf27`.
This commit has not been pushed; use the maintained sibling checkout.

Build and install from the sibling compiler directory:

```sh
cd ../agbcc
CC="gcc -std=gnu89 -fcommon" MAKEFLAGS=-j4 bash ./build.sh
bash ./install.sh ../fomt
cd ../fomt
```

Alternatively, from the FoMT directory, use the wrapper with the same default
`../agbcc` checkout:

```sh
bash tools/install_agbcp.sh
```

An optional argument selects another checkout of the same maintained source:

```sh
bash tools/install_agbcp.sh /path/to/agbcc
```

The wrapper uses the compiler repository's existing `build.sh` and `install.sh`,
with `-j4` by default. It does not clone a repository, switch branches, apply
patch files, or run tests. `CC` and `MAKEFLAGS` remain overridable.

The small frontend corrections preserve destructor identity through asm labels,
support per-declaration Thumb long calls, materialize rejected subword frame
addresses, and preserve named const-array objects and their real relocations.
The Thumb hexadecimal epilogue formatter also emits the immediate marker and
uses hexadecimal digits. These rules inspect language types, declaration
attributes or target instruction constraints, never game names or ROM addresses.
Host build adjustments only fix a generated-header dependency and C dialect
selection; they do not change target instruction selection.

Explicit declaration alignment is recorded by the compiler for C and C++,
including redeclarations. Target alignment preferences do not override that
request. Function alignment is emitted after selecting the function section,
so it does not pad an unrelated preceding data section. The preprocessor no
longer guesses either correction from source or assembler text patterns.

`fomt-preproc` does not reconstruct arrays, select pointer targets from matching
strings, or repair stack-adjustment instructions. Use the installed compiler
from the maintained source checkout.

Build and compare the four ROMs in WSL:

```sh
make -j16 GAME_REGION=JP compare
make -j16 GAME_REGION=US compare
make -j16 GAME_REGION=EU compare
make -j16 GAME_REGION=DE compare
```

## 中文说明

编译器放在 FoMT 同级的 `agbcc` 目录，使用本地 `cp` 分支，从该目录构建并
执行 `install.sh ../fomt`。FoMT 的安装包装脚本也默认读取 `../agbcc`，不依赖
个人机器的绝对路径。当前通用修正已记录于上述本地 cp 提交，尚未推送，不能假定远程分支已包含。
安装脚本不再下载编译器或应用 FoMT 内的补丁文件，也不运行测试用例。
编译器安装包装仍默认 `-j4`，可通过 MAKEFLAGS 覆盖；游戏构建使用 WSL `-j16`。
阶段 1721 已验证四版完整字节及 SHA-1 均与各自 baserom 一致。

## Old instructions

Install the devkitARM toolchain of devkitPro as per [the instructions on their wiki](https://devkitpro.org/wiki/devkitPro_pacman).

Inside the included MSYS2 environment run:

    pacman -S gcc git

To set up the repository:

	git clone https://github.com/not-alons/hmfomt
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	./build.sh
	./install.sh ../hmfomt

	cd ../hmfomt

Place a .gba ROM of Harvest Moon: Friends of Mineral Town (USA) in your hmfomt folder and name it `baserom_us.gba`.

To build **hmfomt_us.gba** and confirm it matches the official ROM image:

	make fomt_us

If an OK is returned, then the installation went smoothly.
