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
| `0875154c` | `gUnk_0875154C` | nine 4bpp tiles | BG slot `0x0A5` |
| `0875130c` | `gUnk_0875130C` | nine 4bpp tiles | BG slot `0x0AE` |
| `0875142c` | `gUnk_0875142C` | nine 4bpp tiles | BG slot `0x0B7` |
| `08752aac` | `gUnk_08752AAC` | one BGR555 palette bank | palette RAM (screen-relative destination) |

The exact JP/US/EU/DE offsets and shared SHA-256 values are the checked
`Profile` entries in `tools/raw_vram_tile_group.py`.  The Make targets rebuild
and verify every profile for all four regions without deriving a tilemap.
