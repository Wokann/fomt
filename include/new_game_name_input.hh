#ifndef NEW_GAME_NAME_INPUT_HH
#define NEW_GAME_NAME_INPUT_HH

#include "new_game_data.hh"

// Buffer 0 holds the Name label, then each page row has one buffer; the
// final buffer holds the mode/end buttons. The current writer emits two
// tile rows. These dimensions do not change the saved 12-byte name format.
#define NEW_GAME_NAME_INPUT_TILE_WIDTH 30
#define NEW_GAME_NAME_INPUT_TILE_HEIGHT 2
#define NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE + 2)
#if defined(REGION_JP)
#define NEW_GAME_NAME_INPUT_PROMPT_WIDTH 6
#else
#define NEW_GAME_NAME_INPUT_PROMPT_WIDTH 9
#endif

// 4bpp tiles contain 32 bytes. Each buffer has a u32 prefix and the core
// starts with an eight-byte bootstrap. Checks below bind these expressions
// to the real C++ types; DMA uploads exclude the buffer prefix.
#define NEW_GAME_NAME_INPUT_TILE_BYTES (NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT * 32)
#define NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES (NEW_GAME_NAME_INPUT_PROMPT_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT * 32)
#define NEW_GAME_NAME_INPUT_BUFFER_BYTES (4 + NEW_GAME_NAME_INPUT_TILE_BYTES)
#define NEW_GAME_NAME_INPUT_PROMPT_BUFFER_BYTES (4 + NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES)
#define NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET (8 + 4)
#define NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET (8 + (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_BUFFER_BYTES + 4)
#define NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET (8 + (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_BUFFER_BYTES + NEW_GAME_NAME_INPUT_PROMPT_BUFFER_BYTES)
#define NEW_GAME_NAME_INPUT_CORE_UI_OFFSET (NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET + 8)
#define NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET (NEW_GAME_NAME_INPUT_CORE_UI_OFFSET + 4)
#define NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET (NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET + 4)
// Two 12-byte sprite records and two 13-byte name buffers precede finished.
#define NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET (NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET + 4 + 2 * 12 + 2 * 13 + 1)

#ifndef __ASSEMBLER__

#include "new_game.hh"

typedef NewGameTextTileBuffer<NEW_GAME_NAME_INPUT_TILE_WIDTH, NEW_GAME_NAME_INPUT_TILE_HEIGHT> NewGameNameInputKeyboardBuffer;
typedef NewGameTextTileBuffer<NEW_GAME_NAME_INPUT_PROMPT_WIDTH, NEW_GAME_NAME_INPUT_TILE_HEIGHT> NewGameNameInputPromptBuffer;

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
    NewGameNameInputCore(char const * prompt, char const * initial_name)
        SECTION(".text.new_game_name_input_core_constructor");
    virtual ~NewGameNameInputCore()
        SECTION(".text.new_game_name_input_core_cleanup");
    NewGameNameInputKeyboardBuffer keyboard_buffers[NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT];
    NewGameNameInputKeyboardBuffer name_buffer;
    NewGameNameInputPromptBuffer prompt_buffer;
    // The native UI borrows these two adjacent slots, starting with player 1.
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
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

typedef char NewGameNameInputMusicStrideCheck[
    offsetof(NewGameNameInputCore, music_player_2) ==
        offsetof(NewGameNameInputCore, music_player_1) + sizeof(HardwareMusicPlayerSlot) ? 1 : -1];

// The reusable keyboard and its core have ordinary C++ lifetimes.
// Keyboard raster and screen setup still use their existing native entries.
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
        offsetof(NewGameNameInputCore, name) + sizeof(((NewGameNameInputCore *)0)->name) ? 1 : -1];

typedef char NewGameNameInputKeyboardBufferSizeCheck[
    sizeof(NewGameNameInputKeyboardBuffer) == NEW_GAME_NAME_INPUT_BUFFER_BYTES ? 1 : -1];
typedef char NewGameNameInputPromptBufferSizeCheck[
    sizeof(NewGameNameInputPromptBuffer) == NEW_GAME_NAME_INPUT_PROMPT_BUFFER_BYTES ? 1 : -1];
typedef char NewGameNameInputKeyboardTilesOffsetCheck[
    offsetof(NewGameNameInputKeyboardBuffer, tiles) == 4 ? 1 : -1];
typedef char NewGameNameInputPromptTilesOffsetCheck[
    offsetof(NewGameNameInputPromptBuffer, tiles) == 4 ? 1 : -1];
typedef char NewGameNameInputKeyboardTileBytesCheck[
    sizeof(((NewGameNameInputKeyboardBuffer *)0)->tiles) == NEW_GAME_NAME_INPUT_TILE_BYTES ? 1 : -1];
typedef char NewGameNameInputPromptTileBytesCheck[
    sizeof(((NewGameNameInputPromptBuffer *)0)->tiles) == NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES ? 1 : -1];
typedef char NewGameNameInputBootstrapSizeCheck[sizeof(HardwareBootstrap) == 8 ? 1 : -1];
typedef char NewGameNameInputMusicSizeCheck[sizeof(HardwareMusicPlayerSlot) == 4 ? 1 : -1];
typedef char NewGameNameInputPointerSizeCheck[sizeof(UiStateOwner *) == 4 ? 1 : -1];
typedef char NewGameNameInputWordSizeCheck[sizeof(u32) == 4 ? 1 : -1];
typedef char NewGameNameInputNameBytesCheck[sizeof(((NewGameNameInputCore *)0)->name) == 13 ? 1 : -1];
typedef char NewGameNameInputNormalizedNameBytesCheck[sizeof(((NewGameNameInputCore *)0)->normalized_name) == 13 ? 1 : -1];
typedef char NewGameNameInputTileRowsCheck[NEW_GAME_NAME_INPUT_TILE_HEIGHT == 2 ? 1 : -1];
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
        == offsetof(NewGameNameInputCore, sprites) + sizeof(((NewGameNameInputCore *)0)->sprites) ? 1 : -1];
typedef char NewGameNameInputRedrawCheck[
    offsetof(NewGameNameInputCore, keyboard_redraw_pending)
        == offsetof(NewGameNameInputCore, finished) + 1 ? 1 : -1];
typedef char NewGameNameInputFinalWordCheck[
    offsetof(NewGameNameInputCore, unk_463c)
        == sizeof(NewGameNameInputCore) - 4 ? 1 : -1];

typedef char NewGameNameInputCoreKeyboardTilesCheck[
    offsetof(NewGameNameInputCore, keyboard_buffers) + offsetof(NewGameNameInputKeyboardBuffer, tiles)
        == NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET ? 1 : -1];
typedef char NewGameNameInputCoreNameBufferCheck[
    offsetof(NewGameNameInputCore, name_buffer) == offsetof(NewGameNameInputCore, keyboard_buffers)
        + sizeof(((NewGameNameInputCore *)0)->keyboard_buffers) ? 1 : -1];
typedef char NewGameNameInputCorePromptBufferCheck[
    offsetof(NewGameNameInputCore, prompt_buffer) == offsetof(NewGameNameInputCore, name_buffer)
        + sizeof(NewGameNameInputKeyboardBuffer) ? 1 : -1];
typedef char NewGameNameInputCorePromptTilesCheck[
    offsetof(NewGameNameInputCore, prompt_buffer) + offsetof(NewGameNameInputPromptBuffer, tiles)
        == NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET ? 1 : -1];
typedef char NewGameNameInputCoreMusicCheck[
    offsetof(NewGameNameInputCore, music_player_1) == NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET ? 1 : -1];
typedef char NewGameNameInputCoreUiCheck[
    offsetof(NewGameNameInputCore, ui_state) == NEW_GAME_NAME_INPUT_CORE_UI_OFFSET ? 1 : -1];
typedef char NewGameNameInputCorePromptCheck[
    offsetof(NewGameNameInputCore, prompt) == NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET ? 1 : -1];
typedef char NewGameNameInputCorePageCheck[
    offsetof(NewGameNameInputCore, keyboard_page) == NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET ? 1 : -1];
typedef char NewGameNameInputCoreFinishedCheck[
    offsetof(NewGameNameInputCore, finished) == offsetof(NewGameNameInputCore, normalized_name)
        + sizeof(((NewGameNameInputCore *)0)->normalized_name) ? 1 : -1];
typedef char NewGameNameInputCoreRedrawCheck[
    offsetof(NewGameNameInputCore, keyboard_redraw_pending) == NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET ? 1 : -1];
typedef char NewGameNameInputSceneSizeCheck[sizeof(NewGameNameInputScene) == 8 ? 1 : -1];
typedef char NewGameNameInputSceneCoreCheck[offsetof(NewGameNameInputScene, core) == 4 ? 1 : -1];

EXTERN_C

// Running and edit operations use the regional layout above.
// Screen setup and keyboard raster still remain assembly.
SceneTransitionOwner RunNameInputCore(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_core_run");
void InitializeNameInputScreen(NewGameNameInputCore * core);
void InitializeNameInputCursorSprites(NewGameNameInputCore * core, u32 tile_index)
    SECTION(".text.new_game_name_input_sprites");
// Reset only the native control fields; sprite OAM and input text are untouched.
void ResetNameInputCore(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_reset");
// Clear the name field, render its fixed-width RAM name and queue the tiles.
void RenderNameInputName(NewGameNameInputCore * core)
    SECTION(".text.new_game_name_input_name_raster");
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

#endif // !__ASSEMBLER__

#endif // NEW_GAME_NAME_INPUT_HH
