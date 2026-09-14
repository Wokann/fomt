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

The nearby twenty 0x500-byte `Unpack` inputs are separately tracked but remain
raw until their consumer and palette/OAM relationships are proven.
