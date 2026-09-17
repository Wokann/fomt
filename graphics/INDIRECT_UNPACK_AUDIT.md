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

## Complete non-VRAM result

The control-flow-aware inventory currently finds seventeen distinct labelled
`Unpack` sources whose destination is either a caller-owned buffer or palette
RAM rather than literal VRAM.  The table below classifies every such label.  A
staging buffer is not an independently editable image source: only the rows
that already have a complete, verified resource pipeline are linked to one.

| Consumer | Labels | Classification |
| --- | --- | --- |
| `func_08000914` | `gUnk_08747A74`, `gUnk_084CDBDC` | Managed Intro Scene indexed-resource archives. The latter is the preserved JP code path; both have verified OAM descriptors, tile ranges and BGR555 palette indices. See `intro_scene/OBJECT_PIPELINE_AUDIT.md`. Their destinations are archive buffers, not direct VRAM tile uploads. |
| `func_08054F40` | `gUnk_08738AD8`, `gUnk_08738CC8`, `gUnk_08738CF0`, `gUnk_08739A64` | Runtime staging inputs for the UI scene's maps and related data. They contribute to code-backed reference views, while only the separately direct-VRAM tile stream has a fixed-slot editable graphics pipeline. |
| `func_0805AB08` | `gUnk_0872F11C`, `gUnk_0872F1BC`, `gUnk_0872F1EC`, `gUnk_0872FBFC` | Runtime map-template staging inputs for the UI scene. Their exact references are useful for inspection, but no replacement layout is inferred from a rendered PNG. |
| `func_080A95A4` | `gUnk_08714A30`, `gUnk_08714B60`, `gUnk_08714BEC`, `gUnk_08716F84`, `gUnk_087170B8` | Map-state fallback buffers detailed above. No tile/palette/OAM ownership is established. |
| `func_080B55D0` | `gUnk_086FD240` | Proven field-data stream: `0x590` packed bytes decode to `0x1A40` bytes. Its selected `32x32` view is documented in `DIRECT_UNPACK_VRAM_AUDIT.md`, but a source edit cannot currently remain within the original slot. |
| `func_080B55D0` | `gUnk_086FD19C` | Direct palette-RAM upload. It provides a read-only palette reference for the auxiliary UI layers, but overlaps neighbouring resource ownership and therefore remains non-editable native data. |

This closes the current static non-VRAM `Unpack` list without converting an
unproved staging buffer into a made-up image asset.  Future work can expand the
control-flow model or trace runtime pointer tables; it must retain the same
evidence boundary.

## Evidence boundary

The conclusion above comes from the assembly implementation of
`func_080A95A4` and the exact `incbin` boundaries in
`asm/data/data_0813B288_de_initial.inc`.  It deliberately makes no claim
about the semantic name of the caller object or the visual role of the
resulting buffers.
