# Winter seasonal background

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

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
resources. The C `fomt-lz` tool directly encodes `winter_tiles.4bpp.lz` with
native Huffman-8/LZ3, ladder `4,10,13`, and `--greedy --tie=exchange`.
The complete original 8492-byte stream matches without fixed-size padding;
the obsolete `winter_tiles.original.lz` is removed. Assembly includes these
resources directly; the build neither reads a retail ROM nor patches the
linked image. The compressor uses natural output length, but growth remains
subject to the existing ROM boundaries and unresolved references.

Native decoder checks verify the original source and three edited sources.
Complete WSL comparisons verify all four regional ROMs. The PNGs under
`../reference/` were rendered from the same native tile
grid, palette banks and BG entries. They are inspection views, not build inputs
or a claim of the game's final composited screen.

季节背景的冬季图块已独立从当前源码重压为原版 8492 字节，旧模板移除；
不再补齐固定压缩槽，但未解析的 ROM 边界仍限制资源扩展。
