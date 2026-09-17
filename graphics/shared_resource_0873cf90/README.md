# Shared resource `0873CF90`

`full/group_*.png` files are the editable indexed-PNG sources for the four
drawable native descriptors. The archive layout, OAM records, tile range,
palette table, and selection records remain part of the fixed `0x2A4`-byte
archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C30F8`
(JP), `0x73CF90` (US), `0x73CFEC` (EU), and `0x4C42FC` (DE).
