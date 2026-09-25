# Shared resource `0873D5FC`

`full/group_000.png` is the editable indexed-PNG source. The ordinary graphics
rules convert it to adjacent `.4bpp` and `.gbapal` files. The selection,
descriptor, OAM, and table-count records are written directly at the archive's
physical position in `asm/data/data_0813B288.s` (and its DE initial include).
The assembler includes the generated tiles and palette between those records.
The resulting `0xDC` bytes are therefore present in the linked object; the
production build does not read a baserom or patch the finished ROM for this
archive.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C3764`
(JP), `0x73D5FC` (US), `0x73D658` (EU), and `0x4C4968` (DE).
