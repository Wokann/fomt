# MapData visual resources

`shared/map_00/` through `shared/map_65/` are the authoritative editable
sources for the visual half of the game's `MapData` records.  They preserve
the native data model instead of flattening a map into one image:

* `layer_0.4bpp` is the 1024-tile, 4bpp character stream.
* `layer_1.gbapal` and `layer_2.gbapal` are the two distinct fifteen-bank
  BGR555 palette groups selected by the map renderer.
* `layer_3.tilemap` through `layer_5.tilemap` are the one to three native
  16-bit BG tilemaps.  Their tile index, horizontal/vertical flip, and
  palette-bank bits are retained verbatim.

These files are the build inputs.  `tools/map_resources.py` reads the actual
MapData pointer tables in the four retail ROMs on every build, derives all
aliases and physical bounds, and rebuilds each compressed stream into the
matching regional archive range.  It does not use a checked-in JSON layout
file.  The normal ROM link then post-link-patches only that proven continuous
archive, retaining every existing code pointer.

## Pointer-table coverage boundary

Each regional `MapData` table has 66 records. On every invocation the tool
walks the first six pointer fields of every record: the character stream, two
palette groups, and up to three BG tilemaps. After resolving aliases, this
produces 272 distinct non-null visual source streams. A shared source is
accepted only when its declared bounds, compressed bytes, decoded bytes, and
native format agree in JP, US, EU, and DE; otherwise the exporter stops rather
than silently treating a regional resource as shared.

The remaining `MapData` pointer fields are terrain/field data rather than
proven tile, palette, map, or OAM inputs. They deliberately remain outside
this image pipeline; adding a visual conversion requires evidence from the
runtime consumer, not merely adjacency to a map record. Rendered screenshots
are likewise not build inputs because they cannot retain native tilemap bits.

## Verification

```console
make gfx-map-resources-all
make gfx-map-resources-patch-test
make gfx-map-resources-edit-test
```

These respectively verify every unchanged native stream against JP, US, EU,
and DE; prove that applying the generated archive preserves all four complete
retail ROMs byte-for-byte; and exercise one capacity-fitting source edit for
every audited compression format.
