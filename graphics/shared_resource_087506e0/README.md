# Shared resource `087506E0`

`full/group_*.png` files are the editable indexed-PNG sources for the four
drawable native OAM groups. The archive layout, descriptor, OAM records, tile
range, palette table, and selection records remain part of the fixed
`0x56C`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D668C`
(JP), `0x7506E0` (US), `0x75073C` (EU), and `0x4D7BFC` (DE).
