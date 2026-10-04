# Cooking UI OAM archive

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`full/native.png` is the editable native-order atlas of all 40 4bpp tiles;
`full/native.pal` contains the one BGR555 palette bank. Ordinary suffix
rules generate `.4bpp` and `.gbapal` beside these sources. `archive.inc`
preserves the original selector, descriptor, OAM, and selection tables and
includes those generated assets at the archive's physical ROM position.
The `group_*.png` files are composited reference views only: their displayed
tile order is not the original packed tile order.

The archive has one selection descriptor, three resource descriptors (two
drawable and one all-zero), three OAM records, and four selection entries.
The cooking constructors instantiate it; the group names remain physical
IDs because their separate gameplay meanings have not been established.

The archive is identical in all four versions, occupies `0x598` bytes, and
begins at JP `0x4DA620`, US `0x754674`, EU `0x7546D0`, and DE `0x4DBB90`.
The subsequent resource starts exactly `0x598` bytes later in each version.
Normal builds do not read a baserom or patch this archive after linking.
