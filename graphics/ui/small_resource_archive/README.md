# Small UI resource archive

`full/group_000.png` through `group_002.png` are the editable, palette-indexed
views of the three drawable resources in one `0x548`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. `archive.inc` contains the native selector,
descriptor, OAM, and selection tables in ROM order. The existing graphics
rules convert the PNGs to 4bpp tiles and two BGR555 palettes, which the
assembler includes directly. Neither the base ROM nor a post-link patch is a
build input for this archive.

The fourth descriptor is an all-zero, non-drawable native slot. It remains in
the linked archive and intentionally has no PNG source. `preview/` contains
transparent RGBA inspection exports only; compilation reads `full/` only.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4DABB8` |
| US | `0x754C0C` |
| EU | `0x754C68` |
| DE | `0x4DC128` |

It has two selection descriptors, four resource descriptors (three drawable),
two OAM records, 36 native 4bpp tiles, two BGR555 palettes, and five selection
entries. The known callers include general UI constructors and cooking-screen
constructors; that proves the resource is shared UI data, but does not justify
assigning a narrower semantic name to its individual cursor/marker artwork.

Use the following checks after editing:

```console
make gfx-small-ui-resource-archive
make -j4 fomt_jp fomt_us fomt_eu fomt_de
```
