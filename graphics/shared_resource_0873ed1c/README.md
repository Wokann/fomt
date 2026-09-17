# Shared resource `0873ED1C`

`full/group_*.png` files are the editable indexed-PNG sources for the ten
drawable native descriptors. The archive layout, OAM records, tile ranges,
palette tables, and eleven selection records remain part of the fixed
`0x6AC`-byte archive rebuild.

No JSON layout sidecar is used. `preview/` contains readable RGBA renderings
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C4E84`
(JP), `0x73ED1C` (US), `0x73ED78` (EU), and `0x4C6190` (DE).
