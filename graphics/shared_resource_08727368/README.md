# Shared resource `08727368`

`full/native.png` contains the 22 native tiles in ROM order. The ordinary
graphics rules generate `native.4bpp` and `native.gbapal` from it. `archive.inc`
links those assets with the native selector, descriptor, OAM, and entry tables,
without a ROM template or post-link patch. The existing `full/group_*.png`
are rendered reference views, not build inputs. Descriptor groups `005` and
`020` are all-zero native slots; no source image is invented for them.

The complete archive is byte-identical at JP `0x4AD4D0`, US `0x727368`, EU
`0x7273C4`, and DE `0x4AE534`. `preview/` is reference-only; compilation reads
`full/native.png` only.
