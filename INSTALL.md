# Installation

## New instructions

- get a `arm-none-eabi` toolchain (devkitARM probably works)
- run `bash tools/install_agbcp.sh` inside WSL to install the pinned C/C++ toolchain
- `make fomt_us`

### Required C++ frontend correction

The installer checks out [notyourav/agbcc] at
`1caa6becde5e4676b59c31c74d68f45ced79557c`, applies
`tools/agbcp-asm-destructors.patch`, then runs its ordinary build and install
scripts. The patch is also preserved in the sibling compiler repository's
local `codex/cp-asm-destructors` branch at
`52840e5535c8975649c1b767f77d82d057b3dbe5`; that branch is not published and
is not required by the installer.

Do not use the unpatched frontend with declarations such as
`~HardwareBlendObject() asm("func_080094B8")`. It identifies destructors by
the assembler-name spelling and can silently omit automatic cleanup after
the name is replaced. The correction preserves the source-level destructor
kind in an existing spare flag and uses it for lookup, cleanup, overriding
and diagnostics in both ARM and Thumb. It does not inspect game addresses,
rewrite instructions, or change the project's optimization flags.

The patch includes `tests/asm-destructor.cc`, an execution regression for
stack, array, virtual deleting and template-member destruction, plus its
small Linux test entry and instructions. Both modes return zero under
`qemu-arm`; that emulator is optional test tooling, not a ROM build input.
The compiler-only regression rebuilt all four existing game versions and
preserved their full ROM bytes, symbol addresses and all 825 allocated-object
signatures before the new destructor declarations were adopted.

To compare a build with the recorded original SHA-1, run in WSL:

```sh
make -j4 GAME_REGION=JP GAME_REVISION=0 compare
make -j4 GAME_REGION=US GAME_REVISION=0 compare
make -j4 GAME_REGION=EU GAME_REVISION=0 compare
make -j4 GAME_REGION=DE GAME_REVISION=0 compare
```

### 中文说明

安装脚本固定上述 `cp` 基准提交，应用仓库内的通用 C++ 前端补丁，
然后正常构建并安装；不依赖尚未发布的本地编译器分支。旧前端会
因析构函数改用汇编符号名而漏掉自动析构，必须使用修正后的版本。
修复保留源语言中的析构身份，不判断游戏地址，也不加入编译后指令
修补。两个前端的析构执行回归及四版本既有工程完整比对均通过。

[notyourav/agbcc]: https://github.com/notyourav/agbcc

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
