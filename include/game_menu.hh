#ifndef GAME_MENU_HH
#define GAME_MENU_HH

#include "game_scene.hh"

#pragma interface "game_menu.hh"

// These views expose only the native destruction interfaces and known members.
// Do not independently allocate either prefix or infer the full core hierarchy.
struct GameSceneMenuOwnedDataPrefix {
    u8 unk_000[0x210];
    virtual ~GameSceneMenuOwnedDataPrefix();
    // Native virtual slot +0x0C; its payload-specific meaning is unknown.
    virtual void vfunc_0C();
private:
    GameSceneMenuOwnedDataPrefix();
};
struct GameSceneMenuOwnedDataOwner {
    GameSceneMenuOwnedDataPrefix * value;
    GameSceneMenuOwnedDataOwner() : value(nullptr) {}
    ~GameSceneMenuOwnedDataOwner() { delete value; }
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
struct GameSceneMenuCorePrefix : GameSceneUiComponent {
    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState resource_state;
    GameSceneMenuOwnedDataOwner unk_78;
    GameSceneMenuOwnedDataOwner unk_7C;
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
typedef char MenuOwnedDataPrefixSizeCheck[sizeof(GameSceneMenuOwnedDataPrefix) == 0x214 ? 1 : -1];
typedef char MenuCorePrefixSizeCheck[sizeof(GameSceneMenuCorePrefix) == 0x8C ? 1 : -1];
typedef char MenuCoreArchiveCheck[offsetof(GameSceneMenuCorePrefix, archive) == 0x10 ? 1 : -1];
typedef char MenuCoreHandleCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, handle) == 0x44 ? 1 : -1];
typedef char MenuCoreSpriteCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, parameters) == 0x58 ? 1 : -1];
typedef char MenuCoreOwnedDataCheck[offsetof(GameSceneMenuCorePrefix, unk_78) == 0x78 ? 1 : -1];
typedef char MenuCoreUiCheck[offsetof(GameSceneMenuCorePrefix, ui) == 0x80 ? 1 : -1];
typedef char MenuCoreResourceStateOffsetCheck[offsetof(GameSceneMenuCorePrefix, resource_state) == 0x40 ? 1 : -1];
typedef char MenuCoreUnknownStateCheck[offsetof(GameSceneMenuCorePrefix, unk_84) == 0x84 ? 1 : -1];
typedef char MenuCoreUnknownResultCheck[offsetof(GameSceneMenuCorePrefix, unk_88) == 0x88 ? 1 : -1];
extern "C" {
#if defined(REGION_JP)
extern u8 const gUnk_084DABB8[];
#else
extern u8 const gUnk_08754C0C[];
#endif
}

// Native menu tilemap command storage. Construction remains in assembly;
// only the verified layout and command/resource cleanup are recovered here.
// Do not allocate these views or assign meaning to untouched words.
struct GameSceneMenuCommandNode {
    GameSceneMenuCommandNode * next;
    GameSceneMenuCommandNode * previous;
    HardwareLinkBase * command;
};
struct GameSceneMenuCommandIterator {
    GameSceneMenuCommandNode * current;
    explicit GameSceneMenuCommandIterator(GameSceneMenuCommandNode * node) : current(node) {}
    GameSceneMenuCommandIterator(GameSceneMenuCommandIterator const & other) : current(other.current) {}
    bool operator!=(GameSceneMenuCommandIterator const & other) const
    {
        return current != other.current;
    }
    GameSceneMenuCommandIterator & operator++()
    {
        current = current->next;
        return *this;
    }
    HardwareLinkBase * operator*() const { return current->command; }
};
struct GameSceneMenuCommandQueue {
    u32 unk_00;
    GameSceneMenuCommandNode * sentinel;
    void ClearNodes();
    ~GameSceneMenuCommandQueue()
    {
        ClearNodes();
        if (sentinel != nullptr)
            free(sentinel);
    }
    GameSceneMenuCommandIterator Begin() const
    {
        return GameSceneMenuCommandIterator(sentinel->next);
    }
    GameSceneMenuCommandIterator End() const
    {
        return GameSceneMenuCommandIterator(sentinel);
    }
private:
    GameSceneMenuCommandQueue();
};

struct GameSceneMenuTilemapData {
    u32 unk_00;
    HardwareStateEntry unk_04;
    HardwareStateEntry unk_0C;
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
typedef char MenuCommandNodeSizeCheck[sizeof(GameSceneMenuCommandNode) == 12 ? 1 : -1];
typedef char MenuCommandNodeValueCheck[offsetof(GameSceneMenuCommandNode, command) == 8 ? 1 : -1];
typedef char MenuCommandIteratorSizeCheck[sizeof(GameSceneMenuCommandIterator) == 4 ? 1 : -1];
typedef char MenuCommandQueueSizeCheck[sizeof(GameSceneMenuCommandQueue) == 8 ? 1 : -1];
typedef char MenuCommandQueueHeadCheck[offsetof(GameSceneMenuCommandQueue, sentinel) == 4 ? 1 : -1];
typedef char MenuTilemapDataSizeCheck[sizeof(GameSceneMenuTilemapData) == 0xC8 ? 1 : -1];
typedef char MenuTilemapDataFirstStateCheck[offsetof(GameSceneMenuTilemapData, unk_04) == 4 ? 1 : -1];
typedef char MenuTilemapDataSecondStateCheck[offsetof(GameSceneMenuTilemapData, unk_0C) == 0xC ? 1 : -1];
typedef char MenuTilemapDataPoolEntryCheck[offsetof(GameSceneMenuTilemapData, unk_14) == 0x14 ? 1 : -1];
typedef char MenuTilemapDataArchiveCheck[offsetof(GameSceneMenuTilemapData, archive) == 0x1C ? 1 : -1];
typedef char MenuTilemapDataFirstResourceCheck[offsetof(GameSceneMenuTilemapData, first) == 0x4C ? 1 : -1];
typedef char MenuTilemapDataSecondResourceCheck[offsetof(GameSceneMenuTilemapData, second) == 0x84 ? 1 : -1];
typedef char MenuTilemapDataUnknownWordCheck[offsetof(GameSceneMenuTilemapData, unk_BC) == 0xBC ? 1 : -1];
typedef char MenuTilemapDataQueueCheck[offsetof(GameSceneMenuTilemapData, commands) == 0xC0 ? 1 : -1];

// Borrowed extension of the verified virtual prefix. Not independently allocated.
struct GameSceneMenuOwnedDataState : GameSceneMenuOwnedDataPrefix {
    u8 unk_214[0x68];
    u8 unk_27C;
    u8 unk_27D[0x1B];
    u32 unk_298;
    u32 GetUnk298() const { return unk_298; }
    u8 GetUnk27C() const { return unk_27C; }
private:
    GameSceneMenuOwnedDataState();
};
typedef char MenuOwnedStateWordCheck[offsetof(GameSceneMenuOwnedDataState, unk_298) == 0x298 ? 1 : -1];
typedef char MenuOwnedStateByteCheck[offsetof(GameSceneMenuOwnedDataState, unk_27C) == 0x27C ? 1 : -1];
typedef char MenuOwnedStateSizeCheck[sizeof(GameSceneMenuOwnedDataState) == 0x29C ? 1 : -1];

struct GameSceneMenuCursorData {
    GameSceneMenuCorePrefix * core;
    i32 selection;
    i32 previous;
    i32 left_limit;
    i32 right_limit;
    HardwareStateEntry state;
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
    HardwareStateEntry state;
    ObjPaletteCollectionEntry resource;
    u32 unk_7C;
    u32 unk_80;
    u8 unk_84;
    GameSceneMenuSpriteData(GameSceneMenuCorePrefix *);
    void Show(i32, u32);
    void Hide();
};
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
// The concrete scene cores add their own payload after this common 0x98 prefix.
struct GameSceneMenuSelectionCore : GameSceneMenuCorePrefix {
    GameSceneMenuCursorDataOwner cursor;
    GameSceneMenuSpriteDataOwner sprite;
    GameSceneMenuTilemapDataOwner tilemap;
protected:
    GameSceneMenuSelectionCore(GameStateSaveImage *);
public:
    void Update();
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
typedef char MenuSelectionCoreSizeCheck[sizeof(GameSceneMenuSelectionCore) == 0x98 ? 1 : -1];
typedef char MenuSelectionCursorCheck[offsetof(GameSceneMenuSelectionCore, cursor) == 0x8C ? 1 : -1];
typedef char MenuSelectionSpriteCheck[offsetof(GameSceneMenuSelectionCore, sprite) == 0x90 ? 1 : -1];
typedef char MenuSelectionTilemapCheck[offsetof(GameSceneMenuSelectionCore, tilemap) == 0x94 ? 1 : -1];
extern "C" u8 const gUiHandCursorArchive[];

extern "C" {
// Actual existing native entries, not generated wrappers or aliases.
void func_080CDDD4(GameSceneMenuCursorData *);
void func_080CECE8(GameSceneMenuSpriteData *);
#if defined(REGION_JP)
void loc_080CDFA0(GameSceneMenuTilemapData *);
void loc_080CBD9C(GameSceneMenuOwnedDataPrefix *, HardwareSpriteBufferState *);
#else
void func_080CE790(GameSceneMenuTilemapData *);
void func_080CC58C(GameSceneMenuOwnedDataPrefix *, HardwareSpriteBufferState *);
#endif
}

// Coordinate readers retain the native unused panel argument, without
// inventing a relationship between the left/right opaque payload types.
MenuGridPosition GetMenuGridLeftCellPosition(GameSceneMenuOwnedDataPrefix const *, i32);
MenuGridPosition GetMenuGridLeftHeaderPosition(GameSceneMenuOwnedDataPrefix const *);
MenuGridPosition GetMenuGridRightCellPosition(GameSceneMenuOwnedDataPrefix const *, i32);
MenuGridPosition GetMenuGridRightHeaderPosition(GameSceneMenuOwnedDataPrefix const *);

#endif // GAME_MENU_HH
