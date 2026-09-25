# Shared resource `087405A0`

`full/native.png` contains all 24 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
declares the native selection, descriptor, and OAM tables and links those
assets directly, without a ROM template or post-link patch. The existing
`full/group_000.png` is a rendered reference view, not a build input.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C6708`
(JP), `0x7405A0` (US), `0x7405FC` (EU), and `0x4C7A14` (DE).
