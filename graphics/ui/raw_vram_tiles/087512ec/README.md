# Farm Status Tool Level List palette — BG bank 2

`func_08068344` uploads this exact `0x20`-byte BGR555 record while setting up
the Tool Level List. Its destination is calculated through a local temporary,
so the literal-only DMA scanner cannot recover it automatically. The JP and
US call paths establish the upload, while the exact source range and byte
domain are checked against all four retail ROMs.

| Source | Region | ROM offset | Size | SHA-256 |
| --- | --- | ---: | ---: | --- |
| `shared/palette.gbapal` | JP | `0x4D7298` | `0x20` | `4e9002d1a59b76f30985349aa2066e6382f673231ec4021f73eeb7d7b88f8b86` |
| `shared/palette.gbapal` | US | `0x7512EC` | `0x20` | same |
| `shared/palette.gbapal` | EU | `0x751348` | `0x20` | same |
| `shared/palette.gbapal` | DE | `0x4D8808` | `0x20` | same |

The former JP profile used `0x4D7F58`, but that address is
`gUnk_084D7F58`: the start of `records_minigame/shared/task_01.4bpp`.
Its first `0x20` bytes are not this palette. The actual JP palette has the
same bytes as the other regions and is linked directly from the shared source.
