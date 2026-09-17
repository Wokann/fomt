# Shared resource `087401A4`

`full/group_*.png` files are the editable indexed-PNG sources for the four
drawable native descriptors. The archive layout, OAM records, tile range,
palette table, and selection records remain part of the fixed `0x2B0`-byte
archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C630C`
(JP), `0x7401A4` (US), `0x740200` (EU), and `0x4C7618` (DE).
