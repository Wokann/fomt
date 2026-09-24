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
make gfx-ui-scene-08054f40-reference
```

The compiled C `fomt-lz` tool converts the editable tiles into a
source-adjacent `tiles.4bpp.lz` with the verified Raw-LZ2 ladder and fixed
slot size. `asm/data/data_0813B288.s` includes that output directly under
`gBeachBackgroundTiles` in each region, and the assembler object depends on
the generated file. The JP literal-pool call and overseas assembly use this
symbol; the DE resource is included at its native location. This stream no
longer reads a baseline ROM or uses a post-`objcopy` patch during the normal
build. Unchanged tiles match all four retail ROMs byte-for-byte; an edit that
exceeds the current slot fails at resource conversion.
