# `func_080C160C` BG resource set

`func_080C160C` directly unpacks two labelled 32-by-32 background tilemaps to
`0x0600F800` and `0x0600F000`, then loads a 4bpp tile source at
`0x06000000`. It configures BG controls `0x1E41` and `0x1F42` for those screen
blocks. The current native sources preserve exactly the three proven streams.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x20C` | `0x800` (32x32 u16 entries) | `020`, ladder `236791011` | `0x0600F800` |
| `layer_1.tilemap` | `0xD8` | `0x800` (32x32 u16 entries) | `030`, ladder `379` | `0x0600F000` |
| `tiles.4bpp` | `0xA38` | `0xE80` (116 4bpp tiles) | `020`, ladder `246781012` | `0x06000000` |

All packed and decoded payloads are byte-identical in all four retail FoMT
regions:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4C5530` | `0x4C5814` |
| US | `0x73F3C8` | `0x73F6AC` |
| EU | `0x73F424` | `0x73F708` |
| DE | `0x4C683C` | `0x4C6B20` |

Immediately after unpacking, the routine copies exactly `0x200` bytes to
palette RAM at `0x05000020`, i.e. beginning with BG palette bank 1. Every
nonblank tilemap entry selects banks 1 through 6, so its entire visible
palette domain is code-proven. The copy extends beyond BG palette RAM into an
OBJ palette bank, but the full loaded payload is retained to keep the native
operation reversible.

The original JP function's literal-pool pointer is `0x084C624C`; this corrects
an earlier invalid simple-offset estimate (`0x084C61CC`). The JP payload at the
correct pointer exactly matches US, EU and DE. All four ranges share SHA-256
`56c55d406a8e778b0f83b672a3b6e0816219c0c9e26527fae77b5f4da550a901`.

| Region | Palette offset | Length |
| --- | ---: | ---: |
| JP | `0x4C624C` | `0x200` |
| US | `0x7400E4` | `0x200` |
| EU | `0x740140` | `0x200` |
| DE | `0x4C7558` | `0x200` |

`shared/palettes.png` is the editable indexed representation of the 256 words
as loaded at bank 1. `reference/layer_0.png`, `layer_1.png`, and `scene.png`
are code-backed 256-by-256 views; `scene.png` composites the upper BG map over
the lower one using palette index zero as transparent. The native tilemaps
remain authoritative for tile IDs, flip flags and actual palette-bank values;
no JSON layout sidecar is used.

```console
make gfx-ui-scene-080c160c-all
make gfx-ui-scene-080c160c-preview
make gfx-ui-scene-080c160c-patch-test
```

The C Raw-LZ tool builds source-adjacent `.tilemap.lz` and `.4bpp.lz`
files, which assembly includes directly under relocatable symbols. The tile
stream uses the encoder's general `--literal-tail` strategy to preserve the
retail final three-byte literal run. All three stream addresses in each region and
the four ROM SHA-1 hashes match retail. Only the 0x200-byte palette copy still
crosses another resource's physical boundary and is patched after `objcopy`.
An edited stream must still fit its original slot until that adjacent data is
made relocatable.
