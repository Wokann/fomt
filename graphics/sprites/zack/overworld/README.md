# Zack actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Zack selector-to-frame mapping only.

This directory owns the complete indexed Zack frames rendered from FoMT's
native actor archive. Every `full/frame_NNNN.png` uses the actual OAM pieces,
tile data, palette and flips from the ROM. Frame IDs are archive descriptor
numbers, not coordinates in a guessed sprite sheet.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x318`-`0x31B` | `ANIMATION_ZACK_IDLE` | 1203-1206 |
| `0x31C`-`0x31F` | `ANIMATION_ZACK_WALK` | 1203-1214 |

The four retail localizations share this actor archive. Regenerate from a
verified US ROM with:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x318-0x31F --output graphics/sprites/zack/overworld
```
