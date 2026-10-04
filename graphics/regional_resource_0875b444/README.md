# Regional `0875B444` indexed OAM archive

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`gUnk_0875B444` has one fixed `IndexedResourceArchive` layout in every retail
FoMT region: six selection records, six group descriptors, one BGR555 palette,
twenty-four 4bpp tiles, and six drawable OAM groups.  The complete JP payload
is distinct; US, EU, and DE share the other complete payload.  The source
trees therefore follow the two verified byte domains:

| Source tree | Regions | ROM offsets | SHA-256 |
| --- | --- | --- | --- |
| `jp/` | JP | `0x4E07CC` | `a3aff94806fef413110271384ca4eed8aef15a02c968528e68935b1f73e18ccb` |
| `overseas/` | US / EU / DE | `0x75B444` / `0x75B4A0` / `0x4E2960` | `8da8ca4fbff49ad00f1ba1f81243cb56718b42741524531b1cf3e307a5693218` |

`full/group_*.png` are editable indexed-PNG sources. The ordinary graphics
rules convert them to `.4bpp` tiles and a `.gbapal` palette. The native
selection, descriptor, OAM, and entry tables are in `archive.inc`, included
at their original locations by `asm/data/data_0813B288.s` (and its DE
initial fragment). The linker assembles the archive directly; the build
does not read a base ROM or patch the linked ROM for this resource.
`preview/group_*.png` are OAM-rendered inspection images only.

The first command generates JP tiles and palette from PNG. The ROM targets
link the selected assets and can be checked against their retail SHA-1 values.
The same targets for EU and DE verify the shared overseas asset domain.
