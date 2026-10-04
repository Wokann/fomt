# Popuri actor-animation source

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Popuri selector-to-frame mapping only.

This directory contains the audited Popuri portion of FoMT's shared native
actor archive. `full/frame_NNNN.png` is a complete palette-indexed image
composited from the archive's real OAM records. The number is the archive
frame-descriptor index, not a synthetic sprite-sheet coordinate. The build
reads OAM geometry, tile references and palette selection from the ROM; this
file is descriptive only and is not an input layout.

The verified actor constants establish the following selector groups. Four
successive selectors are the directional forms of each established base.
Unlabelled neighbouring selectors remain in the build so edits to shared
native pixels are checked, but no guessed meaning is assigned to them.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x22E` | Adjacent selector; shared Rick transition frames | 0920, 0923, 0924 |
| `0x22F`-`0x232` | `ANIMATION_POPURI_IDLE` | 0929-0931 |
| `0x233`-`0x236` | `ANIMATION_POPURI_WALK` | 0929-0938 |
| `0x237`-`0x23A` | `ANIMATION_POPURI_HAND_OVER_ITEM` | 0932, 0939-0943 |
| `0x23B`-`0x23E` | Adjacent selectors; no semantic name claimed | 0944, 0945 |
| `0x23F`-`0x242` | `ANIMATION_POPURI_IN_BED` | 0945, 0946 |
| `0x243`-`0x246` | `ANIMATION_POPURI_REACTION` | 0946-0948 |
| `0x247`-`0x24A` | `ANIMATION_POPURI_WITH_NEWBORN` | 0947, 0948, 0950, 0953, 0956 |
| `0x24B`-`0x24E` | Adjacent selectors; no semantic name claimed | 0949-0959 |
| `0x24F`-`0x252` | `ANIMATION_POPURI_WEDDING_IDLE` | 0958-0963 |
| `0x253`-`0x256` | `ANIMATION_POPURI_WEDDING_WALK` | 0964-0967 |
| `0x257`-`0x25A` | `ANIMATION_POPURI_WEDDING_KISS` | 0963, 0965-0969 |
| `0x25B`-`0x25E` | `ANIMATION_POPURI_SETTLE_IN_BED` | 0946, 0947, 0963, 0968, 0969 |

Frame descriptors 0920, 0923 and 0924 are native shared frames already owned
by the Rick source directory. They are intentionally not duplicated here:
the rebuild tool requires exactly one authored PNG owner for each descriptor.

All four retail FoMT localizations contain the same complete actor archive
payload; only the ROM address varies. Regenerate the Popuri-owned frames from
a verified US ROM with:

The exporter preserves a pre-existing indexed image only when its pixel data
and native palette already match the ROM; it refuses to overwrite an authored
edit without `--replace`.
