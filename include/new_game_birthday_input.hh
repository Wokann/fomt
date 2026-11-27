#ifndef NEW_GAME_BIRTHDAY_INPUT_HH
#define NEW_GAME_BIRTHDAY_INPUT_HH

#include "prelude.h"
#include "font_draw.hh"
#include "gbaio.h"
#include "unknown_types.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "obj_tile_collection.hh"
#include "obj_palette_collection.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_access.hh"
#include "ui_state.hh"
#include "new_game_ui.hh"
#include "utility/fixed_str.hh"

#pragma interface "new_game_birthday_input.hh"

// Halfword-aligned records written by the append routine and read by OAM
// rendering. Only priority's low two bits are consumed by that renderer.
struct PACKED ALIGN(2) NewGameBirthdayInputGlyph {
    i16 x;
    i16 y;
    i16 glyph_index;
    u16 priority;
};

// Frame phases of the native birthday selector; the stored field remains i16.
enum BirthdayInputStep {
    BIRTHDAY_INPUT_WAIT_OPENING,
    BIRTHDAY_INPUT_CHOOSE_DATE,
    BIRTHDAY_INPUT_CONFIRM_DATE,
    BIRTHDAY_INPUT_START_CLOSING,
    BIRTHDAY_INPUT_WAIT_CLOSING,
};

struct NewGameBirthdayInputCore;

struct NewGameBirthdayInputScene : AScene {
    NewGameBirthdayInputCore * core;

    NewGameBirthdayInputScene(GameDate birthday) asm("InitializeBirthdayInputScene");
    virtual ~NewGameBirthdayInputScene() asm("DestroyBirthdayInputScene");
    virtual SceneTransitionOwner Run() asm("RunBirthdayInputScene");
    GameDate GetDate() const asm("GetBirthdayInputSceneDate");
};

struct NewGameBirthdayInputCore : HardwareContext {
    explicit NewGameBirthdayInputCore(GameDate birthday);
    // The implicit virtual destructor releases members in reverse order.
    u32 unk_08;
    GameSceneTalkWindowOwner ui_state;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    ObjTileCollectionEntry glyph_tiles;
    ObjPaletteCollectionEntry glyph_palette;
    ObjTileCollectionEntry cursor_tiles;
    ObjPaletteCollectionEntry cursor_palette;
    i8 cursor_column;
    i8 cursor_row;
    i8 saved_season_column;
    u8 unk_3B;
    NewGameMenuSpriteAttributes cursor_attributes;
    u8 cursor_visible;
    u8 unk_45;
#if defined(REGION_JP)
    NewGameBirthdayInputGlyph glyphs[70];
#elif defined(REGION_DE)
    NewGameBirthdayInputGlyph glyphs[131];
#elif defined(REGION_US) || defined(REGION_EU)
    NewGameBirthdayInputGlyph glyphs[128];
#endif
    i16 glyph_count;
    GameDate birthday;
    i8 season_column;
    i8 day;
    i16 step;
    i16 dialogue_state;
    i16 dialogue_choice;
};
#if defined(REGION_JP)
#elif defined(REGION_DE)
#elif defined(REGION_US) || defined(REGION_EU)
#endif
extern "C" {
SceneTransitionOwner RunBirthdayInputCore(NewGameBirthdayInputCore *);
void UpdateBirthdayInputUi(NewGameBirthdayInputCore *);
void MoveBirthdayInputCursor(NewGameBirthdayInputCore *);
void UpdateBirthdayInputCursor(NewGameBirthdayInputCore *);
bool ConfirmBirthdayInputSelection(NewGameBirthdayInputCore *);
bool CancelBirthdayInputSelection(NewGameBirthdayInputCore *);
// Prepare the native backgrounds and upload the selected regional glyph set.
void InitializeBirthdayInputGraphics(NewGameBirthdayInputCore *);
void InitializeBirthdayInputCursor(NewGameBirthdayInputCore *);
void BuildBirthdayInputGlyphs(NewGameBirthdayInputCore *);
void AppendBirthdayInputGlyph(NewGameBirthdayInputCore *, i32, i32, i32, i32);
void RenderBirthdayInputSprites(NewGameBirthdayInputCore *);
}

extern u16 const gNewGameBirthdayInputGlyphs[];
extern char const gText_NewGameBirthdayInput_Confirmation[];
extern char const gText_NewGameBirthdayInput_Yes[];
extern char const gText_NewGameBirthdayInput_No[];


#endif // NEW_GAME_BIRTHDAY_INPUT_HH
