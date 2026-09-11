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
// Draws a glyph with a caller-provided foreground/background palette pair.
// The original linker label is retained for raw assembly callers.
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

// The adjacent virtual object has not yet received a semantic class name.
// Its layout is retained here because its constructor is shared by both ROMs.
typedef struct UnkFontDrawObject
{
    void * unk_00;
    void * unk_04;
    void const * vtable;
    u32 unk_0c;
    u16 unk_10;
    u16 unk_12;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
} UnkFontDrawObject;

void Clear2DGfxBuffer(u32 size, void *buffer, u32 color);
void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 width,
    u32 height, u32 color);
// Copies every 32-byte tile in a packed two-dimensional 4bpp buffer.
void Copy2DGfxBuffer(u32 size, void *destination, void const *source)
    asm("func_0804E9D0");
// Fills a tilemap rectangle with sequential tile IDs. Only the low 16 bits
// of first_tile and palette are represented in each tilemap entry.
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride) asm("func_0804E9F4");
UnkFontDrawObject * InitializeUnkFontDrawObject(UnkFontDrawObject * object,
    u32 unk_0c, u16 unk_12, u32 unk_14, u32 unk_18, u16 unk_10,
    u32 unk_1c) asm("func_0804EA58");
void DestroyUnkFontDrawObject(UnkFontDrawObject * object)
    asm("func_0804EA80");
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

#if defined(REGION_WESTERN)
extern u8 const gFontSpecialGlyphBlocks[14][12];
extern u8 const gFontSpecialGlyphC3[12];
#else
extern u8 const gFontSpecialGlyph81CD[24];
#endif

EXTERN_C_END

#endif // FONT_HH
