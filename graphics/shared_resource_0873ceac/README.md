# Shared resource `0873CEAC`

`full/group_*.png` is the editable indexed-PNG source for the drawable native
descriptor. The archive layout, OAM record, tile range, palette table, and
selection record remain part of the fixed `0xE4`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C3014`
(JP), `0x73CEAC` (US), `0x73CF08` (EU), and `0x4C4218` (DE).
