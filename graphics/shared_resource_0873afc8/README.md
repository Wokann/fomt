# Shared resource `0873AFC8`

`full/group_*.png` files are the editable indexed-PNG source for the drawable
native descriptor. The archive layout, OAM record, tile range, palette table,
and selection record remain part of the fixed `0xE5C`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C1130`
(JP), `0x73AFC8` (US), `0x73B024` (EU), and `0x4C2334` (DE).
