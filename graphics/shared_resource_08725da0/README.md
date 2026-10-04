# Shared resource `08725DA0`

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`full/native.png` is the editable atlas of all 109 tiles in native 4bpp order.
It is one tile wide so the generic PNG converter writes exactly 109 tiles,
without an invented padding tile. `full/native.pal` contains both original
16-color BGR555 banks. The generic graphics rules generate source-adjacent
`.4bpp` and `.gbapal`; `archive.inc` joins them with the selection, descriptor,
OAM and final index tables directly at the four original assembly positions.
The ordinary build neither reads a ROM template nor patches the linked ROM.

`full/group_000.png` through `group_005.png` are OAM-composited reference
views. Their visual ordering does not retain the native tile layout, so they
are not compilation inputs.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4ABF08` |
| US | `0x725DA0` |
| EU | `0x725DFC` |
| DE | `0x4ACF6C` |

It has six selection descriptors, six resource descriptors, 20 OAM records,
109 native 4bpp tiles, two BGR555 palettes, and six selection entries. It is
used by shared runtime construction paths, but its individual resource
semantics are not independently proven. The original address is therefore
retained in the source path rather than inventing a gameplay-specific name.

`preview/` contains transparent RGBA inspection exports only. The direct-link
layout passes all four original-ROM SHA-1 comparisons.

Use the following checks after editing:
