# Clock/status HUD glyphs

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

All four regions now define the real `gMapClockStatusGlyphTiles` array.
`src/map_clock_status.cc` uses ordinary indexed tile pointers; the remaining
native HUD functions reference this same symbol without regional aliases.

| Source family | Native start | Tiles | PNG layout |
| --- | --- | ---: | --- |
| JP | `0x084E03EC` | 31 | 31 columns by 1 row, 248 by 8 pixels |
| US / EU | `0x0875A440` / `0x0875A49C` | 128 | 16 columns by 8 rows, 128 by 64 pixels |
| DE | `0x084E195C` | 128 | 16 columns by 8 rows, 128 by 64 pixels |

The overseas table contains 128 individual `0x20`-byte records. Native
consumers use `glyph_index << 5` as the source offset when copying a record. Each
record is one 8-by-8 indexed 4bpp glyph.  `us_eu/glyph_indices.png` and
`de/glyph_indices.png` show those records as a 16-column by 8-row tile grid.
The two overseas source families are deliberately separate: US and EU bytes
match exactly, while DE contains localized glyph data.

JP uses the same decimal-digit and colon consumers, but has a shorter atlas.
`jp/glyph_indices.png` contains exactly 31 tiles with no padded image row.
Its 992 bytes end at `0x084E07CC`, where the independently named next resource
starts. The four halfwords immediately before the glyphs are separate map
data, not a font header. This boundary was checked against the project's
assembled data object; PNG-to-4bpp round trips preserve all bytes.

The PNG palette is an editor-only grey ramp that represents indices 0 through
15. It is **not** an exported game palette. The recovered HUD constructor and
shared C++ renderer identify a separate resource-archive palette upload to OBJ
palette RAM; that resource has not been converted into this PNG's authoring
palette. Rebuilding deliberately ignores PNG palette
colours and preserves only tile indices. Overseas `shared/tail.bin` is the final four
bytes of the native `0x1004`-byte record; it is retained verbatim instead of
being misrepresented as a glyph.

Build and verify through the ordinary regional targets:

```console
make -j4 GAME_REGION=JP compare
make -j4 GAME_REGION=US compare
make -j4 GAME_REGION=EU compare
make -j4 GAME_REGION=DE compare
```

The shared gbagfx rule converts each PNG to its source-adjacent
`glyph_indices.4bpp`. Assembly includes that tile data followed by the
four-byte `shared/tail.bin` overseas; JP has no such trailing word.
No dedicated clock-font build script or
intermediate combined binary is needed.

The PNG files are tracked authoring sources. Regional `glyph_indices.4bpp`
files remain beside them as ignored, regenerable build outputs.

The earlier overseas-only classification is superseded by the verified JP
consumer and physical boundary above. The one-time JP source conversion used
the existing assembled project bytes; normal builds read only the maintained
PNG and generated source-adjacent 4bpp file, not an original ROM or a template.

The HUD contains separate date and time buffers, each with eight tiles, a
shared-state handle, a dirty byte and a DMA upload node. DE uses an additional
fixed date-label tile and keeps its hour ones digit in the time buffer, shifting
the colon/minute element indices there. `include/map_clock_status.hh` models
the shared buffer and the actual regional array indices, without adding an
offset to a different region's pointer. JP's fixed glyph 20 initializes time
slot 3, while its weekday setter writes slot 2; these are distinct native slots.
