# Friends of Mineral Town

English | [简体中文](README.zh-cn.md)

This is a matching decompilation of the 2003 Game Boy Advance game
**Harvest Moon: Friends of Mineral Town**, covering the Japanese, US English,
European English, and German versions.

Development is maintained on the **multi-language** branch. See
[decompilation progress](PROGRESS.md) for code, data, function, and
compilation-unit coverage. High-level recovery and relocation audits are
tracked separately from byte matching.

## ROMs

The default configuration builds the original ROMs with the following SHA-1
checksums:

| Version | Output | SHA-1 |
| --- | --- | --- |
| Japanese | `fomt_jp.gba` | `a655b2789aed14a6ac78c6075fbc533d3062dbe3` |
| US English | `fomt_us.gba` | `a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` |
| European English | `fomt_eu.gba` | `7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` |
| German | `fomt_de.gba` | `60f2a30b55c0e32754897b4d5df6ce06f8b71a37` |

Optional fixes are controlled by `BUGFIX` in [include/config.h](include/config.h).
The [bug-fix documentation](BUGFIX.md) describes the affected versions, original
behavior, evidence, and fixes. Optional `UNIFY_REGIONS` automatically enables
`BUGFIX` and adds the selected [regional script unification](REGIONAL_DIFFERENCES.md#unify-regions-scripts).
Both switches are off by default; build enabled modes without `compare`.

## Installation

For Linux/WSL, Windows/MSYS2, and macOS setup and build instructions, see
[INSTALL.md](INSTALL.md).

## Source organization

- `src/` and `include/` contain game modules and their declarations. Shared
  code uses regional conditionals for version differences.
- `asm/` contains standalone startup, platform and sound-driver assembly.
  Modules awaiting high-level recovery keep their assembly in the owning
  C/C++ files.
- `text/<region>/` contains regional game text. Reference Guide pages live in
  `reference_guide/` and Mary script text tables live in `script/`.
  Each numbered script in `data/scripts/` includes its text header when
  it has a text table. [include/fomt_constants.mary.h](include/fomt_constants.mary.h)
  supplies shared native-code and script constants.
- `graphics/` contains authored resources. The
  [graphics rules](graphics_file_rules.mk) convert PNG tiles and independent
  palettes to native formats, then compress resources beside their sources.
- `tools/` contains the host tools. The bundled C++17 Mary compiler and other
  project tools are built automatically by Make.
- `build/<region>/` holds compiled objects and generated code. Each region's
  LDS file controls linking; the ROM, ELF, and map are written to the project
  root.

Normal builds use the project's source code and resources. Base ROMs serve as
independent comparison material.

## Documentation

| Document | Contents |
| --- | --- |
| [PROGRESS.md](PROGRESS.md) | Decompilation coverage and progress records |
| [BUGFIX.md](BUGFIX.md) | Original bugs, evidence, and optional fixes |
| [REGIONAL_DIFFERENCES.md](REGIONAL_DIFFERENCES.md) | Regional mechanics, data, and script differences |
| [RELOCATION_AUDIT.md](RELOCATION_AUDIT.md) | Symbolic references, reader boundaries, and relocation audits |
| [CODE_ROM_LAYOUT.md](CODE_ROM_LAYOUT.md) | Code layout notes |
| [TEXT_ROM_LAYOUT.md](TEXT_ROM_LAYOUT.md) | Text layout notes |
| [TEXT_SYMBOL_AUDIT.md](TEXT_SYMBOL_AUDIT.md) | Text, naming, and call-site audit records |
| [Mary](tools/mary/README.md) | Script compilation, decompilation, and ROM import |
| [Text processing](tools/textproc/README.md) | Text encoding and preprocessing |
| [scaninc](tools/scaninc/README.md) | Source and resource dependency scanning |

## Contributing

Contributions are welcome. See [TODO.md](TODO.md) and the progress and audit
documents for outstanding work.

This project builds on [StanHash/fomt](https://github.com/StanHash/fomt).
Related reverse-engineering notes are available in
[StanHash/FOMT-DOC](https://github.com/StanHash/FOMT-DOC). Imported tools retain
their source notices and licenses.
