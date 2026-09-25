# Shared resource `087506E0`

`full/native.png` contains all 36 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
declares the native selection, descriptor, and OAM tables and links those
assets directly, without a ROM template or post-link patch. The existing
`full/group_*.png` files are rendered reference views, not build inputs.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D668C`
(JP), `0x7506E0` (US), `0x75073C` (EU), and `0x4D7BFC` (DE).
