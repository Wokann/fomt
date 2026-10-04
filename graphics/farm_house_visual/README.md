# FarmHouse visual resources

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`shared/visual_00.png` through `shared/visual_06.png` are the seven native-index
4bpp tile atlases selected by `gFarmHouseVisualDescriptors`.
The house setup branch at `0x080A924C` reads each descriptor's source pointer
at `+0x18`, passes it directly to `Unpack`, and obtains the destination tile
index from `+0x1C`.
The PNGs preserve the original linear tile order: 64, 63, 63, 159, 351, 63,
and 223 tiles. Their grayscale levels represent the sixteen pixel indices,
not an invented FarmHouse scene palette. The last grid cell in each
non-multiple-of-eight atlas is not a source tile. Ordinary gbagfx rules
generate `.4bpp` beside each PNG with its measured tile count; assembly
continues to include the corresponding `.4bpp.lz` file.

All seven original packed streams and all seven decoded payloads are
byte-identical in the JP, US, EU, and DE retail ROMs.  Their **addresses** are
not identical. `visual_01`, `visual_02` and `visual_05` use the generic C
`encode-huff4-lz2` encoder without reading `.original.lz`. Their retained
packed copies are independent comparison samples only. `visual_00`,
`visual_03` and `visual_06` now use source-only `encode-huff8-lz3`, with
`--greedy --tie=exchange` and ladders `1,4,8`, `1,8,11`, and `1,8,12`.
Their complete retail streams match without output-size padding, and their
obsolete templates are removed. Only `visual_04` still uses `rebuild-native`
with its original packing input; this unfinished Huffman-8/LZ2 dependency
must not be counted as completed. All resources are generated beside their
sources, without post-link patches.

| Stream | Codec | Decoded size | Original packed size | Build input |
| --- | --- | --- | --- | --- |
| `visual_00` | Huffman-8/LZ3 | `0x800` | `0x3C4` | Tiles only |
| `visual_01` | Differential-4-bit Huffman-4/LZ2 | `0x7E0` | `0x424` | Tiles only |
| `visual_02` | Differential-4-bit Huffman-4/LZ2 | `0x7E0` | `0x418` | Tiles only |
| `visual_03` | Huffman-8/LZ3 | `0x13E0` | `0xB9C` | Tiles only |
| `visual_04` | Huffman-8/LZ2 | `0x2BE0` | `0x16EC` | Tiles + original packing reference |
| `visual_05` | Huffman-4/LZ2 | `0x7E0` | `0x364` | Tiles only |
| `visual_06` | Huffman-8/LZ3 | `0x1BE0` | `0x10DC` | Tiles only |

Each descriptor also supplies two non-null native 16-bit tilemap patch
buffers.  They are exposed as
`shared/tilemap_patches/patch_NN_buffer_M.tilemap`: `func_080A5BD8` proves an
exact length of `descriptor.width * descriptor.height * 2` for each buffer
and copies it row by row into the live map.  All fourteen buffers are
byte-identical in JP, US, EU and DE; their physical positions are still read
from the selected region's descriptor table.  These are source tilemaps, not
a JSON layout description.

The files deliberately are not exported as full PNG scenes.  A descriptor
also references raw lookup, tile-patch and palette-copy domains; the runtime
copies several of those domains across adjacent physical labels.  The code
proves the seven `+0x18` streams are 4bpp tiles, but does not yet prove a
single independent static palette plus tilemap/OAM layout for each one.
Rendering a convenient full composite at this point would hide palette-bank,
lookup and runtime state information. Native-index tile atlases do not claim
such a composite and remain lossless editable sources.

`shared/palettes/palette_NN_buffer_M.pal`: ten independent JASC PAL sources
selected by the seven descriptors. Each is measured from the
descriptor's `palette_bank_count` (one 0x20-byte, 16-colour bank per count)
and copied by the retail DMA helper into `palette_bank`. Every colour was
checked for a clear unused high bit and each PAL round-trip reproduces the
original bytes. gbagfx generates `.gbapal` beside each PAL, independently
of the tile PNGs. This does not infer a static destination bank or layout.

The codec checks decoded output using the selected native format, filter and
distance ladder. WSL ROM comparisons verify all six directly encoded streams
against the retail bytes. The Huffman-8/LZ3 sources were additionally edited
in three ways each and verified through the native decoder.

The PNG, PAL and native tilemap files are authoring sources, not JSON
sidecars. A future full-scene renderer must first prove the runtime palette
and layout selection; it must not override these native-index atlases.
`LAYOUT_AUDIT.md` records the exact state-dependent tilemap-patch operation
and the remaining evidence needed for such a renderer.

Encoders with a nonzero slot still reject output beyond that declared size.
The three newly independent Huffman-8/LZ3 streams use slot zero: their natural
length is neither padded nor limited by the compressor. ROM growth is still
subject to the existing link boundaries and unresolved references elsewhere;
a codec round trip does not establish arbitrary layout-change safety.

七份房屋图块中六份已直接从源码编码，00、03、06 本次移除旧压缩模板；
仅 04 的 Huffman-8/LZ2 仍依赖模板。新编码流使用自然压缩长度，
不因此承诺整个未完成反编译的 ROM 可以任意扩展。
