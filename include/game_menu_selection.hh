#ifndef GAME_MENU_SELECTION_HH
#define GAME_MENU_SELECTION_HH

#include "game_menu_lifetimes.hh"

#pragma interface "game_menu_selection.hh"

// Concrete scene cores add their own payload after this common 0x98 prefix.
struct GameSceneMenuSelectionCore : GameSceneMenuCorePrefix {
    GameSceneMenuCursorDataOwner cursor;
    GameSceneMenuSpriteDataOwner sprite;
    GameSceneMenuTilemapDataOwner tilemap;
protected:
    GameSceneMenuSelectionCore(GameStateSaveImage *);
public:
    void Update();
};

typedef char MenuSelectionCoreSizeCheck[sizeof(GameSceneMenuSelectionCore) == 0x98 ? 1 : -1];
typedef char MenuSelectionCursorCheck[offsetof(GameSceneMenuSelectionCore, cursor) == 0x8C ? 1 : -1];
typedef char MenuSelectionSpriteCheck[offsetof(GameSceneMenuSelectionCore, sprite) == 0x90 ? 1 : -1];
typedef char MenuSelectionTilemapCheck[offsetof(GameSceneMenuSelectionCore, tilemap) == 0x94 ? 1 : -1];


#endif // GAME_MENU_SELECTION_HH
