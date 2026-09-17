# Large shared resource archive

`full/group_000.png` through `group_101.png` are the editable,
palette-indexed views of the 102 drawable resources in one fixed
`0x6EA0`-byte `IndexedResourceArchive`. They are complete OAM-composited source
images, not tile atlases or screenshots. The original archive retains its
selector, descriptor, OAM, tile-placement, and BGR555 palette tables, so
rebuilding requires no JSON layout sidecar.

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

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-large-shared-resource-archive-all
make gfx-large-shared-resource-archive-patch-test
make gfx-large-shared-resource-archive-edit-test
```
