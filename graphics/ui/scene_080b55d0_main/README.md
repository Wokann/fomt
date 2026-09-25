# `func_080B55D0` main tile source

`shared/main_tiles.4bpp` is the exact 32 KiB (1024-tile) 4bpp payload unpacked
by `func_080B55D0` before that routine constructs its additional UI layers.
It is an editable native tile source, rather than a guessed full-screen PNG:
the routine's base map, palette ownership, display priority, and state order
have not yet been proven together.

The packed `230` (Huffman-8/LZ3) source interval is byte-identical across all
four retail FoMT localizations:

| Region | ROM offset | Packed slot | Decoded source |
| --- | ---: | ---: | ---: |
| JP | `0x481160` | `0x2198` | `0x8000` |
| US | `0x6FB004` | `0x2198` | `0x8000` |
| EU | `0x6FB060` | `0x2198` | `0x8000` |
| DE | `0x4820A0` | `0x2198` | `0x8000` |

The current Python builder retains the publisher stream byte-for-byte when
the source is unchanged. For an edited source, it encodes Huffman-8/LZ3 and
requires the result to fit the `0x2198` slot. The C `fomt-lz` tool now
independently decodes and verifies this format for all four regions; it does
not yet encode it. Consequently this asset still depends on the Python
builder and post-link patch, and is **not yet** on the desired direct-link
resource path.

```console
make gfx-ui-scene-080b55d0-main-all
make gfx-ui-scene-080b55d0-main-patch-test
make gfx-ui-scene-080b55d0-main-edit-test
```

`graphics/ui/scene_080b55d0_aux/` continues to own the separately proven
auxiliary maps and tile stream. Its reference PNGs are visual evidence only;
they are not source data for this main stream.
