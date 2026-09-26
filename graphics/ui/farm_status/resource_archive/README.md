# Farm Status / Town Map OAM resource archive

`full/native_0.png` and `full/native_1.png` are the editable native-order
indexed tile atlases (64 and 9 tiles). `full/native.pal` contains all thirteen
16-color palette banks. The generic graphics rules produce `.4bpp` and
`.gbapal` assets; `archive.inc` links them with the original selector,
descriptor, OAM, and selection tables. No original ROM template or post-link
patch is used for this archive.

`full/resource_000.png` through `full/resource_039.png` are OAM-composited
reference views, not build inputs. Thirty-eight are 16 by 16 pixels and two
are 8 by 8 pixels. `preview/` contains equivalent RGBA review images only.

The native archive is byte-identical in all four retail FoMT localizations:

| Region | ROM range |
| --- | --- |
| JP | `0x4D977C`–`0x4DA620` |
| US | `0x7537D0`–`0x754674` |
| EU | `0x75382C`–`0x7546D0` |
| DE | `0x4DACEC`–`0x4DBB90` |

Its fixed `0xEA4` bytes have SHA-256
`480a114e52b941e289d67055ddd632b6c0bbee3cfa66263523ad91c7e1d4dfc1`.
The six counted runtime tables contain 20 selection records, 40 group
descriptors, 11 OAM entries, 73 4bpp tiles, 13 BGR555 palettes, no sixth-table
records, and 40 selection entries. Each group descriptor has a verified OAM
range, tile range, and exactly one palette range. The first table maps each
high-level selection to two group IDs; it remains native data rather than a
second authored manifest.

`func_0805E790` resolves a group descriptor into the OAM/tile/palette ranges,
and `func_080757E8` copies those referenced tile and palette bytes to OBJ VRAM
and OBJ palette memory. This is the code-backed relationship that makes each
full PNG a safe editing surface.

The source atlases preserve native tile order and color indexes, including
tile pixels hidden in an OAM-composited view. The JASC palette preserves all
thirteen original BGR555 banks. Shared native tiles remain shared through the
original descriptor table, rather than being duplicated per group image.

```console
make -j4 gfx-farm-status-resource-archive
make -j4 fomt_jp
make -j4 fomt_us
make -j4 fomt_eu
make -j4 fomt_de
```
