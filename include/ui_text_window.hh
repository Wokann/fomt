#ifndef UI_TEXT_WINDOW_HH
#define UI_TEXT_WINDOW_HH

#include "prelude.h"
#include "u16_pair.hh"

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

// This queued command redraws a BG screen block and installs its palette.
// The drawing callback currently ignores y; the constructor still stores it.
struct UiTextWindowBorderCommand : HardwareLinkBase {
    UiTextWindowBorderCommand(i32 x, i32 y, u32 width, u32 height,
        u32 screen, u32 tile, u32 bank) SECTION(".text.ui_text_window_border_constructor");
    virtual bool Run() SECTION(".text.ui_text_window_border_command");
    u32 x;
    u32 y;
    u32 width;
    u32 height;
    u8 screen_block : 5;
    u16 first_tile : 10;
    u32 palette : 4;
    u32 unk_high : 13;
};

typedef char UiTextWindowBorderCommandYCheck[offsetof(UiTextWindowBorderCommand, y) == 16 ? 1 : -1];
typedef char UiTextWindowBorderCommandSizeCheck[sizeof(UiTextWindowBorderCommand) == 32 ? 1 : -1];

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

// A BG window owns one pending-upload list and its two concrete commands.
// Phase values are hidden, opening, closing and visible, respectively.
struct HardwareDisplayState;

struct UiTextWindow {
    UiTextWindow(i32 x, i32 y, u32 width, u32 height, u32 background,
        u32 screen, u32 palette, u32 mode);
    u32 Update(HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands);
    enum Phase { HIDDEN, OPENING, CLOSING, VISIBLE };
    void Open() SECTION(".text.ui_text_window_state");
    void OpenImmediate() SECTION(".text.ui_text_window_state");
    void Close() SECTION(".text.ui_text_window_state");
    void CloseImmediate() SECTION(".text.ui_text_window_state");
    U16Pair position;
    u16 width;
    u16 height;
    u8 background : 2;
    u8 screen_block : 5;
    u16 character_block : 2;
    u32 first_tile : 10;
    u8 palette : 4;
    u16 mode : 8;
    u8 phase : 8 __attribute__((packed));
    u8 unk_0c_high : 1;
    u8 frame;
    HardwareLinkedList pending_uploads;
    UiTextWindowTileUploadCommand upload;
    UiTextWindowBorderCommand border;
};

typedef char UiTextWindowSizeCheck[sizeof(UiTextWindow) == 100 ? 1 : -1];
typedef char UiTextWindowFrameCheck[offsetof(UiTextWindow, frame) == 13 ? 1 : -1];
typedef char UiTextWindowUploadsCheck[offsetof(UiTextWindow, pending_uploads) == 16 ? 1 : -1];
typedef char UiTextWindowUploadCommandCheck[offsetof(UiTextWindow, upload) == 44 ? 1 : -1];
typedef char UiTextWindowBorderCommandCheck[offsetof(UiTextWindow, border) == 68 ? 1 : -1];

#pragma implementation
#endif

#endif // UI_TEXT_WINDOW_HH
