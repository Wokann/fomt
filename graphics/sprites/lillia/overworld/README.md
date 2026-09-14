# Lillia actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Lillia selector-to-frame mapping only.

This directory owns the audited Lillia segment of FoMT's shared actor archive.
Every `full/frame_NNNN.png` is a complete indexed image composed from native
OAM entries, not a linear tile dump. Frame numbers are native archive frame
descriptor IDs. The converter reads all OAM dimensions, tile offsets, flips
and palettes from the ROM archive, so this documentation is not an editable
layout definition.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x25F`-`0x262` | `ANIMATION_LILLIA_IDLE` | 0970-0973 |
| `0x263`-`0x266` | `ANIMATION_LILLIA_WALK` | 0970-0981 |

All four retail FoMT localizations use the same archive bytes, relocated per
ROM. To regenerate from a verified US ROM:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x25F,0x260,0x261,0x262,0x263,0x264,0x265,0x266 \
  --output graphics/sprites/lillia/overworld
```

Existing images are preserved only when their indexed pixels and native
palette still match the ROM. Replacing an authored image needs `--replace`.
