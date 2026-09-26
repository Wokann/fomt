# Farm Status graphics

`shared/base_tiles.png` is the editable, linear 4bpp tile source. Its pixels
retain their native values from 0 through 15; it deliberately displays only
palette bank zero.

`shared/base_tiles.original.lz` is the checked-in native Huffman/LZ stream
for this tile grid. The ordinary C `gbagfx` and `fomt-lz` tools produce
`base_tiles.4bpp` and `base_tiles.4bpp.lz` beside the PNG; assembly includes
the packed resource directly. The source build does not read a retail ROM.
The packed stream occupies 0x21C4 bytes at JP 0x2AD72C, US 0x5275D0,
EU 0x52762C, and DE 0x2AE66C.

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

`winter/shared/tiles.png` is the separate 256-by-144 native 4bpp source used
by the overseas winter branch. It rebuilds the identical US/EU/DE tile stream
inside its original `0x1FD4`-byte slot; regional palette data remains
reference-only because EU stores it in a distinct archive.
`winter/shared/winter_tiles.original.lz` supplies the native codec header
and fixed-slot reference to the same C `fomt-lz` rule.
The winter stream occupies 0x1FD4 bytes at US 0x52AA6C, EU 0x52AAC8,
and DE 0x2B1B08; this specific resource is not present in the JP layout.

```console
make gfx-farm-status-winter-all
make gfx-farm-status-winter-edit-test
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
EU-only eight-byte labels remain in the assembly source. Each shared
`.tilemap` is packed by the C codec, then included at its original runtime
label. `secondary_01` and `secondary_04` encode directly from the editable
tilemaps with tested codec parameters; their `.original.lz` files are used
only to compare packed bytes. The other four still use their source-adjacent
`.original.lz` headers and distance ladders during packing.

Rebuild and compare these six streams across all four ROMs with:

```console
make gfx-farm-status-secondary-tilemaps-all
```

Their native packed slots are deliberately fixed. A source edit that expands
past its original compressed slot is rejected rather than overwriting the next
resource.

`shared/exterior_styles/` contains the three raw style groups selected by
`func_0806EC94`: `doghouse/`, `mailbox/`, and `window/`.  Each contains three
editable indexed 4bpp PNGs in native tile order.  Their dimensions are 16 by
16, 8 by 16, and 88 by 16 respectively; these are not arbitrary sheets.  The
runtime copies four doghouse tiles to BG IDs 22-25, two mailbox tiles to IDs
26-27, and twenty-two window tiles to IDs 0-21.  The corresponding Farm
Status maps prove their 2-by-2, 1-by-2, and 11-by-2 arrangements and select
palette bank 5 from `base_palettes.png`. The existing C `gbagfx` tool converts
each PNG to an adjacent `.4bpp`; assembly then writes the native two-word
count header and includes the three styles in source order. No packing script
or layout sidecar is used.

Build all three groups in JP, US, EU, and DE with:

```console
make gfx-farm-status-exterior-styles-all
```

All three original physical ranges are byte-identical across the four retail
ROMs, so one shared source tree is authoritative. The normal ROM compare checks
the complete linked layout and byte content.

`winter/shared/tiles.png` is the editable native 4bpp tile grid selected by
`func_0806EC94` when the season is winter. Its pixel indices are shared by US,
EU and DE. The build preserves the retail format-`220` stream while this source
is unchanged; after an edit it emits a strictly decoder-compatible
Huffman-8/LZ3 stream and rejects any output that exceeds the original
`0x1FD4`-byte slot. Run the overseas byte check and the changed-pixel capacity
fixture with:

```console
make gfx-farm-status-winter-all
make gfx-farm-status-winter-edit-test
```

`reference/winter/tiles_us_de.png` and `palettes_us_de.png`, together with the
EU-specific `tiles_eu.png` and `palettes_eu.png`, remain verified readable
exports. The selected palette is identical only in US/DE; EU supplies a
different payload behind an eight-byte archive header, so the palette files
are deliberately references rather than editable build inputs. JP uses a
separate resource layout and remains direct ROM data in this family.
