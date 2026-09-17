# Shared resource `0871EDD4`

`full/group_000.png` through `group_003.png` are the editable,
palette-indexed views of four drawable resources in one fixed `0x12C`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The fifth native descriptor is all zero and
remains native data. The original archive retains its selector, descriptor,
OAM, tile-placement, and BGR555 palette tables, so rebuilding requires no JSON
layout sidecar.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4A4F3C` |
| US | `0x71EDD4` |
| EU | `0x71EE30` |
| DE | `0x4A5FA0` |

It has one selection descriptor, five resource descriptors, one OAM record,
four native 4bpp tiles, one BGR555 palette, and five selection entries. Its
individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-shared-resource-0871edd4-all
make gfx-shared-resource-0871edd4-patch-test
make gfx-shared-resource-0871edd4-edit-test
```
