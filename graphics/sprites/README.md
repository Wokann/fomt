# Actor graphics pipeline

`tools/actor_archive.py` exposes editable, complete actor-frame PNGs from the
FoMT `IndexedResourceArchive`. The sole build source is
`actor_archive/full/frame_NNNN.png`; individual actor directories retain
selector notes only, so a frame can never have two competing editable copies.
This archive is not a tile sheet: its seven
native tables describe 2,551 animation selectors, 3,009 frame descriptors,
4,795 OAM pieces, 24,398 four-bit tiles, 162 palettes, an empty reserved
table, and 3,990 timing entries. The source images deliberately retain native
frame descriptor IDs (`frame_NNNN.png`) so the relationship remains auditable.

The converter reads all OAM geometry, tile offsets, flip flags and palette
selection from the ROM. It does not use JSON or another hand-authored layout.
During a rebuild it begins with the native actor tile table, patches only
visible pixels changed in a complete indexed PNG, and rejects conflicting
assignments to a shared native pixel. Uncovered archive content therefore
remains byte-for-byte native data.

## Current verified coverage

The Makefile currently rebuilds selector ranges `0x212-0x2BB` and
`0x2FC-0x33F`, `0x3AE-0x3B1`, `0x3E0-0x3E3`, `0x3F0-0x3F3`, and
`0x430-0x433`. Together they reference 293 distinct frame descriptors. The
following directories own exactly one PNG for each covered descriptor:

| Source directory | Complete frames |
| --- | ---: |
| `rick/overworld` | 32 |
| `popuri/overworld` | 41 |
| `lillia/overworld` | 12 |
| `child/overworld` | 31 |
| `cliff/overworld` | 39 |
| `cow/overworld` | 29 |
| `calf/overworld` | 43 |
| `zack/overworld` | 12 |
| `doctor/overworld` | 28 |
| `farm_dog/overworld` | 17 |
| `staid/overworld` | 9 |

Each directory's README records the authoritative selector groups and any
neighbouring selector intentionally retained without a guessed semantic name.

## Build and verify

```console
make gfx-actors
make gfx-actors-all
```

`gfx-actors` rebuilds the active region's native actor-tile payload used by
`asm/data/data_0813B288.s`; normal ROM targets depend on the same generated
binary. `gfx-actors-all` verifies JP, US, EU and DE independently by comparing
the rebuilt byte range at its real regional ROM address. A source set that has
not been edited must reproduce the original tile payload exactly.

`gfx-actors-edit-test` additionally copies the Rick test frames into a
temporary directory, changes one visible indexed pixel, and verifies that the
rebuilt payload changes only inside the selected frames' owned native tile
ranges. It never modifies a committed PNG.

To run every established graphics verifier—fonts, portrait archives, actor
archive, UI grids and OAM packing—use:

```console
make gfx-verify
```

When expanding coverage, export an authoritative selector range into a new or
existing actor directory, document descriptor ownership, add the range and
source directory to the Makefile, then run `make gfx-actors-all`. Do not place
raw linear tile dumps in these directories or create duplicate ownership for a
shared descriptor.
