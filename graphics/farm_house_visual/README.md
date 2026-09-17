# FarmHouse visual tile streams

`shared/visual_00.4bpp` through `shared/visual_06.4bpp` are the seven native
linear 4bpp tile payloads selected by `gFarmHouseVisualDescriptors`.
The house setup branch at `0x080A924C` reads each descriptor's source pointer
at `+0x18`, passes it directly to `Unpack`, and obtains the destination tile
index from `+0x1C`.
The sources therefore preserve the exact decoded pixels in native GBA tile
order: 64, 63, 63, 159, 351, 63, and 223 tiles respectively.

All seven original packed streams and all seven decoded payloads are
byte-identical in the JP, US, EU, and DE retail ROMs.  Their **addresses** are
not identical: the build tool reads the original region's visual descriptor
table before it rebuilds or applies a stream.

Each descriptor also supplies two non-null native 16-bit tilemap patch
buffers.  They are exposed as
`shared/tilemap_patches/patch_NN_buffer_M.tilemap`: `func_080A5BD8` proves an
exact length of `descriptor.width * descriptor.height * 2` for each buffer
and copies it row by row into the live map.  All fourteen buffers are
byte-identical in JP, US, EU and DE; their physical positions are still read
from the selected region's descriptor table.  These are source tilemaps, not
a JSON layout description.

The files deliberately are not exported as full PNG scenes.  A descriptor
also references raw lookup, tile-patch and palette-copy domains; the runtime
copies several of those domains across adjacent physical labels.  The code
proves the seven `+0x18` streams are 4bpp tiles, but does not yet prove a
single independent static palette plus tilemap/OAM layout for each one.
Rendering a convenient composite at this point would hide palette-bank,
lookup and runtime state information and would not be a trustworthy editable
source.

`shared/palettes/palette_NN_buffer_M.gbapal`: ten exact native BGR555 palette
source buffers selected by the seven descriptors.  Each is measured from the
descriptor's `palette_bank_count` (one 0x20-byte, 16-colour bank per count)
and copied by the retail DMA helper into `palette_bank`.  These deliberately
remain binary source files: a PNG swatch would not describe their stateful
destination bank or prove a full FarmHouse layout.

Build and verify every region:

```console
make gfx-farm-house-visual-all
make gfx-farm-house-visual-patch-test
make gfx-farm-house-tilemaps-all
make gfx-farm-house-tilemaps-patch-test
```

The unchanged sources retain the publisher's compressed byte stream.  An
intentional source edit is recompressed with the same decoder format and is
accepted only when it fits the original fixed interval.  The build also has a
deterministic changed-byte fixture covering every managed encoding format and
distance-ladder variant (Huffman-8/LZ3, Huffman-8/LZ2, ordinary
Huffman-4/LZ2, and 4-bit-differential Huffman-4/LZ2):

```console
make gfx-farm-house-visual-edit-test
make gfx-farm-house-tilemaps-edit-test
```

The `.4bpp` files are native source, not a JSON sidecar.  A future full-image
pipeline must first add a separately proven palette and layout source; it may
then generate reference PNGs without replacing these lossless tile payloads.
`LAYOUT_AUDIT.md` records the exact state-dependent tilemap-patch operation
and the remaining evidence needed for such a renderer.

Every stream remains bounded by its original packed interval.  An edit that
recompresses beyond that interval is rejected with the exact required and
available sizes; this is an intentional no-overwrite boundary, not silent
truncation or a claim that every pixel change is guaranteed to fit.
