# Farm Status creature/UI icons

`shared/icon_00.png` through `icon_19.png` are twenty complete, independent
16-by-16 indexed 4bpp records. Each PNG owns the exact sixteen-colour BGR555
palette stored directly after its 0x80-byte tile grid. They are editable source
artwork, not a screenshot, OAM fragment, atlas, or JSON-controlled layout.

All four retail FoMT ROMs contain the same two `0x640`-byte sequences. The
bytes between them stay native ROM data because they belong to other resource
classes.

| Region | `icon_00` offset | `icon_10` offset | Each size |
| --- | ---: | ---: | ---: |
| JP | `0x4D8318` | `0x4D8E98` | `0x640` |
| US | `0x75236C` | `0x752EEC` | `0x640` |
| EU | `0x7523C8` | `0x752F48` | `0x640` |
| DE | `0x4D9888` | `0x4DA408` | `0x640` |

The verified SHA-256 values, in source order, are
`7095571e9e9b0ca2ba0ae87e9f0f9cc2d2f74bd674e76f78f4ed770809ed6ae8` and
`3f3af3b3491fb338cbc6003a73453e03454b47a374a61b15a4eb09f974be6bb5`.
`tools/farm_status_creature_icons.py` verifies both native ranges before
export/rebuild and then compares every generated `0xA0` record individually.

The original code keeps separate tile and palette labels, and those labels are
retained in `asm/data/data_0813B288.s`. Several calls occur within the Farm
Status UI; in particular, the chicken-list code selects `icon_05` when
`GetGrowthStage__C7Chicken` returns one and `icon_06` otherwise. In the second
sequence, the sheep-list code selects `icon_15` for growth stage one,
`icon_16` after shearing, `icon_17` when pregnant, and `icon_18` for the other
growth-stage branch. The other names intentionally retain physical order until
their gameplay roles have equally direct evidence.

```console
make gfx-farm-status-creature-icons-all
```

The target rebuilds each active regional output and checks unchanged PNGs
against JP, US, EU, and DE. Editing a source PNG produces its corresponding
native tile bytes and BGR555 palette without relying on sidecar layout data.
