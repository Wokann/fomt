# Shared resource `08740908`

`full/group_*.png` is the editable indexed-PNG source for the one drawable
native descriptor. The archive layout, OAM record, tile range, palette table,
and selection record remain part of the fixed `0xDC`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C6A70`
(JP), `0x740908` (US), `0x740964` (EU), and `0x4C7D7C` (DE).
