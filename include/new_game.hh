#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"
#include "font_draw.hh"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_music_player.hh"
#include "hardware_state_clear.hh"
#include "hardware_resource.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_access.hh"
#include "ui_state.hh"
#include "new_game_menu.hh"
#include "utility/fixed_str.hh"


// Partial-core tables retain their existing raw callback view. The compiler's
// real C++ vtable symbols require its erased int(...) entry type instead.
// Call code uses the typed scene interfaces, not these erased signatures.
typedef void (*NewGameSceneVTableFunction)(void);
typedef int (*NewGameNativeVTableEntry)(...);

// The workflow creates this transition after all four fields are confirmed.
// Each name is limited to twelve encoded bytes, with word-aligned members.
// Retain the explicit GNU ABI table beside the neighboring partial-core tables;
// the interface pragma prevents a second compiler-emitted table.
#pragma interface "new_game.hh"
struct NewGameFreshSaveTransition : SceneTransition {
    NewGameFreshSaveTransition(char const * farm, char const * player,
        GameDate date, char const * dog)
        : farm_name(farm), player_name(player), birthday(date), dog_name(dog) {}
    // This real native entry forwards the trivial name fields to base cleanup.
    virtual ~NewGameFreshSaveTransition() asm("DestroyFreshSaveGameTransition")
        SECTION(".text.new_game_fresh_save_callbacks");
    virtual SceneOwner CreateScene() asm("CreateFreshSaveGameScene")
        SECTION(".text.new_game_fresh_save_callbacks");

    FixedStr<12> farm_name ALIGN(4);
    FixedStr<12> player_name ALIGN(4);
    GameDate birthday ALIGN(4);
    FixedStr<12> dog_name ALIGN(4);
};
#pragma implementation


typedef char NewGameFreshSaveTransitionSizeCheck[sizeof(NewGameFreshSaveTransition) == 0x38 ? 1 : -1];
typedef char NewGameFreshSaveFarmCheck[offsetof(NewGameFreshSaveTransition, farm_name) == 4 ? 1 : -1];
typedef char NewGameFreshSavePlayerCheck[offsetof(NewGameFreshSaveTransition, player_name) == 0x14 ? 1 : -1];
typedef char NewGameFreshSaveBirthdayCheck[offsetof(NewGameFreshSaveTransition, birthday) == 0x24 ? 1 : -1];
typedef char NewGameFreshSaveDogCheck[offsetof(NewGameFreshSaveTransition, dog_name) == 0x28 ? 1 : -1];

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
    HardwareStateEntry glyph_tiles;
    HardwareResourceEntry glyph_palette;
    HardwareStateEntry cursor_tiles;
    HardwareResourceEntry cursor_palette;
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

// The complete form workflow is this scene's native virtual Run method.
#pragma interface "new_game.hh"
struct NewGameNameEntryScene : AScene {
    NewGameNameEntryScene() asm("func_08004C48") SECTION(".text.new_game_scene_lifecycle");
    virtual ~NewGameNameEntryScene() asm("func_08004C54") SECTION(".text.new_game_scene_lifecycle");
    virtual SceneTransitionOwner Run() asm("func_08004C68")
        SECTION(".text.new_game_name_entry_workflow");
};
#pragma implementation

// Clear2DGfxBuffer and DrawStringTo2DGfxBuffer consume the tile words after
// the untouched four-byte prefix. Each 4bpp tile occupies eight words and
// these new-game text buffers are two tiles high. Their native construction
// leaves them uninitialized; the corresponding UI setup draws their tiles.
template <u32 Width>
struct NewGameTextTileBuffer {
    NewGameTextTileBuffer() {}

    void ClearRect(u32 x, u32 y, u32 width, u32 height, u32 color)
    {
        UnkUiSelectionDimensions size(Width, 2);
        Clear2DGfxBufferRect(reinterpret_cast<u32 const &>(size), tiles,
            x, y, width, height, color);
    }

    void DrawString(i32 x, i32 y, char const * text)
    {
        UnkUiSelectionDimensions size(Width, 2);
        DrawStringTo2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles,
            x, y, reinterpret_cast<u8 const *>(text));
    }


    u32 unk_00;
    u32 tiles[Width * 2 * 8];
};

typedef char NewGameNameEntrySceneSizeCheck[sizeof(NewGameNameEntryScene) == 4 ? 1 : -1];

EXTERN_C

extern NewGameNativeVTableEntry __vt_21NewGameNameEntryScene[4];

AScene * func_08004C48(void * object)
    SECTION(".text.new_game_scene_lifecycle");
void func_08004C54(struct NewGameNameEntryScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");

// C/assembly declarations of the real member entries used by the ABI tables.
SceneTransitionOwner func_08004C68(NewGameNameEntryScene *);
SceneOwner CreateFreshSaveGameScene(NewGameFreshSaveTransition * transition)
    SECTION(".text.new_game_fresh_save_callbacks");
void DestroyFreshSaveGameTransition(NewGameFreshSaveTransition * transition, int flags)
    SECTION(".text.new_game_fresh_save_callbacks");

extern NewGameNativeVTableEntry __vt_26NewGameFreshSaveTransition[4];

EXTERN_C_END

#endif // NEW_GAME_HH
