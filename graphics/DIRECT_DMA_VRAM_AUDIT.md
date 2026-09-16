# Direct DMA-to-VRAM audit

`tools/dma_vram_inventory.py` recognises only calls to `func_08008F0C` where
the preceding assembly establishes all three values: a named `g*` ROM source
in `r1`, a literal VRAM destination in `r2`, and a literal byte count in
`r3`.  Literal values may be loaded directly or formed only by `mov`, left
shift, and addition.  It does not infer a palette, tile format, OAM layout, or
screen ownership from the destination.

The current conservative scanner finds 40 qualifying calls and 31 distinct
source labels.  A further direct call below uses an untracked high-register
temporary for its literal destination and is recorded after manual inspection.
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
| `gUnk_08750C4C` | `0x20` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_08750C8C` | `0x1A0`, `0x1C0` | Managed complete `0x1C0` raw UI tile record; the shorter caller consumes its leading subrange. |
| `gUnk_087510AC` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875166C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_087517AC` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_08750F8C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_08750E4C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_087511CC` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875154C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875130C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875142C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_08752DCC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752B4C` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_087529AC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752D4C` | `0x80` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752ACC` | `0x80` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_0875290C` | `0x80` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752A2C` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752AAC` | `0x20` | Managed raw Farm Status UI tile record; manual direct-DMA audit; palette and layout unproven. |
| `gUnk_08752CCC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752BCC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752C4C` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |

The three icon rows already point at checked-in PNG pipelines.  The twenty-two UI
rows now have verified four-region physical bounds and reversible native-tile
sources.  No arbitrary tile-grid PNG or JSON layout is treated as a source
asset: a future visual pipeline must still establish the companion palette and
tilemap/OAM layout.

The scanner also reports direct dynamic-text transfers and small UI-tile
candidates that do not yet have a complete source/layout audit.  They remain
in the CSV as leads only; this document does not promote them to graphics
assets merely because their destinations are in VRAM.

Generate the machine-readable scan with:

```console
python tools/dma_vram_inventory.py . --csv build/dma_vram_inventory.csv
```
