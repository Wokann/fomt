# Regional resource `0872DE44`

`gUnk_0872DE44` is a 27-group `IndexedResourceArchive` with a byte-identical
JP/US/EU source domain and a distinct DE domain:

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Drawable groups / tiles |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4B3FAC` / `0x72DE44` / `0x72DEA0` | `0x1034` | `27, 27, 6, 106, 1, 0` | 27 / 106 |
| `de/` | DE | `0x4B5118` | `0x10CC` | `27, 27, 9, 110, 1, 0` | 27 / 110 |

JP, US, and EU use exactly the same complete archive bytes, so they share the
same editable source. DE retains the same 27 selected groups but has three
additional native layout records and four additional 4bpp tiles. Each source
domain has one BGR555 palette and 27 selection entries.

`shared/full/native.png` and `de/full/native.png` store tiles in physical ROM
order; `shared/full/native.pal` stores the palette used by all four regions.
The generic graphics rules convert these sources to adjacent `.4bpp` and
`.gbapal` build products. `archive.inc` places the common selection and final
index tables once, selecting only the DE-specific descriptor/OAM/tile layout
where needed. The existing `group_*.png` and `preview/` files show composed OAM
groups for reference only; they are not compilation inputs.

The assembler includes `archive.inc` at the original location in each region.
The normal build neither reads a base ROM for this archive nor overwrites the
linked ROM afterward. JP, US, EU, and DE complete builds match their original
SHA-1 values. To regenerate both tile outputs and the palette, run
`make gfx-regional-resource-0872de44-all` in WSL.
