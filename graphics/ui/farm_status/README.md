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

The ordinary C `gbagfx` and `fomt-lz` tools produce `base_tiles.4bpp` and
`base_tiles.4bpp.lz` beside the PNG. The native Huffman-8/LZ3 encoder uses
ladder `4,8,13` and `--greedy --tie=exchange`, matching all 8644 retail bytes
directly from the current tile source, with no slot padding or compressed
template. The obsolete `shared/base_tiles.original.lz` is removed. Assembly
includes the complete packed resource at its actual entry in every region.
The old EU labels eight bytes into the stream were misplaced resource labels,
not separate header/payload objects; those labels and references are corrected.
The original packed stream occupies 0x21C4 bytes at JP 0x2AD72C, US 0x5275D0,
EU 0x52762C, and DE 0x2AE66C.

`shared/base_palettes.pal` is the editable sixteen-bank palette source;
`gbagfx` converts it to the adjacent `.gbapal` consumed by assembly. Palette
indices remain independent of tile pixels. The old swatch PNG is a preview,
not a palette input to the build.

`shared/tilemaps/` contains the fourteen authoritative native BG tilemaps:
the primary and alternate view for each farm house, coop, and barn level. Each
two-byte entry carries a tile ID, horizontal/vertical flip bits and a palette
bank, so a rendered PNG cannot losslessly replace it. These `.tilemap` source
files are deliberately direct native resources rather than a JSON layout
sidecar. `reference/` contains their convenient generated PNG previews.

`winter/shared/tiles.png` is the separate 256-by-144 native 4bpp source.
The shared C `encode-huff8-lz2` rule uses ladder `3,5,7,8,10,12,14` and
`--tie=exchange` to reproduce the complete `0x1FD4`-byte stream directly
from its `0x4800` source bytes. The old compressed template is removed.
Slot zero permits a natural packed length; includes consume the full output.
Every regional entry names the actual compressed-stream start. The adjacent
512-byte palette has identical bytes in all four regions and remains separate
from the tile stream.
The stream is byte-identical at JP 0x2B0BC8, US 0x52AA6C, EU 0x52AAC8,
and DE 0x2B1B08. JP's original 8148-byte `.byte` block now includes the same
generated resource at its actual `gUnk_0852AA6C` label. The earlier statement
that this stream was absent from JP was incorrect.

All fourteen payloads were verified byte-identical in JP, US, EU and DE.
The assembler includes each native resource at its actual label; C++ pointer
tables refer to these labels through ordinary relocations.

`shared/secondary_tilemaps/` contains the six other native 64-by-44 BG
tilemaps selected by `func_0806EC94`: two layouts, each containing three
screen-block layers. They are source-order arrays of 16-bit BG entries, not
rendered artwork or a sidecar layout description. Each shared
`.tilemap` is packed by the C codec, then included at its original runtime
label. All six encode directly from the editable tilemaps through the shared
suffix rule, without reading a compressed template.

`secondary_02` and `secondary_05` have identical 5632-byte source contents, but
keep their separate resource identities. Both use native Huffman-4/LZ3, ladder
widths `3,6,10`, and the generic `--tie=exchange` frequency sort. Their output is
the exact original 176 bytes, with no fixed-size padding. Both obsolete
`.original.lz` files have been removed. EU, like the other regions, includes
each complete generated stream at its actual entry.

`secondary_03` uses native Huffman-4/LZ3, ladder widths `3,8,12`, and
`--tie=heap-sort`. Its 5632-byte source encodes to the exact original 276 bytes,
without a compressed template or fixed-size padding. Its obsolete
`secondary_03.original.lz` has been removed. EU maps 03-05 now use their
actual stream-entry labels and include complete generated streams, without
an artificial split after eight bytes or a fixed byte count.

农场状态的六份附加地图均已从可编辑 `.tilemap` 直接编码，不读取压缩模板。
02、05 的源码内容相同，但保留各自的资源身份；通用交换排序策略将两份
5632 字节源码各自重压为原版的 176 字节，两份旧模板已移除。03 使用通用
Huffman 堆排序策略重压为原版的 276 字节。EU 的 02-05 压缩头和后续数据
都由生成的 `.lz` 提供，不再写死编码表头或截取固定长度。

主图块 base_tiles 也已用通用交换排序策略独立重压为原版 8644 字节，
其旧压缩模板已移除；三种实际图块修改均可准确往返。冬季图块的
Huffman-8/LZ2 同样从源码独立编码，旧模板移除。它的完整流也存在于
JP 的 0x2B0BC8，JP 已与其他三版一样引用生成资源；此前“海外独有”的
描述已更正。三种冬季源码修改均可准确往返。

Independent encoders with a nonzero slot size still reject packed output
larger than their declared slot. A zero slot size
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
palette bank 5 from `base_palettes.pal`. The existing C `gbagfx` tool converts
each PNG to an adjacent `.4bpp`; assembly then writes the native two-word
count header and includes the three styles in source order. No packing script
or layout sidecar is used.

All three original physical ranges are byte-identical across the four retail
ROMs, so one shared source tree is authoritative. The normal ROM compare checks
the complete linked layout and byte content.

`reference/winter/` contains historical preview exports. The earlier claim
that EU had a different palette behind an eight-byte header was caused by a
misplaced label: the actual 512-byte palette is identical in all four ROMs.
Those preview exports are not authoritative build inputs. The corrected
entry is the shared `gUnk_0852CA40` symbol, with no regional +8 adjustment.
