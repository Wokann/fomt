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
typedef char MenuGridPositionSizeCheck[sizeof(MenuGridPosition) == 4 ? 1 : -1];
typedef char MenuGridPositionYCheck[offsetof(MenuGridPosition, y) == 1 ? 1 : -1];
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
typedef char MenuPanelQueueCheck[offsetof(GameMenuPanel, commands) == 4 ? 1 : -1];
typedef char MenuPanelGlyphBufferCheck[offsetof(GameMenuPanel, glyph_tiles) == 0x10 ? 1 : -1];

// A menu icon borrows its archive data. The first word is the quantity
// displayed as a decimal number when it exceeds one.
struct GameMenuItemIcon {
    u32 quantity;
    IndexedResourceTileUnit const * tiles;
    IndexedResourcePaletteBank const * palette;
};

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
        char const * heading, u8 show_header);
    virtual ~GameMenuTilemapPanel();
    virtual void PruneCompletedCommands();
    GameMenuPanelState state;
};

struct GameMenuSpritePanel : GameMenuPanel {
    virtual ~GameMenuSpritePanel();
    GameMenuSpritePanel(HardwareDmaQueue *, HardwareLinkedList *, u32 count,
        char const * heading, u8 show_header);
    GameMenuPanelState state;
    ObjTileCollectionEntry header_tiles;
    ObjPaletteCollectionEntry header_palette;
    ObjTileCollectionEntry item_tiles[8];
    ObjPaletteCollectionEntry item_palettes[8];
};

typedef char MenuItemIconSizeCheck[sizeof(GameMenuItemIcon) == 12 ? 1 : -1];
typedef char MenuItemIconTilesCheck[offsetof(GameMenuItemIcon, tiles) == 4 ? 1 : -1];
typedef char MenuItemIconPaletteCheck[offsetof(GameMenuItemIcon, palette) == 8 ? 1 : -1];
typedef char MenuIconListSizeCheck[sizeof(GameMenuIconList) == 0x64 ? 1 : -1];
typedef char MenuPanelStateSizeCheck[sizeof(GameMenuPanelState) == 0x88 ? 1 : -1];
typedef char MenuPanelStateDmaQueueCheck[offsetof(GameMenuPanelState, dma_queue) == 0x64 ? 1 : -1];
typedef char MenuPanelStateHeaderCheck[offsetof(GameMenuPanelState, show_header) == 0x68 ? 1 : -1];
typedef char MenuPanelStateHeadingCheck[offsetof(GameMenuPanelState, heading) == 0x78 ? 1 : -1];
typedef char MenuPanelStateCountCheck[offsetof(GameMenuPanelState, item_count) == 0x84 ? 1 : -1];
typedef char MenuTilemapPanelStateCheck[offsetof(GameMenuTilemapPanel, state) == 0x214 ? 1 : -1];
typedef char MenuSpritePanelStateCheck[offsetof(GameMenuSpritePanel, state) == 0x214 ? 1 : -1];
typedef char MenuTilemapPanelSizeCheck[sizeof(GameMenuTilemapPanel) == 0x29C ? 1 : -1];
typedef char MenuSpritePanelSizeCheck[sizeof(GameMenuSpritePanel) == 0x32C ? 1 : -1];
typedef char MenuSpritePanelHeaderTilesCheck[offsetof(GameMenuSpritePanel, header_tiles) == 0x29C ? 1 : -1];
typedef char MenuSpritePanelHeaderPaletteCheck[offsetof(GameMenuSpritePanel, header_palette) == 0x2A4 ? 1 : -1];
typedef char MenuSpritePanelItemTilesCheck[offsetof(GameMenuSpritePanel, item_tiles) == 0x2AC ? 1 : -1];
typedef char MenuSpritePanelItemPalettesCheck[offsetof(GameMenuSpritePanel, item_palettes) == 0x2EC ? 1 : -1];

extern "C" {
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
}

// Coordinate readers retain the native unused panel argument, without
// inventing a relationship between the left/right opaque payload types.
MenuGridPosition GetMenuGridLeftCellPosition(GameMenuPanel const *, i32);
MenuGridPosition GetMenuGridLeftHeaderPosition(GameMenuPanel const *);
MenuGridPosition GetMenuGridRightCellPosition(GameMenuPanel const *, i32);
MenuGridPosition GetMenuGridRightHeaderPosition(GameMenuPanel const *);

#endif // GAME_MENU_PANELS_HH
