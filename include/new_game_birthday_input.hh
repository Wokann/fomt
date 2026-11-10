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

// The dialog is allocated by this core and released after its OBJ resources.
struct BirthdayInputUiOwner {
    UiStateOwner * value;

    explicit inline BirthdayInputUiOwner(u32 const & flags);
    ~BirthdayInputUiOwner() { delete value; }
};

typedef char BirthdayUiOwnerSizeCheck[sizeof(BirthdayInputUiOwner) == 4 ? 1 : -1];

#pragma interface "new_game_birthday_input.hh"

// Halfword-aligned records written by the append routine and read by OAM
// rendering. Only priority's low two bits are consumed by that renderer.
struct PACKED ALIGN(2) NewGameBirthdayInputGlyph {
    i16 x;
    i16 y;
    i16 glyph_index;
    u16 priority;
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
    BirthdayInputUiOwner ui_state;
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
#else
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
typedef char BirthdayCoreSizeCheck[sizeof(NewGameBirthdayInputCore) == 0x284 ? 1 : -1];
typedef char BirthdayFieldCheck[offsetof(NewGameBirthdayInputCore, birthday) == 0x278 ? 1 : -1];
#elif defined(REGION_DE)
typedef char BirthdayCoreSizeCheck[sizeof(NewGameBirthdayInputCore) == 0x46C ? 1 : -1];
typedef char BirthdayFieldCheck[offsetof(NewGameBirthdayInputCore, birthday) == 0x460 ? 1 : -1];
#else
typedef char BirthdayCoreSizeCheck[sizeof(NewGameBirthdayInputCore) == 0x454 ? 1 : -1];
typedef char BirthdayFieldCheck[offsetof(NewGameBirthdayInputCore, birthday) == 0x448 ? 1 : -1];
#endif
typedef char BirthdaySceneSizeCheck[sizeof(NewGameBirthdayInputScene) == 8 ? 1 : -1];
typedef char BirthdaySceneCoreCheck[offsetof(NewGameBirthdayInputScene, core) == 4 ? 1 : -1];
typedef char BirthdayGlyphSizeCheck[sizeof(NewGameBirthdayInputGlyph) == 8 ? 1 : -1];
typedef char BirthdayGlyphAlignmentCheck[__alignof__(NewGameBirthdayInputGlyph) == 2 ? 1 : -1];
typedef char BirthdayGlyphYCheck[offsetof(NewGameBirthdayInputGlyph, y) == 2 ? 1 : -1];
typedef char BirthdayGlyphIndexCheck[offsetof(NewGameBirthdayInputGlyph, glyph_index) == 4 ? 1 : -1];
typedef char BirthdayGlyphPriorityCheck[offsetof(NewGameBirthdayInputGlyph, priority) == 6 ? 1 : -1];
typedef char BirthdayUiCheck[offsetof(NewGameBirthdayInputCore, ui_state) == 0x0C ? 1 : -1];
typedef char BirthdayMusicCheck[offsetof(NewGameBirthdayInputCore, music_player_1) == 0x10 ? 1 : -1];
typedef char BirthdaySecondMusicCheck[offsetof(NewGameBirthdayInputCore, music_player_2) == 0x14 ? 1 : -1];
typedef char BirthdayGlyphTilesCheck[offsetof(NewGameBirthdayInputCore, glyph_tiles) == 0x18 ? 1 : -1];
typedef char BirthdayGlyphPaletteCheck[offsetof(NewGameBirthdayInputCore, glyph_palette) == 0x20 ? 1 : -1];
typedef char BirthdayCursorTilesCheck[offsetof(NewGameBirthdayInputCore, cursor_tiles) == 0x28 ? 1 : -1];
typedef char BirthdayCursorPaletteCheck[offsetof(NewGameBirthdayInputCore, cursor_palette) == 0x30 ? 1 : -1];
typedef char BirthdayCursorCheck[offsetof(NewGameBirthdayInputCore, cursor_column) == 0x38 ? 1 : -1];
typedef char BirthdayCursorRowCheck[offsetof(NewGameBirthdayInputCore, cursor_row) == 0x39 ? 1 : -1];
typedef char BirthdaySavedSeasonCheck[offsetof(NewGameBirthdayInputCore, saved_season_column) == 0x3A ? 1 : -1];
typedef char BirthdayCursorVisibleCheck[offsetof(NewGameBirthdayInputCore, cursor_visible) == 0x44 ? 1 : -1];
typedef char BirthdayGlyphsCheck[offsetof(NewGameBirthdayInputCore, glyphs) == 0x46 ? 1 : -1];
typedef char BirthdayGlyphCountCheck[offsetof(NewGameBirthdayInputCore, glyph_count)
    == offsetof(NewGameBirthdayInputCore, birthday) - 2 ? 1 : -1];
typedef char BirthdayDayCheck[offsetof(NewGameBirthdayInputCore, day)
    == offsetof(NewGameBirthdayInputCore, birthday) + 2 ? 1 : -1];
typedef char BirthdayStepCheck[offsetof(NewGameBirthdayInputCore, step)
    == offsetof(NewGameBirthdayInputCore, birthday) + 4 ? 1 : -1];
typedef char BirthdayDialogueStateCheck[offsetof(NewGameBirthdayInputCore, dialogue_state)
    == offsetof(NewGameBirthdayInputCore, birthday) + 6 ? 1 : -1];
typedef char BirthdayDialogueChoiceCheck[offsetof(NewGameBirthdayInputCore, dialogue_choice)
    == offsetof(NewGameBirthdayInputCore, birthday) + 8 ? 1 : -1];
extern "C" {
SceneTransitionOwner RunBirthdayInputCore(NewGameBirthdayInputCore *);
void UpdateBirthdayInputUi(NewGameBirthdayInputCore *);
void MoveBirthdayInputCursor(NewGameBirthdayInputCore *);
void UpdateBirthdayInputCursor(NewGameBirthdayInputCore *);
bool ConfirmBirthdayInputSelection(NewGameBirthdayInputCore *);
bool CancelBirthdayInputSelection(NewGameBirthdayInputCore *);
// Background/glyph preparation remains native in every region.
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
