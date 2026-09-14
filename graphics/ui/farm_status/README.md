# Farm Status graphics

`shared/base_tiles.png` is the editable, linear 4bpp tile source. Its pixels
retain their native values from 0 through 15; it deliberately displays only
palette bank zero.

`shared/base_palettes.png` is the editable sixteen-bank BGR555 palette source.
Its 256 by 8 swatch arrangement is part of the source format: every row is
the indices 0 through 255, so changing a swatch changes that exact native
palette entry without renumbering any tile indices.

`reference/` contains fourteen generated previews: the primary and alternate
tilemap for each farm house, coop, and barn level. They are checked reference
images, not a second editable source or a layout sidecar. Rebuild and verify
them with:

```console
make gfx-farm-status-previews
```

The command verifies all fourteen tilemap payloads are byte-identical in JP,
US, EU, and DE before rendering the US reference set.
