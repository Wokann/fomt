# Winter seasonal background

`func_08077EC0` selects this presentation when the season value is `3`.
The routine expands `winter_tiles.png` as an 0x8000-byte 4bpp H8/LZ3 stream,
copies the six BGR555 palette banks in `winter_palette_banks.png`, and copies
`winter_bg_29.tilemap` as its 30-by-13 BG29 map.  Its other map is not a
duplicate source: all four retail ROMs use byte-identical data already kept in
`../shared/bg_30.tilemap`.

The PNG inputs are indexed, not RGBA screenshots.  Keep `winter_tiles.png`
at 256 by 256 pixels with sixteen indices, and keep the palette swatch at
96 by 8 pixels with its six native banks in order.  `winter_bg_29.tilemap` is
the native 0x30C-byte map representation; it retains tile IDs, flips and
palette-bank selection that a flattened image would lose.

```console
make gfx-seasonal-winter-all
make gfx-seasonal-winter-edit-test
make gfx-seasonal-winter-reference
```

The first command verifies unchanged JP, US, EU and DE build outputs against
their original ROM ranges.  The second makes a one-byte source edit in memory,
strictly decodes the rebuilt native stream, and verifies that it fits the
immutable 0x212C-byte slot.  Any real edit that needs more than that slot is
rejected rather than overwriting the following resource.

The reference command writes `../reference/winter_bg_30.png` and
`../reference/winter_bg_29.png` from the same native tile grid, six palette
banks and BG entries.  They are code-bounded layer views for inspection, not
flattened build inputs and not a claim of the game's final composited screen.
