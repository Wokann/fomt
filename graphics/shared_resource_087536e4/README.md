# Shared resource `087536E4`

`full/group_*.png` files are the editable indexed-PNG sources for the four
drawable native OAM groups. The archive layout, descriptors, OAM records, tile
range, palette table, and selection records remain part of the fixed
`0xEC`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D9690`
(JP), `0x7536E4` (US), `0x753740` (EU), and `0x4DAC00` (DE).
