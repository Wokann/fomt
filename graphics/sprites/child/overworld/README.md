# Child actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Child selector-to-frame mapping only.

This directory contains the confirmed Child actor frames from FoMT's shared
native actor archive. Each `full/frame_NNNN.png` is an indexed, complete
OAM-composited frame. Descriptor IDs identify ROM structures; they are not
coordinates in a guessed sprite sheet. The build obtains every layout rule,
tile reference, flip and palette from the archive itself.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x267`-`0x26A` | `ANIMATION_CHILD_WALKING_IDLE` | 0982-0985 |
| `0x26B`-`0x26E` | `ANIMATION_CHILD_PRE_WALKING_IDLE` | 0986-0989 |
| `0x26F`-`0x272` | `ANIMATION_CHILD_FIRST_STEPS_WALK` | 0984, 0985, 0990-0999 |
| `0x273`-`0x276` | Adjacent selectors; no semantic name claimed | 1000-1011 |
| `0x277`-`0x27A` | `ANIMATION_CHILD_SLEEPING` | 1012 |

All four retail FoMT localizations share the exact archive bytes, relocated
within each ROM. Regenerate this source set from a verified US ROM:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x267,0x268,0x269,0x26A,0x26B,0x26C,0x26D,0x26E,0x26F,0x270,0x271,0x272,0x273,0x274,0x275,0x276,0x277,0x278,0x279,0x27A \
  --output graphics/sprites/child/overworld
```

The exporter preserves an existing image only when its indexed pixels and
native palette match the ROM; replacing an authored edit requires `--replace`.
