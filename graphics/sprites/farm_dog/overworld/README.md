# Farm Dog actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Farm Dog selector-to-frame mapping only.

This directory contains complete indexed Farm Dog frames from FoMT's shared
native actor archive. Each PNG is a true OAM composition with native palette
data, and each frame number identifies an archive descriptor—not a synthetic
tile-sheet address or manually maintained layout.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x338`-`0x33B` | `ANIMATION_FARM_DOG_IDLE` | 1243, 1245-1247 |
| `0x33C`-`0x33F` | `ANIMATION_FARM_DOG_WALK` | 1244-1255 |
| `0x3AE`-`0x3B1` | `ANIMATION_FARM_DOG_PUPPY_IDLE` | 1406-1409 |
