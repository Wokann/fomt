# `func_08054F40` direct BG tile stream

`func_08054F40` directly unpacks `gUnk_08738D1C` to `0x06000000`, BG
character block 0 (not OBJ VRAM). The decoded payload is exactly 328 4bpp
tiles. It also installs a 32-by-20 static BG3 map at `0x0600E000`, configured
by BG3CNT `0x1C43`. `reference/base_layer_3.png` and the viewport-cropped
`reference/screen.png` are therefore direct, code-backed views of the beach
base layer.

The routine's 0x200-byte palette copy begins at `gUnk_087399C4` and crosses
into the next labelled packed resource. It is validated as a runtime read but
is deliberately not an editable palette source. The tile stream remains the
authoritative editable/reversible source; the base image is a readable
reference, not a replacement layout format.

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

The later BG layers and dynamic calendar/menu data are updated through RAM at
runtime, so this does not claim to be the routine's whole final screen.

```console
make gfx-ui-scene-08054f40-tiles-all
make gfx-ui-scene-08054f40-tiles-patch-test
make gfx-ui-scene-08054f40-reference
```

The normal ROM recipe rebuilds this stream after `objcopy` and patches only
its original regional interval. An unchanged source matches retail bytes
exactly; an edited source is rejected if its Raw-LZ encoding no longer fits
the original fixed slot.
