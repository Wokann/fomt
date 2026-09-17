# Shared resource `08727A74`

`full/group_000.png` is the editable palette-indexed OAM-composited view of a
fixed `0x794`-byte `IndexedResourceArchive`. Native selector, descriptor, OAM,
tile placement, and BGR555 palette data remain the layout source; no JSON
sidecar is used. The single descriptor contains 36 native flipped OAM entries,
which are preserved by the generic rebuild instead of being flattened into a
new layout format.

The complete archive is byte-identical at JP `0x4ADBDC`, US `0x727A74`, EU
`0x727AD0`, and DE `0x4AEC40`. `preview/` is reference-only; compilation reads
`full/` only.
