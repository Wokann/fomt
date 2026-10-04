# Rick actor animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Rick selector-to-frame mapping only.

This directory contains the currently audited continuous Rick actor-animation
interval. `full/frame_NNNN.png` is a complete palette-indexed OAM composition;
the number is the native actor archive frame-descriptor index, not an invented
layout or a linear-tile position. The build reads every OAM and tile relation
from the ROM archive, so this document is descriptive metadata only and has no
effect on conversion or linking.

The project-owned animation constants establish the following directional
groups. The actor runtime adds the current facing to a group base before it
resolves the native animation entry.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x212` | Adjacent physical selector; no semantic name claimed | 0897, 0898, 0899 |
| `0x213`–`0x216` | `ANIMATION_RICK_IDLE` and facing variants | 0900, 0901, 0902, 0903 |
| `0x217`–`0x21A` | `ANIMATION_RICK_WALK` and facing variants | 0900–0911 |
| `0x21B`–`0x222` | Adjacent transition/gesture selectors; no semantic name claimed | 0912–0916 |
| `0x223`–`0x226` | `ANIMATION_RICK_WEDDING_IDLE` and facing variants | 0917–0920 |
| `0x227`–`0x22A` | `ANIMATION_RICK_WEDDING_WALK` and facing variants | 0917–0922, 0925–0928 |
| `0x22B`–`0x22D` | `ANIMATION_RICK_WEDDING_KISS` and facing variants | 0920, 0923, 0924 |

All four retail FoMT localizations contain the same complete actor archive
payload. Only its ROM address differs, so this source set is shared by JP, US,
EU, and DE. To regenerate it from a verified US ROM:

The export command preserves an existing PNG when its indexed pixels and
palette already match the ROM. It refuses to overwrite a changed authored
image unless `--replace` is supplied explicitly.
