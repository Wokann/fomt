# Actor graphics pipeline

The shared FoMT `IndexedResourceArchive` is authored in
`actor_archive/native_tiles.png`, independent `palettes_*.pal` files, and
`archive.inc`. The atlas preserves every native tile, including hidden or
unreferenced pixels. Generic gbagfx rules generate adjacent `.4bpp` and
`.gbapal` files; `archive.inc` includes them between the source-owned tables.
The archive's seven
native tables describe 2,551 animation selectors, 3,009 frame descriptors,
4,795 OAM pieces, 24,398 four-bit tiles, 162 palettes, an empty reserved
table, and 3,990 timing entries. OAM-composited `full/frame_NNNN.png` views
retain descriptor IDs for reference but are not build inputs. Character
directories retain selector notes only, not competing editable frame copies.
The normal build does not read a ROM or apply visible-frame overlays.

## Current verified coverage

The original selector audit identified ranges `0x212-0x2BB` and
`0x2FC-0x33F`, `0x3AE-0x3B1`, `0x3E0-0x3E3`, `0x3F0-0x3F3`, and
`0x430-0x433`. Together they reference 293 distinct frame descriptors. The
following directories document these groups; their counts are reference
mapping coverage, not a restriction on the atlas's build coverage:

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
make -j4 GAME_REGION=JP compare
make -j4 GAME_REGION=US compare
make -j4 GAME_REGION=EU compare
make -j4 GAME_REGION=DE compare
```

These source-referenced builds verify whole-ROM SHA-1 values. To regenerate
only the atlas, request the actual output path:

```console
make NODEP=1 graphics/sprites/actor_archive/native_tiles.4bpp
```

The Python frame overlay/export helpers and per-family Make wrappers have
been retired. Historical investigations and selector mappings remain in the
existing documents; removed helpers can be recovered from Git revision
`31411d1d` if an old audit needs reproduction. Edit the native atlas and
palette sources, not rendered frames or duplicated character-specific PNGs.
