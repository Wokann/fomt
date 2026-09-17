# Indirect map-state unpack audit

This audit records compressed ranges reachable from non-VRAM `Unpack` call
sites.  A successful decompression alone is not treated as proof of tiles,
palettes, or a screen layout.  The five map-state fallback inputs below are
the one exception: their exact decoded size and the destination selected by
each regional map-state loader establish them as complete BGR555 palette
banks, so they now have a bounded native-palette rebuild path.

## Map-state fallback payloads

The regional map-state loaders obtain their active `MapData` record with
`GetMapData`, select one of the following `0x30` (Raw-LZ) payloads for special
map-state branches, and pass it to `Unpack`.  The JP loader uses region-local
labels and offsets; the overseas loader is `func_080A95A4`.

| Source | JP physical range | US physical range | EU physical range | DE physical range | Packed / decoded bytes |
| --- | ---: | ---: | ---: | ---: | ---: |
| `fallback_00` | `0x49AB8C..0x49AC2C` | `0x714A30..0x714AD0` | `0x714A8C..0x714B2C` | `0x49BACC..0x49BB6C` | `0xA0` / `0x1E0` |
| `fallback_01` | `0x49ACBC..0x49AD48` | `0x714B60..0x714BEC` | `0x714BBC..0x714C48` | `0x49BBFC..0x49BC88` | `0x8C` / `0x1E0` |
| `fallback_02` | `0x49AD48..0x49ADE0` | `0x714BEC..0x714C84` | `0x714C48..0x714CE0` | `0x49BC88..0x49BD20` | `0x98` / `0x1E0` |
| `fallback_03` | `0x49D0E0..0x49D174` | `0x716F84..0x717018` | `0x716FE0..0x717074` | `0x49E020..0x49E0B4` | `0x94` / `0x1E0` |
| `fallback_04` | `0x49D214..0x49D2A8` | `0x7170B8..0x71714C` | `0x717114..0x7171A8` | `0x49E154..0x49E1E8` | `0x94` / `0x1E0` |

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
when edited.  JP, US, EU and DE have byte-identical packed payloads and
decoded palette banks; each output ROM receives its own region-local patch.

This proves palette ownership only.  The records must not be exported as
guessed PNGs or presented as tile/OAM layouts: none of the regional map-state
loaders establishes either of those structures.  Their strict decode bounds
also remain in `build/gfx_compression_inventory.csv` for later consumer
analysis.

## Complete non-VRAM result

The control-flow-aware inventory currently finds seventeen distinct semantic
`Unpack` inputs whose destination is either a caller-owned buffer or palette
RAM rather than literal VRAM.  Region-local copies of the five fallback
payloads are one shared semantic group.  The table below classifies every such
input.  A staging buffer is not an independently editable image source: only
the rows that already have a complete, verified resource pipeline are linked
to one.

| Consumer | Labels | Classification |
| --- | --- | --- |
| `func_08000914` | `gUnk_08747A74`, `gUnk_084CDBDC` | Managed Intro Scene indexed-resource archives. The latter is the preserved JP code path; both have verified OAM descriptors, tile ranges and BGR555 palette indices. See `intro_scene/OBJECT_PIPELINE_AUDIT.md`. Their destinations are archive buffers, not direct VRAM tile uploads. |
| `func_08054F40` | `gUnk_08738AD8`, `gUnk_08738CC8`, `gUnk_08738CF0`, `gUnk_08739A64` | Runtime staging inputs for the UI scene's maps and related data. They contribute to code-backed reference views, while only the separately direct-VRAM tile stream has a fixed-slot editable graphics pipeline. |
| `func_0805AB08` | `gUnk_0872F11C`, `gUnk_0872F1BC`, `gUnk_0872F1EC`, `gUnk_0872FBFC` | Runtime map-template staging inputs for the UI scene. Their exact references are useful for inspection, but no replacement layout is inferred from a rendered PNG. |
| Regional map-state loaders (overseas `func_080A95A4`) | Five region-local fallback palette ranges listed above | Five managed state-fallback BGR555 palette payloads. Their ordered native `.gbapal` sources retain exact fixed-slot Raw-LZ bounds; no tile or OAM layout is inferred. |
| `func_080B55D0` | `gUnk_086FD240` | Proven field-data stream: `0x590` packed bytes decode to `0x1A40` bytes. Its selected `32x32` view is documented in `DIRECT_UNPACK_VRAM_AUDIT.md`, but a source edit cannot currently remain within the original slot. |
| `func_080B55D0` | `gUnk_086FD19C` | Direct palette-RAM upload. It provides a read-only palette reference for the auxiliary UI layers, but overlaps neighbouring resource ownership and therefore remains non-editable native data. |

This closes the current static non-VRAM `Unpack` list without converting an
unproved staging buffer into a made-up image asset.  Future work can expand the
control-flow model or trace runtime pointer tables; it must retain the same
evidence boundary.

## Evidence boundary

The palette conclusion comes from each regional loader's `Unpack` call, the
fixed `0x1E0`-byte decode size, the indexed destination within the caller
palette-buffer array, and the exact region-local ROM boundaries.  It
deliberately makes no claim about the semantic name of the caller object or
any final tile/OAM presentation.

## Adjacent uncompressed presentation templates

The same map-state renderer contains two direct, uncompressed source-table
paths which are not `Unpack` inputs and therefore are intentionally outside
the seventeen-row inventory above.  Both are verified byte-identical across
JP, US, EU and DE and now have fixed-range native-source rebuild paths in
`graphics/map_state_templates/shared/`.

| Native source | JP range | US range | EU range | DE range | Proven consumer format |
| --- | ---: | ---: | ---: | ---: | --- |
| `map_state_palette_templates.bin` | `0x45D654..0x462520` | `0x6D74F8..0x6DC3C4` | `0x6D7554..0x6DC420` | `0x45E594..0x463460` | `func_080A8FDC` copies the selected base in `0x60`-byte units into caller-owned palette staging storage. |
| `map_state_tilemap_templates.bin` | `0x464950..0x470E38` | `0x6DE7F4..0x6EACDC` | `0x6DE850..0x6EAD38` | `0x465890..0x471D78` | `func_080AA400` selects the table for map-state type `0x0F` and reads it as 16-bit BG tilemap entries. |

The first table begins with BGR555-looking data and the second begins with
tilemap-looking words, but that is deliberately not promoted into a presumed
per-record PNG format: the functions prove only their copy/entry behaviour,
not all individual record boundaries, palette ownership, or a final rendered
screen.  The checked-in binaries are the reversible source of truth, and the
tool verifies the exact original region range before patching.
