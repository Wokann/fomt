# MapData state-fallback palettes

`shared/fallback_00.gbapal` through `shared/fallback_04.gbapal` are five
editable, ordered BGR555 palette groups.  Each is exactly `0x1E0` bytes:
fifteen 16-colour GBA palette banks.  They are deliberately native palette
sources, not PNG screenshots and not a guessed tilemap/OAM composition.

The regional map-state loaders use the same `MapData` palette-layer interface
as ordinary map rendering.  For particular map-state branches they select one
of these Raw-LZ3 streams rather than `MapData.compressed_layers[1]` or
`[2]`, then expand it to one caller-selected palette buffer.  The loaders
therefore prove a palette role and a complete 15-bank format, but do not prove
one static rendered scene for each fallback.

The five packed streams and their decoded palette bytes are byte-identical in
JP, US, EU and DE, although their physical ROM offsets differ. The build
generates each `.gbapal.lz` beside its editable `.gbapal` source, and assembly
includes that stream directly; no post-link ROM patch is involved.

| Source | JP | US | EU | DE | Packed bytes |
| --- | ---: | ---: | ---: | ---: | ---: |
| `fallback_00.gbapal` | `0x49AB8C` | `0x714A30` | `0x714A8C` | `0x49BACC` | `0xA0` |
| `fallback_01.gbapal` | `0x49ACBC` | `0x714B60` | `0x714BBC` | `0x49BBFC` | `0x8C` |
| `fallback_02.gbapal` | `0x49AD48` | `0x714BEC` | `0x714C48` | `0x49BC88` | `0x98` |
| `fallback_03.gbapal` | `0x49D0E0` | `0x716F84` | `0x716FE0` | `0x49E020` | `0x94` |
| `fallback_04.gbapal` | `0x49D214` | `0x7170B8` | `0x717114` | `0x49E154` | `0x94` |

`tools/fomt_lz.c` provides a reusable host-side Raw-LZ3 codec. These five
rules declare their native ladder and slot size; the tool pads only to that
slot, rejects overflow, and can decode the output for validation. The source
asset and the assembled stream are independent of the reference ROM.

```console
make GAME_REGION=JP gfx-map-state-palettes-test
make GAME_REGION=JP compare
```

Repeat the compare for US, EU, and DE after an asset or codec change. The
first command checks each generated stream against its source; the ROM compare
checks the complete regional image against the reference.
