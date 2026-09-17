# Shared resource `087405A0`

`full/group_*.png` is the editable indexed-PNG source for the one drawable
native descriptor. The archive layout, OAM records, tile range, palette table,
and selection record remain part of the fixed `0x368`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C6708`
(JP), `0x7405A0` (US), `0x7405FC` (EU), and `0x4C7A14` (DE).
