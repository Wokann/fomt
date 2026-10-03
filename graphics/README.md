# Graphics resources

This directory contains image resources that replace verified raw ROM ranges.
Source images are edited here; `make` rebuilds their GBA-native binary payloads
under `build/<region>/graphics/`.

## Build inputs and reference images

Every managed resource has exactly one final-ROM delivery path:

- **Link-time inclusion.**  A source PNG, palette, tilemap, or native 4bpp
  source is converted under `build/<region>/graphics/`, then the owning C or
  assembly data object includes that binary.  This is the normal path for a
  continuous resource whose original data label is also its build boundary.
- **Bounded post-link replacement.**  A source is converted under the same
  build directory, then the final ROM recipe replaces only its independently
  verified original byte interval.  This is used for pointer-bearing MapData,
  region-local records embedded in larger raw containers, and direct-DMA
  records whose surrounding layout is not yet a standalone data object.
  The patch tool verifies both the input length and the target interval; it
  does not search for a matching byte sequence.
- **Reference only.**  Files below a `reference/` directory are readable
  renderings or extraction evidence.  They are never build inputs and cannot
  be used to regenerate ROM bytes.

The two build paths are equivalent in authority: both consume checked-in
editable sources and both are range-verified for JP, US, EU, and DE.  They
must not be applied to the same range twice.  `COVERAGE.md` records the
selected delivery path for every managed family.

For directly viewable complete images and code-backed static scene references,
see [VIEWABLE_REFERENCES.md](VIEWABLE_REFERENCES.md). It deliberately keeps
those readable views distinct from the native source formats used for rebuilds.

Run the complete managed-graphics verification gate with:

```console
make gfx-verify
```

It checks every currently managed payload against the appropriate retail ROM
range in JP, US, EU, and DE. It stops before a full ROM link; the project has
an unrelated C-source build failure outside the graphics path.

`tools/gbagfx` is vendored from pokeemerald and performs PNG/indexed-GBA tile
and palette conversion. FoMT fonts are 1bpp records with twelve active rows,
whereas GBA tile tools operate in 8x8 units. `tools/fontpad` adds four blank
rows per glyph only for PNG conversion and validates those rows are blank when
converting back. It also translates between FoMT's bit-7-first renderer order
and gbagfx's bit-0-first PNG order, so source PNGs are not horizontally mirrored
and the assembled bytes remain lossless.

## First managed asset

`font/shared/single_width_font.png` is the 487-glyph, 8x12 single-width stream,
displayed as a 16-column grid of 8x16 cells. `font/shared/double_width_font.png`
is the 6,922-glyph, 16x12 stream, displayed as a 32-column grid of 16x16 cells.
The bottom four rows in every cell are required padding and must remain blank.
The native ROM representation contains only the first twelve rows.

Byte-level audit of all four retail FoMT localizations establishes that both
streams are physically identical. The metadata records their distinct physical
ROM addresses: JP / US / EU / DE source addresses differ, but each range hashes
to the same authoritative payload. Therefore the project deliberately maintains
one editable PNG per stream rather than four redundant copies.

Rebuild and verify this asset without linking the whole ROM:

```console
make GAME_REGION=JP gfx-font-test
make gfx-fonts-test
```

`gfx-font` rebuilds the active region; `gfx-fonts` verifies all four regional
build paths. The single-width output is 0x16D4 bytes and hashes to
`92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c`.
The double-width output is 0x288F0 bytes and hashes to
`bb7ffb1ed47acb9a05d2789eae9f3236945a4892df746c5a4f9f1dde706c4d3e`.

The PNG files are the authored resources; no JSON manifest maps them onto
ROM ranges. The original single-width JP interval is `0x7515A8` with length
`0x16D4`; US / EU / DE use `0x4F90CC` / `0x4F9128` / `0x71DDD4`.
Use `make gfx-fonts-test` to compare rebuilt bytes with the four retail ROMs.
The old one-off ROM-to-PNG extraction script is not needed to build or check
the tracked source images.

## Shared dialogue portraits

`portraits/shared/native_tiles.png` is the editable 4-bit grayscale atlas in
the archive's physical tile order. Each grayscale value is a native palette
index, not the displayed RGB color. Its 11,586 native tiles include pixels
covered by OAM and pixels shared by several descriptors. The generic gbagfx
rule emits `native_tiles.4bpp` beside the PNG, excluding the fourteen unused
image-grid cells at the end. Edit palette indexes, not RGB-matched colors:
different indexes may intentionally have the same visible color.

The 52 independent palette banks are maintained in `palettes_00_15.pal`,
`palettes_16_31.pal`, `palettes_32_47.pal`, and `palettes_48_51.pal`.
`palette_trailer.pal` holds the separate, unindexed final bank referenced by
`gPortraitArchivePaletteTrailer`. Each PAL is converted directly to its
source-adjacent `.gbapal`; no palette is extracted from the atlas PNG.

`archive.inc` keeps the native order of the 184 selection records, 184
descriptors, 1,037 OAM entries, tiles, palette banks, trailing index table, and
palette trailer. All four regional assembly entries include this same file.
The complete archive is byte-identical in JP, US, EU, and DE; only its physical
ROM address changes. Its SHA-256 is
`34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2`.

`full/`, `preview/`, and `tiles/` are OAM-composited or per-descriptor
reference views, not additional build inputs. A shared native tile is authored
once in the atlas, so edits affect every descriptor that uses it; there is no
second image overlay or arbitration between conflicting frame copies.
The formal build does not assemble an intermediate baseline archive, invoke
Python, read a retail ROM, or apply a post-link patch for these portraits.

```console
make GAME_REGION=JP gfx-portraits
make gfx-portraits-all
```

`gfx-portraits-all` explicitly compares the generated tile interval and every
palette bank against all four retail ROMs. These are optional regression
checks; only PNG, PAL, archive tables, and the C converter are build inputs.
The obsolete complete-frame overlay edit test has been removed.

## Actor animation frames

`sprites/actor_archive/native_tiles.png` is the single 4-bit grayscale atlas for the
24,398 actor tiles, in their original physical order. The generic PNG rule
emits `native_tiles.4bpp` without the two unused image-grid cells.
`palettes_000_015.pal` through `palettes_160_161.pal` independently maintain
the 162 palette banks in numeric order, with at most sixteen banks per PAL.
The converter reads the actual color count, including the final two banks;
it does not pad them to another 256-color palette.

`archive.inc` retains the native animation table, 3,009 frame descriptors,
4,795 OAM entries, atlas, palette banks, and trailing timed-frame entries.
The same archive is directly included at its true position in every region;
no source-archive template or frame patch participates in the build.
Its complete SHA-256 is
`19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736`.

`full/frame_NNNN.png` provides OAM-composited reference images for the 2,963
descriptors used by animation selectors `0x000-0x9F6`. The other 46 descriptor
slots and their atlas pixels are preserved as explicit source data, not
recovered from a ROM during compilation. Existing character-specific READMEs
document identified selectors; guessed six-tile character exports must not
be used as source material.

```console
make GAME_REGION=JP gfx-actors
make gfx-actors-all
```

`gfx-actors-all` compares the generated atlas and all independent palette banks
against each regional ROM. Normal builds need only the grayscale-index atlas, PAL
sources, native archive tables, and gbagfx. The former Python full-frame overlay
and its dedicated edit-test script have been removed.



## Linear 4bpp tile grids

For a located graphics payload whose tiles are stored left-to-right and
top-to-bottom with no OAM or tile-map indirection, the indexed PNG is the
authoring source. The C `gbagfx` tool converts it to native 4bpp tiles and
BGR555 palette bytes; no Python tile-grid conversion runs in this build path.

```console
make graphics/ui/shared_resource/shared_resource.4bpp
make graphics/ui/shared_resource/shared_resource.gbapal
```

`make tile-grid-test` compares both generated files with all four retail ROMs.

## Code-backed UI scene previews

Some scenes consist of a native tile sheet, one or more BG tilemaps, and a
palette selected by code. The tilemap remains the editable source of truth
because a PNG alone loses tile IDs, flips and palette-bank information. Where
the consuming code proves all three inputs, the repository also commits a
readable rendered PNG. For example,
`ui/scene_080b7164/shared/palettes.png` contains the sixteen native palette
banks and `ui/scene_080b7164/reference/` contains the two actual rendered
256-by-256 layers plus their runtime-priority composition. The same verified
route now also covers `ui/scene_080bcfac/`, `ui/scene_080c160c/` (the last
loads its palette beginning at BG bank 1), and `ui/scene_080ae7d0/`.
Regenerate a reference set with:

```console
make gfx-ui-scene-080b7164-preview
make gfx-ui-scene-080bcfac-preview
make gfx-ui-scene-080c160c-preview
make gfx-ui-scene-080ae7d0-preview
```

This is not a guessed screenshot and does not use a JSON layout sidecar: the
renderer reads the same checked-in 4bpp tiles, native tilemap entries and
code-bounded palette used by the verified rebuild path.

Some code-proven views cannot safely become editable palette sources. For
`ui/scene_080a2ba4`, the loaded palette range is also consumed as an archive;
`reference/<region>/screen.png` is consequently a checked read-only rendering,
not an authoring input. Regenerate and validate all four views with:

```console
make gfx-ui-scene-080a2ba4-reference
```

`ui/scene_080b55d0_aux/reference/` follows the same read-only rule. Its two
visible BG maps depend on palette operations that overlap other resource
classes; the preview is a verified auxiliary-layer composition, not a claim to
show the routine's full final screen. Regenerate it with:

```console
make gfx-ui-scene-080b55d0-aux-reference
```

`ui/scene_08054f40_tiles/reference/` similarly exposes the routine's proven
static beach BG3 base. Its map and palette are runtime inputs rather than
editable sources: the map's packed encoder has not been independently
reconstructed and the palette copy crosses the next labelled resource. The
reversible 4bpp tile stream is included directly by the original
`gUnk_08738D1C` assembly symbol. Regenerate the checked preview for all four
retail regions with:

```console
make gfx-ui-scene-08054f40-reference
```

`ui/scene_0805ab08_tiles/reference/` is a further code-backed static view:
the initializer expands four row templates into three BG maps and configures
their priorities. Its palette copy also crosses a resource-label boundary, so
the PNGs are checked references while `tiles.4bpp` remains the editable source
included directly by the original `gUnk_0872F21C` assembly symbol. Regenerate
it with:

```console
make gfx-ui-scene-0805ab08-reference
```

`ui/scene_080ae7d0/shared/` is fully connected to the original loading code:
its two tilemaps, tile stream, and sixteen BGR555 palette banks are included at
`gUiResourcePageMap0`, `gUiResourcePageMap1`, `gUiResourcePageTiles`, and
`gUiResourcePagePalette`.
The rendered PNGs remain previews only; the native source files are the
authoritative editable inputs.

`ui/scene_08077810/shared/layer_0.tilemap` and `layer_1.tilemap` are native
overseas BG maps. US, EU and DE share the same Huffman-4/LZ3 and
Huffman-4/LZ0 streams, which are generated beside those sources and included
directly at `gSharedSceneBackgroundLayer0Tilemap` and
`gSharedSceneBackgroundLayer1Tilemap`. JP instead has a distinct
resource set in `ui/scene_08077810/jp/`. The maps remain native entries, not
guessed PNG composites:

```console
make gfx-ui-scene-08077810-all
```

## FarmHouse descriptor source buffers

The ten native BGR555 buffers in `farm_house_visual/shared/palettes/` are
included directly at their original assembly positions for JP, US/EU and DE.
The fourteen native 16-bit tilemap patches in the adjacent `tilemap_patches/`
directory follow the same direct-link rule. Two patches have identical bytes
but retain separate source files and physical positions because the descriptor
table addresses them separately.
The descriptor pointers continue to refer to those positions; the formal ROM
build does not copy these buffers through a generated directory or patch them
after linking. Independently compare both families with all four retail ROMs
using the C range verifier:

```console
make gfx-farm-house-tilemaps-all
make gfx-farm-house-palettes-all
```

## Map-state fallback palettes

`func_080A95A4` selects one of five state-dependent palette streams while
loading a `MapData` record.  Each stream strictly expands to fifteen complete
16-colour BGR555 banks (`0x1E0` bytes), so the authoritative editable sources
are the ordered native files
`map_state_palettes/shared/fallback_00.gbapal` through `fallback_04.gbapal`.
They are palette sources, not rendered PNGs: the routine does not prove an OBJ
layout, BG tilemap, or a final composited image.

JP, US, EU and DE use byte-identical source streams at different physical ROM
offsets. `tools/fomt_lz.c` compiles the native `.gbapal.lz` streams beside the
sources; assembly includes them directly without patching the linked ROM.
Rebuild and validate the exact fixed-slot Raw-LZ encoding with:

```console
make GAME_REGION=JP gfx-map-state-palettes-test
make GAME_REGION=JP compare
```

## Map-state native presentation templates

The map-state renderer also reads two much larger, uncompressed shared tables:
`map_state_templates/shared/map_state_palette_templates.bin` and
`map_state_templates/shared/map_state_tilemap_templates.bin`.  They are
byte-identical in JP, US, EU and DE, despite occupying different ROM ranges in
each localization.

The first is copied in fixed `0x60`-byte units into caller-owned palette
staging storage; the second is selected by map-state type and read as 16-bit
BG tilemap entries.  Neither path proves standalone record boundaries, a tile
sheet, or an owning palette for every entry.  Their authoritative editable
form therefore remains native binary rather than a guessed PNG or a JSON
layout sidecar. Both tables are now linked directly from these source files at
their original assembly positions. DE labels inside the tables remain at their
original offsets, so its source is included in bounded pieces around them.
The independent range test checks both sources against each original ROM;
there is no ROM-template build input or post-link patch:

| Source | JP | US | EU | DE | Size |
| --- | ---: | ---: | ---: | ---: | ---: |
| `map_state_palette_templates.bin` | `0x45D654` | `0x6D74F8` | `0x6D7554` | `0x45E594` | `0x4ECC` |
| `map_state_tilemap_templates.bin` | `0x464950` | `0x6DE7F4` | `0x6DE850` | `0x465890` | `0xC4E8` |

```console
make gfx-map-state-templates-all
```

## Shared UI tile grid

`ui/shared_resource/shared_resource.png` is the first production use of the
linear-grid converter. `UiSharedResourceData` identifies the resource as a
0x120-byte (24x24 pixel) VRAM tile grid followed by one 16-colour BGR555
palette. The exact tile and palette bytes are common to all four retail FoMT
localizations, while their locations differ: JP `0x4E0BA0` / `0x4E0CC0`, US
`0x75B818` / `0x75B938`, EU `0x75B874` / `0x75B994`, and DE `0x4E2D34` /
`0x4E2E54`. Their SHA-256 values are respectively
`0ccf3327b9f4b30e2b1e47d763f56c9a15d8dff94ff3e44c79b8e87c89a8992c` and
`4c62773b262255ca7aa361ffb127e7d1a36397b9057ab59ff44ba4d5ac357a2c`.

```console
make GAME_REGION=JP gfx-ui-test
make gfx-ui-all
```

The assembler consumes only the generated `shared_resource.4bpp` and
`shared_resource.gbapal` files for the selected localization. The original
surrounding archive bytes and its typed C++ table remain in place. Regenerate
the authored indexed PNG from a verified US ROM with:

```console
python tools/tile_grid.py export baserom_us.gba \
  --tiles-offset 0x75B818 --tiles-length 0x120 \
  --palette-offset 0x75B938 --width 24 \
  --sha256 0ccf3327b9f4b30e2b1e47d763f56c9a15d8dff94ff3e44c79b8e87c89a8992c \
  --output graphics/ui/shared_resource/shared_resource.png --replace
```

## Intro Scene background

`intro_scene/shared/background_tiles.png` is the original linear order of the
Intro Scene's 0x6E00-byte VRAM payload: 40 by 22 4bpp tiles (320 by 176
pixels). It is intentionally preserved as a tile source, rather than claimed
to be a final screen capture. The runtime loads it directly to VRAM in
`func_0805FBB8`; its display registers and later scene composition may crop or
combine it with other layers.

`background_palettes.png` is the immediately following three-bank BGR555
palette source. The swatch rows retain all 48 native palette indices. The
packed stream and all three palette banks are byte-identical in JP, US, EU,
and DE: stream locations are JP `0x4C91C0`, US `0x743058`, EU `0x7430B4`, DE
`0x4CA4CC`; palette locations are JP `0x4CDB7C`, US `0x747A14`, EU `0x747A70`,
DE `0x4CEE88`.

```console
make gfx-intro-background-all
```

Unchanged source preserves the retail `0x70` stream. An edited source is
repacked with the strict native-compatible encoder and must fit the original
`0x49BC`-byte allocation. The encoder's output need not reproduce the
publisher's compressed bitstream after an edit, but it is strictly unpacked
and tested before use.

## Intro Scene object tiles

`intro_scene/shared/object_tiles/object_00.4bpp` through `object_19.4bpp`
are the other twenty inputs passed through `Unpack` by `func_0805FBB8`. Every
source decodes to `0x500` bytes, and the runtime copies each into a fixed
object-tile staging slot before the later OBJ upload path. Their packed and
decoded bytes are identical in all four retail FoMT regions, so one shared
native source set is authoritative.

These files are deliberately **not** linear-grid or completed-sprite PNGs.
The native OAM layout and palette binding are still runtime data; exporting a
visually plausible sheet now would repeat the earlier invalid-frame problem.
The checked-in `.4bpp` files are lossless editable source data with no JSON
layout sidecar. A future verified OAM tool can build full PNG inputs from them
without replacing or guessing their native order.

```console
make gfx-intro-objects-all
```

The build preserves each original stream byte-for-byte while its source is
unchanged. After an edit it uses that stream's original Raw-LZ format and
distance ladder, strictly validates the decoded result, and rejects an edit
that no longer fits the native packed range.

Regenerate the editable sources from a verified US ROM with:

```console
python tools/tile_grid.py export-unpacked baserom_us.gba \
  --stream-offset 0x743058 --stream-length 0x49BC \
  --stream-sha256 f0c828f16cafc75c3b277841bca74d1b7f62bbdf3551c9b591103c0f46213d4f \
  --tiles-length 0x6E00 --palette-offset 0x747A14 --width 320 --bpp 4 \
  --sha256 ee0ea9e581dab0baad7a55f2eed3c44dbc63518a2a5b8da5f79d4ef03d0b91c7 \
  --palette-sha256 7b7ceecd51340e503d145875c32b894e8ddfe22dd4d690820664e117fcc27ba3 \
  --output graphics/intro_scene/shared/background_tiles.png --replace
```

The committed palette PNG is the editable source. The shared gbagfx rule
builds its source-adjacent `background_palettes.gbapal`; the four-region
verification target compares the result with each retail ROM.

## Records Screen task icons

`ui/records_minigame/shared/task_00.png` through `task_06.png` are seven
standalone 16x16 indexed 4bpp icon records.  Unlike a screen background,
each PNG retains the exact sixteen-colour palette attached to that individual
icon, and the Records Screen's C++ pointer table selects the display order.
The source files therefore use stable physical record indices rather than
invented gameplay labels.

The seven `0x80`-byte tile streams and immediately following `0x20`-byte
palettes are byte-identical in JP, US, EU and DE.  Their regional first tile
offsets are JP `0x4D7EB8`, US `0x751F0C`, EU `0x751F68`, DE `0x4D9428`, with
`0xA0` bytes per record.  The assembler replaces every one of these fourteen
pointer-table targets with a generated file for the selected region.

```console
make gfx-records-minigame-all
```

The generic `%.4bpp` and `%.gbapal` rules rebuild the shared outputs beside
their PNG sources; the audit then verifies all fourteen tile/palette ranges
against all four ROMs.  See
`ui/records_minigame/README.md` for the exact source-regeneration command and
the reason no OAM or JSON sidecar is involved.

## Farm Status Harvest Sprite task UI tile

`ui/farm_status/harvest_sprite_task_ui_tile/shared/harvest_sprite_task_ui_tile.png`
is a complete 8x8 indexed 4bpp OBJ tile.  The Farm Status initializer
uploads its single tile and adjacent BGR555 palette together, so this is a
genuine editable PNG source rather than a guessed tile arrangement.  It
rebuilds through:

```console
make gfx-farm-status-task-ui-tile-all
```

See `ui/farm_status/harvest_sprite_task_ui_tile/README.md` for the verified ROM
offsets and runtime evidence.

## Farm-status screen background tiles

`ui/farm_status/shared/base_tiles.png` is the 256x144 indexed 4bpp tile grid
loaded by `func_0806EC94`; `base_palettes.png` is its complete sixteen-bank
palette source. The tile grid deliberately uses palette bank zero only: native
BG tilemaps select the actual bank for every tile. This preserves the real
4-bit pixel indices instead of flattening them into an incorrect 8bpp image.

The seven building levels each have a primary and alternate native tilemap.
Their fourteen authoritative sources live in `shared/tilemaps/*.tilemap`.
These raw BG-entry streams are intentionally source files rather than JSON:
each `u16` retains the native tile ID, flip flags and palette-bank selector
that a rendered PNG cannot represent unambiguously. `reference/` contains all
fourteen convenient generated previews, rebuilt from the editable tile grid,
full palette-bank source and the checked-in tilemaps.

The packed 0x70 stream and the 0x200-byte BGR555 palette are identical in all
four retail FoMT regions.  Their physical locations are JP `0x2AD72C` /
`0x2AF8F0`, US `0x5275D0` / `0x529794`, EU `0x52762C` / `0x5297F0`, and DE
`0x2AE66C` / `0x2B0830`. `tile_grid.py` validates the compressed stream and
strictly unpacks its 0x4800-byte 4bpp payload. The shared gbagfx rule
converts the indexed palette PNG to all 256 BGR555 entries, including
entries that look alike but have distinct native indices.

```console
make gfx-farm-status-all
make gfx-farm-status-tilemaps-all
```

The first command verifies both generated ranges byte-for-byte against every
retail ROM.  An unchanged PNG deliberately reuses the original compressed
stream, so this verification stays exact. An edited tile source is rebuilt to
4bpp then encoded through `marvelous_codec.py`; the strict unpacker checks it again
and the build fails if it exceeds the original 0x21C4-byte allocation.
No JSON layout sidecar participates in either path.

Regenerate the source from a verified US ROM with:

```console
python tools/tile_grid.py export-unpacked baserom_us.gba \
  --stream-offset 0x5275D0 --stream-length 0x21C4 \
  --stream-sha256 669dec9d78bbe0d2ceb08383495eea9da863086b00c7dbd4687d90e5c01cddc5 \
  --tiles-length 0x4800 --palette-offset 0x529794 --width 256 --bpp 4 \
  --sha256 0039e4aa2bb252d5ae17cb2028406e47a79c4461990ad6c1e7e384a962b719e8 \
  --palette-sha256 4538f7889f19367690ca80129ed8a36290924f4defb11261c57f4b095593ca48 \
  --output graphics/ui/farm_status/shared/base_tiles.png --replace

python tools/farm_status_previews.py \
  --tiles-source graphics/ui/farm_status/shared/base_tiles.png \
  --palettes-source graphics/ui/farm_status/shared/base_palettes.png \
  --tilemaps-source graphics/ui/farm_status/shared/tilemaps \
  --rom baserom_us.gba --region us --output graphics/ui/farm_status/reference --replace \
  --verify-jp baserom_jp.gba --verify-us baserom_us.gba \
  --verify-eu baserom_eu.gba --verify-de baserom_de.gba
```

The native `.tilemap` sources are assembled directly in ROM order. They do
not require a Python-generated bundle; `make gfx-farm-status-tilemaps-test`
compares all 14 source records against each of the four retail ROMs.

## Experimental forward OAM compiler

`tools/oam_pack/oam_pack.c` is the separate C implementation used to recover
the original game's OAM-packing rules. It takes one indexed full PNG as the
only authored image input, emits 4bpp tile bytes, one 16-colour BGR555 palette,
and eight-byte GBA OAM templates, then renders the generated tile/OAM bytes
back to require an exact indexed-pixel match. It can also compare every emitted
stream with a selected portrait in a retail ROM. The ROM is a regression oracle
only; it is not read by the normal image build and no JSON layout is involved.

```console
make oam-pack
make oam-pack-test
make oam-pack-audit
tools/oam_pack/oam_pack.exe graphics/portraits/shared/full/000_TALK_PORTRAIT_RICK_NORMAL.png \
  --tiles build/jp/graphics/portrait_000.4bpp \
  --palette build/jp/graphics/portrait_000.gbapal \
  --oam build/jp/graphics/portrait_000.oam \
  --origin-x -24 --origin-y -72 --strategy canvas \
  --reference-rom baserom_jp.gba --reference-offset 0x2B3AE0 --portrait-id 0 \
  --reference-dump
```

The `canvas` profile has already reproduced the original tile stream, palette,
and six OAM entries for the Rick normal, surprised, and wedding portraits
byte-for-byte. `make oam-pack-test` compares the Rick normal profile with all
four retail localizations. The generalized `canvas` partitioner now produces
valid, exact visible indexed-pixel reconstructions for all 184 checked-in
portraits; `make oam-pack-audit` performs that full regression and reports
which entries additionally match the legacy tile/OAM bytes exactly. It
deliberately retains transparent tiles in its stable canvas.

The original asset stream demonstrates why a visible PNG cannot by itself
uniquely determine every legacy byte sequence: some records use transparent
padding outside the visible crop, overlapping rectangles, or a different
anchor/partition despite producing the same pixels. `dense` is a visible-tile
packing baseline; `opaque` avoids overlapping generated rectangles while still
covering every visible tile; and `canvas` partitions an entire source canvas
into legal GBA rectangles, including automatic transparent padding to 8x8
boundaries. Only a profile that passes the ROM comparison is eligible for a
byte-identical production resource class. The C tool reports the original
descriptor/OAM fields for each non-matching comparison, so further common
profiles can be added and validated without relying on a JSON layout file.

The legacy Python archive inspector is only an optional retail-ROM audit and
reference exporter. It is not the compositor used by the production build,
and its full-frame overlay commands do not edit the authoritative native
atlas. Export into a temporary directory so existing authored PNG/PAL sources
cannot be overwritten:

```console
python tools/portrait_archive.py baserom_jp.gba \
  --offset 0x2B3AE0 --length 0x5E0A4 \
  --sha256 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2 \
  audit

python tools/portrait_archive.py baserom_jp.gba \
  --offset 0x2B3AE0 --length 0x5E0A4 \
  --sha256 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2 \
  --names-header include/fomt_constants.mary.h \
  export --output /tmp/fomt_portrait_reference
```
