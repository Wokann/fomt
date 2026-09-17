# Shared resource `0874EE38`

`full/group_*.png` is the editable indexed-PNG source for the one drawable
native descriptor. The archive layout, OAM record, tile range, palette table,
and selection record remain part of the fixed `0xDC`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D5354`
(JP), `0x74EE38` (US), `0x74EE94` (EU), and `0x4D62A4` (DE).
