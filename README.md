# Friends of Mineral Town

This is a decompilation of the 2003 GBA game "Harvest Moon: Friends of Mineral Town".

It builds the following ROM:

* **[fomt_us.gba]** `sha1: a2fc3574f0a65a4fcf7682fb274b9d7eebdef963` — byte-exact
* **fomt_jp.gba** `sha1: a655b2789aed14a6ac78c6075fbc533d3062dbe3` — byte-exact
* **fomt_eu.gba** `sha1: 7ba1ec1e46ce424e3c6fd72e4e8d5e9eb5ede247` — target baseline registered
* **fomt_de.gba** `sha1: 60f2a30b55c0e32754897b4d5df6ce06f8b71a37` — target baseline registered

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

`fomt_us` and `fomt_jp` also run their SHA-1 comparison. `fomt_eu` and
`fomt_de` currently provide independently compiled regional baselines;
`compare_eu` and `compare_de` deliberately remain explicit until their full
regional linker layouts and remaining raw asset blocks have been matched.

The build defines exactly one of `REGION_US`, `REGION_JP`, `REGION_EU`, and
`REGION_DE`. A recovered function belongs in one owning C/C++ or assembly
module: shared code is kept outside the conditional, and only a verified
difference is placed under the relevant region guard. Do not create a separate
region-specific executable object tree.

Some JP functions are not semantic source yet.  Their bounded, byte-exact
assembly is kept directly in the owning `.cc` file's `REGION_JP` branch with
file-scope `asm()`.  It is not a second source file or compilation unit.  As
functions are recovered, move common definitions out of the guard and leave
only the verified regional body inside it.

Large content blocks use the opposite hierarchy: domain first, then version.
For example, scripts live in `data/scripts/<region>`, layout fragments live in
`data/layout/<region>`, and ordinary text sources live in
`data/text/<region>`, all behind their small selectors. Add text, graphics,
and other future regional assets in the same `data/<domain>/<region>` form; do
not split executable code that way.

Script bytecode and its referenced text are treated as one region-specific
block when the text differs substantially. `data/scripts.inc` is the shared
selector for complete Mary-managed RIFF blocks under `data/scripts/<region>`;
matching opcodes alone are not enough to share a script block.

JP revision 0 has a verified linker layout and an exact build target.  The JP
ROM remains an ignored local comparison baseline: use only bounded,
documented source fragments where necessary, never a whole-ROM `incbin`.

Reference Guide text is organized by content category under
`data/text/<region>/reference_guide/`; its small native pointer tables and
declarations stay centralized in `src/reference_guide.cc` and
`include/reference_guide.hh`. Pages 0-47 currently use this layout.

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
