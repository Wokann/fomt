# Shared resource `08753608`

`full/group_000.png` is the editable indexed-PNG source. The ordinary graphics
rules convert it to adjacent `.4bpp` and `.gbapal` files. Selection,
descriptor, OAM, and table-count records sit directly at the original position
in the assembly source; the generated tiles and palette are included there.
The resulting `0xDC` bytes are in the linked object, without a baserom read
or a post-link ROM patch in the production build.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D95B4`
(JP), `0x753608` (US), `0x753664` (EU), and `0x4DAB24` (DE).
