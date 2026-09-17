# Shared resource `0873D234`

`full/group_*.png` files are the editable indexed-PNG sources for the six
drawable native descriptors. The archive layout, OAM records, tile range,
palette table, and selection records remain part of the fixed `0x3C8`-byte
archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C339C`
(JP), `0x73D234` (US), `0x73D290` (EU), and `0x4C45A0` (DE).
