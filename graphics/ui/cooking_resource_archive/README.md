# Cooking UI resource archive

`full/group_000.png` and `group_001.png` are the editable, palette-indexed
views of the two drawable resources in a fixed `0x598`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The original archive retains its selector,
descriptor, OAM, tile-placement, and BGR555 palette tables, so rebuilding
requires no JSON layout sidecar.

The third descriptor is an all-zero, non-drawable native slot. It remains in
the rebuilt archive and intentionally has no PNG source. `preview/` contains
transparent RGBA inspection exports only; compilation reads `full/` only.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4DA620` |
| US | `0x754674` |
| EU | `0x7546D0` |
| DE | `0x4DBB90` |

It has one selection descriptor, three resource descriptors (two drawable),
three OAM records, 40 native 4bpp tiles, one BGR555 palette, and four selection
entries. The cooking constructors instantiate this resource; the two PNG names
remain physical group IDs because the verified archive layout alone does not
prove a distinct gameplay meaning for each frame.

Use the following checks after editing:

```console
make gfx-cooking-ui-resource-archive-all
make gfx-cooking-ui-resource-archive-patch-test
make gfx-cooking-ui-resource-archive-edit-test
```
