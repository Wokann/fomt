# Farm Status graphics

`shared/base_tiles.png` is the editable, linear 4bpp tile source. Its pixels
retain their native values from 0 through 15; it deliberately displays only
palette bank zero.

`shared/base_palettes.png` is the editable sixteen-bank BGR555 palette source.
Its 256 by 8 swatch arrangement is part of the source format: every row is
the indices 0 through 255, so changing a swatch changes that exact native
palette entry without renumbering any tile indices.

`shared/tilemaps/` contains the fourteen authoritative native BG tilemaps:
the primary and alternate view for each farm house, coop, and barn level. Each
two-byte entry carries a tile ID, horizontal/vertical flip bits and a palette
bank, so a rendered PNG cannot losslessly replace it. These `.tilemap` source
files are deliberately direct native resources rather than a JSON layout
sidecar. `reference/` contains their convenient generated PNG previews.

Rebuild the tilemap bundle and verify it against all four ROMs with:

```console
make gfx-farm-status-tilemaps-all
```

Regenerate the reference PNGs with:

```console
make gfx-farm-status-previews
```

The tilemap build verifies all fourteen payloads are byte-identical in JP, US,
EU, and DE. The assembler then includes the selected regional bundle at each
original table label, preserving the C++ pointer table without relocation.

`shared/secondary_tilemaps/` contains the six other native 64-by-44 BG
tilemaps selected by `func_0806EC94`: two layouts, each containing three
screen-block layers. They are source-order arrays of 16-bit BG entries, not
rendered artwork or a sidecar layout description. The stream headers and the
EU-only eight-byte labels remain in the assembly source; the actual compressed
payload is rebuilt from the selected region's `.tilemap` source and is included
at its original runtime label.

Rebuild and compare these six streams across all four ROMs with:

```console
make gfx-farm-status-secondary-tilemaps-all
```

Their native packed slots are deliberately fixed. A source edit that expands
past its original compressed slot is rejected rather than overwriting the next
resource; `make gfx-farm-status-secondary-tilemaps-edit-test` exercises that
capacity guard.
