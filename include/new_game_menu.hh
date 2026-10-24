#ifndef NEW_GAME_MENU_HH
#define NEW_GAME_MENU_HH

#include "prelude.h"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_resource.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_proxy_2.hh"
#include "ui_state.hh"

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

// Runtime text filled by FormatNewGameSaveSlotSummary and selected by the
// menu's second choice. These two 128-byte buffers are not ROM literals.
struct NewGameMenuSaveSlotStatus {
    char text[0x80];

    NewGameMenuSaveSlotStatus() { text[0] = '\0'; }
    bool IsEmpty() const { return text[0] == '\0'; }
    char const * Data() const { return text; }
};

typedef char NewGameMenuSaveSlotStatusSizeCheck[sizeof(NewGameMenuSaveSlotStatus) == 0x80 ? 1 : -1];

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

typedef char NewGameMenuPhaseSizeCheck[sizeof(NewGameMenuPhase) == 4 ? 1 : -1];

// The menu constructor allocates 0x1A0 bytes. Only fields confirmed by its
// constructor, cleanup, and hardware/UI consumers are modeled here; the
// remaining payload is not yet a recovered high-level class.
struct NewGameMenuCore : HardwareBootstrap {
    ~NewGameMenuCore() asm("DestroyNewGameMenuCore")
        SECTION(".text.new_game_menu_core_cleanup");
    // Borrowed active snapshot; null when opening the title-screen load menu.
    GameStateSaveImage * current_save;
    SceneTransitionOwner continuation;
    UiStateOwner ui_state;
    MusicPlayer * music_players[2];
    IndexedResourceArchive resources;
    HardwareStateEntry state_entry;
    HardwareResourceEntry resource_entry;
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

typedef char NewGameMenuCoreSizeCheck[sizeof(NewGameMenuCore) == 0x1A0 ? 1 : -1];
typedef char NewGameMenuCoreSaveCheck[offsetof(NewGameMenuCore, current_save) == 8 ? 1 : -1];
typedef char NewGameMenuCoreUiCheck[offsetof(NewGameMenuCore, ui_state) == 0x10 ? 1 : -1];
typedef char NewGameMenuCoreMusicCheck[offsetof(NewGameMenuCore, music_players) == 0x14 ? 1 : -1];
typedef char NewGameMenuCoreResourcesCheck[offsetof(NewGameMenuCore, resources) == 0x1C ? 1 : -1];
typedef char NewGameMenuCoreStateEntryCheck[offsetof(NewGameMenuCore, state_entry) == 0x4C ? 1 : -1];
typedef char NewGameMenuCoreResourceEntryCheck[offsetof(NewGameMenuCore, resource_entry) == 0x54 ? 1 : -1];
typedef char NewGameMenuCoreOptionAttributesCheck[offsetof(NewGameMenuCore, option_attributes) == 0x5C ? 1 : -1];
typedef char NewGameMenuCoreSelectorResourceCheck[offsetof(NewGameMenuCore, selector_resource) == 0x64 ? 1 : -1];
typedef char NewGameMenuCoreSelectorAttributesCheck[offsetof(NewGameMenuCore, selector_attributes) == 0x78 ? 1 : -1];
typedef char NewGameMenuCoreActiveRowCheck[offsetof(NewGameMenuCore, active_row) == 0x80 ? 1 : -1];
typedef char NewGameMenuCoreChoicesCheck[offsetof(NewGameMenuCore, choices) == 0x84 ? 1 : -1];
typedef char NewGameMenuCorePhaseCheck[offsetof(NewGameMenuCore, phase) == 0x8C ? 1 : -1];
typedef char NewGameMenuCoreSramCheck[offsetof(NewGameMenuCore, sram) == 0x90 ? 1 : -1];
typedef char NewGameMenuCoreSaveSlotStatusCheck[offsetof(NewGameMenuCore, save_slot_status) == 0x98 ? 1 : -1];
typedef char NewGameMenuCoreSavedDisplayOptionsCheck[offsetof(NewGameMenuCore, saved_display_options) == 0x198 ? 1 : -1];

typedef void (*NewGameMenuVTableEntry)(void);

struct NewGameMenuScene : AScene {
    NewGameMenuCore * core;

    // Startup opens with a return-to-intro transition; the in-game form
    // consumes the supplied continuation slot, including residual cleanup.
    NewGameMenuScene() SECTION(".text.new_game_menu_scene");
    NewGameMenuScene(GameStateSaveImage * save, SceneTransition *& continuation)
        SECTION(".text.new_game_menu_scene");
    virtual ~NewGameMenuScene() SECTION(".text.new_game_menu_scene");
    virtual SceneTransitionOwner Run() SECTION(".text.new_game_menu_scene");
};

typedef char NewGameMenuSceneSizeCheck[sizeof(NewGameMenuScene) == 8 ? 1 : -1];
typedef char NewGameMenuSceneCoreCheck[offsetof(NewGameMenuScene, core) == 4 ? 1 : -1];

// Loading transfers the saved image into the next game controller. All
// virtual methods are inline (the implicit destructor owns the image), so
// the compiler emits their shared implementations and table without a key
// method or a separate unused constructor body.
struct NewGameLoadedSaveTransition : SceneTransition {
    explicit NewGameLoadedSaveTransition(GameStateSaveImageOwner & owner)
        : state(owner.release()) {}
    virtual inline SceneOwner CreateScene();
    GameStateSaveImageOwner state;
};

typedef char NewGameLoadedSaveTransitionSizeCheck[sizeof(NewGameLoadedSaveTransition) == 8 ? 1 : -1];
typedef char NewGameLoadedSaveTransitionStateCheck[offsetof(NewGameLoadedSaveTransition, state) == 4 ? 1 : -1];


EXTERN_C

void UpdateNewGameMenuUi(NewGameMenuCore * core);

// Draw the six rows of three labels and upload their 4bpp tiles. The native
// entry ignores its core argument; its body still resides in asm/new_game_menu.s.
void RenderNewGameMenuLabelTiles(NewGameMenuCore * core);

void SubmitNewGameMenuChoiceSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
    SECTION(".text.new_game_menu_update");
void SubmitNewGameMenuCursorSprite(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
    SECTION(".text.new_game_menu_update");
void UpdateNewGameMenuStatusText(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void RunNewGameMenuOpeningBlend(struct HardwareBootstrap * core);
void RunNewGameMenuClosingBlend(struct HardwareBootstrap * core);

// Saving, loading and core construction retain their native order.
bool TrySaveNewGameMenuSlot(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");
bool TryLoadNewGameMenuSlot(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");

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
    SceneTransition *& continuation)
    SECTION(".text.new_game_menu_update");
SceneTransitionOwner RunNewGameMenuCore(struct NewGameMenuCore * core);
extern NewGameMenuVTableEntry const gNewGameMenuCoreVTable[];

// Raw C/assembly view of the real C++ destructor entry and flags.
void DestroyNewGameMenuCore(NewGameMenuCore * core, int flags);

EXTERN_C_END

#endif // NEW_GAME_MENU_HH
