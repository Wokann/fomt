# Direct DMA-to-VRAM audit

`tools/dma_vram_inventory.py` recognises only calls to `func_08008F0C` where
the immediate preceding assembly establishes all three values: a named `g*`
ROM source in `r1`, a literal VRAM destination in `r2`, and a simple literal
byte count in `r3`.  It does not infer a palette, tile format, OAM layout, or
screen ownership from the destination.

The current assembly has 17 qualifying calls and 9 distinct source labels.
Repeated calls are retained in the CSV because different consumers can copy a
single source to different VRAM locations.

| Source label | Static copy size(s) | Audit state |
| --- | ---: | --- |
| `gUnk_086D5508` | `0xE60` | Managed raw 4bpp field leading variant. |
| `gUnk_086D6698` | `0xE60` | Managed raw 4bpp field leading variant. |
| `gUnk_08697920` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_08698E14` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_0869A0A4` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_0875196C` | `0x80` | Existing Animal Festival icon 01 source. |
| `gUnk_0875254C` | `0x20` | Existing Farm Status creature icon 03 source. |
| `gUnk_08752F8C` | `0x80` | Existing Farm Status creature icon 11 source. |
| `gUnk_08750C4C` | `0x20` | Unclassified: static one-tile copy; palette and UI ownership unproven. |
| `gUnk_08750C8C` | `0x1A0`, `0x1C0` | Unclassified: overlapping fixed copies; its complete display relation must be established before exporting source artwork. |
| `gUnk_087510AC` | `0x120` | Unclassified: raw UI candidate; palette and layout unproven. |
| `gUnk_0875166C` | `0x120` | Unclassified: raw UI candidate; palette and layout unproven. |

The three icon rows already point at checked-in PNG pipelines.  The four
unclassified rows remain audit leads only: no arbitrary tile-grid PNG or JSON
layout is treated as a source asset.  Future work must first prove physical
regional bounds, whether the full record is consumed, and the companion
palette/layout.

Generate the machine-readable scan with:

```console
python tools/dma_vram_inventory.py . --csv build/dma_vram_inventory.csv
```
