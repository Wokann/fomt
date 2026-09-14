# `func_0805AB08` direct OBJ tile stream

`func_0805AB08` directly unpacks `gUnk_0872F21C` to `0x06000000`, the OBJ
tile-memory base. The decoded payload is exactly 358 4bpp tiles. Other streams
in the same initializer are staged in RAM before later copies, and its palette
copy starts from a label whose declared range does not cover the copied span;
they are intentionally outside this one-stream pipeline.

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

There is not yet a proven OAM composition or wholly bounded palette for this
buffer, so `tiles.4bpp` remains the authoritative editable source. No guessed
full-image PNG is generated.

```console
make gfx-ui-scene-0805ab08-tiles-all
make gfx-ui-scene-0805ab08-tiles-patch-test
```

The normal ROM recipe rebuilds this stream after `objcopy` and patches only
its original regional interval. An unchanged source matches retail bytes
exactly; an edited source is rejected if its Raw-LZ encoding no longer fits
the original fixed slot.
