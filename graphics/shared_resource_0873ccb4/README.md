# Shared resource `0873CCB4`

`full/native.png` contains all 12 native 4bpp tiles in their original order.
The ordinary graphics rules generate `native.4bpp` and `native.gbapal` from
it. `archive.inc` declares the native selection, descriptor, and OAM tables
and links those generated assets directly, without a ROM template or a
post-link patch. The existing `full/group_*.png` files are rendered reference
views, not build inputs: their composite pixel order is not the native tile
order.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C2E1C`
(JP), `0x73CCB4` (US), `0x73CD10` (EU), and `0x4C4020` (DE).
