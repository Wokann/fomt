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



#endif // GAME_MENU_SELECTION_HH
