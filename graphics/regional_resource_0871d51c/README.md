# Regional resource `0871D51C`

This is one logical `IndexedResourceArchive` family with four independently
verified native layouts. It is not a shared payload:

| Region | ROM offset | Fixed length | Native groups / tiles / selections |
| --- | ---: | ---: | ---: |
| JP | `0x4A3678` | `0x1298` | 31 / 124 / 46 |
| US | `0x71D51C` | `0x128C` | 31 / 124 / 43 |
| EU | `0x71D578` | `0x128C` | 31 / 124 / 43 |
| DE | `0x4A45B8` | `0x13BC` | 33 / 132 / 47 |

Each region's `full/group_*.png` files are its editable indexed-PNG source.
`preview/` is regenerated from the corresponding native OAM records and is a
readable reference only. The selection, descriptor, OAM, tile-allocation and
palette tables remain inside each region's fixed archive; no JSON layout
sidecar is used.

The US and EU payloads happen to be byte-identical at different ROM offsets,
but retain separate source directories so future localization-specific edits
cannot silently affect both builds. JP and DE have different descriptor and
selection-table sizes, and therefore use their own verified profiles.
