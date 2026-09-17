# Regional resource `0872BE64`

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

`full/group_000.png` is the editable indexed-PNG source. `preview/` is a
readable rendering of the original OAM composition only. Descriptor, OAM,
tile-allocation, palette and selection tables remain inside the fixed native
archive, so this pipeline does not use a JSON layout sidecar.

The Make build selects `de/` for `GAME_REGION=DE` and `shared/` otherwise.
It rebuilds the exact native allocation and applies it only to the original
regional address after link. Four-region tests verify unchanged byte recovery,
post-link patch safety, and an editable-pixel round trip that remains within
each region's proven fixed bounds.
