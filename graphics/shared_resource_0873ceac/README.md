# Shared resource `0873CEAC`

`full/group_000.png` is the editable indexed-PNG source for the drawable
descriptor. The shared graphics rules generate its 4bpp tiles and BGR555
palette; `archive.inc` keeps the native selection, descriptor, and OAM tables
in ROM order. Assembly links them directly, without a base-ROM template or
post-link patch.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete `0xE4`-byte archive is byte-identical and independently checked
at `0x4C3014` (JP), `0x73CEAC` (US), `0x73CF08` (EU), and `0x4C4218` (DE).
