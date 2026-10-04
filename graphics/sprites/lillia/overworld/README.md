# Lillia actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

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

Existing images are preserved only when their indexed pixels and native
palette still match the ROM. Replacing an authored image needs `--replace`.
