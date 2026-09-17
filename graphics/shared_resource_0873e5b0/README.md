# Shared resource `0873E5B0`

`full/group_*.png` is the editable indexed-PNG source for the one drawable
native descriptor. The archive layout, OAM record, tile range, palette table,
and selection record remain part of the fixed `0x76C`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C4718`
(JP), `0x73E5B0` (US), `0x73E60C` (EU), and `0x4C5A24` (DE).
