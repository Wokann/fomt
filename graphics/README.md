# Graphics resources

This directory contains image resources that replace verified raw ROM ranges.
Source images are edited here; `make` rebuilds their GBA-native binary payloads
under `build/<region>/graphics/` before assembly.

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
make GAME_REGION=JP gfx-font
make gfx-fonts
```

`gfx-font` rebuilds the active region; `gfx-fonts` verifies all four regional
build paths. The single-width output is 0x16D4 bytes and hashes to
`92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c`.
The double-width output is 0x288F0 bytes and hashes to
`bb7ffb1ed47acb9a05d2789eae9f3236945a4892df746c5a4f9f1dde706c4d3e`.

The adjacent JSON manifests are the authoritative resource metadata: physical
ROM intervals per region, image layout, assembler symbol, and source hashes.
Regenerate a shared PNG from a verified retail ROM with only Python's standard
library plus the two locally built graphics tools:

```console
python tools/extract_gfx.py font-1bpp \
  --manifest graphics/font/shared/single_width_font.json \
  --region JP \
  --rom baserom_jp.gba \
  --gbagfx tools/gbagfx/gbagfx \
  --fontpad tools/fontpad/fontpad
```

Use `--region US`, `EU`, or `DE` with the matching ROM to independently audit
the other localizations. On Windows, use the corresponding `.exe` paths (or
invoke the script through `py -3`). The extractor verifies the selected ROM
range hash before touching the PNG; it refuses an unverified or mismatched ROM
instead of silently producing a plausible but incorrect asset.

## Shared dialogue portraits

`portraits/shared` contains a complete indexed-resource archive for the 184
dialogue portraits. The normal authoring input is the fully composed colored
image in `full/`, for example `000_TALK_PORTRAIT_RICK_NORMAL.png`. It is an
indexed-color source, not merely an RGBA screenshot: preserving the palette
index is necessary because some native palettes contain visually identical
colors at different indexes. The `preview/` directory is a rendered reference
copy. `tiles/` preserves each descriptor's separate tile group for advanced
edits that must touch hidden OAM pixels directly. `layout.json` is generated
from the verified archive and records the canvas origin and ordered OAM pieces
behind every complete image. It is an inspection contract, not a hand-edited
source: ordinary art changes belong in `full/`; an OAM layout change requires
a separate audited layout/repack step.

The 184 descriptors reference 1,037 OAM entries, 11,586 4bpp tiles and 52
palettes. The complete archive is byte-identical in JP, US, EU, and DE, even
though each ROM places it at a different address. `portrait_archive.json`
records every interval and the common full-archive SHA-256:
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

After editing `full/`, refresh the convenient RGBA reference images with the
same in-memory rebuild and OAM compositor used by the build:

```console
python tools/portrait_archive.py baserom_jp.gba \
  --manifest graphics/portraits/shared/portrait_archive.json \
  --region JP \
  --names-header include/fomt_constants.mary.h \
  render-full-preview --source graphics/portraits/shared
```

This only rewrites `preview/`; it does not modify the ROM, `full/`, OAM layout,
or `tiles/`.

Regenerate the source image from any verified retail ROM:

```console
python tools/portrait_archive.py baserom_jp.gba \
  --manifest graphics/portraits/shared/portrait_archive.json \
  --region JP \
  --names-header include/fomt_constants.mary.h \
  audit

python tools/portrait_archive.py baserom_jp.gba \
  --manifest graphics/portraits/shared/portrait_archive.json \
  --region JP \
  --names-header include/fomt_constants.mary.h \
  export --output graphics/portraits/shared
```
