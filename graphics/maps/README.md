# MapData visual resources

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

The first physically continuous MapData stream run is now linked from this
source tree, not copied from a ROM after linking. Its 42 streams are identical
in JP, US, EU, and DE and occupy these verified half-open ranges:

| Region | Start | End |
| --- | ---: | ---: |
| JP | `0x400244` | `0x41DA7C` |
| US | `0x67A0E8` | `0x697920` |
| EU | `0x67A144` | `0x69797C` |
| DE | `0x401184` | `0x41E9BC` |

`shared/map_data.inc` lists the real ROM order and labels. The ordinary
Make rules convert seven editable PNG tile sets to `.4bpp`, eleven editable
JASC palettes to `.gbapal`, and then use the shared `tools/fomt-lz` codec to
make the source-adjacent `.lz` files. The other 24 sources are native u16
`.tilemap` files, preserving tile indices, flip flags, and palette banks.
Twenty-eight streams now encode directly from their `.tilemap` or `.gbapal`
sources: map `08` layers `1`/`2`, map `09` layers `1`/`2`/`5`, and map `31`
layer `5`, plus map `44` and `45` layer `5` with the codec's 16-bit differential
filter. The same filter also directly encodes Raw-LZ2 tilemaps: map `08`
layers `4`/`5`, map `09` layer `4`, map `31` layer `4`, and maps `44`/`45`
layer `4`. The Raw-LZ0 map `15` and `36` layer `1` palettes use the same C
codec's retail greedy command strategy. Another ten map palettes and tilemaps
use the codec's Huffman-4/LZ3 greedy path with explicit same-frequency leaf
ordering. Map `09` layer `3` and map `40` layer `4` additionally use the generic
`--parent-first` Huffman tie policy: an internal subtree is merged before an
equally weighted leaf. This derives the tree from current literal frequencies;
it does not copy a tree or command stream from a reference file. All twenty-eight
rebuilt packed slots match the retail bytes exactly;
their `.original.lz` files are comparison references, not build inputs. The
other streams still use source-adjacent original packing metadata to preserve
exact output. No normal build reads `baserom`; an edit that cannot fit its
verified slot fails rather than overwriting a neighboring record.
The map resource test checks decoded content for all 42 streams and compares
all 28 directly encoded packed streams byte for byte against their audit copies.

The `gMapData` table references 272 distinct visual streams overall. The
remaining 230 are still present as original bytes in the assembly source;
they are **not** covered by this editable pipeline yet. In particular, the
next stream after this run ends at the start of a separate VRAM resource,
not at the following MapData pointer. Treating all 272 pointers as one
uninterrupted archive would overwrite that unrelated resource. Future runs
must be bounded from the actual decoder-consumed length and intervening ROM
labels before moving them into this direct-link workflow.

MapData fields 6 and 7 are terrain/interaction data, not image inputs.
