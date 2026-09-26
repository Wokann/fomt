# Map resource audit

This document records boundaries established before any map resource is
exported as artwork.  It deliberately separates evidence from inference:
unverified map payloads remain direct ROM data.

## Confirmed record shape

`include/map_data.hh` defines 66 `MapData` records.  Each record contains:

| Offset | Field | Established role |
| --- | --- | --- |
| `0x00` | `compressed_layers[0]` | Primary tile-graphics stream: `func_080A5EA0` unpacks it directly to VRAM `0x06000000`. |
| `0x04`–`0x08` | `compressed_layers[1..2]` | BGR555 palette groups. `func_080A5DB8` expands them into one of three constructor-allocated `0x1E0`-byte buffers; every payload is exactly 15 × 16 native BGR555 entries. Layer 1 is always selected first; layer 2 is selected for the fourth caller mode. |
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

The 272 references do **not** form one uninterrupted archive. A previous
boundary assumption used the next MapData pointer as the current stream's
end. For example, US `0x6977C8` consumes `0x158` compressed bytes and ends at
`0x697920`, where the separate `gUnk_08697920` VRAM resource begins. Its next
MapData pointer is at `0x69B3B8`; treating that whole gap as one editable
stream would overwrite independent data.

Only the first 42 streams have so far been moved into the direct-link source
pipeline. Their exact contiguous interval is JP `0x400244–0x41DA7C`, US
`0x67A0E8–0x697920`, EU `0x67A144–0x69797C`, and DE
`0x401184–0x41E9BC` (end exclusive). Seven streams have editable PNG tile
sources, eleven have editable JASC palette sources, and 24 retain native u16
tilemap sources. `graphics/maps/shared/map_data.inc` lists the actual packed
order and symbols; the assembly includes it at that original location.
Source-adjacent `.original.lz` files preserve each original format and slot
size. `tools/fomt_lz.c` rebuilds changed sources and rejects slot overflow;
unchanged sources reproduce original packed bytes. The remaining 230 MapData
streams remain source-owned original bytes in assembly, not an editable
graphics pipeline. They need individual physical bounds before conversion.

## Current status

* The six packed layer ranges, terrain-record table and terrain-index grid are
  all physically labelled in `asm/data/data_0813B288*.s` and referenced by
  `src/map_data.cc`.
* The first 42 unique visual streams are source-backed and direct-linked;
  all four unedited ROMs still match their retail SHA-1. No MapData post-link
  patch or baserom input remains in the normal build rule.
* Layer 0, layers 1–2 and layers 3–5 respectively have verified 4bpp tile,
  BGR555 palette-group and u16 tilemap roles. The converted palette sources
  retain their native bank ordering through JASC `.pal` to `.gbapal`.
* The earlier `unknown_types.hh::MapData` sketch has a speculative
  `packed_img`/palette/tile naming scheme.  It is not used as authoritative
  evidence for this pipeline; `map_data.hh` and the runtime access above are
  authoritative.

## Evidence retained for each editable map family

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

The first 42 MapData streams satisfy points 1, 2 and 4. Their layers 0,
1--2 and 3--5 also satisfy point 3 as native tile, palette and tilemap data
respectively. The other 230 have not passed the physical-boundary test.
Extraction previews may be kept as references but are never used as
authoritative editable sources.
