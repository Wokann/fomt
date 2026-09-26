# Common OAM resource archive

`full/native.png` is the editable, native-order indexed atlas of all 1,624
4bpp tiles. `full/palettes_00.pal` through `palettes_21.pal` contain the 342
original 16-color banks in ROM order. Each JASC file holds at most sixteen
banks because the existing graphics converter supports at most 256 colors
per palette. Its generic suffix rules generate `.4bpp` and `.gbapal` files;
`archive.inc` links those assets with the original selector, descriptor, OAM,
and selection tables. No original ROM template or post-link patch is used.

`full/group_000.png` through `full/group_499.png` are OAM-composited reference
views, not compilation inputs. Groups `316` and `429` are absent because their
descriptors have no drawable OAM content. `preview/` contains RGBA review
images only.

The tile atlas uses the first palette bank for index display. For the actual
colors selected by each group, consult its palette bank or reference view.

The fixed `0x12848` archive is byte-identical across all four retail FoMT
localizations:

| Region | ROM range |
| --- | --- |
| JP | `0x3ED9FC`–`0x3F0244` |
| US | `0x6678A0`–`0x67A0E8` |
| EU | `0x6678FC`–`0x67A144` |
| DE | `0x3EE93C`–`0x401184` |

Its SHA-256 is
`c28eff40e6965f89015da48b9527ea995eeec0d7ec30c4f1f2aeda5b8f3f9f33`.
The seven counted native tables contain 493 selection descriptors, 500 group
descriptors, 101 GBA OAM entries, 1,624 4bpp tiles, 342 BGR555 palettes, no
sixth-table records, and 532 final selection entries. Every drawable group has
one palette range and a valid OAM/tile range. All 1,624 tile slots are covered
by at least one group; a shared tile has one native source definition.

`func_0805E790` resolves the group descriptor fields to those OAM, tile, and
palette ranges. `func_080757E8` uploads the resolved tile and palette bytes to
OBJ VRAM and OBJ palette memory. This proves the group PNGs are composed OAM
views, rather than the native tile stream. Ten group uses include an OAM flip
flag; the original table preserves those flips.

The atlas stores the complete tile stream, including pixels hidden in a group
view. The palette files store all palette banks, rather than borrowing palette
bytes from a baseline ROM. The two empty groups remain explicit zero entries
in the ordered tables.

```console
make -j4 gfx-common-resource-archive
make -j4 fomt_jp
make -j4 fomt_us
make -j4 fomt_eu
make -j4 fomt_de
```
