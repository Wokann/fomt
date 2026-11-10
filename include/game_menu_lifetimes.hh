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
    ~GameMenuTilemapPanelOwner() { delete value; }
};
struct GameMenuSpritePanelOwner {
    GameMenuSpritePanel * value;
    GameMenuSpritePanelOwner() : value(nullptr) {}
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
typedef char MenuResourceStateSizeCheck[sizeof(GameSceneMenuResourceState) == 0x38 ? 1 : -1];
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
typedef char MenuPanelSizeCheck[sizeof(GameMenuPanel) == 0x214 ? 1 : -1];
typedef char MenuCorePrefixSizeCheck[sizeof(GameSceneMenuCorePrefix) == 0x8C ? 1 : -1];
typedef char MenuCoreArchiveCheck[offsetof(GameSceneMenuCorePrefix, archive) == 0x10 ? 1 : -1];
typedef char MenuCoreHandleCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, handle) == 0x44 ? 1 : -1];
typedef char MenuCoreSpriteCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, parameters) == 0x58 ? 1 : -1];
typedef char MenuCoreOwnedDataCheck[offsetof(GameSceneMenuCorePrefix, left_panel) == 0x78 ? 1 : -1];
typedef char MenuCoreUiCheck[offsetof(GameSceneMenuCorePrefix, ui) == 0x80 ? 1 : -1];
typedef char MenuCoreResourceStateOffsetCheck[offsetof(GameSceneMenuCorePrefix, resource_state) == 0x40 ? 1 : -1];
typedef char MenuCoreUnknownStateCheck[offsetof(GameSceneMenuCorePrefix, unk_84) == 0x84 ? 1 : -1];
typedef char MenuCoreUnknownResultCheck[offsetof(GameSceneMenuCorePrefix, unk_88) == 0x88 ? 1 : -1];
// Native menu tilemap command storage. Construction remains in assembly;
// only the verified layout and command/resource cleanup are recovered here.
// Do not allocate these views or assign meaning to untouched words.
struct GameSceneMenuTilemapData {
    u32 unk_00;
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
typedef char MenuTilemapDataSizeCheck[sizeof(GameSceneMenuTilemapData) == 0xC8 ? 1 : -1];
typedef char MenuTilemapDataFirstStateCheck[offsetof(GameSceneMenuTilemapData, unk_04) == 4 ? 1 : -1];
typedef char MenuTilemapDataSecondStateCheck[offsetof(GameSceneMenuTilemapData, unk_0C) == 0xC ? 1 : -1];
typedef char MenuTilemapDataPoolEntryCheck[offsetof(GameSceneMenuTilemapData, unk_14) == 0x14 ? 1 : -1];
typedef char MenuTilemapDataArchiveCheck[offsetof(GameSceneMenuTilemapData, archive) == 0x1C ? 1 : -1];
typedef char MenuTilemapDataFirstResourceCheck[offsetof(GameSceneMenuTilemapData, first) == 0x4C ? 1 : -1];
typedef char MenuTilemapDataSecondResourceCheck[offsetof(GameSceneMenuTilemapData, second) == 0x84 ? 1 : -1];
typedef char MenuTilemapDataUnknownWordCheck[offsetof(GameSceneMenuTilemapData, unk_BC) == 0xBC ? 1 : -1];
typedef char MenuTilemapDataQueueCheck[offsetof(GameSceneMenuTilemapData, commands) == 0xC0 ? 1 : -1];

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
    ~GameSceneMenuCursorDataOwner() { delete value; }
};
struct GameSceneMenuSpriteDataOwner {
    GameSceneMenuSpriteData * value;
    GameSceneMenuSpriteDataOwner() : value(nullptr) {}
    ~GameSceneMenuSpriteDataOwner() { delete value; }
};
struct GameSceneMenuTilemapDataOwner {
    GameSceneMenuTilemapData * value;
    GameSceneMenuTilemapDataOwner() : value(nullptr) {}
    ~GameSceneMenuTilemapDataOwner() { delete value; }
};

typedef char MenuCursorSelectionCheck[offsetof(GameSceneMenuCursorData, selection) == 4 ? 1 : -1];
typedef char MenuCursorPreviousCheck[offsetof(GameSceneMenuCursorData, previous) == 8 ? 1 : -1];
typedef char MenuCursorLeftLimitCheck[offsetof(GameSceneMenuCursorData, left_limit) == 0xC ? 1 : -1];
typedef char MenuCursorRightLimitCheck[offsetof(GameSceneMenuCursorData, right_limit) == 0x10 ? 1 : -1];
typedef char MenuCursorDataSizeCheck[sizeof(GameSceneMenuCursorData) == 0x8C ? 1 : -1];
typedef char MenuCursorStateCheck[offsetof(GameSceneMenuCursorData, state) == 0x14 ? 1 : -1];
typedef char MenuCursorResourceCheck[offsetof(GameSceneMenuCursorData, resource) == 0x1C ? 1 : -1];
typedef char MenuCursorArchiveCheck[offsetof(GameSceneMenuCursorData, archive) == 0x24 ? 1 : -1];
typedef char MenuCursorSpriteCheck[offsetof(GameSceneMenuCursorData, sprite) == 0x54 ? 1 : -1];
typedef char MenuSpriteDataSizeCheck[sizeof(GameSceneMenuSpriteData) == 0x88 ? 1 : -1];
typedef char MenuSpriteArchiveCheck[offsetof(GameSceneMenuSpriteData, archive) == 4 ? 1 : -1];
typedef char MenuSpriteParametersCheck[offsetof(GameSceneMenuSpriteData, sprite) == 0x34 ? 1 : -1];
typedef char MenuSpriteStateCheck[offsetof(GameSceneMenuSpriteData, state) == 0x6C ? 1 : -1];
typedef char MenuSpriteResourceCheck[offsetof(GameSceneMenuSpriteData, resource) == 0x74 ? 1 : -1];
typedef char MenuSpriteUnknownWordCheck[offsetof(GameSceneMenuSpriteData, unk_7C) == 0x7C ? 1 : -1];
typedef char MenuSpriteUnknownByteCheck[offsetof(GameSceneMenuSpriteData, unk_84) == 0x84 ? 1 : -1];
typedef char MenuCursorOwnerSizeCheck[sizeof(GameSceneMenuCursorDataOwner) == 4 ? 1 : -1];
typedef char MenuSpriteOwnerSizeCheck[sizeof(GameSceneMenuSpriteDataOwner) == 4 ? 1 : -1];
typedef char MenuTilemapOwnerSizeCheck[sizeof(GameSceneMenuTilemapDataOwner) == 4 ? 1 : -1];

#pragma interface "game_menu_lifetimes.hh"
#include "game_menu_selection.hh"

#pragma interface "game_menu_lifetimes.hh"

// Keep cleanup visible to actual derived/member callers. agbcp emits the
// panel entry precedes the implicitly generated core cleanup.
inline GameMenuSpritePanel::~GameMenuSpritePanel()
{
}


#endif // GAME_MENU_LIFETIMES_HH
