# Farm Status Tool Level List palette — BG bank 2

`func_08068344` uploads this exact `0x20`-byte BGR555 record while setting up
the Tool Level List. Its destination is calculated through a local temporary,
so the literal-only DMA scanner cannot recover it automatically. The JP and
US call paths establish the upload, while the exact source range and byte
domain are checked against all four retail ROMs.

| Domain | Region | ROM offset | Size | SHA-256 |
| --- | --- | ---: | ---: | --- |
| `jp` | JP | `0x4D7F58` | `0x20` | `31914dafe0d1a2e020d3adc49118040855d874bb122639b47143b991bc49d077` |
| `overseas` | US | `0x7512EC` | `0x20` | `4e9002d1a59b76f30985349aa2066e6382f673231ec4021f73eeb7d7b88f8b86` |
| `overseas` | EU | `0x751348` | `0x20` | same |
| `overseas` | DE | `0x4D8808` | `0x20` | same |

Each `palette.gbapal` is the authoritative fixed-size source for its domain.
It remains separate from a composite PNG until the Tool Level List's full
tilemap and palette-selection path are proven.
