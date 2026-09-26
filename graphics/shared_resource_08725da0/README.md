# Shared resource `08725DA0`

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

```console
make gfx-shared-resource-08725da0-all
make -j4 fomt_jp fomt_us fomt_eu fomt_de
```
