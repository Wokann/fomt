# Shared resource `087536E4`

`full/native.png` contains both native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
declares the native selection, descriptor, and OAM tables and links those
assets directly, without a ROM template or post-link patch. The existing
`full/group_*.png` files are rendered reference views, not build inputs.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4D9690`
(JP), `0x7536E4` (US), `0x753740` (EU), and `0x4DAC00` (DE).
