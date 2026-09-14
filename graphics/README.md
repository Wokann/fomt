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
