# Cliff actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Cliff selector-to-frame mapping only.

This directory owns complete, indexed OAM-composited Cliff frames from the
shared native actor archive. `full/frame_NNNN.png` names the native frame
descriptor rather than a generated tile position. Conversion reads the actual
OAM, tile and palette tables used by the game; no hand-authored layout sidecar
or raw linear tile sheet participates in the build.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x27B`-`0x27E` | `ANIMATION_CLIFF_IDLE` | 1013-1016 |
| `0x27F`-`0x282` | `ANIMATION_CLIFF_WALK` | 1013-1024 |
| `0x283`-`0x286` | Adjacent selectors; no semantic name claimed | 1013-1016, 1025-1028 |
| `0x287`-`0x28A` | `ANIMATION_CLIFF_WEDDING_IDLE` | 1029-1032 |
| `0x28B`-`0x28E` | `ANIMATION_CLIFF_WEDDING_WALK` | 1029, 1031-1038 |
| `0x28F`-`0x292` | `ANIMATION_CLIFF_WEDDING_KISS` | 1032, 1039, 1040 |
| `0x293`-`0x296` | `ANIMATION_CLIFF_HOSPITAL_BED_IDLE` | 1041 |
| `0x297`-`0x29A` | `ANIMATION_CLIFF_HOSPITAL_BED_REACT` | 1042, 1043 |
| `0x29B`-`0x29E` | `ANIMATION_CLIFF_COLLAPSE_FORWARD` | 1013, 1044-1046 |
| `0x29F`-`0x2AB` | Adjacent selectors; no semantic name claimed | 1041, 1042, 1047, 1048, 1051-1053 |

The four retail localizations share these archive bytes; only their ROM
offsets differ. To regenerate from a verified US ROM:

The exporter preserves matching images and native palettes; `--replace` is
required before it replaces an authored image.
