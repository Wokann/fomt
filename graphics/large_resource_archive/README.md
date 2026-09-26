# Large shared resource archive

`full/native.png` is the editable atlas of all 768 tiles in their original
4bpp order. The 46 palette banks are stored in three JASC files:
`palettes_00_15.pal`, `palettes_16_31.pal`, and `palettes_32_45.pal`.
Each file stays within the existing graphics converter's 256-color limit.
The generic graphics rules produce source-adjacent `.4bpp` and `.gbapal`
assets; `archive.inc` joins them with the selector, descriptor, OAM and index
tables at each region's original assembly position. No ROM-derived rebuild,
JSON sidecar or post-link patch is used in the normal build.

`full/group_000.png` through `group_101.png` are OAM-composited reference
views, not compilation inputs; their arrangement does not retain native tile
order.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A5068` |
| US | `0x71EF00` |
| EU | `0x71EF5C` |
| DE | `0x4A60CC` |

It has 27 selection descriptors, 102 resource descriptors, one OAM record,
768 native 4bpp tiles, 46 BGR555 palettes, and 124 selection entries. Its
known callers occur in shared runtime paths, which proves that it is an active
resource archive but does not yet prove individual gameplay semantics. The
group names therefore remain neutral physical IDs.

`preview/` contains transparent RGBA inspection exports only. The direct-link
layout passes JP, US, EU and DE original-ROM SHA-1 comparisons.

Use the following checks after editing:

```console
make gfx-large-shared-resource-archive-all
make -j4 fomt_jp fomt_us fomt_eu fomt_de
```
