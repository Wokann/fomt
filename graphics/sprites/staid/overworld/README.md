# Staid actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Staid selector-to-frame mapping only.

This directory contains the currently confirmed complete Staid frames from
FoMT's native actor archive. Each indexed PNG is composed from actual OAM,
tile and palette entries; its number identifies the native frame descriptor,
not a synthetic sprite sheet location.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x3E0`-`0x3E3` | `ANIMATION_STAID_IDLE` | 1470-1473 |
| `0x3F0`-`0x3F3` | `ANIMATION_STAID_WEDDING_CEREMONY` | 1507-1510 |
| `0x430`-`0x433` | `ANIMATION_STAID_TEA_PARTY` | 1521 |

These disconnected ranges are intentionally explicit: intervening selector
domains are not included until independently audited. Regenerate the confirmed
source from a verified US ROM with separate export invocations for each range.
