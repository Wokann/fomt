#ifndef NEW_GAME_MENU_HH
#define NEW_GAME_MENU_HH

#include "prelude.h"

// Menu OAM coordinates use their wrapped hardware representation, not the
// signed offsets stored in sprite archives. Only the first six bytes are
// copied to OAM; the destination's affine coefficient is left untouched.
struct NewGameMenuSpriteAttributes {
    u32 y : 8;
    u32 affine_mode : 2;
    u32 object_mode : 2;
    u32 mosaic : 1;
    u32 color_mode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 affine_index_low : 3;
    u32 horizontal_flip : 1;
    u32 vertical_flip : 1;
    u32 size : 2;
    u16 tile_attributes;
    u16 affine_coefficient;
};

typedef char NewGameMenuSpriteAttributesSizeCheck[sizeof(NewGameMenuSpriteAttributes) == 8 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesTileCheck[offsetof(NewGameMenuSpriteAttributes, tile_attributes) == 4 ? 1 : -1];
typedef char NewGameMenuSpriteAttributesCoefficientCheck[offsetof(NewGameMenuSpriteAttributes, affine_coefficient) == 6 ? 1 : -1];

struct NewGameMenuCore;

EXTERN_C

void UpdateNewGameMenuUi(NewGameMenuCore * core);

// Draw the six rows of three labels and upload their 4bpp tiles. The native
// entry ignores its core argument; its body still resides in asm/new_game.s.
void RenderNewGameMenuLabelTiles(NewGameMenuCore * core);

void SubmitNewGameMenuChoiceSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
    SECTION(".text.new_game_menu_update");
void SubmitNewGameMenuCursorSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
    SECTION(".text.new_game_menu_update");
void UpdateNewGameMenuStatusText(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");

EXTERN_C_END

#endif // NEW_GAME_MENU_HH
