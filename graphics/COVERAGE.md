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
| Overseas `func_08077810` BG and character streams | `graphics/ui/scene_08077810/shared/tiles.png`, `tiles_trailer.bin`, `layer_0.tilemap`, and `layer_1.tilemap` | editable full Huffman-8/LZ3 character stream (351 4bpp tiles plus an explicit two-byte non-tile trailer), Huffman-4/LZ3 32-by-32 map, and Huffman-4/LZ0 32-by-20 map, included directly by the original US/EU/DE labels | Yes for JP/US/EU/DE: JP has no corresponding consumers and remains direct ROM data |
| Direct `func_080A2BA4` UI-scene BG streams | editable `graphics/ui/scene_080a2ba4/shared/tiles.4bpp` and `layer_*.tilemap`; read-only region-specific `reference/*/screen.png` | four native packed streams included directly by `gUnk_0874EF14`–`gUnk_0874F050`; palette remains archive-owned and is not editable | Yes for streams; palette reference only |
| Direct `func_080AE7D0` UI-scene BG streams | `graphics/ui/scene_080ae7d0/shared/tiles.4bpp`, `layer_*.tilemap`, `palette_banks.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams plus an independently bounded BGR555 palette, included directly by the four original `gUnk_0872FC34`–`gUnk_08731940` symbols | Yes |
| Direct `func_080B7164` UI-scene BG streams | `graphics/ui/scene_080b7164/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` | three native packed streams included directly by `gUnk_0872D5CC`–`gUnk_0872D6D8`; the 0x200 palette read begins at a 0x60 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080C160C` UI-scene BG streams | `graphics/ui/scene_080c160c/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams included directly by `gUnk_0873F3C8`–`gUnk_0873F6AC`; the 256-word palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080BCFAC` UI-scene BG streams | `graphics/ui/scene_080bcfac/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three native packed streams included directly by `gUnk_0873BE24`–`gUnk_0873BFF0`; the 0x200 palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080B55D0` auxiliary BG streams | editable `graphics/ui/scene_080b55d0_aux/shared/tiles.4bpp` and `layer_*.tilemap`; read-only `reference/*.png` | three native packed streams included directly by `gUnk_0872C5D0`–`gUnk_0872C84C`; the 0x200 palette copy starts at a 0x20 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_08054F40` BG tile stream | `graphics/ui/scene_08054f40_tiles/shared/tiles.4bpp`; read-only `reference/base_layer_3.png` and `screen.png` | one native packed 4bpp tile stream included directly by the original `gUnk_08738D1C` symbol; static BG3 map and crossing palette copy are verified reference inputs | Yes for tile stream; reference inputs only |
| Direct `func_0805AB08` BG tile stream | `graphics/ui/scene_0805ab08_tiles/shared/tiles.4bpp`; read-only `reference/layer_*.png`, `scene.png`, and `screen.png` | one native packed 4bpp tile stream included directly by the original `gUnk_0872F21C` symbol; code-built three-BG maps and crossing palette copy are verified reference inputs | Yes for tile stream; reference inputs only |
| FarmHouse visual descriptor tiles, patches and palettes | `graphics/farm_house_visual/shared/visual_00.4bpp` through `visual_06.4bpp`, plus `shared/tilemap_patches/*.tilemap` and `shared/palettes/*.gbapal` | seven fixed native 0x70 tile streams, fourteen bounded 16-bit tilemap patch buffers, and ten exact BGR555 palette-source buffers selected by `gFarmHouseVisualDescriptors`; all are post-link patched at their original regional pointers | Yes for all managed payloads in JP/US/EU/DE; field lookup metadata and runtime layout remain intentionally unmanaged |
| Farm-status non-winter background and building previews | `graphics/ui/farm_status/shared/base_tiles.png`, `base_palettes.png`, and `tilemaps/*.tilemap` | non-winter packed 4bpp tile stream, sixteen BGR555 palette banks, and fourteen BG tilemaps | Yes |
| Farm-status overseas winter background tiles | `graphics/ui/farm_status/winter/shared/tiles.png`; regional palette PNGs remain references | one bounded native packed tile stream included directly at the original US/EU/DE runtime labels | Yes for JP/US/EU/DE: JP retains its separate direct-ROM layout |
| Seasonal non-winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/shared/nonwinter_tiles.png`, `nonwinter_palette_banks.png`, and `bg_30/bg_29.tilemap`; derived layer references are under `reference/` | one H8/LZ2 tile stream, six BGR555 palette banks, and two native 30-by-13 BG maps at their original JP/US/EU/DE locations | Yes |
| Seasonal winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/winter/winter_tiles.png`, `winter_palette_banks.png`, and `winter_bg_29.tilemap`; its BG30 map reuses the verified non-winter `shared/bg_30.tilemap` source; derived layer references are `reference/winter_bg_30.png` and `winter_bg_29.png` | one H8/LZ3 tile stream, six BGR555 palette banks, and the winter-exclusive native 30-by-13 BG29 map at their original JP/US/EU/DE locations | Yes |
| Farm-status secondary layouts | `graphics/ui/farm_status/shared/secondary_tilemaps/*.tilemap` | six native Huffman-4/LZ3 64-by-44 BG tilemap streams | Yes |
| Farm-status exterior styles | `graphics/ui/farm_status/shared/exterior_styles/{doghouse,mailbox,window}/style_*.png` | three raw style records, each retaining its two-u16 count header and three 4bpp variants | Yes |
| Farm-status selector case-09 icon | `graphics/ui/farm_status/shared/auxiliary_icons/selector_case_09.png` | one code-paired 16-by-16 4bpp tile record plus BGR555 palette | Yes |
| Overseas calendar/clock glyphs | `graphics/ui/clock_font/{us_eu,de}/glyph_indices.png`, with `shared/tail.bin` | 128 direct-copy 8-by-8 4bpp glyph records plus four retained bytes; the PNG palette is editor-only because runtime palette ownership remains unproven | Yes for US/EU/DE ranges; JP assembly remains unchanged because this overseas-only code path has no verified JP counterpart |
| Farm-status creature/UI icons | `graphics/ui/farm_status/creature_icons/shared/icon_00.png` through `icon_19.png` | twenty raw 16-by-16 4bpp grids with individual BGR555 palettes, preserved as two physical groups | Yes |
| Farm Status / Town Map OAM resources | `graphics/ui/farm_status/resource_archive/full/resource_000.png` through `resource_039.png` | one fixed `0xEA4` IndexedResourceArchive, preserving all selection, OAM, palette and descriptor bytes while updating only changed visible 4bpp pixels | Yes |
| Common OAM resources | `graphics/common_resource_archive/full/group_000.png` through `group_499.png`, excluding native-empty groups `316` and `429` | fixed `0x12848` IndexedResourceArchive; 498 full OAM-composited indexed PNGs preserve selector, OAM, palette and descriptor bytes while updating only visible 4bpp pixels | Yes |
| Small companion OAM resources | `graphics/small_companion_archive/full/group_000.png` through `group_015.png` | one fixed `0x840` IndexedResourceArchive; sixteen full OAM-composited indexed PNGs preserve selector, OAM, palette and descriptor bytes while updating only visible 4bpp pixels | Yes |
| Direct `gUnk_08697920` VRAM tile group | `graphics/ui/raw_vram_tiles/08697920/shared/tiles.4bpp` | one fixed raw 143-tile 4bpp range, DMA-patched after linking at the original regional offset; palette and layout remain unproven | Yes |
| Direct `gUnk_08698E14` / `gUnk_0869A0A4` field VRAM tile groups | `graphics/ui/raw_vram_tiles/{08698e14,0869a0a4}/shared/tiles.4bpp` | two fixed raw 143-tile 4bpp ranges selected by the field renderer; each is DMA-patched after linking at its original regional offset; palette and layout remain unproven | Yes |
| Direct `gUnk_086D5508` / `gUnk_086D6698` field VRAM tile groups | `graphics/ui/raw_vram_tiles/{086d5508,086d6698}/shared/tiles.4bpp` | two fixed raw 115-tile 4bpp ranges selected by the field renderer; each is DMA-patched after linking at the original regional offset; palette and layout remain unproven | Yes |
| Direct UI DMA tile groups | `graphics/ui/raw_vram_tiles/*/shared/tiles.4bpp` (see `ui/raw_vram_tiles/UI_DMA_TILES.md`) | eleven fixed raw 4bpp character-tile records, DMA-patched after linking at their original regional offsets; no palette or UI layout is claimed | Yes |
| Intro-scene object tile sources | `graphics/intro_scene/shared/object_tiles/*.4bpp` | twenty native Raw-LZ object-tile streams; see `intro_scene/OBJECT_PIPELINE_AUDIT.md` for the proven runtime/OAM boundary | Yes |
| Intro-scene startup background | `graphics/intro_scene/shared/startup_visual/*.png` and `shared/startup_tilemaps/*.tilemap` | one shared Huffman-8/LZ3 4bpp tile stream, sixteen BGR555 palette banks, and four native Huffman-4/LZ3 tilemap streams | Yes |
| Records Screen task icons | `graphics/ui/records_minigame/shared/task_00.png` through `task_06.png` | seven raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| Animal Festival UI icons | `graphics/ui/animal_festival/shared/icon_00.png` through `icon_09.png` | ten raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| MapData visual layers | `graphics/maps/shared/map_XX/layer_N.*` (4bpp tiles, BGR555 palette streams, and native tilemaps) | 272 native packed streams, post-link patched at their original ROM ranges | Yes |

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

The intro-scene startup group has four-region-verified tiles and sixteen
palette banks in `graphics/intro_scene/shared/startup_visual/`, plus eight
code-backed BG-map references in `graphics/intro_scene/reference/startup/`.
The full native group is managed: an unchanged `230` tiles source retains its
retail stream, and the checked one-byte edit fixture strictly decodes inside
the original fixed slot.  The PNG references remain views rather than layout
inputs; the native tilemaps are the editable layout source.

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
python tools/dma_vram_inventory.py . --csv build/dma_vram_inventory.csv
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
`DIRECT_DMA_VRAM_AUDIT.md` does the same for literal `func_08008F0C` copies;
it deliberately excludes indirect or runtime-computed DMA descriptors.

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| `func_080B55D0` main scene layout | Main `230` source plus its field display setup; see `graphics/ui/scene_080b55d0_main/README.md`. | The shared 1024-tile 4bpp main source is managed and fixed-slot editable. Its complete map, palette ownership, display priority and state ordering remain unproven together, so no guessed full-screen source PNG is emitted. |
| FarmHouse visual descriptor lookup/layout domains | `gFarmHouseVisualDescriptors`, `func_080A5BD8`, and the house setup branch at `0x080A924C`; see `graphics/farm_house_visual/LAYOUT_AUDIT.md` and `LOOKUP_AUDIT.md`. | Seven `+0x18` native 4bpp streams, fourteen state-dependent tilemap patches, and ten `+0x20` BGR555 palette buffers are managed. The `+0x10/+0x14` lookup pairs are proven four-region-identical field metadata, not palette data. No named state has all base-map, ordered patches and BG-display inputs proven, so no guessed static scene is authored. |
| Intro-scene object OAM composition and palettes | `gUnk_IntroSceneUnpackSource_*` labels decode to twenty managed native 0x500-byte tile sources; `func_0805FBB8` stages them for OBJ use. `func_08000914`'s regional compressed archive and its shared raw companion archive are separately managed as OAM-composited frames. | The twenty streams remain managed native sources, but their own full-image OAM composition and per-object palette selectors remain runtime data. The nearby archives must not be misused as their layout; `intro_scene/OBJECT_PIPELINE_AUDIT.md` records the boundary. |
| Intro-scene startup presentation sequencing | `func_080019D8` expands the managed shared tiles/palette banks, and copies each of four managed `0x1000`-byte sources as two interleaved 32-by-32 BG maps. | Native tile sheet, palette banks, maps and eight code-backed map references are managed. The runtime's choice and timing of the alternate BG maps still require a compositor/sequence audit, so no guessed final-screen PNG is treated as source. |
| MapData non-visual payloads | MapData `+0x18/+0x1C`, `GetMapData`, and field-render callers; see `MAP_NONVISUAL_AUDIT.md`. | The six visual pointer layers are managed as 272 verified streams. The remaining pair is proven as TerrainInfo lookup data plus one-byte terrain-index grids, not graphics; 63 maps have terrain pointers and 3 use null pointers. |
