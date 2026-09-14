# Farm Dog actor-animation source

This directory contains complete indexed Farm Dog frames from FoMT's shared
native actor archive. Each PNG is a true OAM composition with native palette
data, and each frame number identifies an archive descriptor—not a synthetic
tile-sheet address or manually maintained layout.

| Native selector | Established group | Referenced frame descriptors |
| --- | --- | --- |
| `0x338`-`0x33B` | `ANIMATION_FARM_DOG_IDLE` | 1243, 1245-1247 |
| `0x33C`-`0x33F` | `ANIMATION_FARM_DOG_WALK` | 1244-1255 |

Regenerate from a verified US ROM with:

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x338-0x33F --output graphics/sprites/farm_dog/overworld
```
