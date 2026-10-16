# Installation

## New instructions

- get a `arm-none-eabi` toolchain (devkitARM probably works)
- run `bash tools/install_agbcp.sh` inside WSL to install the pinned C/C++ toolchain
- `make fomt_us`

### Required C++ frontend correction

The installer checks out [notyourav/agbcc] at
`1caa6becde5e4676b59c31c74d68f45ced79557c`, applies
`tools/agbcp-asm-destructors.patch` and `tools/agbcc-long-calls.patch`, then
runs its ordinary build and install scripts. The original assembler-name
correction is also
preserved in the sibling compiler repository's
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

The installer patch also corrects generic multiple-inheritance forwarding
thunks. Such a thunk copies its target's language flags, but must clear the
copied destructor-kind bit before starting the forwarding function: it calls
the destructor with an adjusted `this`, rather than being a second destructor.
Without this correction, the Thumb frontend rejects even ordinary-named
multiple-inheritance destructors. ARM's dedicated assembly-thunk path is
unchanged; both frontend source trees receive the same generic-path fix.
This follow-up is included in the installer patch, not in the older sibling
branch commit mentioned above.

`tests/asm-destructor-mi.cc` adds eight O0/O2 execution combinations across
ARM/Thumb and ordinary/asm-labelled destructors. They check stack cleanup,
virtual calls, deletion through primary and nonzero-offset secondary bases,
and an implicit derived destructor. Each allocation must be freed exactly
once at its complete-object address. The existing two destructor regressions
still run as well; no instruction selection or project build flags change.

### Individual far-call declarations

The second patch adds the GNU `long_call` function-declaration attribute to
the Thumb C and C++ backends. It uses the existing indirect interworking call
path only for a marked declaration, leaving ordinary near calls and the
project's optimization flags unchanged. This permits calls from ROM to ARM
code in IWRAM without fixed-register variables or empty assembly barriers.
It does not provide a new function-pointer type attribute or test game names
or addresses. The existing `-mlong-calls` file-wide option still works.

`tests/long-call.c`, its small mixed-mode entry and linker script, and
`tests/README.long-calls.md` are included in the patch. The same source is
executed as C and C++ under `qemu-arm`, checking far scalar/void/structure
returns together with unchanged direct near calls. Test addresses deliberately
exceed Thumb BL range and have no connection to the game's ROM layout.

To compare a build with the recorded original SHA-1, run in WSL:

```sh
make -j4 GAME_REGION=JP GAME_REVISION=0 compare
make -j4 GAME_REGION=US GAME_REVISION=0 compare
make -j4 GAME_REGION=EU GAME_REVISION=0 compare
make -j4 GAME_REGION=DE GAME_REVISION=0 compare
```

### 中文说明

安装脚本固定上述 `cp` 基准提交，应用仓库内的通用 C++ 析构补丁及
Thumb 函数声明远调用补丁，然后正常构建并安装；不依赖尚未发布的
本地编译器分支。旧前端会
因析构函数改用汇编符号名而漏掉自动析构，必须使用修正后的版本。
修复保留源语言中的析构身份，不判断游戏地址，也不加入编译后指令
修补。两个前端的析构执行回归及四版本既有工程完整比对均通过。

`long_call` 属性只影响被标记的函数声明，使用现有的间接跨模式
调用，普通近调用和优化选项不变；因此 ROM 里的 C 函数可以正常
调用 IWRAM ARM 入口，无需固定寄存器或空汇编。不判断游戏函数名
或地址，也不新增函数指针类型属性。独立混合 ARM/Thumb 测试以
C、C++ 执行，覆盖标量、void、结构体返回及普通近调用。

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
