# Shared resource `0871ECAC`

`full/group_000.png` through `group_003.png` are the editable,
palette-indexed views of four drawable resources in one fixed `0x128`-byte
`IndexedResourceArchive`. They are complete OAM-composited source images, not
tile atlases or screenshots. The fifth native descriptor is all zero and
remains native data. `archive.original.bin` retains its selector, descriptor,
OAM, tile-placement, and BGR555 palette tables, so rebuilding requires no JSON
layout sidecar. This metadata remains a native binary until its structure is
fully expressed as C data.

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

`preview/` contains transparent RGBA inspection exports only. The ordinary
graphics rules use the C `gbagfx` tool to generate adjacent `.4bpp` and
`.gbapal` files from `full/`. The C `fomt-indexed-archive` tool combines
them with the checked-in metadata into adjacent `archive.bin`. The assembler
includes that file directly in all four regions, without an original ROM or
post-link replacement for this archive.

Use the following checks after editing:

```console
make gfx-shared-resource-0871ecac-all
# Then use make compare, compare_eu, and compare_de for whole-ROM checks.
```
