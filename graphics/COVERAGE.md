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
