# Shared resource `0872937C`

`full/group_*.png` are the editable palette-indexed OAM-composited views of a
`0xE4`-byte `IndexedResourceArchive`. The shared graphics rules generate 4bpp
tiles and a BGR555 palette. `archive.inc` keeps the native selector, descriptor,
OAM, and selection tables in ROM order; assembly links them directly without
a base-ROM template or post-link patch.

The complete archive is byte-identical at JP `0x4AF4E4`, US `0x72937C`, EU
`0x7293D8`, and DE `0x4B0548`. `preview/` is reference-only; compilation reads
`full/` only.
