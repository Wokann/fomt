# Raw UI VRAM records

This directory contains lossless native sources for UI records whose runtime
copies, ROM bounds and byte domains are proven, but whose final BG tilemap or
OAM composition is not yet proven.  A `.4bpp` or `.gbapal` file is therefore
the editable source; no arbitrary linear tile-grid PNG is treated as a source
asset.

## Farm Status Tool Level List

`func_08068344` loads the following four-region byte-identical records.  The
numeric slot is the native 4bpp character-RAM index calculated from the
literal DMA destination; it is a stable resource identity, not a claim about
the on-screen position.

| Source directory | ROM label | Native format | Destination |
| --- | --- | --- | --- |
| `08752a2c` | `gUnk_08752A2C` | one 4bpp tile | BG slot `0x058` |
| `08752ccc` | `gUnk_08752CCC` | one 4bpp tile | BG slot `0x059` |
| `08752bcc` | `gUnk_08752BCC` | one 4bpp tile | BG slot `0x05A` |
| `08752c4c` | `gUnk_08752C4C` | one 4bpp tile | BG slot `0x05B` |
| `087511cc` | `gUnk_087511CC` | nine 4bpp tiles | BG slot `0x09C` |
| `087512ec` | `gUnk_087512EC` | one BGR555 palette bank | palette RAM (screen-relative destination) |
| `0875154c` | `gUnk_0875154C` | nine 4bpp tiles | BG slot `0x0A5` |
| `0875130c` | `gUnk_0875130C` | nine 4bpp tiles | BG slot `0x0AE` |
| `0875142c` | `gUnk_0875142C` | nine 4bpp tiles | BG slot `0x0B7` |
| `08752aac` | `gUnk_08752AAC` | one BGR555 palette bank | palette RAM (screen-relative destination) |

The verified JP/US/EU/DE offsets and SHA-256 values are listed in
`UI_DMA_TILES.md`. These records are assembled directly from their native
sources; none needs a resource-specific Python post-link patch. The former JP
`087512ec` profile was misidentified: it pointed into a separate
records-minigame tile. The palette itself is shared by all four regions.

## Farm Status Harvest Sprite List

`func_080645F0` selects the records below.  The shared nine-tile slot pairs
are listed in their own source directories because they are screen-local
alternatives to the Earnings Report sources, despite loading at the same
character-RAM locations.

| Source directory | ROM label | Native format | Destination |
| --- | --- | --- | --- |
| `08752dcc` | `gUnk_08752DCC` | one 4bpp tile | BG slot `0x070` |
| `08752b4c` | `gUnk_08752B4C` | one 4bpp tile | BG slot `0x071` |
| `087529ac` | `gUnk_087529AC` | one 4bpp tile | BG slot `0x072` |
| `08752d4c` | `gUnk_08752D4C` | four contiguous 4bpp tiles | BG slots `0x073`–`0x076` |
| `08752acc` | `gUnk_08752ACC` | four contiguous 4bpp tiles | BG slots `0x077`–`0x07A` |
| `087517ac` | `gUnk_087517AC` | nine 4bpp tiles | BG slot `0x09C` |
| `08750f8c` | `gUnk_08750F8C` | nine 4bpp tiles | BG slot `0x0A5` |
| `08750e4c` | `gUnk_08750E4C` | nine 4bpp tiles | BG slot `0x0AE` |
| `08750f6c` | `gUnk_08750F6C` | one BGR555 palette bank | BG palette bank 3 |

Every table entry is byte-identical across JP, US, EU and DE. The verified
regional boundaries and hashes are listed in `UI_DMA_TILES.md`. The ASM data
file links each native resource directly at its ROM label; a full regional ROM
comparison validates the resulting placement. No final screen composition is
claimed. Three source intervals are only one tile wide, so adjacent
unidentified bytes remain separate inline data until their structure is
understood.
