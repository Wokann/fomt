# Shared resource `08740454`

`full/group_*.png` files are the editable indexed-PNG sources for the three
drawable native descriptors. The archive layout, OAM records (including three
native flips), tile range, palette table, and selection records remain part of
the fixed `0x14C`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C65BC`
(JP), `0x740454` (US), `0x7404B0` (EU), and `0x4C78C8` (DE).
