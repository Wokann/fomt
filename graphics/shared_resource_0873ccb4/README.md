# Shared resource `0873CCB4`

`full/group_*.png` files are the editable indexed-PNG sources for the two
drawable native descriptors. The archive layout, OAM records, tile range,
palette table, and selection records remain part of the fixed `0x1F8`-byte
archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C2E1C`
(JP), `0x73CCB4` (US), `0x73CD10` (EU), and `0x4C4020` (DE).
