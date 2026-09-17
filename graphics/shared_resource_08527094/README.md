# Shared resource `08527094`

`full/group_000.png` through `group_007.png` are eight editable,
palette-indexed OAM-composited source views of a fixed `0x1A4`-byte
`IndexedResourceArchive`. The original selector, descriptor, OAM,
tile-placement, flip, and BGR555 palette data remain native archive data; no
JSON layout sidecar is used.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x2AD1F0` |
| US | `0x527094` |
| EU | `0x5270F0` |
| DE | `0x2AE130` |

It has four selector descriptors, eight resource descriptors, seven OAM
records, four native 4bpp tiles, one BGR555 palette, eight entries, and four
native flipped OAM compositions. The original address remains the source name
until a runtime purpose is independently established.

`preview/` is reference-only; compilation reads `full/` only.
