# `func_0805AB08` direct BG tile stream

`func_0805AB08` directly unpacks `gUnk_0872F21C` to `0x06000000`, BG
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
make gfx-ui-scene-0805ab08-tiles-patch-test
make gfx-ui-scene-0805ab08-reference
```

The normal ROM recipe rebuilds this stream after `objcopy` and patches only
its original regional interval. An unchanged source matches retail bytes
exactly; an edited source is rejected if its Raw-LZ encoding no longer fits
the original fixed slot.
