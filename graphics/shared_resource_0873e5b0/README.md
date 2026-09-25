# Shared resource `0873E5B0`

`full/native.png` contains all 56 native tiles in ROM order. The ordinary
graphics rules generate its 4bpp and BGR555 palette assets; `archive.inc`
declares the selection, descriptor, and OAM tables and links those assets
directly. No ROM template or post-link patch is involved. The existing
`full/group_000.png` is a rendered reference view, not a build input.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C4718`
(JP), `0x73E5B0` (US), `0x73E60C` (EU), and `0x4C5A24` (DE).
