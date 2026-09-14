# Map resource audit

This document records boundaries established before any map resource is
exported as artwork.  It deliberately separates evidence from inference:
unverified map payloads remain direct ROM data.

## Confirmed record shape

`include/map_data.hh` defines 66 `MapData` records.  Each record contains:

| Offset | Field | Established role |
| --- | --- | --- |
| `0x00`–`0x14` | `compressed_layers[6]` | Six independent packed render-layer sources selected by map state.  Their individual layer semantics are not yet named. |
| `0x18` | `terrain_data` | Table of four-byte terrain/interaction records. |
| `0x1C` | `terrain_map` | One-byte index grid into `terrain_data`. |
| `0x20` / `0x22` | `width` / `height` | Terrain grid dimensions. |
| `0x24` | `flags` | Map-level behavior flag; semantic value remains unverified. |

The runtime use in `func_080171F8` (`asm/game_state.s`) independently proves
the terrain fields: it reads `width * height` bytes from `terrain_map`,
multiplies each byte by four, and reads a corresponding word from
`terrain_data`.  These fields therefore cannot be converted to visual tiles
or folded into an image payload.

## Current status

* The six packed layer ranges, terrain-record table and terrain-index grid are
  all physically labelled in `asm/data/data_0813B288*.s` and referenced by
  `src/map_data.cc`.
* The labelled resources are not yet a managed graphics family.  Across the
  table they include large `0x70` streams, short auxiliary tables, and raw
  data.  The present evidence does not prove which packed outputs are tiles,
  tilemaps, palettes, or non-visual state.
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
