# Regional resource `08728208`

`gUnk_08728208` is one logical `IndexedResourceArchive` whose native archive
format is identical in all four retail regions, but whose visual payload has
two independently verified byte domains:

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Entries |
| --- | --- | --- | ---: | --- | ---: |
| `jp/` | JP | `0x4AE370` | `0x118` | `1, 3, 3, 4, 1, 0` | 4 |
| `overseas/` | US / EU / DE | `0x728208` / `0x728264` / `0x4AF3D4` | `0x118` | `1, 3, 3, 4, 1, 0` | 4 |

The US, EU, and DE payloads are byte-identical, so they deliberately share
one editable source directory. JP is a separate verified source because its
payload SHA-256 differs. Both domains contain three drawable OAM groups, four
native 4bpp tiles, one BGR555 palette and four selection entries.

`full/group_*.png` files are editable indexed-PNG source. `preview/` is
regenerated from the native OAM records and is a readable reference only. The
selection, descriptor, OAM, tile-allocation and palette tables remain inside
the fixed-size native archive; no JSON layout sidecar is used.

The Make build selects `jp/` only for `GAME_REGION=JP`; US, EU and DE select
`overseas/`. It rebuilds a region-local `archive.bin`, then applies it to the
original physical range after the normal ROM link. The four-region patch and
editable-pixel tests confirm that an unchanged source preserves every byte and
that a source edit remains confined to the native allocation.
