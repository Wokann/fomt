# Shared resource `08755154`

`full/group_000.png` is the editable indexed-PNG source. The ordinary graphics
rules convert it to adjacent `.4bpp` and `.gbapal` files. Selection,
descriptor, OAM, and table-count records sit directly at the original position
in the assembly source; the generated tiles and palette are included there.
The resulting `0xDC` bytes are in the linked object, without a baserom read
or a post-link ROM patch in the production build.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4DB100`
(JP), `0x755154` (US), `0x7551B0` (EU), and `0x4DC670` (DE).
