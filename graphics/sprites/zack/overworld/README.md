# Zack actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

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
