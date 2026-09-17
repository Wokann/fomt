# Shared resource `086F2FAC`

`full/group_000.png` through `group_015.png` are the editable,
palette-indexed views of all sixteen drawable resources in one fixed
`0x31FC`-byte `IndexedResourceArchive`. They are complete OAM-composited
source images, not tile atlases or screenshots. The original archive retains
its selector, descriptor, OAM, tile-placement, and BGR555 palette tables, so
rebuilding requires no JSON layout sidecar.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x479108` |
| US | `0x6F2FAC` |
| EU | `0x6F3008` |
| DE | `0x47A048` |

It has four selection descriptors, sixteen resource descriptors, two OAM
records, 384 native 4bpp tiles, four BGR555 palettes, and sixteen selection
entries. Its individual gameplay semantics are not independently proven, so
the source directory retains the original address rather than inventing a
semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-shared-resource-086f2fac-all
make gfx-shared-resource-086f2fac-patch-test
make gfx-shared-resource-086f2fac-edit-test
```
