#ifndef GAME_MENU_PANELS_HH
#define GAME_MENU_PANELS_HH

#include "prelude.h"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_handle.hh"
#include "ui_state.hh"
#include "utility/fixed_str.hh"
#include "game_menu_command_queue.hh"

// Coordinate-byte pairs retain the native four-byte record alignment.
// Each consumer selects pixel coordinates or tilemap coordinates.
struct ALIGN(4) MenuGridPosition {
    u8 x;
    u8 y;
};
extern MenuGridPosition const gMenuGridHeaderPosition;
extern MenuGridPosition const gMenuGridCellPositions[8];
extern MenuGridPosition const gMenuGridHeaderTilePosition;
extern MenuGridPosition const gMenuGridCellTilePositions[];
// Shared native panel base. It owns queued drawing commands and a 16-tile
// glyph buffer; the virtual pointer follows the buffer at +0x210.
#pragma interface "game_menu_lifetimes.hh"
struct GameMenuPanel {
    HardwareLinkedList * link_list;
    GameSceneMenuCommandQueue commands;
    u32 unk_0C;
    u8 glyph_tiles[0x200];
    virtual ~GameMenuPanel();
    virtual void PruneCompletedCommands();
protected:
    GameMenuPanel(HardwareLinkedList *);
};

enum GameMenuItemIconId {
    GAME_MENU_ICON_BASKET       = 53,
    GAME_MENU_ICON_WRAPPED_ITEM = 352,
};

// A menu icon borrows its archive data. The first word is the quantity
// displayed as a decimal number when it exceeds one.
struct GameMenuItemIcon {
    u32 quantity;
    IndexedResourceTileUnit const * tiles;
    IndexedResourcePaletteBank const * palette;
};

static inline bool IsMenuItemIconEmpty(GameMenuItemIcon const * icon)
{
    return icon->tiles == nullptr || icon->palette == nullptr;
}

// The native constructors initialize only count active entries (at most eight).
// Retain their counted lifetime instead of interpreting unused slots as items.
#pragma interface "game_menu.hh"
struct GameMenuIconList {
    u32 count;
    GameMenuItemIcon items[8];
    ~GameMenuIconList()
    {
        GameMenuItemIcon * last = items + count;
        GameMenuItemIcon * item = items;
        while (item != last) {
            item->~GameMenuItemIcon();
            ++item;
        }
    }
};

struct GameMenuPanelState {
    GameMenuIconList icons;
    HardwareDmaQueue * dma_queue;
    u8 show_header;
    GameMenuItemIcon header_icon;
    FixedStr<8> heading;
    u32 item_count;
};

#pragma interface "game_menu_lifetimes.hh"
struct GameMenuTilemapPanel : GameMenuPanel {
    GameMenuTilemapPanel(HardwareDmaQueue *, HardwareLinkedList *, u32 count,
        char const * heading, bool show_header);
    virtual ~GameMenuTilemapPanel();
    virtual void PruneCompletedCommands();
    GameMenuPanelState state;
};

struct GameMenuSpritePanel : GameMenuPanel {
    virtual ~GameMenuSpritePanel();
    GameMenuSpritePanel(HardwareDmaQueue *, HardwareLinkedList *, u32 count,
        char const * heading, bool show_header);
    GameMenuPanelState state;
    ObjTileCollectionEntry header_tiles;
    ObjPaletteCollectionEntry header_palette;
    ObjTileCollectionEntry item_tiles[8];
    ObjPaletteCollectionEntry item_palettes[8];
};


extern "C" {
void QueueMenuPanelTilemapRect(GameMenuPanel *, u16 * destination, u16 first_tile,
    u32 width, u32 height, u16 palette, u32 row_stride);
void QueueMenuPanelDecimal(GameMenuPanel *, u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride);
void func_080CB090(GameMenuTilemapPanel *);
void func_080CC310(GameMenuSpritePanel *);
void func_080CCDEC(GameMenuSpritePanel *, u32 index);
extern u8 const gActorIndexedResourceArchive[];
extern u8 const gUnk_083ED9FC[];
extern u8 const gUnk_086678A0[];
void func_080CC728(GameMenuSpritePanel *, u32 index, u8 const * archive,
    u16 icon, u32 quantity);
void func_080CCE58(GameMenuSpritePanel *, u8 const * archive,
    u16 icon, u32 quantity);
void func_080CB304(GameMenuTilemapPanel *, u32 index, u8 const * archive,
    u16 icon, u32 quantity);
void func_080CBAF0(GameMenuTilemapPanel *, u8 const * archive,
    u16 icon, u32 quantity);
void InitializeMenuItemIcon(GameMenuItemIcon *);
GameMenuItemIcon * InitializeMenuItemIconFromArchive(GameMenuItemIcon *,
    u8 const * archive, u16 index, u32 quantity);
GameMenuItemIcon * InitializeMenuItemIconFromData(GameMenuItemIcon *,
    IndexedResourceTileUnit const *, IndexedResourcePaletteBank const *, u32 quantity);
void SetMenuItemIconQuantity(GameMenuItemIcon *, u32 quantity);
u32 GetMenuItemIconQuantity(GameMenuItemIcon const *);
void LoadMenuItemIconFromArchive(GameMenuItemIcon *, u8 const * archive,
    u16 index, u32 quantity);
void SetMenuItemIconData(GameMenuItemIcon *, IndexedResourceTileUnit const *,
    IndexedResourcePaletteBank const *, u32 quantity);
void ClearMenuItemIcon(GameMenuItemIcon *);
// index must refer to one of the panel's active icon entries.
GameMenuItemIcon * GetMenuPanelItemIcon(GameMenuPanel *, u32 index);
GameMenuItemIcon * GetMenuPanelHeaderIcon(GameMenuPanel *);
GameMenuItemIcon * func_080CC70C(GameMenuPanel *, u32 index);
}

// Coordinate readers retain the native unused panel argument, without
// inventing a relationship between the left/right opaque payload types.
MenuGridPosition GetMenuGridLeftCellPosition(GameMenuPanel const *, i32);
MenuGridPosition GetMenuGridLeftHeaderPosition(GameMenuPanel const *);
MenuGridPosition GetMenuGridRightCellPosition(GameMenuPanel const *, i32);
MenuGridPosition GetMenuGridRightHeaderPosition(GameMenuPanel const *);

#endif // GAME_MENU_PANELS_HH
