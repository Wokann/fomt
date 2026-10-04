# Child actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

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

The exporter preserves an existing image only when its indexed pixels and
native palette match the ROM; replacing an authored edit requires `--replace`.
