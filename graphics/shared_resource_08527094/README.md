# Shared resource `08527094`

`full/native.png` contains the four native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
declares the native selector, descriptor, OAM, and entry tables and links those
assets directly, without a ROM template or post-link patch. The existing
`full/group_000.png` through `group_007.png` are rendered reference views,
not build inputs. No JSON layout sidecar is used.

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

All four regional branches now include this same `archive.inc` and define
`gUnk_08527094` directly at their own archive start. JP no longer keeps a
second address-named definition or a raw byte copy of this archive. Every
verified archive pointer, including three former JP literal-pool byte words,
uses a real relocation to that definition rather than an alias or offset.

`preview/` is reference-only; compilation reads `full/native.png` only.
