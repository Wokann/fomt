# Shared resource `08725DA0`

`full/group_000.png` through `group_005.png` are the editable,
palette-indexed views of the six drawable resources in one fixed
`0xF2C`-byte `IndexedResourceArchive`. They are complete OAM-composited source
images, not tile atlases or screenshots. The original archive retains its
selector, descriptor, OAM, tile-placement, and BGR555 palette tables, so
rebuilding requires no JSON layout sidecar.

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

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/` only.

Use the following checks after editing:

```console
make gfx-shared-resource-08725da0-all
make gfx-shared-resource-08725da0-patch-test
make gfx-shared-resource-08725da0-edit-test
```
