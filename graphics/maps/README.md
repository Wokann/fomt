# MapData visual resources

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
Each `.original.lz` records the original packing parameters and fixed slot
size; it is not read from `baserom` during a normal build. An unchanged
source reproduces the original stream exactly. An edit that cannot fit its
verified slot fails the build rather than overwriting a neighboring record.

```console
make -j4 gfx-map-resources-test
make -j4 fomt_jp fomt_us fomt_eu fomt_de
```

The `gMapData` table references 272 distinct visual streams overall. The
remaining 230 are still present as original bytes in the assembly source;
they are **not** covered by this editable pipeline yet. In particular, the
next stream after this run ends at the start of a separate VRAM resource,
not at the following MapData pointer. Treating all 272 pointers as one
uninterrupted archive would overwrite that unrelated resource. Future runs
must be bounded from the actual decoder-consumed length and intervening ROM
labels before moving them into this direct-link workflow.

MapData fields 6 and 7 are terrain/interaction data, not image inputs.
