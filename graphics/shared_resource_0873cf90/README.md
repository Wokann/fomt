# Shared resource `0873CF90`

`full/group_*.png` files are the editable indexed-PNG sources for the four
drawable native descriptors. The shared graphics rules generate their 4bpp
tiles and BGR555 palette; `archive.inc` keeps the native selection, descriptor,
and OAM tables in ROM order. Assembly links them directly without a base-ROM
template or post-link patch.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete `0x2A4`-byte archive is byte-identical and independently checked
at `0x4C30F8` (JP), `0x73CF90` (US), `0x73CFEC` (EU), and `0x4C42FC` (DE).
