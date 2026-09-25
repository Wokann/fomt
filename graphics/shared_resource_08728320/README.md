# Shared resource `08728320`

`full/native.png` contains the 107 native tiles in ROM order as one strip;
the count cannot form a shorter rectangular atlas without padding. The
ordinary graphics rules generate `native.4bpp` and `native.gbapal` from it.
`archive.inc` links those assets with the native selector, descriptor, OAM,
and entry tables, without a ROM template or post-link patch. The existing
`full/group_*.png` are rendered reference views, not build inputs. No JSON
sidecar is used.

The complete archive is byte-identical at JP `0x4AE488`, US `0x728320`, EU
`0x72837C`, and DE `0x4AF4EC`. `preview/` is reference-only; compilation reads
`full/native.png` only.
