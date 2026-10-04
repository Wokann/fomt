# `func_080B55D0` main tile source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

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
`shared/main_tiles.4bpp` source with source-only `encode-huff8-lz3`, ladder
`4,10,12`, and `--greedy --tie=exchange`. All 8600 retail bytes match without
fixed output padding, and three actual source edits decode exactly. The
obsolete `shared/main_tiles.original.lz` is removed. The assembler includes
the result directly; no baseline ROM, saved tree or post-link patch is used.
The compressor uses natural output length; existing ROM boundaries and
unresolved references still constrain larger changes.

`graphics/ui/scene_080b55d0_aux/` continues to own the separately proven
auxiliary maps and tile stream. Its reference PNGs are visual evidence only;
they are not source data for this main stream.

主图块现由通用编码器独立生成原版 8600 字节，旧模板已移除；
辅助地图与图块仍由相邻的独立主题维护，不以本项扩大完成量。
