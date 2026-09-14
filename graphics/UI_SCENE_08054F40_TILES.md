# `func_08054F40` direct OBJ tile stream

`func_08054F40` directly unpacks `gUnk_08738D1C` to `0x06000000`, the OBJ
tile-memory base. The decoded payload is exactly 328 4bpp tiles. The calling
code also stages other data through RAM and copies a palette range whose
declared label does not cover the full copied length; those other resources
are not claimed by this one-stream pipeline.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `tiles.4bpp` | `0xCA8` | `0x2900` (328 4bpp tiles) | `020`, ladder `2578101314` | `0x06000000` |

The stream is byte-identical in all four retail FoMT regions:

| Region | ROM offset |
| --- | ---: |
| JP | `0x4BEE84` |
| US | `0x738D1C` |
| EU | `0x738D78` |
| DE | `0x4C0088` |

There is not yet a proven OAM layout or wholly bounded palette for this
buffer, so `tiles.4bpp` remains the authoritative editable source. No guessed
full-image PNG is generated.

```console
make gfx-ui-scene-08054f40-tiles-all
make gfx-ui-scene-08054f40-tiles-patch-test
```

The normal ROM recipe rebuilds this stream after `objcopy` and patches only
its original regional interval. An unchanged source matches retail bytes
exactly; an edited source is rejected if its Raw-LZ encoding no longer fits
the original fixed slot.
