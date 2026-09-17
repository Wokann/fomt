# Indirect map-state unpack audit

This audit records compressed ranges reachable from non-VRAM `Unpack` call
sites.  A successful decompression alone is not treated as proof of tiles,
palettes, or a screen layout.  The five `func_080A95A4` inputs below are the
one exception: their exact decoded size and the destination selected by the
map-state loader establish them as complete BGR555 palette banks, so they now
have a bounded native-palette rebuild path.

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
and the supplied index (`+ 4 * index`).  It is not a literal VRAM address.
The fixed fifteen-bank payload and that indexed palette-buffer destination
establish the palette source, but the routine does not establish a tile format,
BG map, OBJ OAM descriptor, or display register configuration.

Each decoded payload is exactly `0x1E0` bytes: fifteen 16-colour BGR555 banks
(`15 * 16 * 2`).  The loader selects one full payload as its state-dependent
palette input.  The checked-in ordered sources are therefore native
`graphics/map_state_palettes/shared/fallback_00.gbapal` through
`fallback_04.gbapal`; `tools/map_state_palette_fallbacks.py` preserves the
retail packed bytes when unchanged and uses a strict bounded Raw-LZ rebuild
when edited.  US, EU and DE have byte-identical payloads, while the JP build
has no corresponding code path and is deliberately a no-op.

This proves palette ownership only.  The records must not be exported as
guessed PNGs or presented as tile/OAM layouts: `func_080A95A4` itself does not
establish either of those structures.  Their strict decode bounds also remain
in `build/gfx_compression_inventory.csv` for later consumer analysis.

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
| `func_080A95A4` | `gUnk_08714A30`, `gUnk_08714B60`, `gUnk_08714BEC`, `gUnk_08716F84`, `gUnk_087170B8` | Five managed state-fallback BGR555 palette payloads. Their ordered native `.gbapal` sources retain exact fixed-slot Raw-LZ bounds; no tile or OAM layout is inferred. |
| `func_080B55D0` | `gUnk_086FD240` | Proven field-data stream: `0x590` packed bytes decode to `0x1A40` bytes. Its selected `32x32` view is documented in `DIRECT_UNPACK_VRAM_AUDIT.md`, but a source edit cannot currently remain within the original slot. |
| `func_080B55D0` | `gUnk_086FD19C` | Direct palette-RAM upload. It provides a read-only palette reference for the auxiliary UI layers, but overlaps neighbouring resource ownership and therefore remains non-editable native data. |

This closes the current static non-VRAM `Unpack` list without converting an
unproved staging buffer into a made-up image asset.  Future work can expand the
control-flow model or trace runtime pointer tables; it must retain the same
evidence boundary.

## Evidence boundary

The palette conclusion comes from the assembly implementation of
`func_080A95A4`, its fixed `0x1E0`-byte decode size, its indexed destination
within the caller palette-buffer array, and the exact `incbin` boundaries in
`asm/data/data_0813B288_de_initial.inc`.  It deliberately makes no claim about
the semantic name of the caller object or any final tile/OAM presentation.
