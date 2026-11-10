#ifndef UI_TEXT_WINDOW_HH
#define UI_TEXT_WINDOW_HH

#include "prelude.h"

#include "ui_text_window_border.hh"

// Window coordinates retain their low 16 bits. Pixel consumers interpret
// those bits as signed coordinates; Set and Offset retain wrapping behavior.
struct UiPosition {
    u16 x;
    u16 y;
#ifdef __cplusplus
    void Set(u32 x, u32 y);
    void Offset(u32 dx, u32 dy);
#endif
};

typedef char UiPositionSizeCheck[sizeof(struct UiPosition) == 4 ? 1 : -1];
typedef char UiPositionYCheck[offsetof(struct UiPosition, y) == 2 ? 1 : -1];

#ifdef __cplusplus
#include "hardware_linked_list.hh"
#include "hardware_display_state.hh"
#include "gbaio.h"
#include "gbasvc.h"

#pragma interface "ui_text_window_commands.cc"

struct UiTextWindow;

// The public control owns the window and forwards its state operations.
struct ControlWidget {
    ControlWidget(i32 x, i32 y, u32 width, u32 height, u32 background,
        u32 screen, u32 palette, u32 mode);
    virtual ~ControlWidget();
    virtual void Open();
    virtual void OpenImmediate();
    virtual void Close();
    virtual void CloseImmediate();
    virtual i32 GetX() const;
    virtual i32 GetY() const;
    virtual void SetPosition(u32 x, u32 y);
    virtual void OffsetPosition(u32 x, u32 y);
    u32 GetPhase() const;
    u32 Update(HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands);
    UiTextWindow * state;
};

typedef char ControlWidgetSizeCheck[sizeof(ControlWidget) == 8 ? 1 : -1];
typedef char ControlWidgetStateCheck[offsetof(ControlWidget, state) == 0 ? 1 : -1];

// The enabled mode alternates the two pixel-nibble masks on each queued run.
// It requires a nonzero tile count and an initial phase of zero or one.
// Completion copies the original full tile data and removes the command.
#pragma interface "ui_text_window_commands.cc"
struct UiTextWindowTileUploadCommand : HardwareLinkBase {
    virtual bool Run();
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

#pragma interface "ui_text_window_commands.cc"

// This queued command redraws a BG screen block and installs its palette.
// The drawing callback currently ignores y; the constructor still stores it.
struct UiTextWindowBorderCommand : HardwareLinkBase {
    inline UiTextWindowBorderCommand(i32 x, i32 y, u32 width, u32 height,
        u32 screen, u32 tile, u32 bank);
    virtual bool Run();
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

// A BG window owns one pending-upload list and its two concrete commands.
// Phase values are hidden, opening, closing and visible, respectively.
struct HardwareDisplayState;

#pragma interface "ui_text_window.hh"
struct UiTextWindow {
    UiTextWindow(i32 x, i32 y, u32 width, u32 height, u32 background,
        u32 screen, u32 palette, u32 mode);
    u32 Update(HardwareDisplayState * display, HardwareLinkedList * uploads,
        HardwareLinkedList * commands);
    enum Phase { HIDDEN, OPENING, CLOSING, VISIBLE };
    void Open();
    void OpenImmediate();
    void Close();
    void CloseImmediate();
    UiPosition position;
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

inline UiTextWindowBorderCommand::UiTextWindowBorderCommand(i32 x, i32 y,
    u32 width, u32 height, u32 screen, u32 tile, u32 bank)
    : x(x), y(y), width(width), height(height), screen_block(screen),
      first_tile(tile), palette(bank)
{
}

#endif

#endif // UI_TEXT_WINDOW_HH
