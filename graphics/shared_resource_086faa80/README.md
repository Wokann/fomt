# Shared resource `086FAA80`

`full/native.png` contains the 36 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
declares the native selector, descriptor, OAM, and entry tables and links those
assets directly, without a ROM template or post-link patch. The existing
`full/group_000.png` through `group_008.png` are rendered reference views,
not build inputs. No JSON layout sidecar is used.

The archive is byte-identical in all four retail FoMT ROMs:

| Region | ROM offset |
| --- | ---: |
| JP | `0x480BDC` |
| US | `0x6FAA80` |
| EU | `0x6FAADC` |
| DE | `0x481B1C` |

It has three selection descriptors, nine resource descriptors, one OAM
record, 36 native 4bpp tiles, one BGR555 palette, and nine selection entries.
Its individual gameplay semantics are not independently proven, so the source
directory retains the original address rather than inventing a semantic name.

`preview/` contains transparent RGBA inspection exports only; compilation
reads `full/native.png` only. Build the resource with:

```console
make gfx-shared-resource-086faa80
```
