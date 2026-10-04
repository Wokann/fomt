# Shared resource `0871EDD4`

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`full/group_000.png` through `group_003.png` are the editable,
palette-indexed views of four drawable resources in one fixed `0x12C`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The fifth native descriptor is all zero.
`archive.inc` describes the native selector, descriptors, OAM and selection
entries in ROM order and directly includes the PNG-derived tiles and palette.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A4F3C` |
| US | `0x71EDD4` |
| EU | `0x71EE30` |
| DE | `0x4A5FA0` |

It has one selection descriptor, five resource descriptors, one OAM record,
four native 4bpp tiles, one BGR555 palette, and five selection entries. Its
individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only. `group_000.png` owns the palette shared by all four tiles.
The assembler includes the table source during the ordinary link; no original
ROM input, intermediate archive, or post-link patch is used for this range.

Use the following checks after editing:
