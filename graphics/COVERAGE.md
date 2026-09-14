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
| Farm-status background tiles | `graphics/ui/farm_status/shared/base_tiles.png` | packed 8bpp tile stream plus BGR555 palette | Yes |

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
```

The generated CSV is a local audit artifact and is not source artwork.

## Next audit queue

| Candidate family | Evidence | Current conclusion |
| --- | --- | --- |
| Farm-status building previews | `FarmStatusScreenBuildingPreview` gives seven pairs of ROM pointers, dimensions and screen positions; `func_0806EC28` copies their `u16` values into a background tilemap. | The common 8bpp background tile stream and palette are now managed; these named pointer payloads remain tilemaps and need a separate renderer before exporting complete building-preview PNGs. |
| Intro-scene unpack inputs | `gUnk_IntroSceneUnpackSource_*` labels are passed through the native `Unpack` path from the intro code. | Potential compressed graphics/UI resources; no image export until the compression format, output length, palette and destination relationship are proven. |
| Records-screen resources | `records_screen_data.cc` exposes paired raw resource pointers consumed by the records screen. | Candidate screen tile/tilemap resources; format and palettes remain unclassified. |
| Field/map payloads | The large raw ranges around `FieldPlotRenderRecord_*` and map-resource labels are used by field rendering. | May contain tiles, maps, collision and/or animation data together.  They require per-record boundaries and runtime format analysis, not a bulk linear-tile export. |
