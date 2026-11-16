# Instructions

English | [简体中文](INSTALL.zh-cn.md)

These instructions explain how to install the tools required to build **FoMT**
and assemble the source files into a ROM.

Follow the instructions for your operating system, then proceed to
[Installation](#installation). Additional notes can be expanded by clicking
the **Note...** headings.

## Windows

Choose one of the following terminals:

- [Windows 10/11 (WSL)](#windows-1011-wsl)
- [Windows (MSYS2)](#windows-msys2)

The MSYS2 instructions assume devkitPro is installed in `C:\devkitPro`.
If you use a different location, adjust the paths accordingly.

## Windows 10/11 (WSL)

### Installing WSL

1. Open PowerShell **as administrator** and run:

   ```powershell
   wsl --install -d Ubuntu
   ```

2. Restart Windows if prompted, then open **Ubuntu** from the Start menu.
3. Complete the initial setup by choosing a Linux username and password.

<details>
<summary>Note...</summary>

The terminal does not display characters while you type your password.
See Microsoft's [WSL instructions](https://learn.microsoft.com/en-us/windows/wsl/install)
for additional installation options.

</details>

### Setting up WSL

1. Open **Ubuntu** and update its packages:

   ```sh
   sudo apt update
   sudo apt upgrade
   ```

2. Install the packages required to build FoMT:

   ```sh
   sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
       gcc-arm-none-eabi binutils-arm-none-eabi
   ```

### Choosing where to store FoMT (WSL)

Create a folder for FoMT and agbcc, then change to it:

```sh
mkdir -p ~/projects
cd ~/projects
```

<details>
<summary>Note...</summary>

Keep the project in the Linux filesystem for faster builds. Windows drives are
also accessible through paths such as `/mnt/c` and `/mnt/d`.

</details>

Continue to [Installation](#installation).

## Windows (MSYS2)

### Installing devkitARM

1. Download and run the [devkitPro installer](https://github.com/devkitPro/installer/releases).
2. Select **GBA Development** and install to `C:\devkitPro`.

### Setting up MSYS2

1. Install [MSYS2](https://www.msys2.org/) and open **MSYS2 MINGW64**.
2. Update its packages:

   ```sh
   pacman -Syu
   ```

   If asked to close the terminal, reopen MINGW64 and run the command again.

3. Install the packages required to build FoMT and agbcc:

   ```sh
   pacman -S --needed make git mingw-w64-x86_64-gcc \
       mingw-w64-x86_64-pkgconf mingw-w64-x86_64-libpng \
       mingw-w64-x86_64-zlib mingw-w64-i686-gcc
   ```

4. Add the following lines to `~/.bashrc`, then open a new MINGW64 terminal:

   ```sh
   export DEVKITPRO=/c/devkitPro
   export DEVKITARM="$DEVKITPRO/devkitARM"
   export PATH="$DEVKITARM/bin:$PATH"
   ```

5. Enable Windows Developer Mode, or open MINGW64 **as administrator** for the
   compiler checkout. Before cloning, run:

   ```sh
   export MSYS=winsymlinks:nativestrict
   ```

<details>
<summary>Note about symbolic links...</summary>

agbcc contains symbolic links. Windows needs permission to create them when
cloning the repository; after checkout, the files can be used from a normal
terminal. See the [MSYS2 symbolic-link instructions](https://www.msys2.org/docs/symlinks/).

</details>

### Choosing where to store FoMT (MSYS2)

Create a folder for FoMT and agbcc, then change to it:

```sh
mkdir -p ~/projects
cd ~/projects
```

<details>
<summary>Note...</summary>

Use a path without spaces. In MSYS2, `D:\projects` is written as `/d/projects`.
Run the following installation and build commands inside the MINGW64 terminal.

</details>

Continue to [Installation](#installation).

## macOS

### Installing the required tools

1. Open Terminal and install Apple's command-line tools:

   ```sh
   xcode-select --install
   ```

2. Install [Homebrew](https://brew.sh/) and follow its shell setup instructions.
   Then install the required packages:

   ```sh
   brew install git make coreutils pkgconf libpng zlib gcc@14 arm-none-eabi-gcc
   ```

3. Add these lines to `~/.zprofile`, then open a new terminal:

   ```sh
   export PATH="$(brew --prefix make)/libexec/gnubin:$(brew --prefix coreutils)/libexec/gnubin:$(brew --prefix)/bin:$PATH"
   export PKG_CONFIG_PATH="$(brew --prefix zlib)/lib/pkgconfig${PKG_CONFIG_PATH:+:$PKG_CONFIG_PATH}"
   ```

<details>
<summary>Note...</summary>

If you use Bash instead of the default zsh shell, add the lines to
`~/.bash_profile`. The path selects Homebrew's GNU Make and command-line tools.

</details>

### Choosing where to store FoMT (macOS)

Create a folder for FoMT and agbcc, then change to it:

```sh
mkdir -p ~/projects
cd ~/projects
```

Continue to [Installation](#installation).

## Linux

### Debian / Ubuntu

Open Terminal and install the required packages:

```sh
sudo apt update
sudo apt install build-essential git pkg-config libpng-dev zlib1g-dev \
    gcc-arm-none-eabi binutils-arm-none-eabi
```

### Choosing where to store FoMT (Linux)

Create a folder for FoMT and agbcc, then change to it:

```sh
mkdir -p ~/projects
cd ~/projects
```

Continue to [Installation](#installation).

## Installation

Use the following branches for this project:

| Repository | Branch |
| --- | --- |
| [Wokann/fomt](https://github.com/Wokann/fomt) | `multi-language` |
| [Wokann/agbcc](https://github.com/Wokann/agbcc) | `cp` |

The clone commands below select these branches automatically. If you already
have either repository, follow its branch-switching instructions instead.

1. Clone FoMT if you have not already downloaded it:

   ```sh
   git -c core.autocrlf=false clone --branch multi-language https://github.com/Wokann/fomt.git
   ```

   If you already have FoMT, select and update **multi-language**:

   ```sh
   cd fomt
   git fetch origin
   git switch multi-language
   git pull --ff-only
   cd ..
   ```

2. Clone the maintained **cp** branch of agbcc beside FoMT:

   ```sh
   git -c core.autocrlf=false -c core.symlinks=true clone --branch cp https://github.com/Wokann/agbcc.git
   cd agbcc
   ```

   If you already have agbcc, select and update **cp** instead:

   ```sh
   cd agbcc
   git fetch origin
   git switch cp
   git pull --ff-only
   ```

   <details>
   <summary>Note if agbcc is already installed...</summary>

   If agbcc was built on the same platform and its sources have not changed,
   skip step 3 and continue with installation in step 4.

   </details>

3. Build agbcc using **one** of the following commands for your platform.

   **Linux / WSL:**

   ```sh
   CC="gcc -std=gnu89 -fcommon" MAKEFLAGS=-j16 bash ./build.sh
   ```

   **Windows / MSYS2:**

   ```sh
   (
       export PATH="/mingw32/bin:$DEVKITARM/bin:/usr/bin"
       CC="gcc -std=gnu89 -fcommon -static" CXX="g++ -static" \
           MAKEFLAGS=-j16 bash ./build.sh
   )
   ```

   **macOS:**

   ```sh
   CC="gcc-14 -std=gnu89 -fcommon" CXX=g++-14 MAKEFLAGS=-j16 bash ./build.sh
   ```

4. Install agbcc into FoMT, then enter the game directory:

   ```sh
   bash ./install.sh ../fomt
   cd ../fomt
   ```

Now you are ready to [build FoMT](#build-fomt). The bundled tools, including
Mary, are compiled automatically by Make.

## Build FoMT

From the `fomt` directory, run:

```sh
make -j16
```

This builds the US version and creates **fomt_us.gba** in the project folder.
To build another region, choose one command:

| Version | Command | ROM |
| --- | --- | --- |
| Japanese | `make -j16 GAME_REGION=JP` | `fomt_jp.gba` |
| US English | `make -j16 GAME_REGION=US` | `fomt_us.gba` |
| European English | `make -j16 GAME_REGION=EU` | `fomt_eu.gba` |
| German | `make -j16 GAME_REGION=DE` | `fomt_de.gba` |

## Building guidance

### Compare the ROM to the original

To check the build against the original game's SHA-1, run:

```sh
make GAME_REGION=JP compare
```

Replace `JP` with the region you built. A matching build prints
`fomt_jp.gba: OK` for JP, or the corresponding name for another region.
The SHA-1 manifests are included in the repository; a base ROM is not required
to build or run this check.

### Optional bug fixes

Uncomment `#define BUGFIX` in [include/config.h](include/config.h), then run:

```sh
make GAME_REGION=JP clean
make -j16 GAME_REGION=JP
```

Choose the desired region as above. See [BUGFIX.md](BUGFIX.md) for the available
fixes. To restore the original game, comment out the define and rebuild after
cleaning that region.

<details>
<summary>Note...</summary>

Modified builds, including builds with BUGFIX enabled, have different hashes
from the original game. Build them with `make`, without the `compare` target.

</details>

### Cleaning and updating

To clean a region before rebuilding:

```sh
make GAME_REGION=JP clean
```

Update FoMT and agbcc by running `git pull --ff-only` in their respective
directories. Rebuild and reinstall agbcc after updating its sources.

<details>
<summary>Note when changing operating systems...</summary>

Use a separate checkout and compiler installation for each host operating
system. Windows, Linux, and macOS use different host executables.

</details>
