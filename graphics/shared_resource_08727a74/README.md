# Shared resource `08727A74`

`full/native.png` contains the 49 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
links those assets with the native selector, descriptor, OAM, and entry tables,
without a ROM template or post-link patch. The 36 flipped OAM entries remain
in their original table layout. `full/group_000.png` is a rendered reference
view, not a build input. No JSON sidecar is used.

The complete archive is byte-identical at JP `0x4ADBDC`, US `0x727A74`, EU
`0x727AD0`, and DE `0x4AEC40`. `preview/` is reference-only; compilation reads
`full/native.png` only.
