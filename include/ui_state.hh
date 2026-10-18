#ifndef UI_STATE_HH
#define UI_STATE_HH

#include "prelude.h"
#include "resource_handle.hh"
#include "hardware_resource.hh"
#include "hardware_dma_descriptor.hh"
#include "utility/container_algorithms.hh"
#include "hardware_linked_list.hh"
#include "hardware_state_clear.hh"
#include "utility/fixed_str.hh"

struct HardwareCoreState;
struct HardwareSpriteBufferState;
struct HardwareDisplayState;
struct HardwareStateOwner;
struct HardwareResource;
struct HardwareResourceEntry;
struct MusicPlayer;
struct ScriptTextVariableStore;
struct IndexedResourceGroupResult;

// Own the current portrait archive group, including sprite and tile/palette
// ranges. The pointed-to 32-byte result borrows its actual archive payload.
struct UiPortraitGroupOwner
{
    IndexedResourceGroupResult * value;
    UiPortraitGroupOwner() SECTION(".text.ui_portrait_group");
    UiPortraitGroupOwner(u32 index) SECTION(".text.ui_portrait_group");
    ~UiPortraitGroupOwner() SECTION(".text.ui_portrait_group");
    void Set(u32 index) SECTION(".text.ui_portrait_group");
    IndexedResourceGroupResult Get() const SECTION(".text.ui_portrait_group");
};

typedef char UiPortraitGroupOwnerSizeCheck[sizeof(UiPortraitGroupOwner) == 4 ? 1 : -1];

struct UiTextSubstitution
{
    bool found;
    FixedStr<31> text;
};

// The output base supplies native no-op cursor/page defaults and a byte-valued
// stop query. Concrete output storage below owns its three glyph rows.
// The input adapter below stores a copied key snapshot and a byte-valued gate;
// variable-store implementations still have additional native storage.
struct UiTextOutput
{
    virtual ~UiTextOutput() SECTION(".text.ui_text_output_base_destructor");
    virtual bool Emit(u32 code) = 0;
    virtual void CarriageReturn() SECTION(".text.ui_text_output_defaults");
    virtual void LineFeed() SECTION(".text.ui_text_output_defaults");
    virtual void NextPage() SECTION(".text.ui_text_output_defaults");
    virtual u8 ShouldStop() SECTION(".text.ui_text_output_defaults");
};

inline UiTextOutput::~UiTextOutput() {}

struct UiTextInput
{
    virtual ~UiTextInput() SECTION(".text.ui_text_input_base_destructor");
    virtual bool Fast() SECTION(".text.ui_text_input_defaults");
    virtual bool WaitForInput() SECTION(".text.ui_text_input_defaults");
    virtual bool Resume() SECTION(".text.ui_text_input_defaults");
};

inline UiTextInput::~UiTextInput() {}

struct ScriptTextVariableStore
{
    virtual ~ScriptTextVariableStore();
    virtual UiTextSubstitution Lookup(u32 code) = 0;
};

typedef char UiTextSubstitutionSizeCheck[sizeof(UiTextSubstitution) == 36 ? 1 : -1];
typedef char UiTextSubstitutionTextCheck[offsetof(UiTextSubstitution, text) == 4 ? 1 : -1];

// Native text reader: 0 is idle, 1 reads text and 2 waits for input.
// The parser temporarily switches from cursor to replacement_cursor while
// consuming a substituted value stored in the inline 32-byte buffer.
struct UiTextStream
{
    u32 phase;
    u16 speed;
    u16 progress;
    char const * cursor;
    ScriptTextVariableStore * variables;
    char const * replacement_cursor;
    FixedStr<31> replacement;

    UiTextStream() SECTION(".text.ui_text_stream_setup");
};

typedef char UiTextStreamSizeCheck[sizeof(UiTextStream) == 0x34 ? 1 : -1];
typedef char UiTextStreamSpeedCheck[offsetof(UiTextStream, speed) == 4 ? 1 : -1];
typedef char UiTextStreamProgressCheck[offsetof(UiTextStream, progress) == 6 ? 1 : -1];
typedef char UiTextStreamCursorCheck[offsetof(UiTextStream, cursor) == 8 ? 1 : -1];
typedef char UiTextStreamVariablesCheck[offsetof(UiTextStream, variables) == 0x0C ? 1 : -1];
typedef char UiTextStreamReplacementCursorCheck[offsetof(UiTextStream, replacement_cursor) == 0x10 ? 1 : -1];
typedef char UiTextStreamReplacementCheck[offsetof(UiTextStream, replacement) == 0x14 ? 1 : -1];

EXTERN_C
u32 GetUiPortraitCount() SECTION(".text.ui_portrait_group");
extern u8 const gPortraitIndexedResourceArchive[];

void SetUiTextStreamText(UiTextStream *, char const *, ScriptTextVariableStore *)
    SECTION(".text.ui_text_stream_setup");
void SetUiTextStreamSpeed(UiTextStream *, u16) SECTION(".text.ui_text_stream_setup");
u32 UpdateUiTextStream(UiTextStream *, UiTextOutput *, UiTextInput *)
    SECTION(".text.ui_text_stream_update");
// This dependency keeps its original 44-byte assembly body.
int AdvanceUiTextStreamClock(UiTextStream *);
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

struct FirstFieldStatusByte
{
    u8 unused_00[0x0D];
    u8 value;
};

struct FirstFieldQueryData
{
    u8 unused_00[8];
    u32 mode;
    u8 unused_0c[0x14C];
    void * result;
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

struct UiStatePayload;

struct UiStateOwner
{
    UiStateOwner(u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4,
        HardwareStateOwner const & shared, HardwareResource const & resources)
        SECTION(".text.ui_state_adapters");
    ~UiStateOwner() SECTION(".text.ui_state_adapters");
    i32 GetState() const SECTION(".text.ui_state_adapters");
    i32 Update(HardwareCoreState * state, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, u8 * links, u8 * manager,
        MusicPlayer ** music) const SECTION(".text.ui_state_adapters");

    UiStatePayload * value;
};

typedef char UiStateOwnerSizeCheck[sizeof(UiStateOwner) == 4 ? 1 : -1];

// One-shot window setup: a background screen block, border tile index,
// background palette bank and hand-cursor OBJ palette bank. The upper nine
// bits retain their previous value and still have no established meaning.
struct UiTextWindowSetupCommand : HardwareLinkBase
{
    UiTextWindowSetupCommand(u32, u32, u32, u32) SECTION(".text.ui_state_adapters");
    virtual bool Run() SECTION(".text.ui_text_window_setup");
    unsigned screen_block : 5;
    unsigned first_tile : 10;
    unsigned background_palette : 4;
    unsigned cursor_palette : 4;
    unsigned unk_0c_23 : 9;
};

typedef char UiTextWindowSetupCommandSizeCheck[
    sizeof(UiTextWindowSetupCommand) == 0x10 ? 1 : -1];

// The native UI update copies input.pressed into this word-sized snapshot.
// Only its low eight key bits are queried; allow_resume gates resumption.
struct UiTextInputAdapter : UiTextInput
{
    UiTextInputAdapter(u32 const &, u8);
    // The implicit virtual destructor forwards to the real input base.
    virtual bool Fast() SECTION(".text.ui_text_input_callbacks");
    virtual bool WaitForInput() SECTION(".text.ui_text_input_callbacks");
    virtual bool Resume() SECTION(".text.ui_text_input_callbacks");
    u32 pressed;
    u8 allow_resume;
};

// Native selection storage: three owned rows, each with seven 16-byte
// entries. The buffer prefix and scalar control fields remain unknown.
struct UnkUiSelectionTileBuffer
{
    u32 unk_00;
    u32 tiles[64];
};

struct UnkUiSelectionPixels
{
    UnkUiSelectionTileBuffer * value;
    UnkUiSelectionPixels() : value(new UnkUiSelectionTileBuffer) {}
    ~UnkUiSelectionPixels() { delete value; }
};

struct UnkUiSelectionEntry
{
    UnkUiSelectionPixels pixels;
    HardwareStateEntry state;
    bool changed;
    UnkUiSelectionEntry() : changed(false) {}
};

struct UnkUiSelectionRow
{
    UnkUiSelectionEntry entries[7];
    UnkUiSelectionEntry & Entry(unsigned index) { return entries[index]; }
};

struct UnkUiSelectionRowOwner
{
    UnkUiSelectionRow * value;
    UnkUiSelectionRowOwner() : value(nullptr) {}
    ~UnkUiSelectionRowOwner() { delete value; }
    UnkUiSelectionRow * Get() const { return value; }
    UnkUiSelectionRow * operator->() const { return value; }
    UnkUiSelectionRowOwner & operator=(UnkUiSelectionRow * input)
    {
        UnkUiSelectionRow * const previous = value;
        if (input != previous && previous != nullptr)
            delete previous;
        value = input;
        return *this;
    }
};

struct UnkUiSelectionData : UiTextOutput
{
    UnkUiSelectionData(HardwareResourceEntry *, HardwareStateOwner const &)
        SECTION(".text.ui_state_selection");
    // Keep the implicit virtual destructor: row ownership supplies its body.
    virtual bool Emit(u32) SECTION(".text.ui_text_output_callbacks");
    virtual void CarriageReturn() SECTION(".text.ui_text_output_callbacks");
    virtual void LineFeed() SECTION(".text.ui_text_output_callbacks");
    virtual void NextPage() SECTION(".text.ui_text_output_callbacks");
    // Return the stored byte unchanged; do not normalize it to a C++ bool.
    virtual u8 ShouldStop() SECTION(".text.ui_text_output_callbacks");
    HardwareResourceEntry * palette;
    UnkUiSelectionRowOwner rows[3];
    u16 unk_14;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
};

struct UnkUiSelectionDimensions
{
    u16 width;
    u16 height;
    UnkUiSelectionDimensions(u16 first, u16 second) : width(first), height(second) {}
};

// Upload changed glyph buffers from the three physical rows, then retire
// this queued command. The output storage and its resource handles are borrowed.
struct UiTextOutputUploadCommand : HardwareLinkBase
{
    virtual bool Run() SECTION(".text.ui_text_output_upload");
    UnkUiSelectionData * output;
};

typedef char UiTextOutputUploadCommandSizeCheck[
    sizeof(UiTextOutputUploadCommand) == 0x10 ? 1 : -1];
typedef char UiTextOutputUploadCommandOutputCheck[
    offsetof(UiTextOutputUploadCommand, output) == 0x0C ? 1 : -1];

// A repeating BG tile upload. Alternating mode toggles its nibble mask each
// run; it is not compression. That mode requires at least one 32-byte tile.
struct UiTextTileCopyCommand : HardwareLinkBase
{
    UiTextTileCopyCommand(u32 const *, u32 *, u32, bool) SECTION(".text.ui_state_selection");
    virtual bool Run() SECTION(".text.ui_text_tile_copy");
    u32 const * source;
    u32 * destination;
    u16 tile_count : 14;
    u16 nibble_phase : 1;
    u16 alternate_nibbles : 1;
};

typedef char UiTextInputAdapterSizeCheck[
    sizeof(UiTextInputAdapter) == 0x0C ? 1 : -1];
typedef char UiTextInputAdapterPressedCheck[
    offsetof(UiTextInputAdapter, pressed) == 4 ? 1 : -1];
typedef char UiTextInputAdapterResumeCheck[
    offsetof(UiTextInputAdapter, allow_resume) == 8 ? 1 : -1];
typedef char UnkUiSelectionDataSizeCheck[
    sizeof(UnkUiSelectionData) == 0x1C ? 1 : -1];
typedef char UnkUiSelectionTileBufferSizeCheck[
    sizeof(UnkUiSelectionTileBuffer) == 0x104 ? 1 : -1];
typedef char UnkUiSelectionTileBufferTilesCheck[
    offsetof(UnkUiSelectionTileBuffer, tiles) == 4 ? 1 : -1];
typedef char UnkUiSelectionPixelsSizeCheck[
    sizeof(UnkUiSelectionPixels) == 4 ? 1 : -1];
typedef char UnkUiSelectionEntrySizeCheck[
    sizeof(UnkUiSelectionEntry) == 16 ? 1 : -1];
typedef char UnkUiSelectionEntryStateCheck[
    offsetof(UnkUiSelectionEntry, state) == 4 ? 1 : -1];
typedef char UnkUiSelectionEntryChangedCheck[
    offsetof(UnkUiSelectionEntry, changed) == 12 ? 1 : -1];
typedef char UnkUiSelectionRowSizeCheck[
    sizeof(UnkUiSelectionRow) == 112 ? 1 : -1];
typedef char UnkUiSelectionRowOwnerSizeCheck[
    sizeof(UnkUiSelectionRowOwner) == 4 ? 1 : -1];
typedef char UnkUiSelectionDataRowsCheck[
    offsetof(UnkUiSelectionData, rows) == 8 ? 1 : -1];
typedef char UnkUiSelectionDataControlCheck[
    offsetof(UnkUiSelectionData, unk_14) == 0x14 ? 1 : -1];
typedef char UnkUiSelectionDataLineCheck[
    offsetof(UnkUiSelectionData, unk_16) == 0x16 ? 1 : -1];
typedef char UnkUiSelectionDataOriginCheck[
    offsetof(UnkUiSelectionData, unk_18) == 0x18 ? 1 : -1];
typedef char UnkUiSelectionDataStopCheck[
    offsetof(UnkUiSelectionData, unk_19) == 0x19 ? 1 : -1];
typedef char UnkUiSelectionDataChangedCheck[
    offsetof(UnkUiSelectionData, unk_1a) == 0x1A ? 1 : -1];
typedef char UnkUiSelectionDataNonblankCheck[
    offsetof(UnkUiSelectionData, unk_1b) == 0x1B ? 1 : -1];
typedef char UnkUiSelectionDimensionsSizeCheck[
    sizeof(UnkUiSelectionDimensions) == 4 ? 1 : -1];
typedef char UiTextTileCopyCommandSizeCheck[
    sizeof(UiTextTileCopyCommand) == 0x18 ? 1 : -1];
typedef char UiTextTileCopyCommandSourceCheck[
    offsetof(UiTextTileCopyCommand, source) == 0x0C ? 1 : -1];
typedef char UiTextTileCopyCommandDestinationCheck[
    offsetof(UiTextTileCopyCommand, destination) == 0x10 ? 1 : -1];

EXTERN_C

// The native nine-tile border helper remains assembly.
void func_08051320(u16 * tilemap, u32 x, u32 y, u32 width, u32 height,
    u32 first_tile, u32 palette);
extern u8 const gUiHandCursorArchive[];

u8 func_08050F70(UnkUiSelectionData const * object);
void func_08050F74(UnkUiSelectionData * object, u32 arg_1, u32 arg_2);

// Native renderer: emits up to three rows of seven selection OAM entries.
// Its body remains shared assembly until the C++ reconstruction matches.
void func_08050FA0(UnkUiSelectionData * object, HardwareSpriteBufferState * sprites);

void func_080510E8(UnkUiSelectionData * object)
    SECTION(".text.ui_state_selection");
int func_080512B8(UnkUiSelectionData const * object, int index)
    SECTION(".text.ui_state_selection");
UnkUiSelectionRow * func_080512C8(UnkUiSelectionData const * object, u32 index)
    SECTION(".text.ui_state_selection");
UnkUiSelectionRow * func_080512D0(UnkUiSelectionData const * object, u32 index)
    SECTION(".text.ui_state_selection");

// Existing UI adapter ABI. The menu supplies a text address as arg_r1;
// the payload's other scalar argument domains are still unresolved.
void func_08050D5C(UiStateOwner const * object) SECTION(".text.ui_state_adapters");
void func_08050D68(UiStateOwner const * object) SECTION(".text.ui_state_adapters");
void func_08050D74(void * const * object) SECTION(".text.ui_state_adapters");
void * func_08050DF0(void * const * object) SECTION(".text.ui_state_adapters");
void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3) SECTION(".text.ui_state_adapters");
// Selection rows are encoded text pointers, not integer IDs. Both adapters
// receive the same substitution context as the dialogue message renderer.
void func_08050E0C(UiStateOwner const * object, char const * first, char const * second,
    char const * third, char const * fourth, char const * fifth, char const * sixth,
    ScriptTextVariableStore * variables) SECTION(".text.ui_state_adapters");
void func_08050E30(UiStateOwner const * object, char const * prompt, char const * first,
    char const * second, char const * third, char const * fourth,
    ScriptTextVariableStore * variables) SECTION(".text.ui_state_adapters");
void func_08050E50(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
void func_08050E5C(void * const * object)
    SECTION(".text.ui_state_adapters");
void func_08050E68(void * const * object, char const * text)
    SECTION(".text.ui_state_adapters");
void func_08050E74(void * const * object)
    SECTION(".text.ui_state_adapters");
void func_08050E80(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
void func_08050E8C(void * const * object)
    SECTION(".text.ui_state_adapters");

EXTERN_C_END

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

EC UiTextLayoutPosition GetUiChoiceLayoutPosition(u32 layout, u32 selection)
    SECTION(".text.ui_choice_labels");
EC void RenderUiChoiceLabel(UiStatePayload *, UiTextLayoutPosition const &,
    char const *, ScriptTextVariableStore *) SECTION(".text.ui_choice_labels");
EC i32 MoveUiChoiceSelection(u32 layout, i32 selection, UiChoiceKeyState keys)
    SECTION(".text.ui_choice_labels");
// The encoded input must contain 1..12 bytes. Invalid text only disables the
// nameplate; valid input clears three owned buffers and draws up to four bytes
// into each. The portrait and the text-window state are independent.
EC void SetUiNameplateText(UiStatePayload *, char const *) SECTION(".text.ui_nameplate");

// These native objects physically precede the layout-position table.  The
// full-width decimal formatter FormatFullWidthDecimal reads two encoded bytes from
// each three-byte digit row, or from the space/hyphen strings.  Its checked
// ASCII index uses (DigitRows - '0' * 3) + character * 3; the terminator is
// not copied.  Existing names still describe the verified physical layout.
extern char const gCppRuntimeBadAlloc_PreUiTextLayout[];
extern char const gUnk_PreUiTextLayoutDigitRows[10][3];
extern char const gUnk_PreUiTextLayoutFullWidthSpace[];
extern char const gUnk_PreUiTextLayoutFullWidthHyphen[];
extern char const gCppRuntimeBadAlloc_PostUiTextLayoutGlyphRows[];

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

// Eight 16-byte DMA descriptors; only the counted range has an active lifetime.
struct UiDmaTransferQueue
{
    u32 count;
    u8 storage[8 * sizeof(DmaTransferDescriptor)];

    UiDmaTransferQueue() : count(0) {}
    DmaTransferDescriptor * Begin()
    {
        return reinterpret_cast<DmaTransferDescriptor *>(storage);
    }
    DmaTransferDescriptor * End()
    {
        return reinterpret_cast<DmaTransferDescriptor *>(storage + count * sizeof(DmaTransferDescriptor));
    }
    ~UiDmaTransferQueue()
    {
        typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor Trait;
        DmaTransferDescriptor * last = End();
        destroy_range_inl(Begin(), last, Trait());
    }
};
// The native Run remains assembly. Emit its real table and implicit destructor
// in this implementation without exporting an unused constructor.
#pragma interface "ui_state.hh"
struct UiDmaTransferCommand : HardwareLinkBase
{
    UiDmaTransferQueue * queue;
    virtual bool Run();
};
#pragma implementation
typedef char UiDmaTransferQueueSizeCheck[sizeof(UiDmaTransferQueue) == 0x84 ? 1 : -1];
typedef char UiDmaTransferCommandSizeCheck[sizeof(UiDmaTransferCommand) == 0x10 ? 1 : -1];

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
    // Construction and Update retain their original native assembly bodies.
    UiStatePayload(u32, u32, u32, u32, HardwareStateOwner const &, HardwareResource const &);
    ~UiStatePayload() SECTION(".text.ui_payload_destructor");
    void Open() SECTION(".text.ui_payload_open");
    void OpenImmediately() SECTION(".text.ui_payload_open");
    i32 Update(HardwareCoreState *, HardwareSpriteBufferState *, HardwareDisplayState *,
        u8 *, u8 *, MusicPlayer **);
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
    HardwareResourceEntry palette;
    HardwareStateEntry background_state;
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
    HardwareStateEntry choice_state;
    UiResourceChangeFlags portrait_flags;
    u32 portrait_id;
    UiPortraitGroupOwner portrait;
    HardwareResourceEntry portrait_palette;
    UiResourceChangeFlags nameplate_flags;
    UnkUiSelectionTileBuffer nameplate_tiles[UI_NAMEPLATE_TILE_BUFFER_COUNT];
    u8 nameplate_phase;
    IndexedResourceArchive nameplate_archive;
    IndexedResourceHandle nameplate_handle;
    HardwareResourceEntry nameplate_palette;
    UnkUiPayloadLowFlags low_flags;
};
typedef char UiStatePayloadSizeCheck[sizeof(UiStatePayload) == 0x554 ? 1 : -1];
typedef char UiPayload_state[offsetof(UiStatePayload, state) == 8 ? 1 : -1];
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
typedef char UiPayload_nameplate_phase[offsetof(UiStatePayload, nameplate_phase) == 1280 ? 1 : -1];
typedef char UiPayload_nameplate_archive[offsetof(UiStatePayload, nameplate_archive) == 1284 ? 1 : -1];
typedef char UiPayload_nameplate_handle[offsetof(UiStatePayload, nameplate_handle) == 1332 ? 1 : -1];
typedef char UiPayload_nameplate_palette[offsetof(UiStatePayload, nameplate_palette) == 1352 ? 1 : -1];
typedef char UiPayload_low_flags[offsetof(UiStatePayload, low_flags) == 1360 ? 1 : -1];

#endif // UI_STATE_HH
