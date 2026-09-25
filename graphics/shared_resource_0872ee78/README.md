# Shared resource `0872EE78`

`full/group_*.png` are the editable palette-indexed OAM-composited views of a
`0x2A4`-byte `IndexedResourceArchive`. The native selectors, descriptors, OAM,
and selection entries are written in `archive.inc`; ordinary graphics rules
convert the PNGs to `.4bpp` tiles and the first PNG to a `.gbapal` palette.
The assembler links those pieces directly without a ROM template or post-link
patch.

The complete archive is byte-identical at JP `0x4B4FE0`, US `0x72EE78`, EU
`0x72EED4`, and DE `0x4B61E4`. `preview/` is reference-only; compilation reads
`full/` and `archive.inc` only.
