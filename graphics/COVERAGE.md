# Graphics coverage

This is a conservative inventory of graphics resources with a verified,
editable rebuild path.  It is not a claim that every ROM `incbin` range is an
image, nor that all game graphics have been extracted.

## Managed resources

| Resource family | Editable source | Native build output | Four-region byte check |
| --- | --- | --- | --- |
| Single-width font | `graphics/font/shared/single_width_font.png` | 1bpp glyph stream | Yes |
| Double-width font | `graphics/font/shared/double_width_font.png` | 1bpp glyph stream | Yes |
| Dialogue portraits | `graphics/portraits/shared/full/*.png` | portrait tile stream | Yes |
| Actor archive, every referenced descriptor | `graphics/sprites/actor_archive/full/*.png` | actor tile stream | Yes |
| Located UI tile grid | `graphics/ui/shared_resource/shared_resource.png` | 4bpp tiles plus BGR555 palette | Yes |
| Farm-status background and building previews | `graphics/ui/farm_status/shared/base_tiles.png`, `base_palettes.png`, and `tilemaps/*.tilemap` | packed 4bpp tile stream, sixteen BGR555 palette banks, and fourteen BG tilemaps | Yes |
| Farm-status secondary layouts | `graphics/ui/farm_status/shared/secondary_tilemaps/*.tilemap` | six native Huffman-4/LZ3 64-by-44 BG tilemap streams | Yes |
| Intro-scene object tile sources | `graphics/intro_scene/shared/object_tiles/*.4bpp` | twenty native Raw-LZ object-tile streams | Yes |
| Intro-scene startup tilemaps | `graphics/intro_scene/shared/startup_tilemaps/*.tilemap` | four native Huffman-4/LZ3 streams | Yes |
| Records Screen task icons | `graphics/ui/records_minigame/shared/task_00.png` through `task_06.png` | seven raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| MapData visual layers | `graphics/maps/shared/map_XX/layer_N.*` | 272 native packed streams, post-link patched at their original ROM ranges | Yes |

The actor archive has 3,009 frame descriptors, of which 2,963 are referenced
by the retail animation tables.  Every referenced descriptor has a checked-in
complete PNG source.  The other 46 descriptor slots have no retail animation
caller and remain preserved native data rather than invented source images.

## Build linkage

Most managed families are included from `asm/data/data_0813B288.s` through a
regional `build/<region>/graphics/...` output. MapData visual layers preserve
their original continuous archive position through a post-link replacement
step, because their 272 pointer-bearing streams are not a single assembly
incbin block. The surrounding archive headers, OAM records, palettes, tables,
and unhandled bytes remain direct ROM data until they have a corresponding
verified source/rebuild path.

## Unclassified ROM ranges

Assembly still contains many direct `baserom_*.gba` includes.  They are the
inventory pool for later work.  A direct include must not be converted merely
because it looks like tile data: first establish the exact format, bounds,
palette/layout relationship, consuming code, and four-region byte round trip.

Generate a current list with:

```console
python tools/gfx_incbin_inventory.py . --csv build/gfx_incbin_inventory.csv
python tools/gfx_compression_inventory.py . --csv build/gfx_compression_inventory.csv
python tools/unpack_vram_inventory.py . --csv build/unpack_vram_inventory.csv
```

All generated CSV files are local audit artifacts, not source artwork. The
compression inventory records only direct ranges that begin with a strictly
decodable `0x70` stream. Its enclosing `incbin` boundary is not automatically
the compressed stream's boundary, and a decoded stream is not automatically a
graphics resource. The Unpack-to-VRAM inventory follows only simple literal
and register data flow in assembly, so its rows are code-backed resource leads,
not assertions about tile, palette, or OAM format. Run it with
`make unpack-vram-inventory`; the current assembly yields 30 such calls.

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| Farm-status remaining screen data | `FarmStatusScreenResourceDescriptor` and direct ranges adjacent to the managed layouts. | The common tile grid, full palette-bank set, fourteen building-preview tilemaps and six secondary layouts are now managed; surrounding resource classes still need separate format analysis. |
| Intro-scene OAM composition and palettes | `gUnk_IntroSceneUnpackSource_*` labels decode to twenty managed native 0x500-byte tile sources; `func_0805FBB8` stages them for OBJ use. | The streams are managed, but their full-image OAM composition and per-object palette selectors remain runtime data. No guessed full PNG is treated as source. |
| Intro-scene startup tilemap presentation | `func_08001A90` decodes four managed 0x1000-byte streams and copies each as two interleaved 32-by-32 BG tilemaps. | Native interleaved tilemaps are managed; their tile-sheet, palette-bank and screen-selection rules still require a separate compositor audit. |
| Other Records-screen resources | Raw ranges adjacent to the task-icon records, plus page-specific data pointers in the Records Screen code. | The seven direct task icon/palette pairs are now managed; the remaining ranges still need independent consumer and format analysis. |
| MapData non-visual payloads | MapData fields 1 and 2 plus field-render records are used by field rendering. | The six visual pointer layers are managed as 272 verified streams. The remaining payloads may contain collision, terrain and animation data and require separate runtime format analysis. |
| Indexed resource archives | `IndexedResourceArchive` parses six counted descriptor sections and an entry table; its common and companion payloads are byte-identical across all four regions. | Exact boundaries and regional locations are recorded in `INDEXED_RESOURCE_ARCHIVES.md`. Descriptor semantics still require consumer-by-consumer analysis; neither archive is falsely exported as a graphics sheet. |
