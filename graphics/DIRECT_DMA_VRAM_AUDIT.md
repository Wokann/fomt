# Direct DMA-to-video-RAM audit

`tools/dma_vram_inventory.py` recognises only calls to `func_08008F0C` where
the preceding assembly establishes all three values: a named `g*` ROM source
in `r1`, a literal character-VRAM or palette-RAM destination in `r2`, and a
literal byte count in `r3`. Literal values may be loaded directly or formed
only by `mov`, left shift, and addition. It does not infer a palette, tile
format, OAM layout, or screen ownership from the destination.

The current conservative scanner finds 64 qualifying calls and 47 distinct
source labels: 46 character-VRAM copies and 18 palette-RAM copies. A further
direct call below uses an untracked high-register temporary for its literal
destination and is recorded after manual inspection. Repeated calls are
retained in the CSV because different consumers can copy a single source to
different video-RAM locations.

| Source label | Static copy size(s) | Audit state |
| --- | ---: | --- |
| `gUnk_086D5508` | `0xE60` | Managed raw 4bpp field leading variant. |
| `gUnk_086D6698` | `0xE60` | Managed raw 4bpp field leading variant. |
| `gUnk_08697920` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_08698E14` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_0869A0A4` | `0x11E0` | Managed raw 4bpp field tail variant. |
| `gUnk_0875196C` | `0x80` | Existing Animal Festival icon 01 source. |
| `gUnk_0875254C` | `0x20` | Existing Farm Status UI icon record 03 source. |
| `gUnk_08752F8C` | `0x80` | Existing Farm Status UI icon record 11 source. |
| `gUnk_08750C4C` | `0x20` | Farm Status Harvest Sprite task UI tile PNG source; a complete 8x8 OBJ tile paired with `gUnk_08750C6C`. |
| `gUnk_08750C6C` | `0x20` | Farm Status Harvest Sprite task UI tile BGR555 palette regenerated from the paired PNG source. |
| `gUnk_08750C8C` | `0x1A0`, `0x1C0` | Managed complete `0x1C0` raw UI tile record; the shorter caller consumes its leading subrange. |
| `gUnk_087510AC` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875166C` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_0875178C` | `0x20` | Managed raw UI BGR555 palette record; paired with `gUnk_0875166C`. |
| `gUnk_087517AC` | `0x120` | Managed raw UI tile record; palette and layout unproven. |
| `gUnk_08750F6C` | `0x20` | Managed raw UI BGR555 palette record; paired with `gUnk_08750E4C`. |
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
| `gUnk_0875290C` | `0x80` | Existing Farm Status UI icon record 09 source; its adjacent `gUnk_0875298C` is the paired BGR555 palette. |
| `gUnk_08752A2C` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752AAC` | `0x20` | Managed Farm Status BGR555 palette record; `func_08068344` copies it directly to `0x05000000`. |
| `gUnk_08752CCC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752BCC` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |
| `gUnk_08752C4C` | `0x20` | Managed raw Farm Status UI tile record; palette and layout unproven. |

## Literal palette-RAM leads

The expanded scanner also records direct BGR555 palette uploads. The table
below closes every distinct literal-source palette label without treating an
adjacent range as an image merely because it is nearby. Rows already covered
by an icon pipeline identify the exact icon record; the three raw UI pairs
remain native sources because their tile arrangement is not proven.

| Palette source | Consumer relationship | State |
| --- | --- | --- |
| `gUnk_084D8578` | JP physical label for Farm Status UI icon record 03; immediately follows `gUnk_084D84F8`. | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_087519EC` | Immediately follows Animal Festival icon record 01 (`gUnk_0875196C`). | Managed by the Animal Festival icon PNG pipeline. |
| `gUnk_087525CC` | Immediately follows Farm Status UI icon record 03 (`gUnk_0875254C`). | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_0875298C` | Immediately follows Farm Status UI icon record 09 (`gUnk_0875290C`). | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_0875300C` | Immediately follows Farm Status UI icon record 11 (`gUnk_08752F8C`). | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_0875314C` | Immediately follows Farm Status UI icon record 13 (`gUnk_087530CC`). | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_0875350C` | Immediately follows Farm Status UI icon record 19 (`gUnk_0875348C`). | Managed by the Farm Status icon PNG pipeline. |
| `gUnk_08750C6C` | Immediately follows the single-tile `gUnk_08750C4C` record. | Managed by the Farm Status Harvest Sprite task UI tile PNG pipeline. |
| `gUnk_08750F6C` | Immediately follows raw `gUnk_08750E4C` tile record. | Native tile/palette pair; final layout remains unproven. |
| `gUnk_0875178C` | Immediately follows raw `gUnk_0875166C` tile record. | Native tile/palette pair; final layout remains unproven. |

The icon rows and the single-tile Harvest Sprite row now point at checked-in
PNG pipelines. The remaining twenty-two raw UI records have verified
four-region physical bounds and reversible native source assets. A manual
second pass over every UI call site confirms that twenty records target
character VRAM; the three still-raw palette-RAM records are
`gUnk_08750F6C`, `gUnk_0875178C`, and `gUnk_08752AAC`. No arbitrary tile-grid
PNG or JSON layout is treated as a source asset: a future visual pipeline must
still establish the companion palette and tilemap/OAM layout.

Every static `g*` source label currently found by this conservative scan is
now classified above: it is either already covered by an icon PNG pipeline,
preserved as a separately bounded native 4bpp tile or BGR555 palette record.
This does not
claim that every ROM graphic has been found: calls through pointers, runtime
descriptors, archive dispatch, or non-literal VRAM destinations remain outside
this scanner's deliberately narrow scope.

Generate the machine-readable scan with:

```console
python tools/dma_vram_inventory.py . --csv build/dma_vram_inventory.csv
```
