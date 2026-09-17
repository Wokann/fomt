# Shared resource `0873AE54`

`full/group_*.png` files are the editable indexed-PNG sources for the two
drawable native descriptors. The archive layout, OAM records, palette table,
and selection records remain part of the fixed `0x174`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C0FBC`
(JP), `0x73AE54` (US), `0x73AEB0` (EU), and `0x4C21C0` (DE).
