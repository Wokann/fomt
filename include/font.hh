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

// Writes two-byte full-width digits, spaces and hyphens followed by a NUL.
// Width zero uses the original ten-character limit; nonzero width pads or
// truncates to that many characters. Width must fit the original twelve-byte
// work buffers; output needs two bytes per resulting character plus the NUL.
void FormatFullWidthDecimal(i32 value, char * output, u32 width)
    SECTION(".text.font_decimal");

// Native signed ASCII formatter. A nonzero width pads or truncates the
// magnitude before prepending the sign; zero selects its actual digit count.
// The twelve-byte work buffer and the original extreme-input behavior remain.
void FormatSignedDecimal(i32 value, char * output, u32 width)
    SECTION(".text.font_decimal");

// Draws decimal digits from right to left, using four consecutive tiles per
// digit. right_tile points to the upper-right tile of the final digit;
// row_stride counts u16 entries, and palette occupies the tilemap's high bits.
void DrawDecimalTo2x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride) SECTION(".text.font_decimal");

// The metadata entries and native callbacks are not invoked through this
// opaque table type. Only their actual table addresses are used here.
typedef void (*FontTilemapDecimalVTableFunction)(void);
extern FontTilemapDecimalVTableFunction const vtable_unk_080E7838[];
extern FontTilemapDecimalVTableFunction const vtable_unk_080E7848[];
extern FontTilemapDecimalVTableFunction const vtable_unk_080E7858[];

typedef struct FontTilemapDecimalCommand {
    void * unk_00;
    void * unk_04;
    FontTilemapDecimalVTableFunction const * vtable;
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
} FontTilemapDecimalCommand;

typedef char FontTilemapDecimalCommandSizeCheck[sizeof(FontTilemapDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapDecimalCommandValueCheck[offsetof(FontTilemapDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapDecimalCommandDestinationCheck[offsetof(FontTilemapDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapDecimalCommandBaseTileCheck[offsetof(FontTilemapDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapDecimalCommandPaletteCheck[offsetof(FontTilemapDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapDecimalCommandRowStrideCheck[offsetof(FontTilemapDecimalCommand, row_stride) == 0x18 ? 1 : -1];

FontTilemapDecimalCommand * InitializeFontTilemapDecimalCommand(
    FontTilemapDecimalCommand * object, u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride) SECTION(".text.font_decimal");

void DestroyFontTilemapDecimalCommand(FontTilemapDecimalCommand * object,
    u32 flags) SECTION(".text.font_decimal");

// The overseas ROMs also have a one-column, two-row digit variant.
#if !defined(REGION_JP)
void DrawDecimalTo1x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride) SECTION(".text.font_decimal");
FontTilemapDecimalCommand * InitializeFontTilemapTallDecimalCommand(
    FontTilemapDecimalCommand * object, u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride) SECTION(".text.font_decimal");
void DestroyFontTilemapTallDecimalCommand(FontTilemapDecimalCommand * object,
    u32 flags) SECTION(".text.font_decimal");
#endif

// Single-tile digits use the same native field layout. row_stride is kept
// for the command ABI but this renderer writes only one row.
void DrawDecimalToTilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride) SECTION(".text.font_decimal");
FontTilemapDecimalCommand * InitializeFontTilemapSingleTileDecimalCommand(
    FontTilemapDecimalCommand * object, u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride) SECTION(".text.font_decimal");
void DestroyFontTilemapSingleTileDecimalCommand(FontTilemapDecimalCommand * object,
    u32 flags) SECTION(".text.font_decimal");
u32 RunFontTilemapSingleTileDecimalCommand(FontTilemapDecimalCommand * object)
    SECTION(".text.font_decimal");
#if !defined(REGION_JP)
u32 RunFontTilemapTallDecimalCommand(FontTilemapDecimalCommand * object)
    SECTION(".text.font_decimal");
#endif
u32 RunFontTilemapDecimalCommand(FontTilemapDecimalCommand * object)
    SECTION(".text.font_decimal");

// Writes an unsigned 32-bit value as ASCII decimal followed by a terminator.
// The caller provides space for up to ten digits and the terminator.
void FormatUnsignedDecimal(u32 value, char * output)
    SECTION(".text.font_unsigned_decimal");

// Draw one encoded glyph or a terminated encoded string into a two-dimensional
// 4bpp tile buffer. The packed size stores width in its low half and height
// in its high half; x and y are pixel coordinates.
i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character);
// Draws a glyph with a caller-provided foreground/background palette pair.
i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 foreground, i32 background);
// Both original unaligned paths return zero without modifying their
// destination. Assembly callers refer directly to these C linkage entries.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph);
i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 foreground,
    i32 background);

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
void Copy2DGfxBuffer(u32 size, void *destination, void const *source);
// Fills a tilemap rectangle with sequential tile IDs. Only the low 16 bits
// of first_tile and palette are represented in each tilemap entry.
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride);
UnkFontDrawObject * InitializeUnkFontDrawObject(UnkFontDrawObject * object,
    u32 unk_0c, u16 unk_12, u32 unk_14, u32 unk_18, u16 unk_10,
    u32 unk_1c);
void DestroyUnkFontDrawObject(UnkFontDrawObject * object, u32 flags);
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
