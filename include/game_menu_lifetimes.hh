#ifndef GAME_MENU_LIFETIMES_HH
#define GAME_MENU_LIFETIMES_HH

#include "prelude.h"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "resource_handle.hh"
#include "ui_state.hh"
#include "utility/fixed_str.hh"
#include "game_menu_command_queue.hh"

struct GameStateSaveImage;
struct MenuGridPosition;


#include "game_menu_panels.hh"

#pragma interface "game_menu.hh"
struct GameMenuTilemapPanelOwner {
    GameMenuTilemapPanel * value;
    GameMenuTilemapPanelOwner() : value(nullptr) {}
    GameMenuTilemapPanelOwner & operator=(GameMenuTilemapPanel * input)
    {
        if (input != value)
            delete value;
        value = input;
        return *this;
    }
    ~GameMenuTilemapPanelOwner() { delete value; }
};
struct GameMenuSpritePanelOwner {
    GameMenuSpritePanel * value;
    GameMenuSpritePanelOwner() : value(nullptr) {}
    GameMenuSpritePanelOwner & operator=(GameMenuSpritePanel * input)
    {
        if (input != value)
            delete value;
        value = input;
        return *this;
    }
    ~GameMenuSpritePanelOwner() { delete value; }
};

struct GameSceneMenuResourceState {
    u16 unk_00;
    u16 unk_02;
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_34;
    GameSceneMenuResourceState(IndexedResourceProvider * provider, u32 index, i32 delta)
        : unk_00(0), unk_02(0), handle(provider, index, delta), parameters(), unk_34(0) {}
};
#pragma interface "game_menu_lifetimes.hh"
struct GameSceneMenuCorePrefix : HardwareContext {
    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState resource_state;
    GameMenuTilemapPanelOwner left_panel;
    GameMenuSpritePanelOwner right_panel;
    UiStateOwner ui;
    // Written by the native UI update, not initialized by this constructor.
    u32 unk_84;
    u32 unk_88;
protected:
    GameSceneMenuCorePrefix(GameStateSaveImage *);
public:
    void Update();
    // Native precondition: the selected panel exists and index is 0..17.
    MenuGridPosition GetCursorPosition(i32) const;
    i32 GetItemIndex(i32, i32) const;
};
// Native menu tilemap command storage. Construction remains in assembly;
// only the verified layout and command/resource cleanup are recovered here.
// Do not allocate these views or assign meaning to untouched words.
struct GameSceneMenuTilemapData {
    GameSceneMenuCorePrefix * core;
    ObjTileCollectionEntry unk_04;
    ObjTileCollectionEntry unk_0C;
    ObjPaletteCollectionEntry unk_14;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState first;
    GameSceneMenuResourceState second;
    u32 unk_BC;
    GameSceneMenuCommandQueue commands;
    ~GameSceneMenuTilemapData();
private:
    GameSceneMenuTilemapData();
};

extern "C" void QueueMenuTilemapRect(GameSceneMenuTilemapData *, u16 * destination,
    u16 first_tile, u32 width, u32 height, u16 palette, u32 row_stride);
extern "C" void QueueMenuTilemapDecimal(GameSceneMenuTilemapData *, u32 value,
    u16 * right_tile, u16 base_tile, u16 palette, u32 row_stride);

struct GameSceneMenuCursorData {
    GameSceneMenuCorePrefix * core;
    i32 selection;
    i32 previous;
    i32 left_limit;
    i32 right_limit;
    ObjTileCollectionEntry state;
    ObjPaletteCollectionEntry resource;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState sprite;
    GameSceneMenuCursorData(GameSceneMenuCorePrefix *, u32);
    // Navigation requires both panel views and a selection in 0..17.
    inline void RefreshBounds();
    i32 MoveUp();
    i32 MoveDown();
    i32 MoveLeft();
    i32 SwitchPanel();
    void SetSelection(i32);

};
struct GameSceneMenuSpriteData {
    GameSceneMenuCorePrefix * core;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState sprite;
    ObjTileCollectionEntry state;
    ObjPaletteCollectionEntry resource;
    u32 unk_7C;
    u32 unk_80;
    u8 unk_84;
    GameSceneMenuSpriteData(GameSceneMenuCorePrefix *);
    void Show(i32, u32);
    void Hide();
};
#pragma interface "game_menu.hh"
struct GameSceneMenuCursorDataOwner {
    GameSceneMenuCursorData * value;
    GameSceneMenuCursorDataOwner() : value(nullptr) {}
    GameSceneMenuCursorDataOwner & operator=(GameSceneMenuCursorData * input)
    {
        if (input != value)
            delete value;
        value = input;
        return *this;
    }
    ~GameSceneMenuCursorDataOwner() { delete value; }
};
struct GameSceneMenuSpriteDataOwner {
    GameSceneMenuSpriteData * value;
    GameSceneMenuSpriteDataOwner() : value(nullptr) {}
    GameSceneMenuSpriteDataOwner & operator=(GameSceneMenuSpriteData * input)
    {
        if (input != value)
            delete value;
        value = input;
        return *this;
    }
    ~GameSceneMenuSpriteDataOwner() { delete value; }
};
struct GameSceneMenuTilemapDataOwner {
    GameSceneMenuTilemapData * value;
    GameSceneMenuTilemapDataOwner() : value(nullptr) {}
    ~GameSceneMenuTilemapDataOwner() { delete value; }
};


#pragma interface "game_menu_lifetimes.hh"
#include "game_menu_selection.hh"

#pragma interface "game_menu_lifetimes.hh"

// Keep cleanup visible to actual derived/member callers. agbcp emits the
// panel entry precedes the implicitly generated core cleanup.
inline GameMenuSpritePanel::~GameMenuSpritePanel()
{
}


#endif // GAME_MENU_LIFETIMES_HH
