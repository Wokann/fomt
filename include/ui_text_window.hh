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

// The enabled mode alternates the two pixel-nibble masks on each queued run.
// It requires a nonzero tile count and an initial phase of zero or one.
// Completion copies the original full tile data and removes the command.
struct UiTextWindowTileUploadCommand : HardwareLinkBase {
    virtual bool Run() SECTION(".text.ui_text_window_tile_upload");
    u32 const * source;
    u32 * destination;
    u8 tile_count;
    u8 dither;
    u8 phase;
};

typedef char UiTextWindowTileUploadSizeCheck[sizeof(UiTextWindowTileUploadCommand) == 24 ? 1 : -1];
typedef char UiTextWindowTileUploadSourceCheck[offsetof(UiTextWindowTileUploadCommand, source) == 0xC ? 1 : -1];
typedef char UiTextWindowTileUploadCountCheck[offsetof(UiTextWindowTileUploadCommand, tile_count) == 0x14 ? 1 : -1];
typedef char UiTextWindowTileUploadPhaseCheck[offsetof(UiTextWindowTileUploadCommand, phase) == 0x16 ? 1 : -1];

#pragma implementation
#endif

#endif // UI_TEXT_WINDOW_HH
