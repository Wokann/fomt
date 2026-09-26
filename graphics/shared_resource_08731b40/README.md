# Shared resource `08731B40`

`full/native.png` stores all 794 native 4bpp tiles in their physical archive
order. `full/native.pal` stores the three 16-color BGR555 palettes. The generic
graphics rules convert them to adjacent `.4bpp` and `.gbapal` products, while
`archive.inc` defines the original selector, descriptor, OAM, and final index
tables in their ROM order. The `group_*.png` files are OAM-composited reference
views, not build inputs.

The complete `0x6604`-byte archive is identical at JP `0x4B7CA8`, US
`0x731B40`, EU `0x731B9C`, and DE `0x4B8EAC`. Both archive tile and palette
sources round-trip byte-exactly, and all four complete ROM builds match their
original SHA-1 values. The normal build neither reads a base ROM for this
archive nor patches the linked ROM afterward.
