#ifndef NEW_GAME_MENU_TYPES_HH
#define NEW_GAME_MENU_TYPES_HH

#include "prelude.h"
#include "font_draw.hh"
#include "gbaio.h"
#include "game_state_types.hh"
#include "hardware_context.hh"
#include "hardware_sound.hh"
#include "obj_palette_collection.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_access.hh"
#include "ui_state.hh"

#include "new_game_ui.hh"

// Runtime text filled by FormatNewGameSaveSlotSummary and selected by the
// menu's second choice. These two 128-byte buffers are not ROM literals.
struct NewGameMenuSaveSlotStatus {
    char text[0x80];

    NewGameMenuSaveSlotStatus() { text[0] = '\0'; }
    bool IsEmpty() const { return text[0] == '\0'; }
    char const * Data() const { return text; }
};


// The runner dispatches this separately from active_row and the UI window's
// own animation state. Both confirmation phases return to ordinary selection
// when cancelled; the notice phase waits for the result message to finish.
enum NewGameMenuPhase
{
    NEW_GAME_MENU_SELECTION,
    NEW_GAME_MENU_SAVE_CONFIRMATION,
    NEW_GAME_MENU_LOAD_CONFIRMATION,
    NEW_GAME_MENU_NOTICE,
};


#pragma interface "new_game_menu.hh"
struct NewGameMenuCore;

struct NewGameMenuScene : AScene {
    NewGameMenuCore * core;

    // Startup opens with a return-to-intro transition; the in-game form
    // consumes the supplied continuation slot, including residual cleanup.
    NewGameMenuScene();
    NewGameMenuScene(GameStateSaveImage * save, SceneTransition *& continuation);
    virtual ~NewGameMenuScene();
    virtual SceneTransitionOwner Run();
};


// Members follow the native initialization and destruction order.
struct NewGameMenuCore : HardwareContext {
    NewGameMenuCore(GameStateSaveImage * save, SceneTransitionOwner next)
        asm("InitializeNewGameMenuCore");
    // Cleanup unwinds the members and bootstrap in reverse order.
    // Borrowed active snapshot; null when opening the title-screen load menu.
    GameStateSaveImage * current_save;
    SceneTransitionOwner continuation;
    UiStateOwner ui_state;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    IndexedResourceArchive resources;
    ObjTileCollectionEntry state_entry;
    ObjPaletteCollectionEntry resource_entry;
    HardwareSpriteOamRecord option_attributes;
    IndexedResourceHandle selector_resource;
    HardwareSpriteOamRecord selector_attributes;
    u32 active_row;
    u8 choices[6];
    u8 unk_8A[2];
    NewGameMenuPhase phase;
    SramAccess sram;
    NewGameMenuSaveSlotStatus save_slot_status[2];
    GameDisplayOptions saved_display_options[2];
};


// Loading transfers the saved image into the next game controller.
struct NewGameLoadedSaveTransition : SceneTransition {
    explicit NewGameLoadedSaveTransition(GameStateSaveImageOwner & owner);
    virtual SceneOwner CreateScene();
    GameStateSaveImageOwner state;
};


// The title-screen menu returns to the intro through this continuation.
struct MenuIntroTransition : SceneTransition
{
    virtual SceneOwner CreateScene() asm("CreateIntroScene");
};



EXTERN_C

void UpdateNewGameMenuUi(NewGameMenuCore * core);

// Draw the six rows of three labels and upload their 4bpp tiles. The native
// entry ignores its core argument and uses the shared software glyph renderer.
void RenderNewGameMenuLabelTiles(NewGameMenuCore * core);

void SubmitNewGameMenuChoiceSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes);
void SubmitNewGameMenuCursorSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial);
void UpdateNewGameMenuStatusText(struct NewGameMenuCore * core);

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void RunNewGameMenuOpeningBlend(struct HardwareContext * core);
void RunNewGameMenuClosingBlend(struct HardwareContext * core);

// Saving, loading and core construction retain their native order.
bool TrySaveNewGameMenuSlot(struct NewGameMenuCore * core);
bool TryLoadNewGameMenuSlot(struct NewGameMenuCore * core);

// Clear the output, then append up to 127 encoded bytes and a terminator.
// JP uses full-width digits; overseas text puts the year/day labels before
// their numbers.
// The first argument is unused by the native body, which remains assembly.
void FormatNewGameSaveSlotSummary(struct NewGameMenuCore * core,
    NewGameMenuSaveSlotStatus & output, GameStateSaveImage const * snapshot);

// Initialize the supplied storage and consume the transition pointer word.
// This explicit pointer-reference view preserves the native ownership ABI;
// cleanup of the consumed input also belongs to the callee.
NewGameMenuCore * InitializeNewGameMenuCore(NewGameMenuCore * core, GameStateSaveImage * save,
    SceneTransition *& continuation);
SceneTransitionOwner RunNewGameMenuCore(struct NewGameMenuCore * core);

EXTERN_C_END

#include "new_game_data.hh"

extern NewGameMenuLabelRow const gNewGameMenuLabels[6];

extern char const gText_NewGameMenu_Diary[];
extern char const gText_NewGameMenu_Save[];
extern char const gText_NewGameMenu_Load[];
extern char const gText_NewGameMenu_Blank[];
extern char const gText_NewGameMenu_Data1[];
extern char const gText_NewGameMenu_Data2[];
extern char const gText_NewGameMenu_ControlSettings[];
extern char const gText_NewGameMenu_ClockDisplay[];
extern char const gText_NewGameMenu_Yes[];
extern char const gText_NewGameMenu_No[];
extern char const gText_NewGameMenu_FaceDisplay[];
extern char const gText_NewGameMenu_NameDisplay[];


// Directly copied status-line fragments and prompts used by asm/new_game.s.
extern char const gText_NewGameStatus_YearSuffix[];
extern char const gText_NewGameStatus_SeasonSeparator[];
extern char const gText_NewGameStatus_DaySuffix[];
extern char const gText_NewGameStatus_OpenParen[];
extern char const gText_NewGameStatus_CloseParen[];
extern char const gText_NewGameStatus_FarmSuffix[];
extern char const gText_NewGameStatus_ReadDiary[];
extern char const gText_NewGameStatus_WriteDiary[];
extern char const gText_NewGameStatus_NoSavedData[];

// Fixed-width help messages selected by the new-game configuration screen.
extern char const gText_NewGameHelp_Controls[];
extern char const gText_NewGameHelp_ClockDisplay[];
extern char const gText_NewGameHelp_FaceDisplay[];
extern char const gText_NewGameHelp_NameDisplay[];

// Save/load result messages and confirmation fields used by the new-game flow.
extern char const gText_NewGameSave_SaveFailed[];
extern char const gText_NewGameSave_LoadFailed[];
extern char const gText_NewGameSave_LoadPrompt[];
extern char const gText_NewGameSave_OverwritePrompt[];
extern char const gCppRuntimeError_NewGameSave[];

#if defined(REGION_JP)
extern char const gText_NewGameSave_Affirmative[];
extern char const gText_NewGameSave_Negative[];
#endif




#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_NewGameMenu_ControlOption1[];
#endif
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_NewGameMenu_ControlOption2[];
#endif

#endif // NEW_GAME_MENU_TYPES_HH
