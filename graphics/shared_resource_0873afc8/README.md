# Shared resource `0873AFC8`

`full/native.png` is the editable native-order tile and palette source for this
`0xE5C`-byte archive. `full/group_000.png` is a reference-only OAM-composited
view: its visual tile order differs from ROM tile order. The native selectors,
descriptor, OAM, and selection entry are written in `archive.inc`. Ordinary
graphics rules convert `native.png` to `.4bpp` tiles and a `.gbapal` palette,
and the assembler links those pieces directly without a ROM template or
post-link patch.

No JSON layout sidecar is used. `preview/` contains a readable RGBA rendering
generated from the native descriptor and OAM layout, and is reference-only.

The complete archive is byte-identical and independently checked at `0x4C1130`
(JP), `0x73AFC8` (US), `0x73B024` (EU), and `0x4C2334` (DE).
