# Calf actor-animation source

> The canonical editable PNGs now live in `graphics/sprites/actor_archive/full`.
> This document preserves the verified Calf selector-to-frame mapping only.

This directory contains complete indexed Calf frames from FoMT's shared actor
archive. Every `full/frame_NNNN.png` is rendered from the ROM's actual OAM
records, tile data and palette. Frame IDs identify native descriptors, not a
synthetic tile grid; the build does not use a hand-maintained layout sidecar.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x2FC`-`0x2FF` | `ANIMATION_CALF_IDLE` | 1160-1169 |
| `0x300`-`0x317` | Adjacent Calf selectors; no semantic name claimed | 1160, 1161, 1164, 1167, 1170-1202 |

The retail JP, US, EU and DE ROMs contain the same archive payload at
different offsets. To regenerate the covered Calf range from a verified US
ROM:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x2FC-0x317 --output graphics/sprites/calf/overworld
```

The exporter preserves an existing image only if its indexed pixels and native
palette still match the ROM. Use `--replace` to explicitly overwrite an
authored image.
