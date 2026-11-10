#ifndef FONT_HH
#define FONT_HH

#include "prelude.h"

#ifdef __cplusplus
extern "C" {
#endif

// These native glyph expanders run in ARM IWRAM. Thumb callers use the
// compiler's normal interworking long call to their real entry points.
void DrawGlyph2Tile(u8 const *glyph, void *destination) __attribute__((long_call));
void DrawGlyph1Tile(u8 const *glyph, void *destination) __attribute__((long_call));

// Converts one Shift-JIS two-byte code to the index used by the font's
// double-width glyph map. Returns -1 for a code outside that map.
i32 GetShiftJisGlyphMapIndex(i32 character);
i32 DrawCharacterGlyph(void *destination, i32 character);

// Native runtime literal retained until its original emission is recovered.

// Fourteen uncompressed 4bpp UI numeral/symbol tiles. The native DMA users
// select their own character-RAM slot and runtime palette.
extern u32 const gUiNumberGlyphTiles[];

// Raw font payloads selected by the renderer. Single-width glyphs occupy
// 12 bytes; double-width glyphs occupy 24 bytes.
extern u8 const gFontSingleWidthGlyphData[];
extern i16 const gFontSingleByteGlyphIndices[256];
extern u8 const gFontDoubleWidthGlyphData[];
extern i16 const gFontShiftJisGlyphIndices[7938];

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern u8 const gFontSpecialGlyphBlocks[14][12];
extern u8 const gFontSpecialGlyphC3[12];
#else
extern u8 const gFontSpecialGlyph81CD[24];
#endif

#ifdef __cplusplus
}
#endif

#endif // FONT_HH
