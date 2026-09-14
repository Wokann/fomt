# Doctor actor-animation source

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

```console
py -3 tools/actor_archive.py baserom_us.gba --offset 0x58BA28 \
  --sha256 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736 \
  export --animations 0x320-0x337 --output graphics/sprites/doctor/overworld
```
