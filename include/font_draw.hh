#ifndef FONT_DRAW_HH
#define FONT_DRAW_HH

#include "prelude.h"
#ifdef __cplusplus
#include "hardware_linked_list.hh"
#endif

// Queued tilemap fill. Width and height count tiles; row_stride counts u16
// entries. Construction retains the low 16 bits of the tile and palette.
typedef struct FontTilemapRectCommand
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    u16 * destination;
    u16 palette;
    u16 first_tile;
    u32 width;
    u32 height;
    u32 row_stride;
#ifdef __cplusplus
    FontTilemapRectCommand(u16 * destination, u16 first_tile, u32 width,
        u32 height, u16 palette, u32 row_stride);
    virtual ~FontTilemapRectCommand();
    virtual bool Run();
#endif
} FontTilemapRectCommand;

typedef char FontTilemapRectCommandSizeCheck[sizeof(FontTilemapRectCommand) == 0x20 ? 1 : -1];
typedef char FontTilemapRectCommandDestinationCheck[offsetof(FontTilemapRectCommand, destination) == 0x0C ? 1 : -1];
typedef char FontTilemapRectCommandPaletteCheck[offsetof(FontTilemapRectCommand, palette) == 0x10 ? 1 : -1];
typedef char FontTilemapRectCommandFirstTileCheck[offsetof(FontTilemapRectCommand, first_tile) == 0x12 ? 1 : -1];
typedef char FontTilemapRectCommandWidthCheck[offsetof(FontTilemapRectCommand, width) == 0x14 ? 1 : -1];
typedef char FontTilemapRectCommandHeightCheck[offsetof(FontTilemapRectCommand, height) == 0x18 ? 1 : -1];
typedef char FontTilemapRectCommandStrideCheck[offsetof(FontTilemapRectCommand, row_stride) == 0x1C ? 1 : -1];

EXTERN_C

// The packed size is tile width in its low half and tile height in its high
// half. Glyph coordinates are pixels; the destination is a 4bpp tile buffer.
i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character);
i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 foreground, i32 background);
// The native unaligned paths deliberately return zero without drawing.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph);
i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 foreground, i32 background);
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color);
void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 width,
    u32 height, u32 color);
void Copy2DGfxBuffer(u32 size, void *destination, void const *source);
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride);
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string);
void DrawStringTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string, i32 foreground, i32 background);

EXTERN_C_END

#endif // FONT_DRAW_HH
