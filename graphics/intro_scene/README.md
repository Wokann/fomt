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

```console
make gfx-intro-objects-all
```

Unchanged sources retain their exact retail packed bytes. An edit is re-encoded
with the stream's original Raw-LZ mode and distance ladder, strictly decoded,
and rejected if it exceeds that object's original packed allocation.
