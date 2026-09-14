# Graphics resources

This directory contains image resources that replace verified raw ROM ranges.
Source images are edited here; `make` rebuilds their GBA-native binary payloads
under `build/<region>/graphics/` before assembly.

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

The PNG file itself is the authored resource; no JSON manifest controls its
name, layout, or conversion. The verified regional ROM interval is supplied
explicitly when regenerating a source image. For the single-width font the JP
interval is `0x7515A8`, length `0x16D4`; all four regions have the same
payload hash. Regenerate it with only Python's standard library plus the two
locally built graphics tools:

```console
python tools/extract_gfx.py font-1bpp \
  --rom baserom_jp.gba \
  --offset 0x7515A8 --length 0x16D4 \
  --sha256 92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c \
  --glyph-count 487 --glyph-width 8 --grid-columns 16 \
  --output graphics/font/shared/single_width_font.png \
  --gbagfx tools/gbagfx/gbagfx \
  --fontpad tools/fontpad/fontpad
```

For US / EU / DE the corresponding offsets are `0x4F90CC` / `0x4F9128` /
`0x71DDD4`; keep the remaining arguments identical. On Windows, use the
corresponding `.exe` paths (or invoke the script through `py -3`). The
extractor verifies the selected ROM range hash before touching the PNG; it
refuses an unverified or mismatched ROM instead of silently producing a
plausible but incorrect asset.

## Shared dialogue portraits

`portraits/shared` contains a complete indexed-resource archive for the 184
dialogue portraits. The normal authoring input is the fully composed colored
image in `full/`, for example `000_TALK_PORTRAIT_RICK_NORMAL.png`. It is an
indexed-color source, not merely an RGBA screenshot: preserving the palette
index is necessary because some native palettes contain visually identical
colors at different indexes. The `preview/` directory is a rendered reference
copy. `tiles/` preserves each descriptor's separate tile group for advanced
edits that must touch hidden OAM pixels directly. Ordinary art changes belong
only in `full/`; the verified native archive remains the single source for its
OAM layout and is not duplicated as editable metadata.

The 184 descriptors reference 1,037 OAM entries, 11,586 4bpp tiles and 52
palettes. The complete archive is byte-identical in JP, US, EU, and DE, even
though each ROM places it at a different address. The build rules declare
those physical positions directly; the common full-archive SHA-256 is:
`34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2`.

```console
make GAME_REGION=JP gfx-portraits
make gfx-portraits-all
```

`portrait_archive.py` rebuilds the native 0x5A840-byte tile stream from the
full source PNGs. It first renders the original archive, then writes only a
visible pixel that actually changed in `full/`; hidden OAM pixels therefore
remain untouched and an unedited source round-trips byte-for-byte. It verifies
every descriptor, OAM range, palette and PNG dimension. Sixty-eight tile slots
are intentionally shared between descriptors; if two edited source images
assign different values to such a slot, the build fails rather than arbitrarily
selecting one edit. The four regional assembly paths split their original
archive at the tile stream and retain every header, layout record, palette and
trailing byte around it.

## Actor animation frames

`sprites/actor_archive/full` contains every one of the 2,963 actor frame
descriptors referenced by the retail animation table.  Each source is named
`frame_NNNN.png`, where `NNNN` is the stable native frame-descriptor ID; it is
not a guessed tile position.  The older per-character READMEs retain verified
selector-to-frame notes for the groups already semantically identified.  The
files are not linear tile dumps: every image is composed from the native
animation entry, frame descriptor, OAM records, 4bpp tiles, and its selected
palette.

```console
make GAME_REGION=JP gfx-actors
make gfx-actors-all
```

`tools/actor_archive.py` reads those table relationships directly from the
retail archive; it has no manually maintained layout JSON.  During a rebuild,
it starts with the original complete 24,398-tile stream and changes only
visible pixels that differ from the source PNG.  OAM-covered pixels that are
not visible in the composited image remain byte-for-byte intact.  The rebuild
rejects changed PNG dimensions, palettes, OAM-out-of-bounds pixels, invalid
table references, and conflicting writes to a shared native pixel.  The full
actor archive and Rick's source frame payload are identical in JP, US, EU, and
DE; only their physical ROM offsets differ.

The complete actor animation stream now has one authoritative editable source
set.  Semantic actor names may be added later as documentation around their
native selector/frame IDs; they must not introduce duplicate editable PNGs.
Earlier guessed six-tile character-frame exports were removed and must not be
used as source material.



## Linear 4bpp tile grids

`tools/tile_grid.py` covers the other common case: a located graphics payload
whose tiles are stored left-to-right and top-to-bottom with no OAM or tile-map
indirection. It exports a strict indexed PNG and native BGR555 palette, then
rebuilds the same raw tile order. It requires an expected SHA-256 when reading
a ROM, so an incorrect offset cannot silently become authored art.

```console
python tools/tile_grid.py export baserom_us.gba \
  --tiles-offset 0x75B818 --tiles-length 0x120 \
  --palette-offset 0x75B938 --width 24 \
  --sha256 0ccf3327b9f4b30e2b1e47d763f56c9a15d8dff94ff3e44c79b8e87c89a8992c \
  --output build/tile_grid_probe/ui_shared_resource.png
python tools/tile_grid.py build \
  --source build/tile_grid_probe/ui_shared_resource.png \
  --tiles build/tile_grid_probe/ui_shared_resource.4bpp \
  --palette build/tile_grid_probe/ui_shared_resource.gbapal
```

`make tile-grid-test` runs that generic route against all four retail ROMs.

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
make gfx-intro-background-edit-test
```

Unchanged source preserves the retail `0x70` stream. An edited source is
repacked with the strict native-compatible encoder and must fit the original
`0x49BC`-byte allocation. The encoder's output need not reproduce the
publisher's compressed bitstream after an edit, but it is strictly unpacked
and tested before use. The other twenty Intro Scene 0x500-byte unpack inputs
remain unexported until their palette and display layout are independently
proven.

Regenerate the editable sources from a verified US ROM with:

```console
python tools/tile_grid.py export-unpacked baserom_us.gba \
  --stream-offset 0x743058 --stream-length 0x49BC \
  --stream-sha256 f0c828f16cafc75c3b277841bca74d1b7f62bbdf3551c9b591103c0f46213d4f \
  --tiles-length 0x6E00 --palette-offset 0x747A14 --width 320 --bpp 4 \
  --sha256 ee0ea9e581dab0baad7a55f2eed3c44dbc63518a2a5b8da5f79d4ef03d0b91c7 \
  --palette-sha256 7b7ceecd51340e503d145875c32b894e8ddfe22dd4d690820664e117fcc27ba3 \
  --output graphics/intro_scene/shared/background_tiles.png --replace

python tools/palette_banks.py export baserom_us.gba --offset 0x747A14 --banks 3 \
  --sha256 9d372a163a837204d61a996f95b8f894912cd6d7e4f49342fd07b810c2751d8e \
  --output graphics/intro_scene/shared/background_palettes.png --replace
```

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

This command rebuilds all four output directories and verifies each of the
fourteen generated ranges against all four ROMs.  See
`ui/records_minigame/README.md` for the exact source-regeneration command and
the reason no OAM or JSON sidecar is involved.

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
strictly unpacks its 0x4800-byte 4bpp payload. `palette_banks.py` preserves all
256 BGR555 entries, including palette entries that look alike but have distinct
native indices.

```console
make gfx-farm-status-all
make gfx-farm-status-edit-test
make gfx-farm-status-tilemaps-all
```

The first command verifies both generated ranges byte-for-byte against every
retail ROM.  An unchanged PNG deliberately reuses the original compressed
stream, so this verification stays exact. An edited tile source is rebuilt to
4bpp then encoded through `marvelous_codec.py`; the strict unpacker checks it again
and the build fails if it exceeds the original 0x21C4-byte allocation.  The
edit test changes one temporary source pixel and proves that a non-identical,
valid stream still fits.  No JSON layout sidecar participates in either path.

Regenerate the source from a verified US ROM with:

```console
python tools/tile_grid.py export-unpacked baserom_us.gba \
  --stream-offset 0x5275D0 --stream-length 0x21C4 \
  --stream-sha256 669dec9d78bbe0d2ceb08383495eea9da863086b00c7dbd4687d90e5c01cddc5 \
  --tiles-length 0x4800 --palette-offset 0x529794 --width 256 --bpp 4 \
  --sha256 0039e4aa2bb252d5ae17cb2028406e47a79c4461990ad6c1e7e384a962b719e8 \
  --palette-sha256 4538f7889f19367690ca80129ed8a36290924f4defb11261c57f4b095593ca48 \
  --output graphics/ui/farm_status/shared/base_tiles.png --replace

python tools/palette_banks.py export baserom_us.gba \
  --offset 0x529794 \
  --sha256 8d2885512b1f0a453e45d632c61a41be90d978f8614aa07109202a955da61303 \
  --output graphics/ui/farm_status/shared/base_palettes.png --replace

python tools/farm_status_previews.py \
  --tiles-source graphics/ui/farm_status/shared/base_tiles.png \
  --palettes-source graphics/ui/farm_status/shared/base_palettes.png \
  --tilemaps-source graphics/ui/farm_status/shared/tilemaps \
  --rom baserom_us.gba --region us --output graphics/ui/farm_status/reference --replace \
  --verify-jp baserom_jp.gba --verify-us baserom_us.gba \
  --verify-eu baserom_eu.gba --verify-de baserom_de.gba
```

Regenerate the native tilemap sources from a verified JP ROM only when
intentionally restoring the retail layout:

```console
python tools/farm_status_tilemaps.py export \
  --rom baserom_jp.gba --region jp \
  --output-dir graphics/ui/farm_status/shared/tilemaps --replace
```

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

After editing `full/`, refresh the convenient RGBA reference images with the
same in-memory rebuild and OAM compositor used by the build:

```console
python tools/portrait_archive.py baserom_jp.gba \
  --offset 0x2B3AE0 --length 0x5E0A4 \
  --sha256 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2 \
  render-full-preview --source graphics/portraits/shared
```

This only rewrites `preview/`; it does not modify the ROM, `full/`, OAM layout,
or `tiles/`.

Regenerate the source image from any verified retail ROM:

```console
python tools/portrait_archive.py baserom_jp.gba \
  --offset 0x2B3AE0 --length 0x5E0A4 \
  --sha256 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2 \
  audit

python tools/portrait_archive.py baserom_jp.gba \
  --offset 0x2B3AE0 --length 0x5E0A4 \
  --sha256 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2 \
  --names-header include/fomt_constants.mary.h \
  export --output graphics/portraits/shared
```
