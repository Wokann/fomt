#ifndef UI_STATE_HH
#define UI_STATE_HH

#include "prelude.h"
#include "ui_text_commands.hh"
#include "scene_text_variable_lifetimes.hh"
#include "ui_portrait.hh"
#include "gbaio.h"
#include "gbasvc.h"
#include "ui_text_stream.hh"
#include "resource_handle.hh"
#include "obj_palette_collection.hh"
#include "hardware_dma.hh"
#include "utility/container_algorithms.hh"
#include "hardware_linked_list.hh"
#include "obj_tile_collection.hh"
#include "utility/fixed_str.hh"

struct HardwareInputState;
struct HardwareSpriteBufferState;
struct HardwareDisplayState;
struct ObjTileCollection;
struct ObjPaletteCollection;
struct ObjPaletteCollectionEntry;
struct HardwareMusicPlayerSlot;
struct HardwareInterruptList;
struct IndexedResourceGroupResult;

EXTERN_C
extern u8 const gUiHeartIndicatorArchive[];
EXTERN_C_END

// Verified views of the state fields consumed by the native UI adapters.
struct UiObjectState
{
    u8 unknown_00[8];
    i32 state;
};

struct UiActionStateFlags
{
    u8 active : 1;
    u8 unknown_01 : 7;
};

struct UiActionState
{
    u8 unknown_00[0x1DC];
    UiActionStateFlags flags_01dc;
    u8 unknown_01e0[0x10];
    UiActionStateFlags flags_01f0;
};

struct FirstFieldUiFlags
{
    u8 unused_00[0x550];
    unsigned low_flags : 6;
    unsigned unused_flags : 2;
};

struct FirstFieldUiOwner
{
    FirstFieldUiFlags * data;
};

EXTERN_C
u32 func_08050E98(FirstFieldUiOwner &, u32 flag_mask);
u32 func_08050EBC(FirstFieldUiOwner &, u32 flag_mask);
EXTERN_C_END

struct UiStatePayload;

struct UiStateOwner
{
    UiStateOwner(u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4,
        ObjTileCollection const & shared, ObjPaletteCollection const & resources);
    ~UiStateOwner();
    i32 GetState() const;
    // Preserve the previous raw gate byte, rather than normalizing it to bool.
    u8 DisableResume() const;
    u8 EnableResume() const;
    // Zero while choosing; otherwise the stored choice index, not a pointer.
    // This is not a completion query for unrelated window phases.
    u32 GetChoiceResult() const;
    i32 Update(HardwareInputState * state, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, HardwareLinkedList * links, HardwareInterruptList * manager,
        HardwareMusicPlayerSlot * music) const;
    // These take an archive level index, not a character ID. GameScene owns
    // the love-value to level mapping used by the script-facing operation.
    void ShowPortrait(u32 index) const;
    void ShowHeartIndicator(u32 level) const;
    void HideHeartIndicator() const;

    UiStatePayload * value;
};

typedef char UiStateOwnerSizeCheck[sizeof(UiStateOwner) == 4 ? 1 : -1];

struct GameSceneTalkWindowOwner {
    UiStateOwner * value;

    GameSceneTalkWindowOwner() : value(nullptr) {}
    GameSceneTalkWindowOwner(UiStateOwner * window) : value(window) {}
    inline GameSceneTalkWindowOwner(void * storage, u32 palette, u32 const & mode,
        ObjTileCollection const & tiles = ObjTileCollection(),
        ObjPaletteCollection const & palettes = ObjPaletteCollection());
    ~GameSceneTalkWindowOwner() { delete value; }
    UiStateOwner * Get() const { return value; }
    GameSceneTalkWindowOwner & operator=(UiStateOwner * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

// Direct constructor ABI for native initializers that already own the
// storage. This is the existing C++ entry, with no allocation wrapper.
extern "C" UiStateOwner * ConstructUiStateOwner(void * storage,
    u32 background, u32 screen, u32 palette, u32 mode,
    ObjTileCollection const & tiles, ObjPaletteCollection const & palettes)
    asm("__12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection");

inline GameSceneTalkWindowOwner::GameSceneTalkWindowOwner(void * storage,
    u32 palette, u32 const & mode, ObjTileCollection const & tiles,
    ObjPaletteCollection const & palettes)
    : value(ConstructUiStateOwner(storage, 0, 31, palette, mode, tiles, palettes))
{
}

EXTERN_C

extern u8 const gUiHandCursorArchive[];
#if defined(REGION_JP)
extern u8 const gUnk_084AF4E4[];
#else
extern u8 const gUnk_0872937C[];
#endif

u8 func_08050F70(UnkUiSelectionData const * object);
void func_08050F74(UnkUiSelectionData * object, u32 arg_1, u32 arg_2);

// Emit the three visible rows, retaining OAM affine coefficients.
void DrawUiTextRows(UnkUiSelectionData * object, HardwareSpriteBufferState * sprites);

void func_080510E8(UnkUiSelectionData * object);
int func_080512B8(UnkUiSelectionData const * object, int index);
UnkUiSelectionRow * func_080512C8(UnkUiSelectionData const * object, u32 index);
UnkUiSelectionRow * func_080512D0(UnkUiSelectionData const * object, u32 index);

extern "C" void SetUiObjectStateTwoIfNonzero(void * object);
extern "C" void ClearUiObjectStateIfNonzero(void * object);
extern "C" void ClearUiActionStateFlag01DC(void * object);
extern "C" void ClearUiActionStateFlag01F0(void * object);
EC void func_08050D80(void * const * object);
EC void func_08050D8C(void * const * object, u32 arg_r1);

// Existing C adapter ABI. Message adapters pass encoded text, a u16 speed
// and an optional variable store to the typed payload SetText method.
void func_08050D5C(UiStateOwner const * object);
void func_08050D68(UiStateOwner const * object);
void func_08050D74(void * const * object);
void func_08050DA0(UiStateOwner const * object, char const * text,
    ScriptTextVariableStore * variables);
void func_08050DB4(UiStateOwner const * object, char const * text, u16 speed);
void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3);
// Selection rows are encoded text pointers, not integer IDs. Both adapters
// receive the same substitution context as the dialogue message renderer.
void func_08050E0C(UiStateOwner const * object, char const * first, char const * second,
    char const * third, char const * fourth, char const * fifth, char const * sixth,
    ScriptTextVariableStore * variables);
void func_08050E30(UiStateOwner const * object, char const * prompt, char const * first,
    char const * second, char const * third, char const * fourth,
    ScriptTextVariableStore * variables);
void func_08050E5C(void * const * object);
void func_08050E68(void * const * object, char const * text);
void func_08050E74(void * const * object);

EXTERN_C_END

static inline void ShowUiTwoChoicePrompt(UiStateOwner const * window, char const * prompt,
    char const * first, char const * second, ScriptTextVariableStore * variables)
{
    func_08050E30(window, prompt, first, second, nullptr, nullptr, variables);
}

enum
{
    UI_TEXT_LAYOUT_VARIANT_COUNT = 8,
    UI_TEXT_LAYOUT_SLOT_COUNT = 6,
    UI_NAMEPLATE_TILE_BUFFER_COUNT = 3,
    UI_NAMEPLATE_CHUNK_BYTE_COUNT = 4,
    UI_NAMEPLATE_TEXT_MAX_BYTES = UI_NAMEPLATE_TILE_BUFFER_COUNT * UI_NAMEPLATE_CHUNK_BYTE_COUNT,
};

// The layout table stores one packed byte per choice. Coordinates address
// three text rows and 28 glyph columns; bit seven has no verified meaning.
struct UiTextLayoutPosition
{
    u8 row : 2;
    u8 column : 5;
    u8 unknown : 1;
} PACKED;
typedef char UiTextLayoutPositionSizeCheck[sizeof(UiTextLayoutPosition) == 1 ? 1 : -1];

// Navigation receives a halfword key mask by value. The native C++ ABI
// rounds this value object to one word, rather than a scalar u16 argument.
struct UiChoiceKeyState
{
    enum
    {
        RIGHT = 0x10,
        LEFT = 0x20,
        UP = 0x40,
        DOWN = 0x80,
    };
    u16 value;
};
typedef char UiChoiceKeyStateSizeCheck[sizeof(UiChoiceKeyState) == 4 ? 1 : -1];

EC UiTextLayoutPosition GetUiChoiceLayoutPosition(u32 layout, u32 selection);
EC void RenderUiChoiceLabel(UiStatePayload *, UiTextLayoutPosition const &,
    char const *, ScriptTextVariableStore *);
EC i32 MoveUiChoiceSelection(u32 layout, i32 selection, UiChoiceKeyState keys);
// The encoded input must contain 1..12 bytes. Invalid text only disables the
// nameplate; valid input clears three owned buffers and draws up to four bytes
// into each. The portrait and the text-window state are independent.
EC void SetUiNameplateText(UiStatePayload *, char const *);

#include "decimal_text.hh"

// The native helper indexes this object as
// base + layout * UI_TEXT_LAYOUT_SLOT_COUNT + one_based_slot.  Byte zero is
// also deliberately used as an empty-string fallback by the same code.
// The 4-byte type alignment supplies the three trailing ROM padding bytes.
struct UiTextLayoutPositionTable
{
    u8 empty_string;
    u8 position_codes[UI_TEXT_LAYOUT_VARIANT_COUNT][UI_TEXT_LAYOUT_SLOT_COUNT];
} ALIGN(4);

extern UiTextLayoutPositionTable const gUiTextLayoutPositionTable;

// These adjacent objects are loaded independently by the native UI callers.
// Keep their physical order in ui_state.cc; each has its own real relocation.
extern u8 const gUnk_UiSharedResourceData_000[];
extern u8 const gUnk_UiSharedResourceData_001[];
extern u8 const * const gUiSharedTiles;
extern u32 const gUiSharedTileByteCount;
extern u8 const * const gUiSharedPalette;
extern u32 const gUiSharedPaletteByteCount;

struct UiResourceChangeFlags
{
    bool active : 1;
    bool changed : 1;
    u8 unknown : 6;
    UiResourceChangeFlags() : active(0), changed(0) {}
};
struct UnkUiPayloadLowFlags
{
    u8 low : 6;
    u8 unknown : 2;
    UnkUiPayloadLowFlags() : low(0x3F) {}
};
// Native member order and ownership are checked against the original complete
// constructor and destructor. Opening and destruction are recovered in C++.
struct UiStatePayload
{
    // Construction follows these owned members; Update remains native.
    UiStatePayload(u32, u32, u32, u32, ObjTileCollection const &, ObjPaletteCollection const &);
    ~UiStatePayload();
    void Open();
    void OpenImmediately();
    void SetText(char const *, u16 speed, ScriptTextVariableStore *);
    void SetChoices(char const * first, char const * second, char const * third,
        char const * fourth, char const * fifth, char const * sixth,
        ScriptTextVariableStore *);
    void SetPromptChoices(char const * prompt, char const * first, char const * second,
        char const * third, char const * fourth,
        ScriptTextVariableStore *);
    i32 Update(HardwareInputState *, HardwareSpriteBufferState *, HardwareDisplayState *,
        HardwareLinkedList *, HardwareInterruptList *, HardwareMusicPlayerSlot *);
    // Known portrait operation; its body remains native until byte-matched.
    void ShowPortrait(u32 index);
    void ShowHeartIndicator(u32 level);
    void HideHeartIndicator();
    unsigned background : 2;
    unsigned screen_block : 5;
    unsigned character_block : 2;
    unsigned first_tile : 10;
    unsigned background_palette : 4;
    unsigned unknown_00_23 : 9;
    u32 mode;
    i32 state;
    u8 unk_0c;
    u8 allow_resume;
    ObjPaletteCollectionEntry palette;
    ObjTileCollectionEntry background_state;
    HardwareLinkedList commands;
    UiDmaTransferQueue records;
    UiDmaTransferCommand records_command;
    UnkUiSelectionData output;
    UiTextStream text;
    UiTextOutputUploadCommand output_command;
    UiTextTileCopyCommand tile_copy;
    UiTextWindowSetupCommand window;
    u32 choice_index;
    u32 choice_layout;
    IndexedResourceArchive hand_cursor;
    IndexedResourceArchive choice_cursor;
    IndexedResourceHandle choice_handle;
    ObjTileCollectionEntry choice_state;
    UiResourceChangeFlags portrait_flags;
    u32 portrait_id;
    UiPortraitGroupOwner portrait;
    ObjPaletteCollectionEntry portrait_palette;
    UiResourceChangeFlags nameplate_flags;
    UnkUiSelectionTileBuffer nameplate_tiles[UI_NAMEPLATE_TILE_BUFFER_COUNT];
    u8 heart_indicator_visible;
    IndexedResourceArchive heart_indicator_archive;
    IndexedResourceHandle heart_indicator_handle;
    ObjPaletteCollectionEntry heart_indicator_palette;
    UnkUiPayloadLowFlags low_flags;
};
typedef char UiStatePayloadSizeCheck[sizeof(UiStatePayload) == 0x554 ? 1 : -1];
typedef char UiPayload_state[offsetof(UiStatePayload, state) == 8 ? 1 : -1];
typedef char UiPayload_allow_resume[offsetof(UiStatePayload, allow_resume) == 0x0D ? 1 : -1];
typedef char UiPayload_palette[offsetof(UiStatePayload, palette) == 16 ? 1 : -1];
typedef char UiPayload_background_state[offsetof(UiStatePayload, background_state) == 24 ? 1 : -1];
typedef char UiPayload_commands[offsetof(UiStatePayload, commands) == 32 ? 1 : -1];
typedef char UiPayload_records[offsetof(UiStatePayload, records) == 60 ? 1 : -1];
typedef char UiPayload_records_command[offsetof(UiStatePayload, records_command) == 192 ? 1 : -1];
typedef char UiPayload_output[offsetof(UiStatePayload, output) == 208 ? 1 : -1];
typedef char UiPayload_text[offsetof(UiStatePayload, text) == 236 ? 1 : -1];
typedef char UiPayload_output_command[offsetof(UiStatePayload, output_command) == 288 ? 1 : -1];
typedef char UiPayload_tile_copy[offsetof(UiStatePayload, tile_copy) == 304 ? 1 : -1];
typedef char UiPayload_window[offsetof(UiStatePayload, window) == 328 ? 1 : -1];
typedef char UiPayload_choice_index[offsetof(UiStatePayload, choice_index) == 344 ? 1 : -1];
typedef char UiPayload_choice_layout[offsetof(UiStatePayload, choice_layout) == 348 ? 1 : -1];
typedef char UiPayload_hand_cursor[offsetof(UiStatePayload, hand_cursor) == 352 ? 1 : -1];
typedef char UiPayload_choice_cursor[offsetof(UiStatePayload, choice_cursor) == 400 ? 1 : -1];
typedef char UiPayload_choice_handle[offsetof(UiStatePayload, choice_handle) == 448 ? 1 : -1];
typedef char UiPayload_choice_state[offsetof(UiStatePayload, choice_state) == 468 ? 1 : -1];
typedef char UiPayload_portrait_flags[offsetof(UiStatePayload, portrait_flags) == 476 ? 1 : -1];
typedef char UiPayload_portrait_id[offsetof(UiStatePayload, portrait_id) == 480 ? 1 : -1];
typedef char UiPayload_portrait[offsetof(UiStatePayload, portrait) == 484 ? 1 : -1];
typedef char UiPayload_portrait_palette[offsetof(UiStatePayload, portrait_palette) == 488 ? 1 : -1];
typedef char UiPayload_nameplate_flags[offsetof(UiStatePayload, nameplate_flags) == 496 ? 1 : -1];
typedef char UiPayload_nameplate_tiles[offsetof(UiStatePayload, nameplate_tiles) == 500 ? 1 : -1];
typedef char UiPayload_heart_indicator_visible[offsetof(UiStatePayload, heart_indicator_visible) == 1280 ? 1 : -1];
typedef char UiPayload_heart_indicator_archive[offsetof(UiStatePayload, heart_indicator_archive) == 1284 ? 1 : -1];
typedef char UiPayload_heart_indicator_handle[offsetof(UiStatePayload, heart_indicator_handle) == 1332 ? 1 : -1];
typedef char UiPayload_heart_indicator_palette[offsetof(UiStatePayload, heart_indicator_palette) == 1352 ? 1 : -1];
typedef char UiPayload_low_flags[offsetof(UiStatePayload, low_flags) == 1360 ? 1 : -1];

#endif // UI_STATE_HH
