# Regional resource `0872BE64`

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`gUnk_0872BE64` is a one-group `IndexedResourceArchive` with a byte-identical
JP/US/EU source domain and a distinct, larger DE domain:

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Drawable groups / tiles |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4B1FCC` / `0x72BE64` / `0x72BEC0` | `0x76C` | `1, 1, 3, 56, 1, 0` | 1 / 56 |
| `de/` | DE | `0x4B3030` | `0x874` | `1, 1, 4, 64, 1, 0` | 1 / 64 |

JP, US, and EU have exactly the same complete archive bytes, so they share
one editable source directory. DE has one additional native layout record and
eight additional 4bpp tiles, therefore it is rebuilt from a separate source.
Each domain has one drawable OAM group, one BGR555 palette and one selection
entry.

`shared/full/native.png` and `de/full/native.png` are the editable atlases in
native 4bpp tile order. Both use the byte-identical 16-color palette in
`shared/full/native.pal`. The ordinary graphics rules generate source-adjacent
`.4bpp` and `.gbapal` files. One `archive.inc` places the original selection,
descriptor, OAM and index tables around those assets at their original ROM
positions, with a region conditional for the extra DE OAM entry and tiles.

`full/group_000.png` and `preview/` in each domain are OAM-composited
reference views, not compilation inputs. They do not preserve native tile
order. No JSON layout sidecar is needed.

The Make build selects `de/` tiles for `GAME_REGION=DE` and `shared/` tiles
otherwise. All four ROMs match their original SHA-1 after direct linking;
there is no ROM-derived rebuild or post-link patch for this archive.
