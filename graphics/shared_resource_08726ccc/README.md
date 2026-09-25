# Shared resource `08726CCC`

`full/native.png` contains all 48 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
links those assets with the original selector, descriptor, OAM, and entry
tables, without a ROM template or post-link patch. `full/group_000.png` is a
rendered reference view, not a build input. No JSON sidecar is used.

The complete `0x69C`-byte archive is byte-identical at JP `0x4ACE34`, US
`0x726CCC`, EU `0x726D28`, and DE `0x4ADE98`.

`preview/` is reference-only; compilation reads `full/native.png` only.
