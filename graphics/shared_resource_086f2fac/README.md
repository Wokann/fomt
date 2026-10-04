# Shared resource `086F2FAC`

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`full/native.png` is the editable, indexed atlas of all 384 native 4bpp tiles.
`full/native.pal` is the editable JASC palette containing the four original
16-color banks. The generic graphics rules produce `native.4bpp` and
`native.gbapal`; `archive.inc` links those assets with the original selector,
descriptor, OAM, and selection tables. The build does not read a ROM template
or patch the linked ROM for this archive.

`full/group_000.png` through `group_015.png` are OAM-composited reference
views, not the compilation input: their pixel order differs from the native
tile stream. `preview/` contains transparent RGBA inspection exports only.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x479108` |
| US | `0x6F2FAC` |
| EU | `0x6F3008` |
| DE | `0x47A048` |

It has four selection descriptors, sixteen resource descriptors, two OAM
records, 384 native 4bpp tiles, four BGR555 palettes, and sixteen selection
entries. Its individual gameplay semantics are not independently proven, so
the source directory retains the original address rather than inventing a
semantic name.

Use the following checks after editing:
