# Popuri actor-animation source

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

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x22F,0x230,0x231,0x232,0x233,0x234,0x235,0x236,0x237,0x238,0x239,0x23A,0x23B,0x23C,0x23D,0x23E,0x23F,0x240,0x241,0x242,0x243,0x244,0x245,0x246,0x247,0x248,0x249,0x24A,0x24B,0x24C,0x24D,0x24E,0x24F,0x250,0x251,0x252,0x253,0x254,0x255,0x256,0x257,0x258,0x259,0x25A,0x25B,0x25C,0x25D,0x25E \
  --output graphics/sprites/popuri/overworld
```

The exporter preserves a pre-existing indexed image only when its pixel data
and native palette already match the ROM; it refuses to overwrite an authored
edit without `--replace`.
