# `func_0805AB08` direct BG tile stream

`func_0805AB08` directly unpacks `gUiThreeLayerBackgroundTiles` to `0x06000000`, BG
character block 0 (not OBJ VRAM). The decoded payload is exactly 358 4bpp
tiles. It expands four 32-row template streams into three 32-by-32 maps at
`0x0600C800`, `0x0600D800`, and `0x0600E800`, configured as BG3, BG2, and
BG1 with priorities 3, 2, and 1. Its code-built static composition is rendered
as `reference/layer_*.png`, `reference/scene.png`, and the viewport-cropped
`reference/screen.png`.

The 0x200-byte palette copy begins at `gUnk_0872FA9C` and crosses later
labelled data, so it is validated only as a read-only runtime input. The tile
stream remains the authoritative editable/reversible source; reference PNGs
do not replace the native map or layout data.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `tiles.4bpp` | `0x880` | `0x2CC0` (358 4bpp tiles) | `020`, ladder `35710111214` | `0x06000000` |

The stream is byte-identical in all four retail FoMT regions:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4B5384` |
| US | `0x72F21C` |
| EU | `0x72F278` |
| DE | `0x4B6588` |

Later code updates the scene state, so the reference proves this initializer's
static three-BG result rather than claiming every later runtime frame.

```console
make gfx-ui-scene-0805ab08-tiles-all
make gfx-ui-scene-0805ab08-reference
```

The compiled C `fomt-lz` tool converts the editable tiles into a
source-adjacent `tiles.4bpp.lz` with the verified Raw-LZ2 ladder and fixed
slot size. The assembler includes it directly under
`gUiThreeLayerBackgroundTiles` in each region, with a normal object
prerequisite. The JP literal-pool pointer and overseas assembly use this
symbol. This stream no longer reads a baseline ROM or needs a post-`objcopy`
patch in the normal build. Unchanged tiles match all four retail ROMs
byte-for-byte; an edit that exceeds the current slot fails at conversion.
