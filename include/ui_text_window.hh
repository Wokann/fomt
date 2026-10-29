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

#ifdef __cplusplus
#include "hardware_linked_list.hh"

#pragma interface "ui_text_window.hh"

struct PACKED UiTextWindowBorderStyle {
    u8 screen_block : 5;
    u16 first_tile : 10;
    u32 palette : 4;
    u32 unk_high : 13;
};

// This queued command redraws a BG screen block and installs its palette.
// The second payload word is not read by this drawing callback.
struct UiTextWindowBorderCommand : HardwareLinkBase {
    virtual bool Run() SECTION(".text.ui_text_window_border_command");
    u32 x;
    u32 unk_10;
    u32 width;
    u32 height;
    UiTextWindowBorderStyle style;
};

typedef char UiTextWindowBorderStyleSizeCheck[sizeof(UiTextWindowBorderStyle) == 4 ? 1 : -1];
typedef char UiTextWindowBorderCommandSizeCheck[sizeof(UiTextWindowBorderCommand) == 32 ? 1 : -1];
typedef char UiTextWindowBorderCommandStyleCheck[offsetof(UiTextWindowBorderCommand, style) == 28 ? 1 : -1];

#pragma implementation
#endif

#endif // UI_TEXT_WINDOW_HH
