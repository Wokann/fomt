# Menu UI resource archive

`full/group_000.png` through `group_007.png` are the editable,
palette-indexed views of the eight drawable resources in one `0x504`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. `archive.inc` keeps the native selector,
descriptor, OAM, and selection tables in ROM order. The shared graphics rules
turn the PNGs into 4bpp tiles and a BGR555 palette for direct assembly; no
base-ROM template, custom archive builder, or post-link patch is needed.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A4910` |
| US | `0x71E7A8` |
| EU | `0x71E804` |
| DE | `0x4A5974` |

It has eight selection descriptors, eight resource descriptors, one OAM
record, 32 native 4bpp tiles, one BGR555 palette, and eight selection entries.
The known constructor resides beside the menu entry-ID table. That establishes
this as menu UI data, while the group file names deliberately remain physical
IDs until individual menu-icon semantics are independently established.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-menu-ui-resource-archive
make -j4 fomt_jp fomt_us fomt_eu fomt_de
```
