# MapData state-fallback palettes

`shared/fallback_00.gbapal` through `shared/fallback_04.gbapal` are five
editable, ordered BGR555 palette groups.  Each is exactly `0x1E0` bytes:
fifteen 16-colour GBA palette banks.  They are deliberately native palette
sources, not PNG screenshots and not a guessed tilemap/OAM composition.

The regional map-state loaders use the same `MapData` palette-layer interface
as ordinary map rendering.  For particular map-state branches they select one
of these `0x30` Raw-LZ streams rather than `MapData.compressed_layers[1]` or
`[2]`, then expand it to one caller-selected palette buffer.  The loaders
therefore prove a palette role and a complete 15-bank format, but do not prove
one static rendered scene for each fallback.

The five packed streams and their decoded palette bytes are byte-identical in
JP, US, EU and DE, although their physical ROM offsets differ.  Every region
is rebuilt and patched at its own original bounded ranges.

| Source | JP | US | EU | DE | Packed bytes |
| --- | ---: | ---: | ---: | ---: | ---: |
| `fallback_00.gbapal` | `0x49AB8C` | `0x714A30` | `0x714A8C` | `0x49BACC` | `0xA0` |
| `fallback_01.gbapal` | `0x49ACBC` | `0x714B60` | `0x714BBC` | `0x49BBFC` | `0x8C` |
| `fallback_02.gbapal` | `0x49AD48` | `0x714BEC` | `0x714C48` | `0x49BC88` | `0x98` |
| `fallback_03.gbapal` | `0x49D0E0` | `0x716F84` | `0x716FE0` | `0x49E020` | `0x94` |
| `fallback_04.gbapal` | `0x49D214` | `0x7170B8` | `0x717114` | `0x49E154` | `0x94` |

`tools/map_state_palette_fallbacks.py` derives and verifies all physical
bounds.  It preserves retail packed bytes while a source is unchanged.  For
an edit it uses the audited native Raw-LZ `030` encoder, strictly decodes the
result, and rejects output that does not fit the immutable original slot.  The
post-link patcher writes only those five bounded ranges and refuses a target
containing third-party bytes.

```console
make gfx-map-state-palettes-all
make gfx-map-state-palettes-patch-test
make gfx-map-state-palettes-edit-test
```

The first command validates all four regional builds.  The patch test proves
that unchanged sources preserve every retail ROM byte-for-byte.  The edit test
finds and strictly decodes a capacity-fitting one-byte authored change for
each of the five streams without changing checked-in source files.
