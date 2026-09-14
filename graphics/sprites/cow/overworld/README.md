# Cow actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Cow selector-to-frame mapping only.

This directory owns complete indexed Cow frames from FoMT's shared native
actor archive. Each `full/frame_NNNN.png` is built from real OAM pieces and
the native palette, not an assumed linear tile layout. The frame number is the
archive descriptor ID; geometry, flips and tile references are always read
from the ROM resource tables during export and rebuild.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x2AC`-`0x2AF` | `ANIMATION_COW_IDLE` | 1054-1063 |
| `0x2B0`-`0x2B3` | `ANIMATION_COW_WALK` | 1054, 1055, 1058, 1061, 1064-1071 |
| `0x2B4`-`0x2B7` | Adjacent selectors; no semantic name claimed | 1072-1078 |
| `0x2B8`-`0x2BB` | `ANIMATION_COW_SICK_IDLE` | 1079-1082 |

All four retail localizations contain the same archive payload at different
offsets. Regenerate this source set from a verified US ROM with:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x2AC-0x2BB --output graphics/sprites/cow/overworld
```

Existing indexed images are preserved only when both pixels and palette match
the ROM. Replacing an authored image requires `--replace`.
