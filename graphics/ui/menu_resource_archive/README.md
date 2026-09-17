# Menu UI resource archive

`full/group_000.png` through `group_007.png` are the editable,
palette-indexed views of the eight drawable resources in one fixed
`0x504`-byte `IndexedResourceArchive`. They are complete OAM-composited source
images, not tile atlases or screenshots. The original archive retains its
selector, descriptor, OAM, tile-placement, and BGR555 palette tables, so
rebuilding requires no JSON layout sidecar.

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
make gfx-menu-ui-resource-archive-all
make gfx-menu-ui-resource-archive-patch-test
make gfx-menu-ui-resource-archive-edit-test
```
