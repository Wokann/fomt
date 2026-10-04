# Farm Status graphics

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`shared/base_tiles.png` is the editable, linear 4bpp tile source. Its pixels
retain their native values from 0 through 15; it deliberately displays only
palette bank zero.

`shared/base_tiles.original.lz` is the checked-in native Huffman/LZ stream
for this tile grid. The ordinary C `gbagfx` and `fomt-lz` tools produce
`base_tiles.4bpp` and `base_tiles.4bpp.lz` beside the PNG; assembly includes
the packed resource directly. The source build does not read a retail ROM.
The packed stream occupies 0x21C4 bytes at JP 0x2AD72C, US 0x5275D0,
EU 0x52762C, and DE 0x2AE66C.

`shared/base_palettes.png` is the editable sixteen-bank BGR555 palette source.
Its 256 by 8 swatch arrangement is part of the source format: every row is
the indices 0 through 255, so changing a swatch changes that exact native
palette entry without renumbering any tile indices.

`shared/tilemaps/` contains the fourteen authoritative native BG tilemaps:
the primary and alternate view for each farm house, coop, and barn level. Each
two-byte entry carries a tile ID, horizontal/vertical flip bits and a palette
bank, so a rendered PNG cannot losslessly replace it. These `.tilemap` source
files are deliberately direct native resources rather than a JSON layout
sidecar. `reference/` contains their convenient generated PNG previews.

`winter/shared/tiles.png` is the separate 256-by-144 native 4bpp source used
by the overseas winter branch. It rebuilds the identical US/EU/DE tile stream
inside its original `0x1FD4`-byte slot; regional palette data remains
reference-only because EU stores it in a distinct archive.
`winter/shared/winter_tiles.original.lz` supplies the native codec header
and fixed-slot reference to the same C `fomt-lz` rule.
The winter stream occupies 0x1FD4 bytes at US 0x52AA6C, EU 0x52AAC8,
and DE 0x2B1B08; this specific resource is not present in the JP layout.

The tilemap build verifies all fourteen payloads are byte-identical in JP, US,
EU, and DE. The assembler then includes the selected regional bundle at each
original table label, preserving the C++ pointer table without relocation.

`shared/secondary_tilemaps/` contains the six other native 64-by-44 BG
tilemaps selected by `func_0806EC94`: two layouts, each containing three
screen-block layers. They are source-order arrays of 16-bit BG entries, not
rendered artwork or a sidecar layout description. The stream headers and the
EU-only eight-byte labels remain in the assembly source. Each shared
`.tilemap` is packed by the C codec, then included at its original runtime
label. All six encode directly from the editable tilemaps through the shared
suffix rule, without reading a compressed template.

`secondary_02` and `secondary_05` have identical 5632-byte source contents, but
keep their separate resource identities. Both use native Huffman-4/LZ3, ladder
widths `3,6,10`, and the generic `--tie=exchange` frequency sort. Their output is
the exact original 176 bytes, with no fixed-size padding. Both obsolete
`.original.lz` files have been removed; the EU map 02 header now comes from
the generated stream, and its payload include consumes the entire remainder.

`secondary_03` uses native Huffman-4/LZ3, ladder widths `3,8,12`, and
`--tie=heap-sort`. Its 5632-byte source encodes to the exact original 276 bytes,
without a compressed template or fixed-size padding. Its obsolete
`secondary_03.original.lz` has been removed. The EU headers for maps 03-05 are
included from the generated streams rather than hard-coded; their historical
header/payload labels remain at the real eight-byte boundary. The payload
includes consume the remainder of each generated stream, not a fixed byte count.

农场状态的六份附加地图均已从可编辑 `.tilemap` 直接编码，不读取压缩模板。
02、05 的源码内容相同，但保留各自的资源身份；通用交换排序策略将两份
5632 字节源码各自重压为原版的 176 字节，两份旧模板已移除。03 使用通用
Huffman 堆排序策略重压为原版的 276 字节。EU 的 02-05 压缩头和后续数据
都由生成的 `.lz` 提供，不再写死编码表头或截取固定长度。

Template-dependent streams and independent encoders with a nonzero slot size
still reject packed output larger than their declared slot. A zero slot size
does not pad or limit the output; ROM growth remains subject to each region's
existing linking and resource-reference constraints. An edited-stream round
trip alone does not prove that an arbitrary larger ROM layout is safe.

`shared/exterior_styles/` contains the three raw style groups selected by
`func_0806EC94`: `doghouse/`, `mailbox/`, and `window/`.  Each contains three
editable indexed 4bpp PNGs in native tile order.  Their dimensions are 16 by
16, 8 by 16, and 88 by 16 respectively; these are not arbitrary sheets.  The
runtime copies four doghouse tiles to BG IDs 22-25, two mailbox tiles to IDs
26-27, and twenty-two window tiles to IDs 0-21.  The corresponding Farm
Status maps prove their 2-by-2, 1-by-2, and 11-by-2 arrangements and select
palette bank 5 from `base_palettes.png`. The existing C `gbagfx` tool converts
each PNG to an adjacent `.4bpp`; assembly then writes the native two-word
count header and includes the three styles in source order. No packing script
or layout sidecar is used.

All three original physical ranges are byte-identical across the four retail
ROMs, so one shared source tree is authoritative. The normal ROM compare checks
the complete linked layout and byte content.

`winter/shared/tiles.png` is the editable native 4bpp tile grid selected by
`func_0806EC94` when the season is winter. Its pixel indices are shared by US,
EU and DE. The build preserves the retail format-`220` stream while this source
is unchanged; after an edit it emits a strictly decoder-compatible
Huffman-8/LZ3 stream and rejects any output that exceeds the original
`0x1FD4`-byte slot. Run the overseas byte check and the changed-pixel capacity
fixture with:

`reference/winter/tiles_us_de.png` and `palettes_us_de.png`, together with the
EU-specific `tiles_eu.png` and `palettes_eu.png`, remain verified readable
exports. The selected palette is identical only in US/DE; EU supplies a
different payload behind an eight-byte archive header, so the palette files
are deliberately references rather than editable build inputs. JP uses a
separate resource layout and remains direct ROM data in this family.
