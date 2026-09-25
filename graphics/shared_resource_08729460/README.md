# Shared resource `08729460`

`full/native.png` is the editable native-order tile and palette source for this
`0x2A04`-byte `IndexedResourceArchive`. `full/group_*.png` are reference-only
OAM-composited views: their visual tile order differs from ROM tile order.
The native selectors, descriptors, OAM, and selection entries are written in
`archive.inc`. Ordinary graphics rules convert `native.png` to `.4bpp` tiles
and a `.gbapal` palette, and the assembler links those pieces directly without
a ROM template or post-link patch.

The complete archive is byte-identical at JP `0x4AF5C8`, US `0x729460`, EU
`0x7294BC`, and DE `0x4B062C`. `preview/` is reference-only; compilation reads
`full/native.png` and `archive.inc` only.
