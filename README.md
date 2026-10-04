# Friends of Mineral Town

This is a decompilation of the 2003 GBA game "Harvest Moon: Friends of Mineral Town".

It builds the following ROM:

* **[fomt_us.gba]** `sha1: a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` — byte-exact
* **fomt_jp.gba** `sha1: a655b2789aed14a6ac78c6075fbc533d3062dbe3` — byte-exact
* **fomt_eu.gba** `sha1: 7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` — byte-exact
* **fomt_de.gba** `sha1: 60f2a30b55c0e32754897b4d5df6ce06f8b71a37` — byte-exact

[fomt_us.gba]: https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1249

## Region selection

The build configuration follows the `pokeruby` multi-version model. Select a
target with `GAME_REGION=US`, `GAME_REGION=JP`, `GAME_REGION=EU`, or
`GAME_REGION=DE`; `GAME_REVISION=0` is currently the only supported revision.
The default remains US, and each region uses a separate object directory. The
older lowercase `REGION=us|jp|eu|de` spelling remains available as a
compatibility alias.

```sh
make REGION=us compare
make fomt_us
make fomt_jp
make fomt_eu
make fomt_de
```

All four `fomt_*` targets build their region and run its SHA-1 comparison.
Use `make -j4 fomt_jp` (or the corresponding regional target) under WSL.
`compare_eu` and `compare_de` are aliases for their regional comparisons.

The build defines exactly one of `REGION_US`, `REGION_JP`, `REGION_EU`, and
`REGION_DE`. A recovered function belongs in one owning C/C++ or assembly
module: shared code is kept outside the conditional, and only a verified
difference is placed under the relevant region guard. Do not create a separate
region-specific executable object tree.

As in `pokeruby`, `config.mk` is the sole source for each ROM header's title,
game code, maker code, and revision.  The build applies those values with the
host-side `tools/gbafix` after `objcopy`; no regional layout fragment carries
header identity or a duplicate game-code definition.  The repository has no
regional layout fragment for the ROM header.

Some JP functions are not semantic source yet.  Their bounded, byte-exact
assembly is kept directly in the owning `.cc` file's `REGION_JP` branch with
file-scope `asm()`.  It is not a second source file or compilation unit.  As
functions are recovered, move common definitions out of the guard and leave
only the verified regional body inside it.

Large content blocks use the opposite hierarchy: domain first, then version.
For example, scripts live in `data/scripts/<region>` and ordinary text sources
live in `data/text/<region>`, both behind their small selectors. Add text,
graphics, and other future regional assets in the same
`data/<domain>/<region>` form; do not split executable code that way.

Script bytecode and its referenced text are treated as one region-specific
block when the text differs substantially.  Mary compiles every
`data/scripts/<region>/*.mary.c` source into one packed RIFF stream and a
relocatable script-pointer table.  Each regional directory keeps its callable
and slot-table headers beside the scripts; the C/C++-shared
`include/fomt_constants.mary.h` is passed to Mary explicitly.  The generated
assembly is linked by the regional LDS files, so matching opcodes alone are
not used to share a script block.

JP revision 0 has a verified linker layout and an exact build target.  The JP
ROM remains an ignored local comparison baseline: use only bounded,
documented source fragments where necessary, never a whole-ROM `incbin`.

Reference Guide text is organized by content category under
`data/text/<region>/reference_guide/`; its small native pointer tables and
declarations stay centralized in `src/reference_guide.cc` and
`include/reference_guide.hh`. Pages 0-47 currently use this layout.

## Setting up

See [INSTALL.md](./INSTALL.md).

## Build workflow

Graphics are generated beside their authored sources: shared suffix rules
convert PNG tiles to `.1bpp`, `.4bpp`, or `.8bpp`, and independent `.pal`
sources to `.gbapal`. FoMT's native compression uses `tools/fomt-lz`, not
the GBA BIOS LZ codec. Rules that still take `.original.lz` remain template
dependent; these have not all been replaced with independent encoders.

Native Huffman/LZ3 encoding supports the same source-only greedy algorithm
for 4-bit and 8-bit literals. Huffman-4 uses it by default; Huffman-8 requires
`--greedy`, preserving the existing default planner. `--tie=last` selects
the same deterministic equal-weight policy used by Huffman/LZ2. It builds
the tree from the current literals rather than reading a saved tree.
Three additional map palette/tilemap streams now use this policy through
the existing shared rule; other template-dependent streams remain unfinished.
`--tie=reverse-select` orders equal-weight symbols by reversing an ascending
selection sort computed from the current literal frequencies. The shared
`map_15/layer_5.tilemap` now also encodes directly with this generic policy;
it does not read an original stream, save a symbol permutation, or pad to a
fixed output size.
`--tie=quick` starts with reverse alphabetic leaves and uses a deterministic
three-way frequency sort, then assigns the computed Huffman length histogram
in decreasing frequency order. The sort is implemented in the native codec,
not delegated to a host-dependent `qsort`. The fourth shared startup tilemap
now uses this policy without an original-stream input or output-size padding.
`--tie=heap-sort` builds from reverse-alphabet leaves, preferring the last-created
node on equal weights, then heap-sorts the leaves by their current frequencies.
Canonical codes keep the tree's computed leaf depths. Unlike `--tie=heap`, this
policy sorts the canonical code table rather than using heap traversal to build
the tree. The shared Farm Status `secondary_03.tilemap` now uses this source-only
policy with no original-stream input, stored permutation, or fixed-size padding.
`--tie=exchange` sorts the full alphabet by current literal frequency using
ordinary descending pairwise exchanges, then omits unused leaves. Tree merges
prefer the last-created node on equal weights; canonical codes retain each
leaf's computed depth. It uses neither a saved permutation nor a template.
Besides Farm Status `secondary_02` and `secondary_05`, fourteen Huffman-8/LZ3
streams now use this policy through the shared rule: six map tile sets, three
FarmHouse visuals, startup tiles, Farm Status tiles, winter background tiles,
and two scene tile sets. All fourteen reproduce the complete retail streams
without fixed-size output padding; their obsolete packing templates are removed.
`--tail=FILE` optionally appends another source before encoding. It is used
only by the scene whose decoded payload really has a separate two-byte trailer,
not as a general archive builder or a ROM-derived padding step.
Run `tools/fomt-lz test-huff-lz3` for the native boundary self-tests.

通用交换排序策略根据当前源码的频率建立 Huffman 树并生成规范码，
不读取原版编码表。本次十四份 Huffman-8/LZ3 流均已独立逐字节匹配，
移除了压缩模板；有真实两字节尾部的场景才使用通用 `--tail=FILE` 拼接。
实际 Make 依赖中仍有 JP 六份、US/EU/DE 各七份 `.original.lz` 输入，
它们尚未完成独立编码匹配，不能据此宣布整个资源链已经完成。

The upstream [scaninc](./tools/scaninc/README.md) scans assembly includes and
resource references before assembly, including on the first build. Make loads
the generated `.d` files and builds missing resources through the graphics
rules. There is no duplicate per-object asset inventory or separate global
graphics stage. C/C++ header and regional macro dependencies continue to be
resolved by the actual C preprocessor.

Source objects are compiled in `build/<region>`, linked with the regional LDS,
and converted with `objcopy` and `gbafix`. Each LDS now lists code and read-only
data in separate `.text` and `.rodata` output sections, retaining the existing
RAM sections and verified physical order. Partial-decompilation boundaries
remain explicit absolute ROM addresses; splitting the output sections does
not remove those bounds or establish that every pointer is relocatable.
The four ROM targets do not read
baserom, run Python resource generators, or patch resources after linking.
The old per-family `gfx-*` wrappers and Python extraction, preview, and
inventory helpers have been retired instead of being translated into new
resource-specific tools. Their completed audit observations remain under
`graphics/`; old reproduction helpers are available in Git history.
For a resource-only build, request its real output path with `NODEP=1`, for
example `make NODEP=1 graphics/font/shared/single_width_font.1bpp`.
Normal ROM builds resolve the same outputs through their source references.
The default target is explicitly `all`, which builds the selected region's
ROM (US unless configured otherwise); `.SECONDARY` retains generated
intermediates and `.DELETE_ON_ERROR` removes failed targets, as in pret.
Ignored base ROMs are only independent comparison material, not Make inputs.

## Contributing

Please do. Feel free to yell at me if you need naming/style/formatting guidelines.

If you're looking for things that need to be done, check out [TODO.md](./TODO.md).

## Contact

You can find me over at the [Fire Emblem Universe Discord](https://feuniverse.us/t/feu-discord-server/1480?u=stanh) under the handle `nat_776`. I also lurk other places such as the pret Discord.

See also my other stuff:

* [**StanHash/FOMT-DOC**](https://github.com/StanHash/FOMT-DOC), my old documentation of this game's internals.
* [**StanHash/fe6**](https://github.com/StanHash/fe6), a decompilation of Fire Emblem: The Binding Blade (JP)
