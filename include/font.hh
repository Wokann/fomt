#ifndef FONT_HH
#define FONT_HH

#include "prelude.h"

EXTERN_C

// Converts one Shift-JIS two-byte code to the index used by the font's
// double-width glyph map. Returns -1 for a code outside that map.
i32 GetShiftJisGlyphMapIndex(i32 character);
i32 DrawCharacterGlyph(void *destination, i32 character);

// Draw one encoded glyph or a terminated encoded string into a two-dimensional
// 4bpp tile buffer. The packed size stores width in its low half and height
// in its high half; x and y are pixel coordinates.
i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character) asm("func_0804E4AC");
// The extended compositor remains in the raw block for now. Keeping its
// original linker label lets normal C++ callers use its semantic declaration.
i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 foreground, i32 background) asm("func_0804E5AC");
// Both original unaligned paths return zero without modifying their
// destination. Keeping their original linker labels lets the raw callers
// retain ordinary C/C++ definitions instead of four-byte assembly stubs.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph) asm("func_0804E9C8");
i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 foreground,
    i32 background) asm("func_0804E9CC");
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color);
void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 width,
    u32 height, u32 color);
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string);
void DrawStringTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string, i32 foreground, i32 background);

// Raw font payloads selected by the renderer. Single-width glyphs occupy
// 12 bytes; double-width glyphs occupy 24 bytes.
extern u8 const gFontSingleWidthGlyphData[];
extern i16 const gFontSingleByteGlyphIndices[256];
extern u8 const gFontDoubleWidthGlyphData[];
extern i16 const gFontShiftJisGlyphIndices[7938];

#if defined(REGION_US)
extern u8 const gFontSpecialGlyphBlocks[14][12];
extern u8 const gFontSpecialGlyphC3[12];
#else
extern u8 const gFontSpecialGlyph81CD[24];
#endif

EXTERN_C_END

#endif // FONT_HH
