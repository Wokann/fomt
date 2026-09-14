# Cliff actor-animation source

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

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x27B,0x27C,0x27D,0x27E,0x27F,0x280,0x281,0x282,0x283,0x284,0x285,0x286,0x287,0x288,0x289,0x28A,0x28B,0x28C,0x28D,0x28E,0x28F,0x290,0x291,0x292,0x293,0x294,0x295,0x296,0x297,0x298,0x299,0x29A,0x29B,0x29C,0x29D,0x29E \
  --output graphics/sprites/cliff/overworld
```

The exporter preserves matching images and native palettes; `--replace` is
required before it replaces an authored image.
