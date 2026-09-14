# Rick actor animation source

This directory contains the currently audited continuous Rick actor-animation
interval. `full/frame_NNNN.png` is a complete palette-indexed OAM composition;
the number is the native actor archive frame-descriptor index, not an invented
layout or a linear-tile position. The build reads every OAM and tile relation
from the ROM archive, so this document is descriptive metadata only and has no
effect on conversion or linking.

The project-owned animation constants establish the following directional
groups. The actor runtime adds the current facing to a group base before it
resolves the native animation entry.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x212` | Adjacent physical selector; no semantic name claimed | 0897, 0898, 0899 |
| `0x213`–`0x216` | `ANIMATION_RICK_IDLE` and facing variants | 0900, 0901, 0902, 0903 |
| `0x217`–`0x21A` | `ANIMATION_RICK_WALK` and facing variants | 0900–0911 |
| `0x21B`–`0x222` | Adjacent transition/gesture selectors; no semantic name claimed | 0912–0916 |
| `0x223`–`0x226` | `ANIMATION_RICK_WEDDING_IDLE` and facing variants | 0917–0920 |
| `0x227`–`0x22A` | `ANIMATION_RICK_WEDDING_WALK` and facing variants | 0917–0922, 0925–0928 |
| `0x22B`–`0x22D` | `ANIMATION_RICK_WEDDING_KISS` and facing variants | 0920, 0923, 0924 |

All four retail FoMT localizations contain the same complete actor archive
payload. Only its ROM address differs, so this source set is shared by JP, US,
EU, and DE. To regenerate it from a verified US ROM:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x212,0x213,0x214,0x215,0x216,0x217,0x218,0x219,0x21A,0x21B,0x21C,0x21D,0x21E,0x21F,0x220,0x221,0x222,0x223,0x224,0x225,0x226,0x227,0x228,0x229,0x22A,0x22B,0x22C,0x22D \
  --output graphics/sprites/rick/overworld
```

The export command preserves an existing PNG when its indexed pixels and
palette already match the ROM. It refuses to overwrite a changed authored
image unless `--replace` is supplied explicitly.
