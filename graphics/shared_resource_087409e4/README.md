# Shared resource `087409E4`

`full/group_*.png` files are the editable indexed-PNG sources for the three
drawable native OAM groups. The archive layout, descriptor, OAM records, tile
range, palette table, and selection records remain part of the fixed
`0x1010`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C6B4C`
(JP), `0x7409E4` (US), `0x740A40` (EU), and `0x4C7E58` (DE).
