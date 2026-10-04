# Shared resource `0871ECAC`

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`full/group_000.png` through `group_003.png` are the editable,
palette-indexed views of four drawable resources in one fixed `0x128`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The fifth native descriptor is all zero.
`archive.inc` now expresses the seven native tables in ROM order and includes
the four PNG-derived tiles and the shared palette directly. There is no ROM
template or intermediate `archive.bin` in the build.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A4E14` |
| US | `0x71ECAC` |
| EU | `0x71ED08` |
| DE | `0x4A5E78` |

It has one selection descriptor, five resource descriptors, one OAM record,
four native 4bpp tiles, one BGR555 palette, and four selection entries. Its
individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only. The ordinary
graphics rules use `gbagfx` to generate adjacent `.4bpp` files from all four
PNGs and a `.gbapal` from `group_000.png`. All four retail palettes are
identical; `group_000.png` owns the shared palette. The assembler includes
the table source directly in all four regions, without a separate archive
builder or post-link replacement.

Use the following checks after editing:
