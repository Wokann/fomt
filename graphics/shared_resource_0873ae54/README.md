# Shared resource `0873AE54`

`full/group_000.png` and `full/group_001.png` are the editable indexed-PNG
sources. The ordinary graphics rules convert them to adjacent `.4bpp` and
`.gbapal` files. The two pictures must retain the same palette: the graphics
target compares the generated palette files and fails if they differ. The
selection, descriptor, OAM, and table-count records sit at the original
position in the assembly source, with both generated tile runs and the shared
palette included between them. The resulting `0x174` bytes are linked without
a baserom read or post-link ROM patch in the production build.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C0FBC`
(JP), `0x73AE54` (US), `0x73AEB0` (EU), and `0x4C21C0` (DE).
