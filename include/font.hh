#ifndef FONT_HH
#define FONT_HH

#include "prelude.h"
#include "font_draw.hh"

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
#if !defined(REGION_JP)
extern FontTilemapDecimalVTableFunction const vtable_unk_080E7858[];
#endif

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
