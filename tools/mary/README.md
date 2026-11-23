# Mary

Vendored from Wokann/mary, branch `c++`, commit
`a7fccf142b5c6d02cd83a612a1ceea591168cdfc`.
FoMT builds this tool from source through its ordinary Makefile. Compilation
uses `include/fomt_constants.mary.h` and the two headers beside each region's
scripts; `goodies/` is only the optional original-game decompilation adaptation.

[English](README.md) | [简体中文](README.zh-CN.md)

Mary is a portable C++17 compiler, decompiler and ROM importer for the event
scripts in Friends of Mineral Town (JP, US, EU, DE) and More Friends of Mineral
Town (JP, US). It builds with a normal host C++ compiler and GNU Make. Rust,
Cargo, parser generators and third-party libraries are not required.

## Build

```sh
make -j4
make check
```

Use GCC or Clang on Linux, Apple's command-line C++ tools on macOS, or MinGW-w64
and Make in a Windows MSYS2 environment. The program is `mary` on Unix and
`mary.exe` on Windows. Windows builds link the GCC and C++ runtimes statically.

```sh
make CXX=clang++ CXXFLAGS="-O2 -Wall -Wextra"
make clean
```

The Makefile follows the small host-tool model: `src/*.cc` and `src/*.hh` produce
one executable. `make check` additionally builds a portable C++ regression
program. No ROM is needed to build or run that check. All source changes for
this port are developed on branch `c++`; the former Rust implementation remains
available in the history of `Enhanced`.

## Compile source

Mary-C is the canonical editable source format. Its `.mary.c` and `.mary.h`
suffixes enable C highlighting; the language is compiled by Mary, not by a C
compiler. The original DSL is also supported.

```sh
./mary compile decompiled_text/fomt_us/script_1.mary.c --mary-c \
  --charmap charmap.txt --binary -o script.riff

./mary compile script.mary --binary -o script.riff
./mary compile script.mary --print-ir -o script_arrays.c
```

Without `--binary`, compile emits C arrays. Binary mode requires exactly one
script. An omitted input filename reads stdin.

Mary-C expands quoted `#include` directives in active branches. It searches the
including file's directory first, then the directories passed with repeated
`-I DIR` or `-IDIR` options. Macro definitions and removals carry across
includes. Relative CLI paths, including `-I`, are resolved from the process
working directory.

`--constants`, `--library` and `--script-table` load metadata explicitly. Each
supplied table is loaded once per request. Includes matching its standard
metadata name or supplied filename use the explicit path.

If `include/ready.mary.h` contains `#define READY 1`, use it in
`src/example.mary.c` as follows.

```c
#include "ready.mary.h"

mary_script(1) void Example(void)
{
#if READY
    return;
#endif
}
```

```sh
./mary compile src/example.mary.c --mary-c --binary -D MARY_FOMT_US \
  -I include --source-map example.tsv --source-map-version 2 -o example.riff
```

`--source-map FILE` writes a line map alongside binary Mary-C output. The
default v1 map uses lines in the main file. Version 2 adds a file table and
physical locations for CODE, text declarations by STR slot and resolved
includes. Paths in the file table are UTF-8 encoded as hexadecimal, and lines
are one-based. Use `--source-map -` to write the map to stderr.

The shared integer header supports checked 64-bit constant expressions,
object-like and function-like macros, continuations, nested conditions and
target defines. Runtime VM arithmetic is preserved rather than folded away.
Bitwise operations in script source require constant operands. Stringification,
token pasting and variadic macros are not supported.

## Decompile: neutral IDs by default

```sh
./mary decompile rom/fomt_us.gba --all --mary-c --charmap charmap.txt \
  -o decompiled_text/fomt_us
```

The default does **not** load original-game naming or constant tables. It writes
neutral `script_N` names and explicit numbered instructions in a `mary_ir`
block. Text remains editable through the selected character map. This form can
be compiled without assuming that a modified game's callable IDs, constants or
script names still mean what they meant in the original game.

```c
mary_script(1) void script_1(void)
{
    mary_ir
    {
        String("Example text")
        PushInt(0)
        Call(33)
    }
}
```

The numbered form preserves the physical STR table, labels, branches, switch
cases and stack operations. It is not a guess at a callable's arguments or
meaning. The legacy DSL uses `ir` for the same instruction representation.

An explicitly supplied `--library` provides callable shapes for structured
neutral output. Names are still replaced with `func_N` / `proc_N`, and original
constant names are not applied.

### Opt into original adaptation tables

```sh
./mary decompile rom/fomt_us.gba --all --mary-c --vanilla-names \
  --charmap charmap.txt -o decompiled_text/fomt_us
```

Use `--vanilla-names` only for an original ROM or a modification that preserves
the relevant original definitions. Mary then reads the matching adaptation in
`goodies/`, including callable signatures, typed constants, script/text names
and local type hints. The result is structured Mary-C with semantic names.

`--library`, `--constants`, `--script-table` and `--symbols` can select explicit
adaptation files. `--text-names` is an alias for `--symbols`. A mismatch is
reported rather than silently assigning unrelated original names. A raw RIFF
without an identifiable ROM header needs `-D MARY_FOMT_US` or another target
when exporting Mary-C or using original names.

Use `--script-id N` to export one ROM table entry, or `--offset 0xADDRESS` for a
RIFF at an explicit file offset / GBA ROM address. These selectors are mutually
exclusive with `--all`. Modified pointer tables can be selected using
`--pointer-table ADDRESS --pointer-count COUNT`. Without a selector, the input
is interpreted as one RIFF. `--print-ir` appends an instruction listing.

## Bundle for a decompilation project

```sh
./mary bundle data/scripts/us -o build/us/data/scripts --layout packed \
  --library data/scripts/us/fomt_callables.mary.h \
  --script-table data/scripts/us/fomt_scripts.mary.h \
  --constants include/fomt_constants.mary.h \
  --charmap charmap.txt -D MARY_FOMT_US
```

Packed mode writes `scripts.bin`, `scripts.s`, `script_table.s` and `scripts.d`.
The assembly exposes script symbols, individual text symbols and the ordered
pointer table for the regular assembler/linker. `--layout split` writes each
RIFF under `riff/` instead of combining it into `scripts.bin`. Dependency paths
are escaped for Make. Null pointer slots and each physical string declaration
remain distinct. `-D BUGFIX` selects source repairs where supplied by a project.

Use `--dep-target PATH` when a Make stamp or another target runs the bundle
command. Mary adds the target to `scripts.d` with the same active inputs,
including transitive headers.

For future FoMT integration, keep the compiler sources in `tools/mary/` and
build them with the ordinary host-tool rules. The authoritative compilation
tables stay in FoMT: `include/fomt_constants.mary.h` and each language's
`data/scripts/<region>/fomt_callables.mary.h` / `fomt_scripts.mary.h`. Mary reads
those explicit paths. It does not install another copy over them. The independent
`goodies/` adaptation is for opt-in decompilation and testing only.

## Import into a ROM copy

```sh
./mary import rom/fomt_us.gba decompiled_text/fomt_us -o edited.gba \
  --charmap charmap.txt --dry-run

./mary import rom/fomt_us.gba decompiled_text/fomt_us -o edited.gba \
  --charmap charmap.txt
```

A directory imports the complete ordered source table. One source file requires
`--script-id N`. By default, data must fit its existing aligned allocation.
`--address ADDRESS` explicitly selects another script-data destination;
`--relocate-pointer-table ADDRESS` moves the whole table and updates the known
native references. Relocated tables carry `MARYTAB1` metadata so later exports
can find the current count and location. The input ROM is never overwritten.

The importer checks bounds, overlap, null slots, table references and occupied
destinations. `--force` authorizes reported overwrites, while `--dry-run` writes
no output. Output replacement uses a unique temporary file and an atomic rename.
It does not expand the ROM or infer arbitrary new native-code references.

## Character map

Mappings use `HEX=TEXT`, preserve trailing spaces and take the first textual
encoding as canonical. Duplicate byte keys and embedded STR terminators are
rejected. Ambiguous or unknown bytes remain explicit `\xNN` escapes on export.
Strings can mix mapped text with raw byte escapes.

Named controls such as `\r`, `\n`, `\p`, `{Press}` and `{Player}` come from the
map. Generated source splits after `\n` / `\p` without adding bytes. Ordinary
`#` comments remain supported; regional `#if` conditions select mappings without
treating mapped quotes or slashes as C syntax.

## Analysis helpers

The former helper executables are retained as commands in the same program:

```sh
./mary analyse-callable-shapes rom/fomt_us.gba
./mary generate-script-table goodies/fomt_scripts_text.mary.sym MARY_FOMT_US scripts.mary.h
./mary generate-symbols rom/fomt_jp.gba rom/fomt_us.gba rom/fomt_eu.gba rom/fomt_de.gba \
  rom/mfomt_jp.gba rom/mfomt_us.gba generated_symbols
```

Symbol generation creates numbered starting tables; it does not infer semantic
names or overwrite curated tables unless their directory is explicitly selected.

## Verification

The migration checks six original ROMs in both original-name and neutral-number
modes: ROM → exported source → native compilation/bundle/import → ROM. Each
output matches its input SHA-1. The corpus contains 8,142 non-null scripts.
FoMT's existing four-language source corpus also matches the Rust compiler's
RIFF bytes with BUGFIX both disabled and enabled. ROMs and local validation
outputs are not required by the build and are not distributed with this project.
