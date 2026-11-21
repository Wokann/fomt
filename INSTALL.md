# Instructions

English | [简体中文](INSTALL.zh-cn.md)

These instructions explain how to set up the tools required to build
**FoMT** from source. Set up your platform, then proceed to
[Installation](#installation).

## Windows

Choose a terminal for building FoMT.

- [Windows 10/11 (WSL)](#windows-1011-wsl)
- [Windows (MSYS2)](#windows-msys2)

## Windows 10/11 (WSL)

In an administrator PowerShell, install Ubuntu.

```powershell
wsl --install -d Ubuntu
```

Restart if prompted. Open Ubuntu from the Start menu, complete its first-run
setup, and follow the [Linux instructions](#linux) in that terminal.

## Windows (MSYS2)

### Setting up MSYS2

Install [MSYS2](https://www.msys2.org/). Open **UCRT64** on x86_64 or
**CLANGARM64** on ARM64. Run `pacman -Syu` and repeat it in the same terminal
if prompted to reopen it.

**UCRT64 (x86_64)**

```sh
pacman -S --needed make mingw-w64-ucrt-x86_64-git mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-pkgconf mingw-w64-ucrt-x86_64-libpng \
    mingw-w64-ucrt-x86_64-zlib mingw-w64-ucrt-x86_64-arm-none-eabi-gcc
```

**CLANGARM64 (ARM64)**

```sh
pacman -S --needed make mingw-w64-clang-aarch64-git mingw-w64-clang-aarch64-clang \
    mingw-w64-clang-aarch64-gcc-compat mingw-w64-clang-aarch64-pkgconf \
    mingw-w64-clang-aarch64-libpng mingw-w64-clang-aarch64-zlib \
    mingw-w64-clang-aarch64-arm-none-eabi-binutils
```

Before cloning agbcc, enable Windows Developer Mode or open MSYS2 as
administrator so Git can create its symbolic links.

## macOS

Install Apple's command-line tools with `xcode-select --install`, then set up
[Homebrew](https://brew.sh/). Use native arm64 Homebrew on Apple Silicon.

```sh
brew install git make coreutils pkgconf libpng zlib gcc@14 arm-none-eabi-gcc
export PATH="$(brew --prefix make)/libexec/gnubin:$(brew --prefix coreutils)/libexec/gnubin:$PATH"
export PKG_CONFIG_PATH="$(brew --prefix zlib)/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
```

Keep using this terminal, or save the two `export` lines in `~/.zprofile`
(`~/.bash_profile` for Bash).

## Linux

### Debian / Ubuntu

On Debian or Ubuntu, including Ubuntu in WSL, install these packages.

```sh
sudo apt update
sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
    gcc-arm-none-eabi binutils-arm-none-eabi
```

## Installation

Choose a directory whose path contains no spaces. Keep FoMT and agbcc
side by side in that directory.

1. Clone FoMT.

   ```sh
   git -c core.autocrlf=false clone --branch multi-language https://github.com/Wokann/fomt.git
   ```

2. Build and install agbcc.

   ```sh
   git -c core.autocrlf=false -c core.symlinks=true clone --branch cp https://github.com/Wokann/agbcc.git
   cd agbcc
   ./build.sh
   ./install.sh ../fomt
   cd ..
   ```

If you already have the repositories, run `git fetch origin` in each
one, then `git switch multi-language` in FoMT or `git switch cp` in agbcc.
Update each with `git pull --ff-only` before building and installing.

## Build FoMT

Enter the `fomt` directory and run `make`.

```sh
cd fomt
make
```

The default build produces the Japanese ROM, `fomt_jp.gba`.
Select a version with `make jp`, `make us`, `make eu`, or `make de`.
The `REGION` option still works, for example `make REGION=us`.

# Building guidance

## Parallel builds

To speed up builds, check how many logical CPUs the terminal can use. Run
`nproc` on Linux, WSL, or MSYS2, or `sysctl -n hw.ncpu` on macOS.
Use the returned number or a smaller value with `make -j`. For example,
if the command returns 8, use `make -j8 us` to build the US ROM in parallel.

## Compare ROM to the original

Run `make compare` to build and check the ROM against the original SHA-1.
A matching default build prints `fomt_jp.gba: OK`. You can also run
`make compare_jp`, `make compare_us`, `make compare_eu`, or `make compare_de`.
Add `-j` to parallelize any build needed for the check, for example
`make -j8 compare_us`.

## Clean build outputs

`make clean` removes the selected version's ROM and build outputs.
Use `make clean_jp`, `make clean_us`, `make clean_eu`, or `make clean_de`
to select a version, or `make clean_all` to remove all four versions' outputs.
To clean and rebuild in order, run `make clean_us && make -j8 us`.

## Optional bug fixes

For optional fixes, see [BUGFIX.md](BUGFIX.md). After changing the setting,
clean the region you plan to rebuild, for example with `make clean_jp`. Use the
normal build command without `compare` when BUGFIX is enabled.
