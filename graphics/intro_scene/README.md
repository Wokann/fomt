# Intro Scene graphics

`shared/background_tiles.png` and `shared/background_palettes.png` are the
authoritative editable sources for the decoded linear 4bpp Intro Scene VRAM
payload and its three BGR555 palette banks.

The checked source represents the native tile order. It is not a guessed final
screen layout: other Intro Scene resources, palette choices, display registers
and possible composition remain distinct runtime data. The original stream is
used byte-for-byte when source pixels are unchanged. Edited tiles are rebuilt
to 4bpp, encoded into a valid `0x70` stream, strictly decoded, and rejected if
they do not fit the original 0x49BC-byte allocation.

`shared/object_tiles/object_00.4bpp` through `object_19.4bpp` are the twenty
additional streams loaded by the same routine. Each decodes to exactly `0x500`
bytes and is copied into the intro object's tile staging area before the
runtime object code uploads it to OBJ VRAM. All twenty packed streams and
decoded payloads are byte-identical in JP, US, EU and DE.

They are intentionally checked in as native 4bpp tile sources, not fabricated
full-image PNGs: their OAM composition and per-object palette selection are
still runtime data and have not yet been independently reconstructed. This is
an editable and lossless source representation without a JSON layout sidecar;
it is also the appropriate input for a later verified OAM/full-PNG tool.

`OBJECT_PIPELINE_AUDIT.md` records the code-backed boundary: the twenty
streams are a fixed VRAM loading sequence, while the scene's actual frame,
OAM-piece and palette selection come from runtime indexed-resource handles.

```console
make gfx-intro-objects-all
```

Unchanged sources retain their exact retail packed bytes. An edit is re-encoded
with the stream's original Raw-LZ mode and distance ladder, strictly decoded,
and rejected if it exceeds that object's original packed allocation.

## Startup background layers

`func_080019D8` additionally expands a shared `0x8000`-byte 4bpp tile payload,
loads sixteen BGR555 palette banks, and then uses the four native startup-map
sources.  The tiles and palette banks are verified byte-identically against
the JP, US, EU and DE ROMs and are available under
`shared/startup_visual/`.

`shared/startup_tilemaps/startup_00.tilemap` through `startup_03.tilemap`
remain the authoritative editable layout sources.  Each `0x1000`-byte source
contains two 32-by-32 BG maps in alternating 0x40-byte rows.  The eight PNGs
under `reference/startup/` are generated from that proven row split, tile IDs,
flip bits and palette-bank fields; they are visual references only, because a
flat PNG cannot preserve those native map fields.

The startup tile payload uses the `230` Huffman-8/LZ3 family.  Its tile and
palette sources are linked back into the original ranges.  An unchanged tile
source retains the exact retail stream; an edited source is strictly decoded
after H8/LZ3 encoding and rejected if it exceeds the original `0x3970` slot.
The checked edit fixture changes a real tile byte and succeeds in that slot.
The native startup maps remain independently editable and rebuild through
their verified Huffman-4/LZ3 path.

```console
make gfx-intro-startup-visual-test
make gfx-intro-startup-visual-reference
make gfx-intro-startup-visual-edit-test
make gfx-intro-startup-tilemaps-all
```
