#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"
#include "game_state.hh"
#include "hardware_bootstrap.hh"
#include "hardware_state_clear.hh"
#include "hardware_resource.hh"
#include "resource_handle.hh"
#include "scene.hh"
#include "sram_proxy_2.hh"
#include "ui_state.hh"
#include "utility/fixed_str.hh"

struct MusicPlayer;

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

// Runtime save-summary text, filled by func_08003788 and selected by the
// menu's second choice. These two 128-byte buffers are not ROM literals.
struct NewGameMenuSaveSlotStatus {
    char text[0x80];

    NewGameMenuSaveSlotStatus() { text[0] = '\0'; }
    bool IsEmpty() const { return text[0] == '\0'; }
    char const * Data() const { return text; }
};

typedef char NewGameMenuSaveSlotStatusSizeCheck[sizeof(NewGameMenuSaveSlotStatus) == 0x80 ? 1 : -1];

// The menu constructor allocates 0x1A0 bytes. Only fields confirmed by its
// constructor, cleanup, and hardware/UI consumers are modeled here; the
// remaining payload is not yet a recovered high-level class.
struct NewGameMenuCore : HardwareBootstrap {
    void * unk_08;
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
    u32 unk_8C;
    SramAccess sram;
    NewGameMenuSaveSlotStatus save_slot_status[2];
    GameDisplayOptions saved_display_options[2];
};

typedef char NewGameMenuCoreSizeCheck[sizeof(NewGameMenuCore) == 0x1A0 ? 1 : -1];
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
typedef char NewGameMenuCoreUnk8CCheck[offsetof(NewGameMenuCore, unk_8C) == 0x8C ? 1 : -1];
typedef char NewGameMenuCoreSramCheck[offsetof(NewGameMenuCore, sram) == 0x90 ? 1 : -1];
typedef char NewGameMenuCoreSaveSlotStatusCheck[offsetof(NewGameMenuCore, save_slot_status) == 0x98 ? 1 : -1];
typedef char NewGameMenuCoreSavedDisplayOptionsCheck[offsetof(NewGameMenuCore, saved_display_options) == 0x198 ? 1 : -1];

// Original ABI tables contain two metadata words before their callbacks.
typedef void (*NewGameSceneVTableFunction)(void);

// This one-word owner scopes the allocation returned by the save read. Its
// layout stays opaque; cleanup uses the existing image destructor. Failed
// reads release the allocation for the caller's original raw-delete path.
class NewGameLoadedSaveOwner {
public:
    explicit NewGameLoadedSaveOwner(void * state) : value(state) {}
    ~NewGameLoadedSaveOwner()
    {
        if (value != nullptr)
            func_080D4480(value, 3);
    }
    void * get() const { return value; }
    void * release()
    {
        void * state = value;
        value = nullptr;
        return state;
    }

private:
    void * value;
    NewGameLoadedSaveOwner(NewGameLoadedSaveOwner const &);
    NewGameLoadedSaveOwner & operator=(NewGameLoadedSaveOwner const &);
};

// The existing +0x0C virtual callback creates the next game scene; its
// destructor cleans up the save image stored immediately after the vtable.
struct NewGameLoadedSaveTransition {
    NewGameSceneVTableFunction const * vtable;
    void * state;
};

typedef char NewGameLoadedSaveOwnerSizeCheck[sizeof(NewGameLoadedSaveOwner) == 4 ? 1 : -1];
typedef char NewGameLoadedSaveTransitionSizeCheck[sizeof(NewGameLoadedSaveTransition) == 8 ? 1 : -1];
typedef char NewGameLoadedSaveTransitionStateCheck[offsetof(NewGameLoadedSaveTransition, state) == 4 ? 1 : -1];

struct NewGameMenuScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameMenuCore * core;
};

struct NewGameNameEntryScene {
    NewGameSceneVTableFunction const * vtable;
};

// Clear2DGfxBuffer and DrawStringTo2DGfxBuffer consume the tile words after
// the untouched four-byte prefix. Each 4bpp tile occupies eight words and
// these new-game text buffers are two tiles high. Their native construction
// leaves them uninitialized; the corresponding UI setup draws their tiles.
template <u32 Width>
struct NewGameTextTileBuffer {
    NewGameTextTileBuffer() {}

    u32 unk_00;
    u32 tiles[Width * 2 * 8];
};

typedef char NewGameIdentityValueBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<12>) == 0x304 ? 1 : -1];
typedef char NewGameIdentityLabelBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<14>) == 0x384 ? 1 : -1];
typedef char NewGameIdentityTilesOffsetCheck[
    offsetof(NewGameTextTileBuffer<12>, tiles) == 4 ? 1 : -1];
typedef char NewGameIdentityTextBufferSizeCheck[sizeof(FixedStr<15>) == 0x10 ? 1 : -1];

// Physical field order: player name, birthday, farm name, dog name. Native
// construction bounds each byte string to 15 bytes plus its terminator;
// func_08005278 renders these four consecutive values in the same order.
enum NewGameIdentityField {
    NEW_GAME_IDENTITY_PLAYER_NAME,
    NEW_GAME_IDENTITY_BIRTHDAY,
    NEW_GAME_IDENTITY_FARM_NAME,
    NEW_GAME_IDENTITY_DOG_NAME,
    NEW_GAME_IDENTITY_FIELD_COUNT,
};

// The identity-confirmation form owns a 0x1878-byte JP core or a 0x1A78-byte
// overseas core. JP uses eight equal-width buffers: four values followed by
// four labels. Overseas labels are wider and form their own four-entry array.
// The unknown scalar and control-byte names retain their original US offsets.
struct NewGameIdentityCore : HardwareBootstrap {
#if defined(REGION_JP)
    NewGameTextTileBuffer<12> buffers[8];
#else
    NewGameTextTileBuffer<12> value_buffers[4];
    NewGameTextTileBuffer<14> label_buffers[4];
#endif
    u32 unk_1A28;
    UiStateOwner * ui_state;
    MusicPlayer * music;
    FixedStr<15> fields[NEW_GAME_IDENTITY_FIELD_COUNT];
    u8 unk_1A74;
    u8 unk_1A75;
    u8 unk_1A76;
    u8 unk_1A77;
};

struct NewGameIdentityScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameIdentityCore * core;
};

// Each name-input sprite has four control bytes before its native OAM record.
// Sprite 0 uses bytes 0/1 for keyboard column/row; sprite 1 uses byte 0 for
// the name-slot caret. The remaining bytes retain their unknown meanings.
// The initializer clears only the OAM record.
struct NewGameNameInputSpriteState {
    u8 unk_00[4];
    HardwareSpriteOamRecord attributes;
};

typedef char NewGameNameInputSpriteStateSizeCheck[
    sizeof(NewGameNameInputSpriteState) == 12 ? 1 : -1];
typedef char NewGameNameInputSpriteStateAttributesCheck[
    offsetof(NewGameNameInputSpriteState, attributes) == 4 ? 1 : -1];

// The keyboard scene owns eight two-tile-high, 30-tile-wide text buffers
// (nine in DE), followed by the current name and optional prompt buffers.
// Construction and the drawing/upload consumers confirm this physical order.
// Remaining control fields keep their unknown names; name is RAM storage.
struct NewGameNameInputCore : HardwareBootstrap {
#if defined(REGION_DE)
    NewGameTextTileBuffer<30> keyboard_buffers[9];
#else
    NewGameTextTileBuffer<30> keyboard_buffers[8];
#endif
    NewGameTextTileBuffer<30> name_buffer;
#if defined(REGION_JP)
    NewGameTextTileBuffer<6> prompt_buffer;
#else
    NewGameTextTileBuffer<9> prompt_buffer;
#endif
    MusicPlayer * music_players[2];
    UiStateOwner * ui_state;
    char const * prompt;
    u32 keyboard_page;
    NewGameNameInputSpriteState sprites[2];
    char name[13];
    // Confirmation uses this separate, terminated copy; editing keeps name intact.
    u8 normalized_name[13];
    u8 finished;
    u8 keyboard_redraw_pending;
    u8 unk_after_keyboard_redraw[4];
    u32 unk_463c;
};

struct NewGameNameInputScene {
    NewGameSceneVTableFunction const * vtable;
    NewGameNameInputCore * core;
};

typedef char NewGameNameInputNormalizedNameCheck[
    offsetof(NewGameNameInputCore, normalized_name) ==
        offsetof(NewGameNameInputCore, name) + 13 ? 1 : -1];

typedef char NewGameNameInputKeyboardBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<30>) == 0x784 ? 1 : -1];
typedef char NewGameNameInputJpPromptBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<6>) == 0x184 ? 1 : -1];
typedef char NewGameNameInputOverseasPromptBufferSizeCheck[
    sizeof(NewGameTextTileBuffer<9>) == 0x244 ? 1 : -1];
typedef char NewGameNameInputKeyboardCheck[
    offsetof(NewGameNameInputCore, keyboard_buffers) == 8 ? 1 : -1];
typedef char NewGameNameInputPageCheck[
    offsetof(NewGameNameInputCore, keyboard_page)
        == offsetof(NewGameNameInputCore, prompt) + 4 ? 1 : -1];
typedef char NewGameNameInputSpritesCheck[
    offsetof(NewGameNameInputCore, sprites)
        == offsetof(NewGameNameInputCore, keyboard_page) + 4 ? 1 : -1];
typedef char NewGameNameInputSpritesEndCheck[
    offsetof(NewGameNameInputCore, name)
        == offsetof(NewGameNameInputCore, sprites) + 24 ? 1 : -1];
typedef char NewGameNameInputRedrawCheck[
    offsetof(NewGameNameInputCore, keyboard_redraw_pending)
        == offsetof(NewGameNameInputCore, finished) + 1 ? 1 : -1];
typedef char NewGameNameInputFinalWordCheck[
    offsetof(NewGameNameInputCore, unk_463c)
        == sizeof(NewGameNameInputCore) - 4 ? 1 : -1];

typedef char NewGameMenuSceneSizeCheck[sizeof(NewGameMenuScene) == 8 ? 1 : -1];
typedef char NewGameNameEntrySceneSizeCheck[sizeof(NewGameNameEntryScene) == 4 ? 1 : -1];
#if defined(REGION_JP)
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1878 ? 1 : -1];
typedef char NewGameIdentityCoreBuffersCheck[offsetof(NewGameIdentityCore, buffers) == 8 ? 1 : -1];
typedef char NewGameIdentityCoreUnk1A28Check[offsetof(NewGameIdentityCore, unk_1A28) == 0x1828 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x182C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1830 ? 1 : -1];
typedef char NewGameIdentityCoreFieldsCheck[offsetof(NewGameIdentityCore, fields) == 0x1834 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1874 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, unk_1A76) == 0x1876 ? 1 : -1];
#else
typedef char NewGameIdentityCoreSizeCheck[sizeof(NewGameIdentityCore) == 0x1A78 ? 1 : -1];
typedef char NewGameIdentityCoreValueBuffersCheck[offsetof(NewGameIdentityCore, value_buffers) == 8 ? 1 : -1];
typedef char NewGameIdentityCoreLabelBuffersCheck[offsetof(NewGameIdentityCore, label_buffers) == 0xC18 ? 1 : -1];
typedef char NewGameIdentityCoreUnk1A28Check[offsetof(NewGameIdentityCore, unk_1A28) == 0x1A28 ? 1 : -1];
typedef char NewGameIdentityCoreUiCheck[offsetof(NewGameIdentityCore, ui_state) == 0x1A2C ? 1 : -1];
typedef char NewGameIdentityCoreMusicCheck[offsetof(NewGameIdentityCore, music) == 0x1A30 ? 1 : -1];
typedef char NewGameIdentityCoreFieldsCheck[offsetof(NewGameIdentityCore, fields) == 0x1A34 ? 1 : -1];
typedef char NewGameIdentityCoreControlCheck[offsetof(NewGameIdentityCore, unk_1A74) == 0x1A74 ? 1 : -1];
typedef char NewGameIdentityCoreResultCheck[offsetof(NewGameIdentityCore, unk_1A76) == 0x1A76 ? 1 : -1];
#endif
typedef char NewGameIdentitySceneSizeCheck[sizeof(NewGameIdentityScene) == 8 ? 1 : -1];
typedef char NewGameIdentitySceneCoreCheck[offsetof(NewGameIdentityScene, core) == 4 ? 1 : -1];

#if defined(REGION_JP)
typedef char NewGameNameInputCoreSizeCheck[sizeof(NewGameNameInputCore) == 0x4580 ? 1 : -1];
typedef char NewGameNameInputCoreNameBufferCheck[offsetof(NewGameNameInputCore, name_buffer) == 0x3C28 ? 1 : -1];
typedef char NewGameNameInputCorePromptBufferCheck[offsetof(NewGameNameInputCore, prompt_buffer) == 0x43AC ? 1 : -1];
typedef char NewGameNameInputCoreMusicCheck[offsetof(NewGameNameInputCore, music_players) == 0x4530 ? 1 : -1];
typedef char NewGameNameInputCoreUiCheck[offsetof(NewGameNameInputCore, ui_state) == 0x4538 ? 1 : -1];
typedef char NewGameNameInputCorePromptCheck[offsetof(NewGameNameInputCore, prompt) == 0x453C ? 1 : -1];
typedef char NewGameNameInputCoreNameCheck[offsetof(NewGameNameInputCore, name) == 0x455C ? 1 : -1];
typedef char NewGameNameInputCoreFinishedCheck[offsetof(NewGameNameInputCore, finished) == 0x4576 ? 1 : -1];
#elif defined(REGION_DE)
typedef char NewGameNameInputCoreSizeCheck[sizeof(NewGameNameInputCore) == 0x4DC4 ? 1 : -1];
typedef char NewGameNameInputCoreNameBufferCheck[offsetof(NewGameNameInputCore, name_buffer) == 0x43AC ? 1 : -1];
typedef char NewGameNameInputCorePromptBufferCheck[offsetof(NewGameNameInputCore, prompt_buffer) == 0x4B30 ? 1 : -1];
typedef char NewGameNameInputCoreMusicCheck[offsetof(NewGameNameInputCore, music_players) == 0x4D74 ? 1 : -1];
typedef char NewGameNameInputCoreUiCheck[offsetof(NewGameNameInputCore, ui_state) == 0x4D7C ? 1 : -1];
typedef char NewGameNameInputCorePromptCheck[offsetof(NewGameNameInputCore, prompt) == 0x4D80 ? 1 : -1];
typedef char NewGameNameInputCoreNameCheck[offsetof(NewGameNameInputCore, name) == 0x4DA0 ? 1 : -1];
typedef char NewGameNameInputCoreFinishedCheck[offsetof(NewGameNameInputCore, finished) == 0x4DBA ? 1 : -1];
#else
typedef char NewGameNameInputCoreSizeCheck[sizeof(NewGameNameInputCore) == 0x4640 ? 1 : -1];
typedef char NewGameNameInputCoreNameBufferCheck[offsetof(NewGameNameInputCore, name_buffer) == 0x3C28 ? 1 : -1];
typedef char NewGameNameInputCorePromptBufferCheck[offsetof(NewGameNameInputCore, prompt_buffer) == 0x43AC ? 1 : -1];
typedef char NewGameNameInputCoreMusicCheck[offsetof(NewGameNameInputCore, music_players) == 0x45F0 ? 1 : -1];
typedef char NewGameNameInputCoreUiCheck[offsetof(NewGameNameInputCore, ui_state) == 0x45F8 ? 1 : -1];
typedef char NewGameNameInputCorePromptCheck[offsetof(NewGameNameInputCore, prompt) == 0x45FC ? 1 : -1];
typedef char NewGameNameInputCoreNameCheck[offsetof(NewGameNameInputCore, name) == 0x461C ? 1 : -1];
typedef char NewGameNameInputCoreFinishedCheck[offsetof(NewGameNameInputCore, finished) == 0x4636 ? 1 : -1];
#endif
typedef char NewGameNameInputSceneSizeCheck[sizeof(NewGameNameInputScene) == 8 ? 1 : -1];
typedef char NewGameNameInputSceneCoreCheck[offsetof(NewGameNameInputScene, core) == 4 ? 1 : -1];

EXTERN_C

// Both menu transitions wait until their stack-owned blend command leaves
// the hardware queue. The first decreases progress; the second increases it.
void func_08003B40(struct HardwareBootstrap * core);
void func_08003BB4(struct HardwareBootstrap * core);
void func_08003C28(struct NewGameMenuCore * core);

// One contiguous interval: option OAM, selector OAM, status, saving, loading,
// and core construction.
// The preceding label graphics renderer still remains assembly.
void func_08003DF0(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes attributes)
    SECTION(".text.new_game_menu_update");
void func_08003E88(struct NewGameMenuCore * core, u32 row,
    NewGameMenuSpriteAttributes const initial)
    SECTION(".text.new_game_menu_update");
void func_08003EEC(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");
bool func_08003F9C(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");
bool func_080040A0(struct NewGameMenuCore * core)
    SECTION(".text.new_game_menu_update");

// Formats one runtime save-summary buffer from the save image. Calendar and
// farm members are recovered; the formatter body still remains assembly.
void func_08003788(struct NewGameMenuCore * core,
    NewGameMenuSaveSlotStatus & output, GameStateSaveImage const * snapshot);

// Initialize the supplied storage and consume the transition pointer word.
// This explicit pointer-reference view preserves the native ownership ABI;
// cleanup of the consumed input also belongs to the callee.
NewGameMenuCore * func_080041DC(NewGameMenuCore * core, void * state,
    SceneTransition *& continuation)
    SECTION(".text.new_game_menu_update");
SceneTransitionOwner func_08004570(struct NewGameMenuCore * core);
AScene * func_08004B58(void * object)
    SECTION(".text.new_game_scene_lifecycle");
// This native entry consumes and clears a caller-provided pointer slot.
// Residual-input cleanup belongs to the callee, as in the core entry.
AScene * func_08004B94(void * object, void * state, SceneTransition *& continuation)
    SECTION(".text.new_game_scene_lifecycle");

extern NewGameSceneVTableFunction const vtable_unk_080E5A3C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A4C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A5C[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A68[];
extern NewGameSceneVTableFunction const vtable_unk_080E5A88[];
extern u8 const gUiHandCursorArchive[];

// One contiguous scene lifecycle interval, beginning with both constructors.
void func_08004BDC(struct NewGameMenuScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");
SceneTransitionOwner func_08004C0C(struct NewGameMenuScene * scene)
    SECTION(".text.new_game_scene_lifecycle");
AScene * func_08004C48(void * object)
    SECTION(".text.new_game_scene_lifecycle");
void func_08004C54(struct NewGameNameEntryScene * scene, int flags)
    SECTION(".text.new_game_scene_lifecycle");

// Native form construction and UI setup still remain assembly. The
// running core and scene below share their real allocation and return-owner ABI.
NewGameIdentityCore * func_08004EFC(NewGameIdentityCore * core,
    char const * player_name, u32 birthday, char const * farm_name, char const * dog_name);
void func_080050C8(NewGameIdentityCore * core, int flags)
    SECTION(".text.new_game_identity_core_cleanup");
SceneTransitionOwner func_080050F8(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_run");
void func_08005254(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
void func_08005260(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_initialization");
void func_08005278(NewGameIdentityCore * core);
void func_08005800(NewGameIdentityCore * core)
    SECTION(".text.new_game_identity_core_update");
extern NewGameSceneVTableFunction const vtable_unk_080E5A98[];
extern NewGameSceneVTableFunction const vtable_unk_080E5AA4[];

// One consecutive scene interval: construction, cleanup, running and the
// two native byte-result accessors. Its core remains an incomplete field view.
NewGameIdentityScene * func_0800598C(NewGameIdentityScene * scene,
    char const * player_name, u32 birthday, char const * farm_name, char const * dog_name)
    SECTION(".text.new_game_identity_scene");
void func_080059D0(NewGameIdentityScene * scene, int flags)
    SECTION(".text.new_game_identity_scene");
SceneTransitionOwner func_08005A00(NewGameIdentityScene * scene)
    SECTION(".text.new_game_identity_scene");
u8 func_08005A3C(NewGameIdentityScene const * scene)
    SECTION(".text.new_game_identity_scene");
u8 func_08005A4C(NewGameIdentityCore const * core)
    SECTION(".text.new_game_identity_scene");

// Native keyboard construction and its running loop share the regional
// member layout above. Keyboard drawing and input helpers remain assembly.
NewGameNameInputCore * func_08005A58(NewGameNameInputCore * core,
    char const * prompt, char const * initial_name)
    SECTION(".text.new_game_name_input_core_constructor");
void func_08005B38(NewGameNameInputCore * core, int flags)
    SECTION(".text.new_game_name_input_core_cleanup");
SceneTransitionOwner func_08005B68(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_core_run");
void func_08005CDC(NewGameNameInputCore * core);
void func_080061A0(NewGameNameInputCore * core, u32 tile_index)
    SECTION(".text.new_game_name_input_sprites");
// Reset only the native control fields; sprite OAM and input text are untouched.
void func_08006334(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_reset");
void func_0800637C(NewGameNameInputCore * core);
void func_080064E8(NewGameNameInputCore * core);
void func_08006858(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_submit_sprites");
// Position both cursors and select the keyboard-cell or bottom-button shape.
void UpdateNameInputCursorSprites(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_cursor_sprites");
// Move the keyboard selection with wrapping and last-row/bottom-button rules.
void MoveNameInputKeyboardCursor(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_keyboard_cursor");
// Insert the selected keyboard character and advance the fixed name-slot caret.
void InsertNameInputCharacter(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_insert_character");
// Shift the remaining fixed name slots left and restore the final placeholder.
// JP has six two-byte slots; overseas versions have twelve one-byte slots.
void EraseNameInputCharacter(NewGameNameInputCore * core, u8 index)
    SECTION(".text.new_game_name_input_erase_character");
// Trim trailing placeholders and replace interior placeholders with spaces.
// Reject names made entirely of placeholders and spaces, without changing name.
bool NormalizeNameInput(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_normalization");
void ProcessNameInputKeys(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_keys");
void func_08006ED8(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_confirmation");
extern NewGameSceneVTableFunction const vtable_unk_080E5AB4[];
extern NewGameSceneVTableFunction const vtable_unk_080E5AC0[];

// One consecutive keyboard-scene interval: construction, cleanup, running,
// and the two accessors returning the core's actual runtime name buffer.
NewGameNameInputScene * func_08007078(NewGameNameInputScene * scene,
    char const * prompt, char const * initial_name)
    SECTION(".text.new_game_name_input_scene");
void func_080070A4(NewGameNameInputScene * scene, int flags)
    SECTION(".text.new_game_name_input_scene");
SceneTransitionOwner func_080070D4(NewGameNameInputScene * scene)
    SECTION(".text.new_game_name_input_scene");
char const * func_08007110(NewGameNameInputScene const * scene)
    SECTION(".text.new_game_name_input_scene");
char const * func_0800711C(NewGameNameInputCore const * core)
    SECTION(".text.new_game_name_input_scene");

EXTERN_C_END

#endif // NEW_GAME_HH
