# Regional resource `0871D51C`

This is one logical `IndexedResourceArchive` family with four independently
verified native layouts. It is not a shared payload:

| Region | ROM offset | Fixed length | Native groups / tiles / selections |
| --- | ---: | ---: | ---: |
| JP | `0x4A3678` | `0x1298` | 31 / 124 / 46 |
| US | `0x71D51C` | `0x128C` | 31 / 124 / 43 |
| EU | `0x71D578` | `0x128C` | 31 / 124 / 43 |
| DE | `0x4A45B8` | `0x13BC` | 33 / 132 / 47 |

Each region's `full/native.png` is the editable atlas in the archive's actual
4bpp tile order; `full/native.pal` is its single palette bank. The generic
graphics rules produce adjacent `.4bpp` and `.gbapal` files, which the original
assembly includes at the tile and palette positions. The selection, descriptor,
OAM and final index tables remain in physical order in that assembly. No ROM
input, separate archive builder or post-link patch is used in the normal build.

`full/group_*.png` and `preview/` are OAM-composited references. They do not
retain the archive's native tile order and are not build inputs.

The US and EU payloads happen to be byte-identical at different ROM offsets,
but retain separate source directories so future localization-specific edits
cannot silently affect both builds. JP and DE have different descriptor, tile
and selection-table sizes; their assembly tables and native images preserve
those differences. All four ROM SHA-1 comparisons pass with this layout.
