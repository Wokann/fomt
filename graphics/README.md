# Graphics resources

This directory contains authored graphics sources and their source-adjacent
generated GBA payloads. Normal builds use source references and automatic
dependencies, not a separate per-family export, patch, or verification stage.

## Build inputs and reference images

PNG tile sources become `.1bpp`, `.4bpp`, or `.8bpp`; independent `.pal`
sources become `.gbapal`. Tilemaps and native records remain independent
sources rather than being reconstructed from a preview PNG. `archive.inc`
files preserve the actual ordered archive tables and include their generated
tiles and palettes. Compiled resources stay beside their authoring files;
`build/<region>` holds code objects, generated assembly, and compiler/linker
intermediates.

Each payload has one link-time delivery path through its actual C/C++ or
assembly reference. `scaninc` discovers assembly `.include` and `.incbin`
dependencies; the C preprocessor resolves headers and regional macros.
Missing resources are built by shared suffix rules in
`graphics_file_rules.mk`. Normal ROM recipes only link, use `objcopy`, and
apply the standard `gbafix` header/padding operation. They do not read
baserom or perform post-link resource replacement.

FoMT's native compression is implemented by the C tool `tools/fomt-lz`.
Source-only encoders use one shared `.lz` recipe with codec parameters as
target metadata. All four normal ROM dependency graphs now have zero
`.original.lz` inputs, and the template-rebuild suffix rules are removed.
Old packed samples that remain in the repository are independent audit data,
not build inputs. This does not make still-raw resource data semantic artwork
or prove that every resource reference is relocatable. Do not substitute the
GBA BIOS LZ format for FoMT's native format.

Files under `reference/` and OAM-composited `full/frame_NNNN.png` renderings
are reference views unless a local README explicitly identifies them as
authoring sources. In particular, actor and portrait archives are authored
as their native tile atlases, independent palette banks, and `archive.inc`
tables; rendered frames are not a second set of editable build inputs.

For directly viewable complete images and code-backed static scene references,
see [VIEWABLE_REFERENCES.md](VIEWABLE_REFERENCES.md). It deliberately keeps
those readable views distinct from the native source formats used for rebuilds.

Build and verify the selected region with:

```console
make -j4 GAME_REGION=JP compare
make -j4 GAME_REGION=US compare
make -j4 GAME_REGION=EU compare
make -j4 GAME_REGION=DE compare
```

These targets verify complete ROM SHA-1 values. To build just one resource,
request its actual output path, without adding a wrapper or an asset list:

```console
make NODEP=1 graphics/font/shared/single_width_font.1bpp
```

The old per-family `gfx-*` wrappers, Python extraction/preview/inventory
helpers, and their ROM-address verification recipes have been retired.
They can be recovered from Git revision `31411d1d` for reproducing an old
audit; they are not current project build dependencies. The format and
address investigations below, and linked older audit reports, retain their
historical observations rather than defining the present build workflow.

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

Rebuild this asset by requesting its actual output path, as shown above.
The single-width output is 0x16D4 bytes and hashes to
`92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c`.
The double-width output is 0x288F0 bytes and hashes to
`bb7ffb1ed47acb9a05d2789eae9f3236945a4892df746c5a4f9f1dde706c4d3e`.

The PNG files are the authored resources; no JSON manifest maps them onto
ROM ranges. The original single-width JP interval is `0x7515A8` with length
`0x16D4`; US / EU / DE use `0x4F90CC` / `0x4F9128` / `0x71DDD4`.
Use the four regional `compare` targets for full-ROM verification.
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
make NODEP=1 graphics/ui/shared_resource/shared_resource.4bpp
make NODEP=1 graphics/ui/shared_resource/shared_resource.gbapal
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

This is not a guessed screenshot and does not use a JSON layout sidecar: the
renderer reads the same checked-in 4bpp tiles, native tilemap entries and
code-bounded palette used by the verified rebuild path.

Some code-proven views cannot safely become editable palette sources. For
`ui/scene_080a2ba4`, the loaded palette range is also consumed as an archive;
`reference/<region>/screen.png` is consequently a checked read-only rendering,
not an authoring input. Regenerate and validate all four views with:

`ui/scene_080b55d0_aux/reference/` follows the same read-only rule. Its two
visible BG maps depend on palette operations that overlap other resource
classes; the preview is a verified auxiliary-layer composition, not a claim to
show the routine's full final screen. Regenerate it with:

`ui/scene_08054f40_tiles/reference/` similarly exposes the routine's proven
static beach BG3 base. Its map and palette are runtime inputs rather than
editable sources: the map's packed encoder has not been independently
reconstructed and the palette copy crosses the next labelled resource. The
reversible 4bpp tile stream is included directly by the original
`gUnk_08738D1C` assembly symbol. Regenerate the checked preview for all four
retail regions with:

`ui/scene_0805ab08_tiles/reference/` is a further code-backed static view:
the initializer expands four row templates into three BG maps and configures
their priorities. Its palette copy also crosses a resource-label boundary, so
the PNGs are checked references while `tiles.4bpp` remains the editable source
included directly by the original `gUnk_0872F21C` assembly symbol. Regenerate
it with:

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

The overseas scene's `tiles.4bpp` source is 11232 bytes, followed by the
actual two-byte `tiles_trailer.bin`. The generic C encoder's `--tail=FILE`
concatenates only these proven source parts before source-only Huffman-8/LZ3
encoding (`6,10,12`, `--greedy --tie=exchange`). Its complete 1272-byte retail
stream matches, including the trailer, and the old packing template is removed.
No concatenation helper script or additional archive directory is introduced;
JP continues to use its already independent, different resource set.

海外版这份图块的 11232 字节与真实两字节尾部由通用工具拼接后编码，
完整重压为原版 1272 字节；JP 使用不同的现有独立资源，不能混为一份。

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

## Map-state fallback palettes

`func_080A95A4` selects one of five state-dependent palette streams while
loading a `MapData` record.  Each stream strictly expands to fifteen complete
16-colour BGR555 banks (`0x1E0` bytes), so the authoritative editable sources
are the ordered PAL files
`map_state_palettes/shared/fallback_00.pal` through `fallback_04.pal`.
They are palette sources, not rendered PNGs: the routine does not prove an OBJ
layout, BG tilemap, or a final composited image.

JP, US, EU and DE use byte-identical source streams at different physical ROM
offsets. `tools/fomt_lz.c` compiles the native `.gbapal.lz` streams beside the
sources; assembly includes them directly without patching the linked ROM.

## Map-state native presentation templates

The renderer's palette-copy path proves a native `0x60`-byte unit, not a whole
`0x4ECC`-byte palette table. A later complete MapData audit established that
the old `map_state_palette_templates.bin` aggregate joined this prefix to 25
independent compressed map streams. Those streams now build from the normal
PNG/PAL/tilemap inputs, and the prefix remains explicit original-position data.
The misleading aggregate file is retired; see `maps/README.md` and
`CODE_ROM_LAYOUT.md` for actual stream boundaries.

`map_state_templates/shared/map_state_tilemap_templates.bin` remains a
separate native data container. The map-state type selects data read as
16-bit BG tilemap entries, but this does not establish the format of the
whole container: it also holds independently referenced tile-patch frame
resources. Individual record ownership is not yet fully resolved. Its source
is included in contiguous bounded pieces at the original positions in all
four regions, with actual labels at the 61 audited FarmHouse/FieldRender
resource boundaries, not container-start offset aliases. The same native
bytes remain authoritative pending structured extraction. It has no
ROM-template build input or post-link patch. The original aggregate ranges
are recorded below; the first
row is historical, not an assertion that its entire range is one table:

| Source | JP | US | EU | DE | Size |
| --- | ---: | ---: | ---: | ---: | ---: |
| `map_state_palette_templates.bin` | `0x45D654` | `0x6D74F8` | `0x6D7554` | `0x45E594` | `0x4ECC` |
| `map_state_tilemap_templates.bin` | `0x464950` | `0x6DE7F4` | `0x6DE850` | `0x465890` | `0xC4E8` |

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

The assembler consumes only the generated `shared_resource.4bpp` and
`shared_resource.gbapal` files for the selected localization. The original
surrounding archive bytes and its typed C++ table remain in place. Regenerate
the authored indexed PNG from a verified US ROM with:

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

Unchanged source preserves the retail `0x70` stream. An edited source is
repacked with the strict native-compatible encoder and must fit the original
`0x49BC`-byte allocation. The encoder's output need not reproduce the
publisher's compressed bitstream after an edit, but it is strictly unpacked
and tested before use.

## Intro Scene object tiles

`intro_scene/shared/object_tiles/object_00.png` through `object_19.png`
are twenty native tile atlases for the inputs passed through `Unpack` by
`func_0805FBB8`. Each 64-by-40-pixel grayscale PNG preserves 40 native tiles
and their sixteen pixel indices. The shared suffix rules generate adjacent
`.4bpp` and `.4bpp.lz` files; every decoded payload is `0x500` bytes.
The runtime copies each into a fixed
object-tile staging slot before the later OBJ upload path. Their packed and
decoded bytes are identical in all four retail FoMT regions, so one shared
native source set is authoritative.

These files are linear native-tile views, not completed-sprite PNGs. The
runtime OAM layout and palette binding remain unproven. Using a native tile
grid does not require inventing either: unchanged conversion preserves every
tile byte, and the grayscale view does not claim to be the game's palette.
A future verified OAM tool can build full-frame editing views without
replacing or guessing their native order. The old tracked `.4bpp` sources
are now generated files, and no JSON layout sidecar is used.

The build preserves each original stream byte-for-byte while its source is
unchanged. After an edit it uses that stream's original Raw-LZ format and
distance ladder, strictly validates the decoded result, and rejects an edit
that no longer fits the native packed range.

The background's committed `background_palettes.pal` is the editable color
table; its PNG is a reference view. The shared gbagfx rule builds the adjacent
`.gbapal` file, independently of the object-tile grayscale atlases.

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
`0x2AE66C` / `0x2B0830`. The source-only C Huffman-8/LZ3 encoder regenerates
the complete 0x21C4-byte packed stream from its 0x4800-byte 4bpp source with
ladder `4,8,13` and `--greedy --tie=exchange`. The shared gbagfx rule
converts the indexed palette PNG to all 256 BGR555 entries, including
entries that look alike but have distinct native indices.

The original compressed template has been removed; no unchanged-source
shortcut or Python encoder participates. Changed tile sources are encoded
with the same native C algorithm and checked by its decoder. The encoder's
zero slot size emits the natural packed length without padding or truncation;
the existing ROM link boundaries and unresolved references still constrain
layout changes. Full four-region builds reproduce the complete retail bytes.

The native `.tilemap` sources are assembled directly in ROM order, without a
Python-generated bundle. Normal four-region ROM comparisons cover all fourteen
source records.

The separate `winter/shared/tiles.png` stream also encodes directly with
Huffman-8/LZ2, ladder `3,5,7,8,10,12,14`, and the same `--tie=exchange` policy.
Its 0x4800-byte source reproduces all 0x1FD4 packed bytes in JP, US, EU, and
DE. JP now includes the same generated resource rather than raw `.byte` data.
The obsolete winter template and fixed payload-length clips are removed.

The nonwinter seasonal backdrop uses
`ui/seasonal_background/shared/nonwinter_tiles.png`. Its 0x8000-byte source
encodes to the exact 0x2298-byte native Huffman-8/LZ2 stream with ladder
`2,5,8,10,11,12,14` and `--tie=exchange`. Both seasonal tile sources retain
native indices; their palettes and maps remain separate runtime resources.

## Experimental forward OAM compiler

`tools/oam_pack/oam_pack.c` is the separate C implementation used to recover
the original game's OAM-packing rules. It takes one indexed full PNG as the
only authored image input, emits 4bpp tile bytes, one 16-colour BGR555 palette,
and eight-byte GBA OAM templates, then renders the generated tile/OAM bytes
back to require an exact indexed-pixel match. It can also compare every emitted
stream with a selected portrait in a retail ROM. The ROM is a regression oracle
only; it is not read by the normal image build and no JSON layout is involved.

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
