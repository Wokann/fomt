# Graphics coverage

This is a conservative inventory of graphics resources with a verified,
editable rebuild path.  It is not a claim that every ROM `incbin` range is an
image, nor that all game graphics have been extracted.

## Managed resources

| Resource family | Editable source | Native build output | Four-region byte check |
| --- | --- | --- | --- |
| Single-width font | `graphics/font/shared/single_width_font.png` | 1bpp glyph stream | Yes |
| Double-width font | `graphics/font/shared/double_width_font.png` | 1bpp glyph stream | Yes |
| Dialogue portraits | `graphics/portraits/shared/full/*.png` | portrait tile stream | Yes |
| Actor archive, every referenced descriptor | `graphics/sprites/actor_archive/full/*.png` | actor tile stream | Yes |
| Located UI tile grid | `graphics/ui/shared_resource/shared_resource.png` | 4bpp tiles plus BGR555 palette | Yes |
| Farm-status background and building previews | `graphics/ui/farm_status/shared/base_tiles.png`, `base_palettes.png`, and `tilemaps/*.tilemap` | packed 4bpp tile stream, sixteen BGR555 palette banks, and fourteen BG tilemaps | Yes |
| Records Screen task icons | `graphics/ui/records_minigame/shared/task_00.png` through `task_06.png` | seven raw 16x16 4bpp grids with individual BGR555 palettes | Yes |

The actor archive has 3,009 frame descriptors, of which 2,963 are referenced
by the retail animation tables.  Every referenced descriptor has a checked-in
complete PNG source.  The other 46 descriptor slots have no retail animation
caller and remain preserved native data rather than invented source images.

## Build linkage

Every managed family is included from `asm/data/data_0813B288.s` through a
regional `build/<region>/graphics/...` output.  The surrounding archive headers,
OAM records, palettes, tables, and unhandled bytes remain direct ROM data until
they have a corresponding verified source/rebuild path.

## Unclassified ROM ranges

Assembly still contains many direct `baserom_*.gba` includes.  They are the
inventory pool for later work.  A direct include must not be converted merely
because it looks like tile data: first establish the exact format, bounds,
palette/layout relationship, consuming code, and four-region byte round trip.

Generate a current list with:

```console
python tools/gfx_incbin_inventory.py . --csv build/gfx_incbin_inventory.csv
python tools/gfx_compression_inventory.py . --csv build/gfx_compression_inventory.csv
```

Both generated CSV files are local audit artifacts, not source artwork. The
compression inventory records only direct ranges that begin with a strictly
decodable `0x70` stream. Its enclosing `incbin` boundary is not automatically
the compressed stream's boundary, and a decoded stream is not automatically a
graphics resource.

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| Farm-status secondary screen data | `FarmStatusScreenResourceDescriptor`, native tile lookup and the other direct ranges around the preview maps. | The common tile grid, full palette-bank set and all fourteen building-preview BG tilemaps are now managed; surrounding resource classes still need separate format analysis. |
| Intro-scene unpack inputs | `gUnk_IntroSceneUnpackSource_*` labels are passed through the native `Unpack` path from the intro code. | Potential compressed graphics/UI resources; no image export until the compression format, output length, palette and destination relationship are proven. |
| Other Records-screen resources | Raw ranges adjacent to the task-icon records, plus page-specific data pointers in the Records Screen code. | The seven direct task icon/palette pairs are now managed; the remaining ranges still need independent consumer and format analysis. |
| Field/map payloads | The large raw ranges around `FieldPlotRenderRecord_*` and map-resource labels are used by field rendering. | May contain tiles, maps, collision and/or animation data together.  They require per-record boundaries and runtime format analysis, not a bulk linear-tile export. |
