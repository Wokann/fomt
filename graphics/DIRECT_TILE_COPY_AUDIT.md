# Direct tile-copy audit

This inventory records raw tile payloads whose consumers copy fixed tile
records directly instead of calling a decompressor.  A row is not eligible for
the managed-resource table merely because its bytes decode as tiles: its native
range, regional placement, palette ownership, and presentation layout must all
be established first.

## Overseas calendar/clock glyph set

`gUnk_0875A440` (annotated `gClockFont`) is a proven direct-copy glyph source
for the overseas code path.  In `asm/code_0803A8A4.s`, the consumers form a
source address as `gUnk_0875A440 + (glyph_index << 5)` and copy exactly
`0x20` bytes with `memcpy`.  This establishes 4bpp 8-by-8 glyph records, not
an OAM atlas or a screen-layout image.

The assembly label covers `0x1004` bytes.  Its first `0x1000` bytes are 128
complete 0x20-byte glyph records.  The final four bytes are retained as part
of the original labelled range but have not yet been proven to be a glyph or
font metadata, so they must not be silently discarded or drawn as a tile.

| Region | Physical offset | Labelled length | Payload relation |
| --- | ---: | ---: | --- |
| US | `0x75A440` | `0x1004` | Baseline overseas payload |
| EU | `0x75A49C` | `0x1004` | Byte-identical to US; only its physical placement differs |
| DE | `0x75C4C0` | `0x1004` | Same direct-copy format but distinct localized bytes |
| JP | — | — | No corresponding overseas `gClockFont` consumer or byte-identical payload has been established |

The glyph-copy calls do not copy a palette with this payload.  The palette
selection and any character-to-glyph mapping still need independent runtime
evidence.  The set is therefore managed as an **indexed source**, not as an
in-game colour rendering: `graphics/ui/clock_font/{us_eu,de}/glyph_indices.png`
uses a neutral index palette solely to expose the native pixel values.  Its
source palette is editor-only and is ignored during rebuilding.  The pipeline
reorders its 16-by-8 glyph sheet back to the original 128 sequential records,
then appends the verified four-byte `shared/tail.bin` unchanged.  This supplies
a reversible glyph-editing path without claiming an unproven display palette.
