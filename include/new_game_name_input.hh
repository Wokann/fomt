#ifndef NEW_GAME_NAME_INPUT_HH
#define NEW_GAME_NAME_INPUT_HH

#include "new_game.hh"

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
    ~NewGameNameInputCore() asm("DestroyNameInputCore")
        SECTION(".text.new_game_name_input_core_cleanup");
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

// The reusable keyboard is a real scene. Its core keeps the verified native
// bootstrap interface until that separate hierarchy is fully recovered.
struct NewGameNameInputScene : AScene {
    NewGameNameInputScene(char const * prompt, char const * initial_name)
        asm("ConstructNameInputScene") SECTION(".text.new_game_name_input_scene");
    virtual ~NewGameNameInputScene()
        asm("DestroyNameInputScene") SECTION(".text.new_game_name_input_scene");
    virtual SceneTransitionOwner Run()
        asm("RunNameInputScene") SECTION(".text.new_game_name_input_scene");
    char const * GetName() const
        asm("GetNameInputSceneName") SECTION(".text.new_game_name_input_scene");
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

// Core construction, running and edit operations use the regional layout above.
// Screen setup, current-name raster and keyboard raster still remain assembly.
NewGameNameInputCore * InitializeNameInputCore(NewGameNameInputCore * core,
    char const * prompt, char const * initial_name)
    SECTION(".text.new_game_name_input_core_constructor");
void DestroyNameInputCore(NewGameNameInputCore * core, int flags)
    SECTION(".text.new_game_name_input_core_cleanup");
SceneTransitionOwner RunNameInputCore(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_core_run");
void InitializeNameInputScreen(NewGameNameInputCore * core);
void InitializeNameInputCursorSprites(NewGameNameInputCore * core, u32 tile_index)
    SECTION(".text.new_game_name_input_sprites");
// Reset only the native control fields; sprite OAM and input text are untouched.
void ResetNameInputCore(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_reset");
void RenderNameInputName(NewGameNameInputCore * core);
void RenderNameInputKeyboard(NewGameNameInputCore * core);
void SubmitNameInputCursorSprites(NewGameNameInputCore * core)
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
void UpdateNameInputConfirmation(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_confirmation");
extern NewGameSceneVTableFunction const gNewGameNameInputCoreVTable[];

// These C declarations name the actual member ABI for existing native
// callers; they do not emit extra wrappers or alias symbols.
// One consecutive keyboard-scene interval: construction, cleanup, running,
// and the two accessors returning the core's actual runtime name buffer.
NewGameNameInputScene * ConstructNameInputScene(NewGameNameInputScene * scene,
    char const * prompt, char const * initial_name)
    SECTION(".text.new_game_name_input_scene");
void DestroyNameInputScene(NewGameNameInputScene * scene, int flags)
    SECTION(".text.new_game_name_input_scene");
SceneTransitionOwner RunNameInputScene(NewGameNameInputScene * scene)
    SECTION(".text.new_game_name_input_scene");
char const * GetNameInputSceneName(NewGameNameInputScene const * scene)
    SECTION(".text.new_game_name_input_scene");
char const * GetNameInputCoreName(NewGameNameInputCore const * core)
    SECTION(".text.new_game_name_input_scene");

EXTERN_C_END

#endif // NEW_GAME_NAME_INPUT_HH
