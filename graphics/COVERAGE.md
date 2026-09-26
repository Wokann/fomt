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
| Common OAM resource archive | `graphics/common_resource_archive/full/native.png` (1,624 native tiles) and `palettes_*.pal` (342 banks in 22 files); group PNGs are reference-only | generic `.4bpp`/`.gbapal` conversion and direct linking with original tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Small companion OAM archive | `graphics/small_companion_archive/full/native.png` (52 native tiles) and `native.pal` (two palette banks); group views are reference-only | generic `.4bpp`/`.gbapal` conversion and direct linking with original tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Small shared UI OAM archive | `graphics/ui/small_resource_archive/full/group_*.png` (3 drawable groups) | shared fixed `0x548`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Cooking UI OAM archive | `graphics/ui/cooking_resource_archive/full/native.png` and `native.pal`; two group PNGs are reference views | shared `0x598`-byte `IndexedResourceArchive`, directly linked from native-order tiles, palette, and source-owned tables; no ROM-template build or post-link patch | Yes |
| Menu UI OAM archive | `graphics/ui/menu_resource_archive/full/group_*.png` (8 drawable groups) | shared fixed `0x504`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Large shared OAM archive | `graphics/large_resource_archive/full/native.png` and three `palettes_*.pal`; 102 group PNGs are reference views | shared `0x6EA0`-byte archive; native tiles and 46 palette banks compile through generic rules and link with the original tables in `archive.inc` | Yes: no ROM-template build or post-link patch; four regional ROM SHA-1 checks pass. |
| Shared OAM archive `08725DA0` | `graphics/shared_resource_08725da0/full/native.png` and `native.pal`; 6 group PNGs are reference views | shared `0xF2C`-byte archive; 109 native tiles and two palette banks compile through generic rules and link with original ordered tables in `archive.inc` | Yes: no ROM-template build or post-link patch; four regional ROM SHA-1 checks pass. |
| Shared OAM archive `086F2FAC` | `graphics/shared_resource_086f2fac/full/native.png` (384 native tiles) and `native.pal` (four palette banks); group views are reference-only | generic `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `086FAA80` | `graphics/shared_resource_086faa80/full/native.png` (36 native tiles; group views are reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `0871ECAC` | `graphics/shared_resource_0871ecac/full/group_*.png` (4 drawable groups) | shared fixed `0x128`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0871EDD4` | `graphics/shared_resource_0871edd4/full/group_*.png` (4 drawable groups) | shared fixed `0x12C`-byte `IndexedResourceArchive`; one all-zero descriptor stays native and descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08527094` | `graphics/shared_resource_08527094/full/native.png` (4 native tiles; group views are reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `08726CCC` | `graphics/shared_resource_08726ccc/full/native.png` (48 native tiles; group view is reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `08727368` | `graphics/shared_resource_08727368/full/native.png` (22 native tiles; group views are reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; two all-zero descriptors remain native | Yes |
| Shared OAM archive `08727A74` | `graphics/shared_resource_08727a74/full/native.png` (49 native tiles; group view is reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; 36 flipped OAM entries remain native | Yes |
| Shared OAM archive `08728320` | `graphics/shared_resource_08728320/full/native.png` (107 native tiles; group views are reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `0872937C` | `graphics/shared_resource_0872937c/full/group_*.png` (3 drawable groups) | shared fixed `0xE4`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08729460` | `graphics/shared_resource_08729460/full/native.png` (330 native tiles; group views are reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `0872EE78` | `graphics/shared_resource_0872ee78/full/group_*.png` (4 drawable groups) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `08731B40` | `graphics/shared_resource_08731b40/full/group_*.png` (20 drawable groups) | shared fixed `0x6604`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873AE54` | `graphics/shared_resource_0873ae54/full/group_*.png` (2 drawable groups) | shared fixed `0x174`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873AFC8` | `graphics/shared_resource_0873afc8/full/native.png` (110 native tiles; group view is reference-only) | ordinary `.4bpp`/`.gbapal` conversion, then direct linking with native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Shared OAM archive `0873CCB4` | `graphics/shared_resource_0873ccb4/full/native.png` (12 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873CEAC` | `graphics/shared_resource_0873ceac/full/group_000.png` (4 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873CF90` | `graphics/shared_resource_0873cf90/full/group_*.png` (16 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873D234` | `graphics/shared_resource_0873d234/full/native.png` (24 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873D5FC` | `graphics/shared_resource_0873d5fc/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `0873DE44` | `graphics/shared_resource_0873de44/full/native.png` (56 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873E5B0` | `graphics/shared_resource_0873e5b0/full/native.png` (56 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0873ED1C` | `graphics/shared_resource_0873ed1c/full/native.png` (41 native tiles) and `full/palettes.pal` (two banks) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `087401A4` | `graphics/shared_resource_087401a4/full/native.png` (16 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `08740454` | `graphics/shared_resource_08740454/full/native.png` (6 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `087405A0` | `graphics/shared_resource_087405a0/full/native.png` (24 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `08740908` | `graphics/shared_resource_08740908/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087409E4` | `graphics/shared_resource_087409e4/full/native.png` (120 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0874EE38` | `graphics/shared_resource_0874ee38/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087506E0` | `graphics/shared_resource_087506e0/full/native.png` (36 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `0875352C` | `graphics/shared_resource_0875352c/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `08753608` | `graphics/shared_resource_08753608/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Shared OAM archive `087536E4` | `graphics/shared_resource_087536e4/full/native.png` (2 native tiles) | generic 4bpp/palette conversion and source-linked archive tables; no post-link patch | Yes |
| Shared OAM archive `08755154` | `graphics/shared_resource_08755154/full/group_*.png` (1 drawable group) | shared fixed `0xDC`-byte `IndexedResourceArchive`; descriptor, OAM and palette tables remain native layout data | Yes |
| Regional OAM archive `0875B444` | `graphics/regional_resource_0875b444/{jp,overseas}/full/group_*.png` (6 groups per domain) | JP and overseas tiles/palettes use one source-owned native table layout | Yes: direct-linked without this archive's Python ROM patch; four regional ROM SHA-1 checks pass. |
| Regional OAM archive `0871D51C` | `graphics/regional_resource_0871d51c/{jp,us,eu,de}/full/native.png` and `native.pal` | four native tile/palette sources directly included among their original selection, descriptor, OAM and index tables; `group_*.png` is reference only | Yes: direct-linked without this archive's Python ROM patch; all four regional ROM SHA-1 comparisons pass. |
| Regional OAM archive `08728208` | `graphics/regional_resource_08728208/{jp,overseas}/full/group_000.png` (three OAM groups share four tiles) | JP and overseas tiles/palettes use one source-owned native table layout | Yes: direct-linked without this archive's Python ROM patch; four regional ROM SHA-1 checks pass. |
| Regional OAM archive `0872BE64` | `graphics/regional_resource_0872be64/{shared,de}/full/group_*.png` (1 group per domain) | JP/US/EU share a fixed `0x76C` archive; DE uses a fixed `0x874` archive with one extra native layout record and eight extra tiles | Yes: both source domains rebuild byte-exactly; JP/US/EU/DE post-link patch and editable-source bounds tests all pass. |
| Regional OAM archive `0872DE44` | `graphics/regional_resource_0872de44/{shared,de}/full/group_*.png` (27 groups per domain) | JP/US/EU share a fixed `0x1034` archive; DE uses a fixed `0x10CC` archive with three extra native layout records and four extra tiles | Yes: both source domains rebuild byte-exactly; JP/US/EU/DE post-link patch and editable-source bounds tests all pass. |
| Regional OAM archive `08738144` | `graphics/regional_resource_08738144/{jp,us_eu,de}/full/group_*.png` (JP/DE: 3 groups; US/EU: 20 groups) | three independent native layouts: JP and DE share dimensions but not bytes; US/EU share a larger 20-group archive | Yes: every source domain is rebuilt, post-link-patched and editable-source-tested against all four regional bounds. |
| Regional OAM archive `0873A6E8` | `graphics/regional_resource_0873a6e8/{shared,de}/full/group_000.png` | JP/US/EU share one fixed `0x76C` source; DE has the same layout with different content | Yes: both source domains rebuild exactly and all four regional patch/edit tests pass. |
| Regional OAM archive `0873D6D8` | `graphics/regional_resource_0873d6d8/{shared,de}/full/group_000.png` | JP/US/EU share a fixed `0x76C` source; DE uses a fixed `0x874` archive with one extra native layout record and eight extra tiles | Yes: both source domains rebuild exactly and all four regional patch/edit tests pass. |
| Regional OAM archive `0874F34C` | `graphics/regional_resource_0874f34c/{jp,us_eu,de}/full/group_*.png` (22 groups per domain) | JP, US/EU and DE have independent fixed layouts: 92, 134 and 140 tiles respectively | Yes: every source domain rebuilds and is post-link-patched and editable-source-tested against the four original regional bounds. |
| Farm Status / Town Map OAM archive | `graphics/ui/farm_status/resource_archive/full/native_{0,1}.png` (73 native tiles) and `native.pal` (13 palette banks); group PNGs are reference-only | generic `.4bpp`/`.gbapal` conversion and source-linked native tables in `archive.inc`; no ROM template or post-link patch | Yes |
| Located UI tile grid | `graphics/ui/shared_resource/shared_resource.png` | 4bpp tiles plus BGR555 palette | Yes |
| `func_08077810` regional BG and character streams | Overseas: `graphics/ui/scene_08077810/shared/tiles.png`, `tiles_trailer.bin`, `layer_0.tilemap`, and `layer_1.tilemap`; JP: `graphics/ui/scene_08077810/jp/tiles.png` and `layer_1.tilemap` | US/EU/DE generate their shared character stream, palette, Huffman-4/LZ3 `layer_0` tilemap, and Huffman-4/LZ0 `layer_1` tilemap beside the editable sources with `gbagfx` and the reusable C codec. JP generates its distinct tiles, palette, and Huffman-4/LZ2 map the same way. All these resources link directly; this scene no longer has a Python build step or baserom build input. | All four ROM hashes match; the generated resources also match their unpatched ELF images at the regional ROM offsets. |
| Overseas `func_080A2BA4` UI-scene BG streams | editable `graphics/ui/scene_080a2ba4/shared/tiles.4bpp` and `layer_*.tilemap`; read-only overseas `reference/*/screen.png` | four native packed streams included directly by `gUiSceneBackgroundLayer0Tilemap`–`gUiSceneBackgroundTiles`; the byte-identical JP carrier exists only to preserve the data build and is not treated as this routine's runtime input; palette remains archive-owned and is not editable | Yes for streams; palette reference only |
| `func_080AE7D0` / JP `func_080AE208` UI-scene BG streams | `graphics/ui/scene_080ae7d0/shared/tiles.4bpp`, `layer_*.tilemap`, `palette_banks.png`; rendered `reference/layer_*.png` and `scene.png` | three C-compressed source-adjacent streams and one PNG-derived BGR555 palette, directly linked as `gUiResourcePageMap0`–`gUiResourcePagePalette` in all four regions | Yes |
| Direct `func_080B7164` UI-scene BG streams | `graphics/ui/scene_080b7164/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` | three C-compressed, source-adjacent streams directly linked under `gUiTwoLayerBackgroundMap0`–`gUiTwoLayerBackgroundTiles`; the 0x200 palette read begins at a 0x60 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080C160C` UI-scene BG streams | `graphics/ui/scene_080c160c/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three C-compressed source-adjacent streams directly linked as `gUiScene080C160C*`; the 256-word palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080BCFAC` UI-scene BG streams | `graphics/ui/scene_080bcfac/shared/tiles.4bpp`, `layer_*.tilemap`, and `palettes.png`; rendered `reference/layer_*.png` and `scene.png` | three C-compressed source-adjacent streams directly linked as `gUiScene080BCFAC*`; the 0x200 palette copy begins at a 0xC0 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080B55D0` auxiliary BG streams | editable `graphics/ui/scene_080b55d0_aux/shared/tiles.4bpp` and `layer_*.tilemap`; read-only `reference/*.png` | three C-compressed, source-adjacent `.lz` streams linked directly as `gUiLayeredSceneAuxMap0`–`gUiLayeredSceneAuxTiles`; the 0x200 palette copy starts at a 0x20 symbol and remains cross-resource ROM data | Yes for streams; palette reference only |
| Direct `func_080B55D0` main tile stream | `graphics/ui/scene_080b55d0_main/shared/main_tiles.4bpp` | one shared native Huffman-8/LZ3 1024-tile stream, rebuilt in its original four-region 0x2198-byte slot; scene composition remains unproven | Yes for the tile stream; no guessed scene layout |
| Direct `func_08054F40` BG tile stream | `graphics/ui/scene_08054f40_tiles/shared/tiles.4bpp`; read-only `reference/base_layer_3.png` and `screen.png` | one C-compressed, source-adjacent 4bpp tile stream included directly by `gBeachBackgroundTiles`; static BG3 map and crossing palette copy remain verified reference inputs | Yes for tile stream; reference inputs only |
| Direct `func_0805AB08` BG tile stream | `graphics/ui/scene_0805ab08_tiles/shared/tiles.4bpp`; read-only `reference/layer_*.png`, `scene.png`, and `screen.png` | one C-compressed, source-adjacent 4bpp tile stream included directly by `gUiThreeLayerBackgroundTiles`; code-built three-BG maps and crossing palette copy remain verified reference inputs | Yes for tile stream; reference inputs only |
| Farm-status non-winter background and building previews | `graphics/ui/farm_status/shared/base_tiles.png`, `base_palettes.png`, and `tilemaps/*.tilemap` | C-built source-adjacent `base_tiles.4bpp.lz` stream, sixteen BGR555 palette banks, and fourteen BG tilemaps | Yes |
| Farm-status overseas winter background tiles | `graphics/ui/farm_status/winter/shared/tiles.png`; regional palette PNGs remain references | C-built source-adjacent `winter_tiles.4bpp.lz` included at the original US/EU/DE runtime labels | Yes for US/EU/DE; JP has a separate layout |
| Seasonal non-winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/shared/nonwinter_tiles.png`, `nonwinter_palette_banks.png`, and `bg_30/bg_29.tilemap`; derived layer references are under `reference/` | one H8/LZ2 tile stream, six BGR555 palette banks, and two native 30-by-13 BG maps at their original JP/US/EU/DE locations | Yes |
| Seasonal winter background (`func_08077EC0`) | `graphics/ui/seasonal_background/winter/winter_tiles.png`, `winter_palette_banks.png`, and `winter_bg_29.tilemap`; BG30 reuses verified `shared/bg_30.tilemap` | one H8/LZ3 tile stream, six BGR555 palette banks, and the winter-exclusive native 30-by-13 BG29 map at their original JP/US/EU/DE locations | Yes |
| Farm-status secondary layouts | `graphics/ui/farm_status/shared/secondary_tilemaps/*.tilemap` | six native Huffman-4/LZ3 64-by-44 BG tilemap streams | Yes |
| Farm Status UI icon records | `graphics/ui/farm_status/creature_icons/shared/icon_00.png` through `icon_19.png` | twenty raw 16x16 4bpp grids with individual BGR555 palettes; physical order is retained because the set contains both animal-list states and the Harvest Sprite list's cake icon | Yes |
| Farm Status Harvest Sprite task UI tile | `graphics/ui/farm_status/harvest_sprite_task_ui_tile/shared/harvest_sprite_task_ui_tile.png` | one independently uploaded 8x8 OBJ tile with its adjacent BGR555 palette | Yes |
| Intro-scene object tile sources | `graphics/intro_scene/shared/object_tiles/*.4bpp` | twenty native Raw-LZ object-tile streams; see `intro_scene/OBJECT_PIPELINE_AUDIT.md` for the proven runtime/OAM boundary | Yes |
| Intro-scene main background | `graphics/intro_scene/shared/background_tiles.png` and `background_palettes.png` | C-built source-adjacent `background_tiles.4bpp.lz` stream and three BGR555 palette banks | Yes |
| Intro-scene startup background | `graphics/intro_scene/shared/startup_visual/*.png` and `shared/startup_tilemaps/*.tilemap` | one shared Huffman-8/LZ3 4bpp tile stream, sixteen BGR555 palette banks, and four native Huffman-4/LZ3 tilemap streams | Yes |
| Intro-scene indexed frame archive | `graphics/intro_scene/indexed_archive/{jp,us_eu,de}/full/*.png` | regional indexed archives with verified frame descriptors, OAM pieces, tiles, and BGR555 palettes; JP uses H4/LZ2 and US/EU/DE use H8/LZ2 | Yes |
| Records Screen task icons | `graphics/ui/records_minigame/shared/task_00.png` through `task_06.png` | seven raw 16x16 4bpp grids with individual BGR555 palettes; the runtime table uses a verified nonphysical presentation order | Yes; see `RECORDS_SCREEN_RESOURCE_AUDIT.md` |
| Animal Festival UI icons | `graphics/ui/animal_festival/shared/icon_00.png` through `icon_09.png` | ten raw 16x16 4bpp grids with individual BGR555 palettes | Yes |
| Direct-DMA raw UI records | `graphics/ui/raw_vram_tiles/*/{shared,jp,overseas}/*` | nineteen fixed-size raw 4bpp tile records and four BGR555 palette records; `087512ec` is split into JP and overseas source domains, while callers without a complete static layout retain native source rather than fabricating a PNG | Yes |
| MapData visual layers | `graphics/maps/shared/map_XX/layer_N.*` | First 42 streams direct-linked from editable PNG/palette or native tilemap sources; 230 remain original assembly bytes pending physical-boundary checks | Partial |

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
regional `build/<region>/graphics/...` output. The first 42 MapData streams
are now included directly from source-adjacent `.lz` files; the remaining
230 stay as original assembly bytes until their actual physical boundaries
are verified. Most direct UI-scene streams use the same explicit post-link
replacement rule because their region-specific physical labels are embedded in
otherwise raw data containers. `func_080A2BA4`, `func_080AE7D0`,
`func_080B7164`, `func_080C160C`, `func_080BCFAC`, `func_080B55D0`,
`func_08054F40`, `func_0805AB08`, and the overseas-only `func_08077810` are
the current exceptions: their independently bounded streams are included
directly at verified resource symbols. The
surrounding archive headers, OAM records, palettes, tables, and unhandled bytes
remain direct ROM data until they have a
corresponding verified source/rebuild path.

The direct-DMA raw UI profiles follow the bounded post-link route as well.  A
profile rebuilds one proven native 4bpp or BGR555 interval and the final ROM
recipe replaces only that interval after link.  It is deliberately not also
included by `data_0813B288.s`: one resource range has one authoritative
delivery path.

## Unclassified ROM ranges

Assembly no longer contains direct `baserom_*.gba` includes. The earlier
one-off scanners for those includes are therefore no longer part of the
toolset. Remaining unclassified resources must still be identified from
their consuming code, exact bounds, format and four-region byte round trip;
the absence of direct ROM includes does not mean every resource has an
editable source. The code-backed Unpack inventories remain available:

```console
python tools/unpack_vram_inventory.py . --csv build/unpack_vram_inventory.csv
make unpack-coverage-inventory
```

All generated CSV files are local audit artifacts, not source artwork. The
Unpack-to-VRAM inventory follows only simple literal
and register data flow in assembly, so its rows are code-backed resource leads,
not assertions about tile, palette, or OAM format. Run it with
`make unpack-vram-inventory`; the current assembly yields 44 such calls.
`DIRECT_UNPACK_VRAM_AUDIT.md` records the current code-consumer classification
and keeps unproven streams out of the managed-resource table.

`unpack-coverage-inventory` is deliberately broader than that conservative
named-source report: it records every static `bl Unpack` site and writes
`<unresolved>` when the source comes through a table or caller argument. It is
an audit queue, not an asset extractor. `UNPACK_CALL_COVERAGE.md` records how
the current unresolved sites map to already-bounded MapData, Farm House, Intro
Scene, or generic caller-owned paths.

## Audited runtime-delivery paths

The table below measures code paths rather than attempting a blind scan for
byte sequences that happen to resemble graphics.  A row is complete only when
the relevant scanner can recover the source boundary and the resulting source
is either rebuilt or explicitly retained as native data.  It is consequently
an auditable lower bound on coverage, not a claim that every unlabelled ROM
byte is visual data.

| Delivery path | Static result | Current disposition |
| --- | --- | --- |
| Label-bound `IndexedResourceArchive` | 51 bounded payloads: 42 shared and 9 regional byte domains | Every payload rebuilds from indexed-PNG sources or its explicitly separated regional source; see `INDEXED_RESOURCE_ARCHIVE_INVENTORY.md`. |
| Literal `Unpack` to VRAM | 44 calls, 37 distinct physical labels | Every recovered source is classified in `DIRECT_UNPACK_VRAM_AUDIT.md`; region-local symbols remain separate physical labels even when they belong to an already-managed logical resource group. Each source is either a verified editable pipeline, an archive-owned component, or an intentionally native-only resource whose image layout is not proven. |
| All static `Unpack` calls | 98 call sites; 43 table/caller-derived sources remain explicit | `UNPACK_CALL_COVERAGE.md` resolves every non-direct-label site to MapData, Farm House, Intro Scene, or a generic caller-owned decoder. The report does not invent source ranges for dynamic pointers. |
| Literal direct DMA to video RAM | 64 scanner-qualified calls, 47 distinct labels, plus one manually checked high-register call | Every recovered label is classified in `DIRECT_DMA_VRAM_AUDIT.md`. Raw tile and palette records retain their native source when no static tilemap/OAM layout exists. |
| Literal guarded RAM copies | 18 bounded paths, all to palette RAM | Every source is classified in `DIRECT_COPY_RAM_AUDIT.md`; a palette slice is not promoted to a standalone image unless its owning layout is proven. |
| MapData visual layers | 272 distinct native stream references; 42 direct-linked | The first physically continuous run is editable; the remaining 230 require individual physical bounds. Terrain, collision, and other non-visual fields remain outside the graphics pipeline. |
| MapData state-fallback palettes | 5 bounded Raw-LZ streams, each decoding to 15 BGR555 banks | Managed as ordered native palette sources. JP/US/EU/DE share byte-identical packed and decoded streams; every region is rebuilt and patched at its own original fixed slots. |
| Map-state native presentation templates | 2 bounded raw tables (`0x4ECC` palette-template bytes and `0xC4E8` 16-bit tilemap-template bytes) | Managed as shared native binary sources. The renderer proves fixed copy/entry formats but not independently authored tile or palette layouts, so no guessed PNG or layout sidecar is created. Every region is rebuilt and patched at its own original range. |
| Indirect map-state `Unpack` buffers | 17 labelled non-VRAM inputs, including five fallback payloads | `INDIRECT_UNPACK_AUDIT.md` records strict decode bounds for every input. The five regional map-state fallback payloads (overseas `func_080A95A4`) are managed native BGR555 palettes; the remaining staging data stays native until its consumer proves a visual format and layout. |

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| Farm-status remaining screen data | `FarmStatusScreenResourceDescriptor`, `func_0806EC94`, and the direct ranges adjacent to the managed layouts. | The complete runtime-presented set is now managed: base/winter tile grids, palette banks, fourteen building-preview tilemaps, six secondary layouts, three exterior-style groups, creature icons, and the Farm Status OAM archive. Adjacent blobs without a proven visual consumer remain native data; they are not misclassified as images. |
| Intro-scene object OAM composition and palettes | `gUnk_IntroSceneUnpackSource_*` labels decode to twenty managed native 0x500-byte tile sources; `func_0805FBB8` stages them for OBJ use. `func_08000914`'s regional compressed archive and its shared raw companion archive are separately managed as OAM-composited frames. | The twenty streams remain native sources, but their own full-image OAM composition and per-object palette selectors remain runtime data. The nearby archives must not be treated as their layout; `intro_scene/OBJECT_PIPELINE_AUDIT.md` records the boundary. |
| Intro-scene startup presentation sequencing | `func_080019D8` expands the managed shared tiles/palette banks, and copies each of four managed `0x1000`-byte streams as two interleaved 32-by-32 BG maps. | Native tile sheet, palette banks, maps and eight code-backed map references are managed. Runtime selection and timing of alternate BG maps still need compositor/sequence analysis; no guessed final-screen PNG is treated as source. |
| MapData non-visual payloads | MapData fields 6 and 7 (`terrain_data` and `terrain_map`) plus field-render records are used by field rendering. | The six visual pointer layers (fields 0--5) are managed as 272 verified streams. The remaining terrain payloads are verified field-interaction data, not image inputs. |
| Indexed resource archives | `IndexedResourceArchive` parses six counted descriptor sections and an entry table. | All 51 label-bound archive payloads are now rebuilt from fixed editable indexed-PNG sources and validated at their regional bounds. Exact boundaries, byte domains, and source paths are recorded in `INDEXED_RESOURCE_ARCHIVES.md`; gameplay semantics of individual groups remain neutral until each consumer is analysed. |
| Seasonal winter background | `func_08077EC0` selects paired non-winter/winter 0x8000-byte tile streams, six-bank palettes and two 30x13 tilemaps. | The winter `230` group is managed with its own tile grid, six palette banks and BG29 map; the shared BG30 source remains in the non-winter group. A verified 512-candidate native H8/LZ3 edit fits its immutable `0x212C` slot and strictly decodes. |
