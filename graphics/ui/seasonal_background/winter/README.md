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

`gbagfx` converts the PNGs into source-adjacent `.4bpp` and `.gbapal`
resources. The C `fomt-lz` tool then builds `winter_tiles.4bpp.lz`, preserving
the checked-in publisher stream for unchanged pixels. Assembly includes these
resources directly; the build neither reads a retail ROM nor patches the
linked image. Edited streams must fit the original 0x212C-byte slot.

```console
make gfx-seasonal-winter-test
```

This command verifies that the generated stream decodes to the editable tile
source. The PNGs under `../reference/` were rendered from the same native tile
grid, palette banks and BG entries. They are inspection views, not build inputs
or a claim of the game's final composited screen.
