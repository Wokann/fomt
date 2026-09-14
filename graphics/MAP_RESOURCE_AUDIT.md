# Map resource audit

This document records boundaries established before any map resource is
exported as artwork.  It deliberately separates evidence from inference:
unverified map payloads remain direct ROM data.

## Confirmed record shape

`include/map_data.hh` defines 66 `MapData` records.  Each record contains:

| Offset | Field | Established role |
| --- | --- | --- |
| `0x00` | `compressed_layers[0]` | Primary tile-graphics stream: `func_080A5EA0` unpacks it directly to VRAM `0x06000000`. |
| `0x04`–`0x08` | `compressed_layers[1..2]` | Additional packed visual layers. `func_080A5DB8` always loads layer 1 and conditionally also loads layer 2 to caller-selected destinations; their exact tile/palette roles need further destination tracing. |
| `0x0C`–`0x14` | `compressed_layers[3..5]` | Three packed 16-bit BG tilemap layers. `func_080A5CC0` unpacks them into three destination buffers; if absent, it fills exactly `width * height * 2` bytes with `0x03FF`, proving a u16 tile-entry grid. |
| `0x18` | `terrain_data` | Table of four-byte terrain/interaction records. |
| `0x1C` | `terrain_map` | One-byte index grid into `terrain_data`. |
| `0x20` / `0x22` | `width` / `height` | Terrain grid dimensions. |
| `0x24` | `flags` | Map-level behavior flag; semantic value remains unverified. |

The runtime use in `func_080171F8` (`asm/game_state.s`) independently proves
the terrain fields: it reads `width * height` bytes from `terrain_map`,
multiplies each byte by four, and reads a corresponding word from
`terrain_data`.  These fields therefore cannot be converted to visual tiles
or folded into an image payload.  `func_080A5CC0`, `func_080A5DB8`, and
`func_080A5EA0` (`asm/code_809E804.s`) establish the three distinct visual
layer roles listed above.

## Four-region comparison

The actual `gMapData` pointer table was read from each matched retail ROM
(`fomt_jp.map`, `fomt_us.map`, `fomt_eu.map`, and `fomt_de.map` supply each
table address). Every non-null layer decompresses to byte-identical content
and uses the same native format/ladder in all four regions:

| Layer | Shared map records | Fixed decoded size / check |
| --- | --- | --- |
| 0 | 66 of 66 | `0x8000` bytes per map |
| 1 | 66 of 66 | `0x1E0` bytes per map |
| 2 | 66 of 66 | `0x1E0` bytes per map |
| 3 | 66 of 66 | exactly `width * height * 2` bytes |
| 4 | 66 of 66 | exactly `width * height * 2` bytes |
| 5 | 62 of 62 non-null records | exactly `width * height * 2` bytes; four records intentionally have no third map layer |

Thus map assets can use a single shared source tree while retaining
per-region packed outputs at their original physical ROM locations. The next
implementation step is a generated assembly include that splits the currently
aggregate map-data `incbin` ranges at these verified stream boundaries; it
must preserve every intervening non-map byte and retain the retail packed
stream verbatim for unchanged sources.

## Current status

* The six packed layer ranges, terrain-record table and terrain-index grid are
  all physically labelled in `asm/data/data_0813B288*.s` and referenced by
  `src/map_data.cc`.
* The labelled resources are not yet a managed graphics family. Across the
  table they include large `0x70` streams, short auxiliary tables, and raw
  data. Layer 0 and layers 3–5 now have verified graphics/tilemap roles;
  layers 1–2 still require exact tile/palette destination analysis.
* The earlier `unknown_types.hh::MapData` sketch has a speculative
  `packed_img`/palette/tile naming scheme.  It is not used as authoritative
  evidence for this pipeline; `map_data.hh` and the runtime access above are
  authoritative.

## Required evidence before a map family becomes editable

For each map layer family, establish all of the following before replacing an
original `incbin` range:

1. Exact compressed interval for JP, US, EU and DE, with the next label or
   pointer proving its end.
2. Native `Unpack` output size and format, plus its consumer's destination
   (VRAM, RAM tilemap, palette memory, or non-visual memory).
3. Tile dimensions, palette-bank association and tilemap layout where the
   output is graphical.
4. A source representation that preserves native ordering without JSON layout
   sidecars, a rebuild path, and four-region range-byte verification.

Until then, extraction previews may be retained only as reference images and
must not be used as authoritative editable sources.
