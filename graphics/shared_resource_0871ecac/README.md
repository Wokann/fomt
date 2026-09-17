# Shared resource `0871ECAC`

`full/group_000.png` through `group_003.png` are the editable,
palette-indexed views of four drawable resources in one fixed `0x128`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The fifth native descriptor is all zero and
remains native data. The original archive retains its selector, descriptor,
OAM, tile-placement, and BGR555 palette tables, so rebuilding requires no JSON
layout sidecar.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A4E14` |
| US | `0x71ECAC` |
| EU | `0x71ED08` |
| DE | `0x4A5E78` |

It has one selection descriptor, five resource descriptors, one OAM record,
four native 4bpp tiles, one BGR555 palette, and four selection entries. Its
individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-shared-resource-0871ecac-all
make gfx-shared-resource-0871ecac-patch-test
make gfx-shared-resource-0871ecac-edit-test
```
