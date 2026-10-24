#ifndef UI_TEXT_WINDOW_HH
#define UI_TEXT_WINDOW_HH

#include "prelude.h"

EXTERN_C

// Draw a nine-tile frame in one 32x32 BG screen block. Coordinates wrap
// modulo 32; the right and bottom edges clip. Effective dimensions must
// both be at least three. The tile index uses ten bits and the palette four;
// the original 16-bit tile-offset arithmetic is retained.
void DrawUiTextWindowBorder(u16 * tilemap, u32 x, u32 y, u32 width, u32 height,
    u32 first_tile, u32 palette);

EXTERN_C_END

#endif // UI_TEXT_WINDOW_HH
