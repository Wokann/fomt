#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"
#include "font_draw.hh"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "obj_tile_collection.hh"
#include "obj_palette_collection.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_access.hh"
#include "ui_state.hh"
#include "new_game_menu.hh"
#include "utility/fixed_str.hh"

// The remaining birthday classes are implemented in new_game.cc.
#pragma implementation


// The birthday core and identity scene retain native callback views.
typedef void (*NewGameSceneVTableFunction)(void);
typedef int (*NewGameNativeVTableEntry)(...);

// Halfword-aligned records written by the append routine and read by OAM
// rendering. Only priority's low two bits are consumed by that renderer.
struct PACKED ALIGN(2) NewGameBirthdayInputGlyph {
    i16 x;
    i16 y;
    i16 glyph_index;
    u16 priority;
};

struct NewGameBirthdayInputCore : HardwareBootstrap {
    virtual ~NewGameBirthdayInputCore() asm("DestroyBirthdayInputCore");
    u32 unk_08;
    UiStateOwner * ui_state;
    HardwareMusicPlayerSlot music_players[2];
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
private:
    NewGameBirthdayInputCore();
};
struct NewGameBirthdayInputScene : AScene {
    NewGameBirthdayInputCore * core;

    NewGameBirthdayInputScene(GameDate birthday) asm("InitializeBirthdayInputScene")
        SECTION(".text.new_game_birthday_input_scene");
    virtual ~NewGameBirthdayInputScene() asm("DestroyBirthdayInputScene")
        SECTION(".text.new_game_birthday_input_scene");
    virtual SceneTransitionOwner Run() asm("RunBirthdayInputScene")
        SECTION(".text.new_game_birthday_input_scene");
    GameDate GetDate() const asm("GetBirthdayInputSceneDate")
        SECTION(".text.new_game_birthday_input_scene");
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
typedef char BirthdayMusicCheck[offsetof(NewGameBirthdayInputCore, music_players) == 0x10 ? 1 : -1];
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
NewGameBirthdayInputCore * InitializeBirthdayInputCore(NewGameBirthdayInputCore *, GameDate)
    SECTION(".text.new_game_birthday_core");
void DestroyBirthdayInputCore(NewGameBirthdayInputCore *, u32 flags)
    SECTION(".text.new_game_birthday_core_cleanup");
extern NewGameSceneVTableFunction const vtable_unk_080E7AB4[];
extern NewGameSceneVTableFunction const vtable_unk_080E7AC4[];
SceneTransitionOwner func_0806DB38(NewGameBirthdayInputCore *);
void UpdateBirthdayInputUi(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_ui");
void MoveBirthdayInputCursor(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_navigation");
void func_0806E02C(NewGameBirthdayInputCore *);
bool ConfirmBirthdayInputSelection(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_selection");
bool CancelBirthdayInputSelection(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_selection");
// Background/glyph preparation remains native in every region.
void func_0806E234(NewGameBirthdayInputCore *);
void InitializeBirthdayInputCursor(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_cursor_setup");
void BuildBirthdayInputGlyphs(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_glyph_layout");
void AppendBirthdayInputGlyph(NewGameBirthdayInputCore *, i32, i32, i32, i32)
    SECTION(".text.new_game_birthday_glyph_append");
void RenderBirthdayInputSprites(NewGameBirthdayInputCore *)
    SECTION(".text.new_game_birthday_sprite_render");
}

// Clear2DGfxBuffer and DrawStringTo2DGfxBuffer consume the tile words after
// the untouched four-byte prefix. Each 4bpp tile occupies eight words and
// the default new-game text buffers are two tiles high. Native construction
// leaves them uninitialized; the corresponding UI setup draws their tiles.
template <u32 Width, u32 Height = 2>
struct NewGameTextTileBuffer {
    NewGameTextTileBuffer() {}

    void Clear()
    {
        UnkUiSelectionDimensions size(Width, Height);
        Clear2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles, 0);
    }

    void ClearRect(u32 x, u32 y, u32 width, u32 height, u32 color)
    {
        UnkUiSelectionDimensions size(Width, Height);
        Clear2DGfxBufferRect(reinterpret_cast<u32 const &>(size), tiles,
            x, y, width, height, color);
    }

    void DrawString(i32 x, i32 y, char const * text)
    {
        UnkUiSelectionDimensions size(Width, Height);
        DrawStringTo2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles,
            x, y, reinterpret_cast<u8 const *>(text));
    }


    u32 unk_00;
    u32 tiles[Width * Height * 8];
};

#endif // NEW_GAME_HH
