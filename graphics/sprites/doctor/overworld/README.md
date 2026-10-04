# Doctor actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Doctor selector-to-frame mapping only.

This directory owns complete indexed Doctor frames from FoMT's native actor
archive. The editable PNGs are complete OAM compositions, never linear raw
tile sheets. Their frame IDs are native archive descriptor IDs; the build
obtains geometry, palette and tile associations from the ROM resource tables.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x320`-`0x323` | `ANIMATION_DOCTOR_IDLE` | 1215-1218 |
| `0x324`-`0x327` | `ANIMATION_DOCTOR_WALK` | 1215-1226 |
| `0x328`-`0x32B` | `ANIMATION_DOCTOR_GESTURE` | 1227-1230 |
| `0x32C`-`0x32F` | `ANIMATION_DOCTOR_WEDDING_IDLE` | 1231-1234 |
| `0x330`-`0x333` | `ANIMATION_DOCTOR_WEDDING_WALK` | 1231, 1233-1240 |
| `0x334`-`0x337` | `ANIMATION_DOCTOR_WEDDING_KISS` | 1234, 1241, 1242 |

To regenerate from a verified US ROM:
