# Records Screen task icons

`shared/task_00.png` through `task_06.png` are the seven physical task-icon
records used by the Records Screen.  Each file is a complete 16-by-16 indexed
4bpp source with the original record's own sixteen-colour BGR555 palette.
They are not screen captures and do not require a tilemap, OAM description or
JSON layout sidecar.

`records_screen_data.cc` contains the runtime pointer table.  It chooses the
presentation order from these physical records, so the PNG suffix is kept as
the stable ROM-order index rather than assigning unproven gameplay names to
the individual icons.

The raw tile/palette pairs are byte-identical in all four retail FoMT ROMs:

| Region | First tile offset | Pair stride | Records |
| --- | ---: | ---: | ---: |
| JP | `0x4D7EB8` | `0xA0` | 7 |
| US | `0x751F0C` | `0xA0` | 7 |
| EU | `0x751F68` | `0xA0` | 7 |
| DE | `0x4D9428` | `0xA0` | 7 |

Every pair is `0x80` bytes of 4bpp tiles followed by `0x20` bytes of BGR555
palette data. The Make rules record these physical bounds and compare each
generated tile/palette file with the corresponding retail ROM range.

The normal build uses the shared `PNG -> .4bpp/.gbapal` Make rules and
`gbagfx`, one PNG at a time. The shared range verifier is used only by the
explicit test target, not by the conversion path.

```console
make gfx-records-minigame-all
```

This rebuilds the source-adjacent `shared/task_XX.4bpp` and
`shared/task_XX.gbapal` inputs, then verifies every generated tile/palette
pair against JP, US, EU and DE.  The assembler consumes those files directly
at the original resource labels, so an unchanged source rebuild is
byte-identical and preserves the native C++ pointer-table references.
