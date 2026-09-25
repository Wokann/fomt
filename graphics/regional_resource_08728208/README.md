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

`full/group_000.png` is the canonical indexed-PNG source: all three group
PNGs encode the same four native tiles. `preview/` is an OAM-rendered
reference. The selection, descriptor, OAM and entry tables are written in
`archive.inc`, which is included at the original physical ROM positions.

The ordinary graphics rules convert the selected PNG to `.4bpp` tiles and
`.gbapal` palette. The linker assembles the archive directly; this resource
has no base-ROM input or post-link patch. JP uses `jp/`; US, EU and DE use
`overseas/`. The four region ROM SHA-1 checks verify unchanged reconstruction.
