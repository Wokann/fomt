# Shared resource `0873D234`

`full/native.png` contains all 24 native tiles in ROM order. The ordinary
graphics rules generate its 4bpp and BGR555 palette assets; `archive.inc`
declares the selection, descriptor, and OAM tables and links those assets
directly. No ROM template or post-link patch is involved. The existing
`full/group_*.png` files are rendered reference views, not build inputs.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C339C`
(JP), `0x73D234` (US), `0x73D290` (EU), and `0x4C45A0` (DE).
