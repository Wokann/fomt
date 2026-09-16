# Common OAM resource archive

`full/group_000.png` through `full/group_499.png` are the editable indexed
PNG sources for the drawable groups in FoMT's shared common
`IndexedResourceArchive`. Groups `316` and `429` are deliberately absent:
their native descriptors are all zero and therefore have no drawable OAM
content. `preview/` contains equivalent RGBA review output and is not input.

The fixed `0x12848` archive is byte-identical across all four retail FoMT
localizations:

| Region | ROM range |
| --- | --- |
| JP | `0x3ED9FC`–`0x3F0244` |
| US | `0x6678A0`–`0x67A0E8` |
| EU | `0x6678FC`–`0x67A144` |
| DE | `0x3EE93C`–`0x401184` |

Its SHA-256 is
`c28eff40e6965f89015da48b9527ea995eeec0d7ec30c4f1f2aeda5b8f3f9f33`.
The seven counted native tables contain 493 selection descriptors, 500 group
descriptors, 101 GBA OAM entries, 1,624 4bpp tiles, 342 BGR555 palettes, no
sixth-table records, and 532 final selection entries. Every drawable group has
one palette range and a valid OAM/tile range. All 1,624 tile slots are covered
by at least one group; shared tile edits must agree across every visible owner.

`func_0805E790` resolves the group descriptor fields to those OAM, tile, and
palette ranges. `func_080757E8` uploads the resolved tile and palette bytes to
OBJ VRAM and OBJ palette memory. This proves the full PNGs are composed OAM
resources, rather than arbitrary tile dumps. Ten group uses include an OAM
flip flag; the conversion preserves those native flips while presenting the
normal visual orientation for editing.

Rebuild starts from the verified native archive. It changes only visible 4bpp
pixels that differ from `full/`; all selection data, group descriptors, OAM,
palette bytes, non-visible tile pixels, and the two empty groups remain byte
for byte intact. Changing an indexed PNG's 16-color palette is rejected.

```console
make gfx-common-resource-archive-all
make gfx-common-resource-archive-patch-test
make gfx-common-resource-archive-edit-test
```

The first command verifies unchanged reconstruction in JP, US, EU, and DE.
The second proves applying each generated archive back to its original ROM
range is byte-neutral. The final command changes one shared visible pixel and
proves that metadata and the fixed archive boundary remain unchanged.
