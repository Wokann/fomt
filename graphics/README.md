# Graphics resources

This directory contains image resources that replace verified raw ROM ranges.
Source images are edited here; `make` rebuilds their GBA-native binary payloads
under `build/<region>/graphics/` before assembly.

`tools/gbagfx` is vendored from pokeemerald and performs PNG/indexed-GBA tile
and palette conversion.  FoMT also stores a single-width font as 8x12 1bpp
records, while GBA tile tools operate in 8x8 units.  `tools/fontpad` adds four
blank rows per glyph only for PNG conversion and validates those rows are blank
when converting back, so the assembled bytes remain exactly 12 bytes per glyph.

## First managed asset

`font/jp/single_width_font.png` is the original FoMT-JP single-width glyph
stream, displayed as a 16-column grid of 487 8x16 tiles. The bottom four rows
of each 16-pixel block are required padding and must remain transparent/blank.
The native ROM representation contains only the first twelve rows.

Rebuild and verify this asset without linking the whole ROM:

```console
make GAME_REGION=JP gfx-jp-font
```

The output must be 0x16D4 bytes.  Its SHA-256 for the verified Japanese retail
ROM is `92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c`.
