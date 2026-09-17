# Shared resource `086FAA80`

`full/group_000.png` through `group_008.png` are the editable,
palette-indexed views of all nine drawable resources in one fixed
`0x584`-byte `IndexedResourceArchive`. They are complete OAM-composited
source images, not tile atlases or screenshots. The original archive retains
its selector, descriptor, OAM, tile-placement, and BGR555 palette tables, so
rebuilding requires no JSON layout sidecar.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x480BDC` |
| US | `0x6FAA80` |
| EU | `0x6FAADC` |
| DE | `0x481B1C` |

It has three selection descriptors, nine resource descriptors, one OAM
record, 36 native 4bpp tiles, one BGR555 palette, and nine selection entries.
Its individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-shared-resource-086faa80-all
make gfx-shared-resource-086faa80-patch-test
make gfx-shared-resource-086faa80-edit-test
```
