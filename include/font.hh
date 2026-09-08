#ifndef FONT_HH
#define FONT_HH

#include "prelude.h"

EXTERN_C

// Converts one Shift-JIS two-byte code to the index used by the font's
// double-width glyph map. Returns -1 for a code outside that map.
i32 GetShiftJisGlyphMapIndex(i32 character);

#if defined(REGION_US)
extern u8 const gFontSpecialGlyphBlocks[14][12];
#endif

EXTERN_C_END

#endif // FONT_HH
