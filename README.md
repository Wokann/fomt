# Friends of Mineral Town

This is a decompilation of the 2003 GBA game "Harvest Moon: Friends of Mineral Town" (US).

It builds the following ROM:

* **[fomt_us.gba]** `sha1: a2fc3574f0a65a4fcf7682fb274b9d7eebdef963`

[fomt_us.gba]: https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1249

## Region selection

The build configuration follows the `pokeruby` multi-version model. Select a
target with `GAME_REGION=US` or `GAME_REGION=JP`; `GAME_REVISION=0` is currently
the only verified revision. The default remains US, and each region uses a
separate object directory (`build/us` or `build/jp`). The older lowercase
`REGION=us/jp` spelling remains available as a compatibility alias.

```sh
make REGION=us compare
make fomt_us
make fomt_jp
```

The build defines exactly one of `REGION_US` and `REGION_JP`.  A recovered
function belongs in one owning C/C++ or assembly module: shared code is kept
outside the conditional, and only a real difference is placed under
`#if defined(REGION_JP)` / `#else` (or assembler `.ifdef REGION_JP`).  Do not
create a separate region-specific executable object tree.

Some JP functions are not semantic source yet.  Their bounded, byte-exact
assembly is kept directly in the owning `.cc` file's `REGION_JP` branch with
file-scope `asm()`.  It is not a second source file or compilation unit.  As
functions are recovered, move common definitions out of the guard and leave
only the verified regional body inside it.

Large content blocks use the opposite hierarchy: domain first, then version.
For example, scripts live in `data/scripts/us` and `data/scripts/jp`, while
layout fragments live in `data/layout/us` and `data/layout/jp` behind their
small selectors (`data/scripts.inc` and `data/layout.inc`).  Add text,
graphics, and other future regional assets in the same `data/<domain>/<us|jp>`
form; do not split executable code that way.

Script bytecode and its referenced text are treated as one region-specific
block when the text differs substantially.  `data/scripts.inc` is the shared
selector for the complete blocks under `data/scripts/us` and
`data/scripts/jp`; matching opcodes alone are not enough to share a
script block.

JP revision 0 has a verified linker layout and an exact build target.  The JP
ROM remains an ignored local comparison baseline: use only bounded,
documented source fragments where necessary, never a whole-ROM `incbin`.

Reference Guide text is organized by content category under
`data/text/<region>/reference_guide/`; its small native pointer tables and
declarations stay centralized in `src/reference_guide.cc` and
`include/reference_guide.hh`. Pages 0-30 currently use this layout.

## Setting up

See [INSTALL.md](./INSTALL.md).

## Contributing

Please do. Feel free to yell at me if you need naming/style/formatting guidelines.

If you're looking for things that need to be done, check out [TODO.md](./TODO.md).

## Contact

You can find me over at the [Fire Emblem Universe Discord](https://feuniverse.us/t/feu-discord-server/1480?u=stanh) under the handle `nat_776`. I also lurk other places such as the pret Discord.

See also my other stuff:

* [**StanHash/FOMT-DOC**](https://github.com/StanHash/FOMT-DOC), my old documentation of this game's internals.
* [**StanHash/fe6**](https://github.com/StanHash/fe6), a decompilation of Fire Emblem: The Binding Blade (JP)
