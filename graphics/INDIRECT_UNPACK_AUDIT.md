# Indirect map-state unpack audit

This audit records a small family of compressed ranges that is reachable from
the map-state renderer but is **not** a verified graphics-export pipeline.
It exists to prevent a successful decompression from being mistaken for proof
of tiles, a palette, or a screen layout.

## `func_080A95A4` fallback payloads

`func_080A95A4` obtains its active `MapData` record with `GetMapData`, selects
one of the following `0x30` (Raw-LZ) payloads for special map-state branches,
and passes it to `Unpack`:

| Label | DE physical range | Packed bytes consumed | Decoded bytes |
| --- | ---: | ---: | ---: |
| `gUnk_08714A30` | `0x49BACC..0x49BB6C` | `0xA0` | `0x1E0` |
| `gUnk_08714B60` | `0x49BBFC..0x49BC88` | `0x8C` | `0x1E0` |
| `gUnk_08714BEC` | `0x49BC88..0x49BD20` | `0x98` | `0x1E0` |
| `gUnk_08716F84` | `0x49E020..0x49E0B4` | `0x94` | `0x1E0` |
| `gUnk_087170B8` | `0x49E154..0x49E1E8` | `0x94` | `0x1E0` |

The branch is selected by the map-state value at the caller's `+0x04` field
(`0x10` and `0x11` have dedicated paths) and other local state values.  The
`Unpack` destination is calculated from the caller's `+0x1C` pointer array
and the supplied index (`+ 4 * index`).  It is not a literal VRAM address and
the routine does not establish a tile format, palette source, BG map, OBJ OAM
descriptor, or display register configuration for these bytes.

Consequently these records remain native ROM data.  They must not be exported
as guessed PNGs or given an editable graphics rebuild path until a later audit
proves their runtime structure and ownership.  Their strict decode bounds are
nevertheless retained in `build/gfx_compression_inventory.csv` so a future
consumer analysis can start from exact payload sizes.

## Evidence boundary

The conclusion above comes from the assembly implementation of
`func_080A95A4` and the exact `incbin` boundaries in
`asm/data/data_0813B288_de_initial.inc`.  It deliberately makes no claim
about the semantic name of the caller object or the visual role of the
resulting buffers.
