# Animal Festival UI icons

`shared/icon_00.png` through `icon_09.png` are ten complete, independent
16-by-16 indexed 4bpp icon records.  Every PNG owns the exact sixteen-colour
BGR555 palette that follows its 0x80-byte tile grid in ROM.  They are source
artwork, not screenshots, OAM fragments, a tile atlas, or a JSON-controlled
layout.

The icons occur in code paths for the Animal Festival UI.  In particular,
`icon_01` is passed with its palette by the winner-display paths.  The other
slots remain physical-order names until each caller's game-level role is
independently established; no visual guess is encoded into a source name.

All four retail FoMT ROMs contain exactly the same 0x640-byte archive:

| Region | Archive offset | Size |
| --- | ---: | ---: |
| JP | `0x4D7878` | `0x640` |
| US | `0x7518CC` | `0x640` |
| EU | `0x751928` | `0x640` |
| DE | `0x4D8DE8` | `0x640` |

The verified archive SHA-256 is
`38ffc2dc46e7d720773ca0ee78e7329bceaced0848a8f4c123cdb7a7a97739af`.
`tools/animal_festival_icons.py` verifies that full range before export and
rebuild, then validates every 0xA0-byte icon record individually.  Assembly
keeps all original address labels and replaces only those 20 tile/palette
payloads with the matching regional build outputs.

```console
make gfx-animal-festival-icons-all
```

This builds the active region's outputs and verifies the authored PNGs against
JP, US, EU and DE.  The unchanged result is byte-identical at every original
range; changing a PNG produces the corresponding native 4bpp bytes and
BGR555 palette without a sidecar layout format.
