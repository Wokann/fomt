# Shared resource `0873ED1C`

`full/native.png` contains all 41 native tiles in ROM order. The two
independent 16-color banks are editable in `full/palettes.pal`. The ordinary
graphics rules generate `native.4bpp` and `palettes.gbapal`; `archive.inc`
declares the selection, descriptor, and OAM tables and links those assets
directly, without a ROM template or post-link patch. The existing
`full/group_*.png` files are rendered reference views, not build inputs.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C4E84`
(JP), `0x73ED1C` (US), `0x73ED78` (EU), and `0x4C6190` (DE).
