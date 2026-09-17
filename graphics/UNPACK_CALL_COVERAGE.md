# Static `Unpack` call coverage

`tools/unpack_inventory.py --coverage-csv` supplements the conservative
named-source report. It lists every statically visible `bl Unpack` call in the
checked-in assembly and marks a source as `<unresolved>` when the small
data-flow model cannot recover a direct `g*` symbol. It does not dereference
runtime pointers, guess a ROM range, or promote a decoded buffer to graphics.

Run the reproducible audit with:

```console
make unpack-coverage-inventory
```

The current four-region assembly contains 98 distinct static call sites. The
CSV may contain more rows because a control-flow join can conservatively retain
multiple named source alternatives for one call site. Of the 98 sites, 43 have
a table-derived or caller-derived source and are retained explicitly for review
rather than omitted from the inventory.

## Resolution of the current unresolved sites

| Source family | Static sites | Evidence and disposition |
| --- | ---: | --- |
| MapData visual layers and state branches | 13 | The JP and overseas map loaders obtain `MapData` fields at runtime. The six visual pointer layers are already bounded as 272 native map streams, while the state fallback branches use the five separately managed BGR555 palette streams. These sites do not identify a new independent ROM blob. |
| Farm House visual descriptors | 26 | The two regional Farm House render paths select descriptors from `gFarmHouseVisualDescriptors`. Their compressed resources, palettes, and tilemaps are already owned by the Farm House visual pipeline; the call sites are conditions selecting existing descriptor entries. |
| Intro Scene pointer tables | 3 | One site iterates the twenty `gIntroSceneUnpackSources` records; two regional startup sites select existing source arrays. The tile sources and startup presentation maps remain in their established native rebuild pipelines. |
| Generic caller-provided decoder | 1 | `func_0806EB70` accepts its compressed pointer from the caller and expands it into a temporary buffer before rearranging it for VRAM. The helper owns no ROM source itself, so it is not evidence of a separate graphics family. |

This resolves every currently static-but-not-direct-label call site to an
existing resource owner or to a generic, caller-owned decoding helper. It does
**not** prove that every runtime pointer source in the game is graphics; new
dynamic dispatch paths still require a consumer and physical-range audit before
entering the managed graphics pipeline.
