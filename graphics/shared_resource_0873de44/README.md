# Shared resource `0873DE44`

`full/group_*.png` is the editable indexed-PNG source for the one drawable
native descriptor. The archive layout, OAM record, tile range, palette table,
and selection record remain part of the fixed `0x76C`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C3FAC`
(JP), `0x73DE44` (US), `0x73DEA0` (EU), and `0x4C52B8` (DE).
