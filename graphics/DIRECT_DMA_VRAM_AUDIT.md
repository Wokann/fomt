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
| `gUnk_08750C8C` | `0x1A0`, `0x1C0` | Shared UI native tiles at BG slot `0x150`; Farm Status Earnings Report and Cooking menu code both consume it, and the shorter caller uses its leading subrange. |
| `gUnk_087510AC` | `0x120` | Farm Status Earnings Report native tiles at BG slot `0x0A5`; final layout unproven. |
| `gUnk_0875166C` | `0x120` | Farm Status Earnings Report native tiles at BG slot `0x09C`; paired BGR555 palette is `gUnk_0875178C`, while final layout remains unproven. |
| `gUnk_0875178C` | `0x20` | Farm Status Earnings Report BGR555 palette bank 2; paired with `gUnk_0875166C`. |
| `gUnk_087517AC` | `0x120` | Farm Status Harvest Sprite List native tiles at BG slot `0x09C`; final layout unproven. |
| `gUnk_08750F6C` | `0x20` | Farm Status Harvest Sprite List BGR555 palette bank 3; paired with `gUnk_08750E4C`. |
| `gUnk_08750F8C` | `0x120` | Farm Status Harvest Sprite List native tiles at BG slot `0x0A5`; final layout unproven. |
| `gUnk_08750E4C` | `0x120` | Farm Status Harvest Sprite List native tiles at BG slot `0x0AE`; paired BGR555 palette is `gUnk_08750F6C`, while final layout remains unproven. |
| `gUnk_087511CC` | `0x120` | Farm Status Tool Level List native tiles at BG slot `0x09C`; final layout unproven. |
| `gUnk_087512EC` | `0x20` | Farm Status Tool Level List BGR555 palette bank 2. JP uses a distinct record; US/EU/DE share one overseas record. The destination is assembled through a stack temporary, so this manually audited call is outside the literal-only scanner. |
| `gUnk_0875154C` | `0x120` | Farm Status Tool Level List native tiles at BG slot `0x0A5`; final layout unproven. |
| `gUnk_0875130C` | `0x120` | Farm Status Tool Level List native tiles at BG slot `0x0AE`; final layout unproven. |
| `gUnk_0875142C` | `0x120` | Farm Status Tool Level List native tiles at BG slot `0x0B7`; final layout unproven. |
| `gUnk_08752DCC` | `0x20` | Farm Status Harvest Sprite List native tile at BG slot `0x070`; final layout unproven. |
| `gUnk_08752B4C` | `0x20` | Farm Status Harvest Sprite List native tile at BG slot `0x071`; final layout unproven. |
| `gUnk_087529AC` | `0x20` | Farm Status Harvest Sprite List native tile at BG slot `0x072`; final layout unproven. |
| `gUnk_08752D4C` | `0x80` | Farm Status Harvest Sprite List native tiles at contiguous BG slots `0x073`–`0x076`; final layout unproven. |
| `gUnk_08752ACC` | `0x80` | Farm Status Harvest Sprite List native tiles at contiguous BG slots `0x077`–`0x07A`; final layout unproven. |
| `gUnk_0875290C` | `0x80` | Existing Farm Status UI icon record 09 source; its adjacent `gUnk_0875298C` is the paired BGR555 palette. |
| `gUnk_08752A2C` | `0x20` | Farm Status Tool Level List native tile at BG slot `0x058`; final layout unproven. |
| `gUnk_08752AAC` | `0x20` | Farm Status Tool Level List BGR555 palette record; `func_08068344` copies it directly to palette RAM. |
| `gUnk_08752CCC` | `0x20` | Farm Status Tool Level List native tile at BG slot `0x059`; final layout unproven. |
| `gUnk_08752BCC` | `0x20` | Farm Status Tool Level List native tile at BG slot `0x05A`; final layout unproven. |
| `gUnk_08752C4C` | `0x20` | Farm Status Tool Level List native tile at BG slot `0x05B`; final layout unproven. |

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
| `gUnk_08750F6C` | `func_080645F0` (Farm Status Harvest Sprite List) copies it to palette RAM immediately after loading `gUnk_08750E4C`. | Native tile/palette pair; final layout remains unproven. |
| `gUnk_087512EC` | `func_08068344` uploads it to palette RAM beside the Tool Level List tiles. | Managed native BGR555 source, split into JP and US/EU/DE domains; final screen layout remains unproven. |
| `gUnk_0875178C` | `func_0806644C` (Farm Status Earnings Report) copies it to palette RAM immediately after loading `gUnk_0875166C`. | Native tile/palette pair; final layout remains unproven. |

The icon rows and the single-tile Harvest Sprite row now point at checked-in
PNG pipelines. The remaining twenty-three raw UI records have verified
four-region physical bounds and reversible native source assets. A manual
second pass over every UI call site confirms that nineteen records target
character VRAM; the four still-raw palette-RAM records are
`gUnk_08750F6C`, `gUnk_087512EC`, `gUnk_0875178C`, and `gUnk_08752AAC`. No arbitrary tile-grid
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
