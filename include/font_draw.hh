#ifndef FONT_DRAW_HH
#define FONT_DRAW_HH

#include "prelude.h"
#ifdef __cplusplus
#include "hardware_linked_list.hh"
#pragma interface "font_draw.hh"
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


EXTERN_C

// The packed size is tile width in its low half and tile height in its high
// half. Glyph coordinates are pixels; the destination is a 4bpp tile buffer.
// Extended draws map palette 0 to background, 1 to foreground, and 2 to
// foreground + 1 (shadow), preserving the native parameter order.
i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character);
i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 background, i32 foreground);
// The native unaligned paths deliberately return zero without drawing.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph);
i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 background, i32 foreground);
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color);
void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 width,
    u32 height, u32 color);
void Copy2DGfxBuffer(u32 size, void *destination, void const *source);
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride);
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string);
void DrawStringTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string, i32 background, i32 foreground);

EXTERN_C_END

#ifdef __cplusplus
#endif

#endif // FONT_DRAW_HH
