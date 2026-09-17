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

## Read-only visual references

`tools/map_visual_references.py` can render each proven BG layer directly from
the native sources.  Its output is deliberately written to
`build/graphics/maps/reference/`, not to `shared/`, because a rendered image
cannot carry the complete 16-bit tilemap data back into the build.

For each map and each available tilemap it writes both
`layer_N_palette_1.png` and `layer_N_palette_2.png`.  The game has two
separate palette streams and selects between them at runtime, so neither is
presented as the single canonical screenshot.  The renderer handles GBA tile
flips and palette-bank indices.  It skips a layer that requests bank 15,
because the per-map streams contain only banks 0--14 and supplying an invented
colour would make the reference misleading.

Generate all available references with:

```console
make gfx-map-resources-reference
```

The command is an inspection aid only.  It never edits `shared/`, ROM data,
or build input files.  For a small focused inspection, invoke the renderer
directly with one map ID:

```console
python tools/map_visual_references.py render ^
  --source-dir graphics/maps/shared ^
  --output-dir build/graphics/maps/reference ^
  --map-id 0 ^
  --rom jp baserom_jp.gba --rom us baserom_us.gba ^
  --rom eu baserom_eu.gba --rom de baserom_de.gba
```

The `^` continuation marker is for `cmd.exe`; remove it or use the shell's
own continuation syntax elsewhere.

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
