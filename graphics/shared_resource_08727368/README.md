# Shared resource `08727368`

`full/group_*.png` are the editable palette-indexed OAM-composited views of a
fixed `0x70C`-byte `IndexedResourceArchive`. Native selectors, descriptors,
OAM, tile placement, and BGR555 palette data remain the layout source; no JSON
sidecar is used. Descriptor groups `005` and `020` are all-zero native slots,
so no source PNG is invented for them.

The complete archive is byte-identical at JP `0x4AD4D0`, US `0x727368`, EU
`0x7273C4`, and DE `0x4AE534`. `preview/` is reference-only; compilation reads
`full/` only.
