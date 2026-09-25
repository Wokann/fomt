# Shared resource `08740908`

`full/group_000.png` is the editable indexed-PNG source. The ordinary graphics
rules convert it to adjacent `.4bpp` and `.gbapal` files. Selection,
descriptor, OAM, and table-count records sit directly at the original position
in the assembly source; the generated tiles and palette are included there.
The resulting `0xDC` bytes are in the linked object, without a baserom read
or a post-link ROM patch in the production build.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C6A70`
(JP), `0x740908` (US), `0x740964` (EU), and `0x4C7D7C` (DE).
