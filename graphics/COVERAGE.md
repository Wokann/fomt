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
| Common OAM resource archive | `graphics/common_resource_archive/full/group_*.png` (498 drawable groups) | shared fixed `0x12848`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Small companion OAM archive | `graphics/small_companion_archive/full/group_*.png` (16 groups) | shared fixed `0x840`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Small shared UI OAM archive | `graphics/ui/small_resource_archive/full/group_*.png` (3 drawable groups) | shared fixed `0x548`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Cooking UI OAM archive | `graphics/ui/cooking_resource_archive/full/group_*.png` (2 drawable groups) | shared fixed `0x598`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Menu UI OAM archive | `graphics/ui/menu_resource_archive/full/group_*.png` (8 drawable groups) | shared fixed `0x504`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Large shared OAM archive | `graphics/large_resource_archive/full/group_*.png` (102 drawable groups) | shared fixed `0x6EA0`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08725DA0` | `graphics/shared_resource_08725da0/full/group_*.png` (6 drawable groups) | shared fixed `0xF2C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `086F2FAC` | `graphics/shared_resource_086f2fac/full/group_*.png` (16 drawable groups) | shared fixed `0x31FC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `086FAA80` | `graphics/shared_resource_086faa80/full/group_*.png` (9 drawable groups) | shared fixed `0x584`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0871ECAC` | `graphics/shared_resource_0871ecac/full/group_*.png` (4 drawable groups) | shared fixed `0x128`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0871EDD4` | `graphics/shared_resource_0871edd4/full/group_*.png` (4 drawable groups) | shared fixed `0x12C`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08527094` | `graphics/shared_resource_08527094/full/group_*.png` (8 drawable groups) | shared fixed `0x1A4`-byte `IndexedResourceArchive`; four flipped OAM compositions remain native layout data | Yes |
| Shared OAM archive `08727368` | `graphics/shared_resource_08727368/full/group_*.png` (19 drawable groups) | shared fixed `0x70C`-byte `IndexedResourceArchive`; two all-zero descriptors remain native layout data | Yes |
| Shared OAM archive `08727A74` | `graphics/shared_resource_08727a74/full/group_*.png` (1 drawable group) | shared fixed `0x794`-byte `IndexedResourceArchive`; 36 native flipped OAM entries remain layout data | Yes |
| Shared OAM archive `08728320` | `graphics/shared_resource_08728320/full/group_*.png` (21 drawable groups) | shared fixed `0x105C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0872937C` | `graphics/shared_resource_0872937c/full/group_*.png` (3 drawable groups) | shared fixed `0xE4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08729460` | `graphics/shared_resource_08729460/full/group_*.png` (3 drawable groups) | shared fixed `0x2A04`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0872EE78` | `graphics/shared_resource_0872ee78/full/group_*.png` (4 drawable groups) | shared fixed `0x2A4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08731B40` | `graphics/shared_resource_08731b40/full/group_*.png` (20 drawable groups) | shared fixed `0x6604`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873AE54` | `graphics/shared_resource_0873ae54/full/group_*.png` (2 drawable groups) | shared fixed `0x174`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873AFC8` | `graphics/shared_resource_0873afc8/full/group_*.png` (1 drawable group) | shared fixed `0xE5C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873CCB4` | `graphics/shared_resource_0873ccb4/full/group_*.png` (2 drawable groups) | shared fixed `0x1F8`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873CEAC` | `graphics/shared_resource_0873ceac/full/group_*.png` (1 drawable group) | shared fixed `0xE4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873CF90` | `graphics/shared_resource_0873cf90/full/group_*.png` (4 drawable groups) | shared fixed `0x2A4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873D234` | `graphics/shared_resource_0873d234/full/group_*.png` (6 drawable groups) | shared fixed `0x3C8`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873D5FC` | `graphics/shared_resource_0873d5fc/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873DE44` | `graphics/shared_resource_0873de44/full/group_*.png` (1 drawable group) | shared fixed `0x76C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873E5B0` | `graphics/shared_resource_0873e5b0/full/group_*.png` (1 drawable group) | shared fixed `0x76C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873ED1C` | `graphics/shared_resource_0873ed1c/full/group_*.png` (10 drawable groups) | shared fixed `0x6AC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087401A4` | `graphics/shared_resource_087401a4/full/group_*.png` (4 drawable groups) | shared fixed `0x2B0`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08740454` | `graphics/shared_resource_08740454/full/group_*.png` (3 drawable groups) | shared fixed `0x14C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087405A0` | `graphics/shared_resource_087405a0/full/group_*.png` (1 drawable group) | shared fixed `0x368`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08740908` | `graphics/shared_resource_08740908/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087409E4` | `graphics/shared_resource_087409e4/full/group_*.png` (4 drawable groups) | shared fixed `0x1010`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0874EE38` | `graphics/shared_resource_0874ee38/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087506E0` | `graphics/shared_resource_087506e0/full/group_*.png` (4 drawable groups) | shared fixed `0x56C`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0875352C` | `graphics/shared_resource_0875352c/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08753608` | `graphics/shared_resource_08753608/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087536E4` | `graphics/shared_resource_087536e4/full/group_*.png` (4 drawable groups) | shared fixed `0xEC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08755154` | `graphics/shared_resource_08755154/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Regional OAM archive `0871D51C` | `graphics/regional_resource_0871d51c/{jp,us,eu,de}/full/group_*.png` (JP/US/EU: 31 groups; DE: 33 groups) | four independently fixed `IndexedResourceArchive` layouts; selection, descriptor, OAM and palette tables remain native data in each regional archive | Yes: every regional source is rebuilt, post-link-patched and edit-tested against its own bounds and SHA-256. US/EU currently share bytes but are intentionally not coupled as one source. |
| Farm Status / Town Map OAM archive | `graphics/ui/farm_status/resource_archive/full/resource_*.png` (40 groups) | shared fixed `0xEA4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Located UI tile grid | `graphics/ui/shared_resource/shared_resource.png` | 4bpp tiles plus BGR555 palette | Yes |
| `func_08077810` regional BG and character streams | Overseas: `graphics/ui/scene_08077810/shared/tiles.png`, `tiles_trailer.bin`, `layer_0.tilemap`, and `layer_1.tilemap`; JP: `graphics/ui/scene_08077810/jp/tiles.png` and `layer_1.tilemap` | US/EU/DE rebuild an editable Huffman-8/LZ3 character stream (351 4bpp tiles plus an explicit two-byte non-tile trailer), a Huffman-4/LZ3 32-by-32 map, and a Huffman-4/LZ0 32-by-20 map. JP rebuilds its separate Huffman-4/LZ3 96-tile stream, one BGR555 palette bank, and a Huffman-4/LZ2 32-by-20 map at its own original labels. | Yes: JP and US/EU/DE are independently bounded, rebuilt, post-link-patched, and edit-tested; they are not treated as a shared scene. |
| Direct `func_080A2BA4` UI-scene BG streams | editable `graphics/ui/scene_080a2ba4/shared/tiles.4bpp` and `layer_*.tilemap`; read-only region-specific `reference/*/screen.png` | four native packed streams included directly by `gUnk_0874EF14`–`gUnk_0874F050`; palette remains archive-owned and is not editable | Yes for streams; palette reference only |
| Direct `func_080AE7D0` UI-scene BG streams | `graphics/ui/scene_080ae7d0/shared/tiles.4bpp`, `layer_*.tilemap`, `palette_banks.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams plus an independently bounded BGR555 palette, included directly by the four original `gUnk_0872FC34`–`gUnk_08731940` symbols | Yes |
| Direct `func_080B7164` UI-scene BG streams | `graphics/ui/scene_080b7164/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` | three native packed streams included directly by `gUnk_0872D5CC`–`gUnk_0872D6D8`; the 0x200 palette read begins at a 0x60 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080C160C` UI-scene BG streams | `graphics/ui/scene_080c160c/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams included directly by `gUnk_0873F3C8`–`gUnk_0873F6AC`; the 256-word palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080BCFAC` UI-scene BG streams | `graphics/ui/scene_080bcfac/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams included directly by `gUnk_0873BE24`–`gUnk_0873BFF0`; the 0x200 palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080B55D0` auxiliary BG streams | editable `graphics/ui/scene_080b55d0_aux/shared/tiles.4bpp` and `layer_*.tilemap`; read-only `reference/*.png` | three native packed streams included directly by `gUnk_0872C5D0`–`gUnk_0872C84C`; the 0x200 palette copy starts at a 0x20 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080B55D0` main tile stream | `graphics/ui/scene_080b55d0_main/shared/main_tiles.4bpp` | one shared native Huffman-8/LZ3 1024-tile stream, rebuilt in its original four-region 0x2198-byte slot; scene composition remains unproven | Yes for the tile stream; no guessed scene layout |
| Direct `func_08054F40` BG tile stream | `graphics/ui/scene_08054f40_tiles/shared/tiles.4bpp`; read-only `reference/base_layer_3.png` and `screen.png` | one native packed 4bpp tile stream included directly by the original `gUnk_08738D1C` symbol; static BG3 map and crossing palette copy are verified reference inputs | Yes for tile stream; reference inputs only |
| Direct `func_0805AB08` BG tile stream | `graphics/ui/scene_0805ab08_tiles/shared/tiles.4bpp`; read-only `reference/layer_*.png`, `scene.png`, and `screen.png` | one native packed 4bpp tile stream included directly by the original `gUnk_0872F21C` symbol; code-built three-BG maps and crossing palette copy are verified reference inputs | Yes for tile stream; reference inputs only |
| Farm-status non-winter background and building previews | `graphics/ui/farm_status/shared/base_tiles.png`, `base_palettes.png`, and `tilemaps/*.tilemap` | non-winter packed 4bpp tile stream, sixteen BGR555 palette banks, and fourteen BG tilemaps | Yes |
| Farm-status overseas winter background tiles | `graphics/ui/farm_status/winter/shared/tiles.png`; regional palette PNGs remain references | one bounded native packed tile stream included directly at the original US/EU/DE runtime labels | Yes for JP/US/EU/DE: JP retains its separate direct-ROM layout |
| Seasonal non-winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/shared/nonwinter_tiles.png`, `nonwinter_palette_banks.png`, and `bg_30/bg_29.tilemap`; derived layer references are under `reference/` | one H8/LZ2 tile stream, six BGR555 palette banks, and two native 30-by-13 BG maps at their original JP/US/EU/DE locations | Yes |
| Seasonal winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/winter/winter_tiles.png`, `winter_palette_banks.png`, and `winter_bg_29.tilemap`; BG30 reuses verified `shared/bg_30.tilemap` | one H8/LZ3 tile stream, six BGR555 palette banks, and the winter-exclusive native 30-by-13 BG29 map at their original JP/US/EU/DE locations | Yes |
| Farm-status secondary layouts | `graphics/ui/farm_status/shared/secondary_tilemaps/*.tilemap` | six native Huffman-4/LZ3 64-by-44 BG tilemap streams | Yes |
| Farm Status UI icon records | `graphics/ui/farm_status/creature_icons/shared/icon_00.png` through `icon_19.png` | twenty raw 16x16 4bpp grids with individual BGR555 palettes; physical order is retained because the set contains both animal-list states and the Harvest Sprite list's cake icon | Yes |
| Intro-scene object tile sources | `graphics/intro_scene/shared/object_tiles/*.4bpp` | twenty native Raw-LZ object-tile streams; see `intro_scene/OBJECT_PIPELINE_AUDIT.md` for the proven runtime/OAM boundary | Yes |
| Intro-scene startup background | `graphics/intro_scene/shared/startup_visual/*.png` and `shared/startup_tilemaps/*.tilemap` | one shared Huffman-8/LZ3 4bpp tile stream, sixteen BGR555 palette banks, and four native Huffman-4/LZ3 tilemap streams | Yes |
| Intro-scene indexed frame archive | `graphics/intro_scene/indexed_archive/{jp,us_eu,de}/full/*.png` | regional indexed archives with verified frame descriptors, OAM pieces, tiles, and BGR555 palettes; JP uses H4/LZ2 and US/EU/DE use H8/LZ2 | Yes |
| Records Screen task icons | `graphics/ui/records_minigame/shared/task_00.png` through `task_06.png` | seven raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| Animal Festival UI icons | `graphics/ui/animal_festival/shared/icon_00.png` through `icon_09.png` | ten raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| Direct-DMA raw UI records | `graphics/ui/raw_vram_tiles/*/shared/*.4bpp` and the paired `*.gbapal` records | twenty fixed-size raw 4bpp tile records and four BGR555 palette records; where the caller lacks a complete static layout, native source is retained rather than fabricating a PNG | Yes |
| MapData visual layers | `graphics/maps/shared/map_XX/layer_N.*`; derived inspection images are generated under `build/graphics/maps/reference/` | 272 native packed streams, post-link patched at their original ROM ranges | Yes |

The actor archive has 3,009 frame descriptors, of which 2,963 are referenced
by the retail animation tables.  Every referenced descriptor has a checked-in
complete PNG source.  The other 46 descriptor slots have no retail animation
caller and remain preserved native data rather than invented source images.

The Farm Status screen has a separate winter tile stream (`gUnk_0852AA6C` in
the overseas layouts). Its US/EU/DE bytes and decoded 4bpp tile data are
verified identical and now rebuild from one editable tile grid. The selected
palette is shared only by US/DE; EU has its own archive-wrapped palette
payload, which remains a read-only reference. Hash-checked readable references
live under `graphics/ui/farm_status/reference/winter/`; see
`DIRECT_UNPACK_VRAM_AUDIT.md` for the proven fixed-slot rebuild bounds.

## Build linkage

Most managed families are included from `asm/data/data_0813B288.s` through a
regional `build/<region>/graphics/...` output. MapData visual layers preserve
their original continuous archive position through a post-link replacement
step, because their 272 pointer-bearing streams are not a single assembly
incbin block. Most direct UI-scene streams use the same explicit post-link
replacement rule because their region-specific physical labels are embedded in
otherwise raw data containers. `func_080A2BA4`, `func_080AE7D0`,
`func_080B7164`, `func_080C160C`, `func_080BCFAC`, `func_080B55D0`,
`func_08054F40`, `func_0805AB08`, and the overseas-only `func_08077810` are
the current exceptions: their
independently bounded streams are included directly at the original `gUnk_*`
symbols. The
surrounding archive headers, OAM records, palettes, tables, and unhandled bytes
remain direct ROM data until they have a
corresponding verified source/rebuild path.

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
`DIRECT_UNPACK_VRAM_AUDIT.md` records the current code-consumer classification
and keeps unproven streams out of the managed-resource table.

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| Farm-status remaining screen data | `FarmStatusScreenResourceDescriptor` and direct ranges adjacent to the managed layouts. | The common tile grid, full palette-bank set, fourteen building-preview tilemaps and six secondary layouts are now managed; surrounding resource classes still need separate format analysis. |
| Intro-scene object OAM composition and palettes | `gUnk_IntroSceneUnpackSource_*` labels decode to twenty managed native 0x500-byte tile sources; `func_0805FBB8` stages them for OBJ use. `func_08000914`'s regional compressed archive and its shared raw companion archive are separately managed as OAM-composited frames. | The twenty streams remain native sources, but their own full-image OAM composition and per-object palette selectors remain runtime data. The nearby archives must not be treated as their layout; `intro_scene/OBJECT_PIPELINE_AUDIT.md` records the boundary. |
| Intro-scene startup presentation sequencing | `func_080019D8` expands the managed shared tiles/palette banks, and copies each of four managed `0x1000`-byte streams as two interleaved 32-by-32 BG maps. | Native tile sheet, palette banks, maps and eight code-backed map references are managed. Runtime selection and timing of alternate BG maps still need compositor/sequence analysis; no guessed final-screen PNG is treated as source. |
| Other Records-screen resources | Raw ranges adjacent to the task-icon records, plus page-specific data pointers in the Records Screen code. | The seven direct task icon/palette pairs are now managed; the remaining ranges still need independent consumer and format analysis. |
| MapData non-visual payloads | MapData fields 1 and 2 plus field-render records are used by field rendering. | The six visual pointer layers are managed as 272 verified streams. The remaining payloads may contain collision, terrain and animation data and require separate runtime format analysis. |
| Indexed resource archives | `IndexedResourceArchive` parses six counted descriptor sections and an entry table; its common and companion payloads are byte-identical across all four regions. | Exact boundaries and regional locations are recorded in `INDEXED_RESOURCE_ARCHIVES.md`. Descriptor semantics still require consumer-by-consumer analysis; neither archive is falsely exported as a graphics sheet. |
| Seasonal winter background | `func_08077EC0` selects paired non-winter/winter 0x8000-byte tile streams, six-bank palettes and two 30x13 tilemaps. | The winter `230` group is managed with its own tile grid, six palette banks and BG29 map; the shared BG30 source remains in the non-winter group. A verified 512-candidate native H8/LZ3 edit fits its immutable `0x212C` slot and strictly decodes. |
