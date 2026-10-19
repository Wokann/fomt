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

EXTERN_C_END

// These sibling queue commands retain the same payload layout, but have
// distinct virtual drawing methods. right_tile is the upper-right tile of
// the final digit. The base unlinks a command when its Run returns false.
typedef struct FontTilemapDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride) SECTION(".text.font_decimal");
    virtual ~FontTilemapDecimalCommand() SECTION(".text.font_decimal");
    virtual bool Run() SECTION(".text.font_decimal");
#endif
} FontTilemapDecimalCommand;

typedef char FontTilemapDecimalCommandSizeCheck[sizeof(FontTilemapDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapDecimalCommandValueCheck[offsetof(FontTilemapDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapDecimalCommandDestinationCheck[offsetof(FontTilemapDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapDecimalCommandBaseTileCheck[offsetof(FontTilemapDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapDecimalCommandPaletteCheck[offsetof(FontTilemapDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapDecimalCommandRowStrideCheck[offsetof(FontTilemapDecimalCommand, row_stride) == 0x18 ? 1 : -1];

// Overseas ROMs insert the one-column, two-row variant. JP has no such class.
#if !defined(REGION_JP)
typedef struct FontTilemapTallDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapTallDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride) SECTION(".text.font_decimal");
    virtual ~FontTilemapTallDecimalCommand() SECTION(".text.font_decimal");
    virtual bool Run() SECTION(".text.font_decimal");
#endif
} FontTilemapTallDecimalCommand;

typedef char FontTilemapTallDecimalCommandSizeCheck[sizeof(FontTilemapTallDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapTallDecimalCommandValueCheck[offsetof(FontTilemapTallDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapTallDecimalCommandDestinationCheck[offsetof(FontTilemapTallDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandBaseTileCheck[offsetof(FontTilemapTallDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandPaletteCheck[offsetof(FontTilemapTallDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapTallDecimalCommandStrideCheck[offsetof(FontTilemapTallDecimalCommand, row_stride) == 0x18 ? 1 : -1];
#endif

// Single-tile digits retain row_stride in the ABI but write only one row.
typedef struct FontTilemapSingleTileDecimalCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u32 value;
    u16 * right_tile;
    u16 base_tile;
    u16 palette;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapSingleTileDecimalCommand(u32 value, u16 * right_tile, u16 base_tile,
        u16 palette, u32 row_stride) SECTION(".text.font_decimal");
    virtual ~FontTilemapSingleTileDecimalCommand() SECTION(".text.font_decimal");
    virtual bool Run() SECTION(".text.font_decimal");
#endif
} FontTilemapSingleTileDecimalCommand;

typedef char FontTilemapSingleTileDecimalCommandSizeCheck[sizeof(FontTilemapSingleTileDecimalCommand) == 0x1C ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandValueCheck[offsetof(FontTilemapSingleTileDecimalCommand, value) == 0x0C ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandDestinationCheck[offsetof(FontTilemapSingleTileDecimalCommand, right_tile) == 0x10 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandBaseTileCheck[offsetof(FontTilemapSingleTileDecimalCommand, base_tile) == 0x14 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandPaletteCheck[offsetof(FontTilemapSingleTileDecimalCommand, palette) == 0x16 ? 1 : -1];
typedef char FontTilemapSingleTileDecimalCommandStrideCheck[offsetof(FontTilemapSingleTileDecimalCommand, row_stride) == 0x18 ? 1 : -1];

EXTERN_C

#if !defined(REGION_JP)
void DrawDecimalTo1x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride) SECTION(".text.font_decimal");
#endif
void DrawDecimalToTilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride) SECTION(".text.font_decimal");

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
