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

The C `fomt-lz` tool builds `shared/main_tiles.4bpp.lz` from the editable
`shared/main_tiles.4bpp` source. Its `rebuild-huff8-lz3` mode verifies the
tracked, byte-identical `shared/main_tiles.original.lz` publisher stream and
retains it while the decoded source is unchanged. Once the source changes,
the same C tool encodes a new Huffman-8/LZ3 stream, verifies its decoded
bytes, and enforces the fixed `0x2198` slot. The assembler includes the
result directly; no baseline ROM is read or patched in this production step.

```console
make gfx-ui-scene-080b55d0-main-all
```

`graphics/ui/scene_080b55d0_aux/` continues to own the separately proven
auxiliary maps and tile stream. Its reference PNGs are visual evidence only;
they are not source data for this main stream.
