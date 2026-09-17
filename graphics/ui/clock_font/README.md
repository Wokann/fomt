# Overseas clock and calendar glyphs

The overseas code copies the `gClockFont` resource as 128 individual
`0x20`-byte records, using `glyph_index << 5` as the source offset.  Each
record is one 8-by-8 indexed 4bpp glyph.  `us_eu/glyph_indices.png` and
`de/glyph_indices.png` show those records as a 16-column by 8-row tile grid.
The two overseas source families are deliberately separate: US and EU bytes
match exactly, while DE contains localized glyph data.

The PNG palette is an editor-only grey ramp that represents indices 0 through
15.  It is **not** the game's runtime palette, which has not been proven by
the direct-copy consumer.  Rebuilding deliberately ignores PNG palette
colours and preserves only tile indices.  `shared/tail.bin` is the final four
bytes of the native `0x1004`-byte record; it is retained verbatim instead of
being misrepresented as a glyph.

Build and verify the US, EU, and DE source ranges, then assemble the unchanged
JP/US/EU/DE data container with:

```console
make gfx-clock-font-all
make gfx-clock-font-edit-test
```

JP has no established equivalent `gClockFont` consumer, so its original
container bytes remain untouched.  This does not assert that JP lacks a clock
display; only that it does not share this proven overseas resource path.
