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

`full/group_*.png` contains the editable indexed-PNG sources. `preview/` is
regenerated from the corresponding original OAM records and is reference-only.
The native selection, descriptor, OAM, tile-allocation and palette data remain
in their fixed archive layout; no JSON layout sidecar participates in build.

The Make build selects `de/` only with `GAME_REGION=DE`; JP, US, and EU select
`shared/`. It rebuilds the native fixed allocation, then applies it only to its
original address after link. The four-region test suite checks exact unchanged
rebuilds, post-link patch safety, and a visible-pixel edit confined to each
region's verified archive bounds.
