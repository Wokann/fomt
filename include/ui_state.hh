#ifndef UI_STATE_HH
#define UI_STATE_HH

#include "prelude.h"
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

struct UiTextSubstitution
{
    bool found;
    FixedStr<31> text;
};

// Recovered virtual contracts only; concrete output, input and variable-store
// objects still have native implementations and additional storage.
struct UiTextOutput
{
    virtual ~UiTextOutput();
    virtual bool Emit(u32 code) = 0;
    virtual void CarriageReturn() = 0;
    virtual void LineFeed() = 0;
    virtual void NextPage() = 0;
    virtual bool ShouldStop() = 0;
};

struct UiTextInput
{
    virtual ~UiTextInput();
    virtual bool Fast() = 0;
    virtual bool WaitForInput() = 0;
    virtual bool Resume() = 0;
};

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

    UiTextStream()
        : phase(0), speed(0x100), progress(0), cursor(nullptr),
          variables(nullptr), replacement_cursor(nullptr) {}
};

typedef char UiTextStreamSizeCheck[sizeof(UiTextStream) == 0x34 ? 1 : -1];
typedef char UiTextStreamSpeedCheck[offsetof(UiTextStream, speed) == 4 ? 1 : -1];
typedef char UiTextStreamProgressCheck[offsetof(UiTextStream, progress) == 6 ? 1 : -1];
typedef char UiTextStreamCursorCheck[offsetof(UiTextStream, cursor) == 8 ? 1 : -1];
typedef char UiTextStreamVariablesCheck[offsetof(UiTextStream, variables) == 0x0C ? 1 : -1];
typedef char UiTextStreamReplacementCursorCheck[offsetof(UiTextStream, replacement_cursor) == 0x10 ? 1 : -1];
typedef char UiTextStreamReplacementCheck[offsetof(UiTextStream, replacement) == 0x14 ? 1 : -1];

EXTERN_C
UiTextStream * InitializeUiTextStream(UiTextStream *) SECTION(".text.ui_text_stream_setup");
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

// The payload's allocation size and state field are verified. Its constructor,
// destructor and update routine still have their original assembly bodies;
// the remaining fields must not be treated as recovered high-level data.
struct UiStatePayload
{
    UiStatePayload(u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4,
        HardwareStateOwner const & shared, HardwareResource const & resources);
    ~UiStatePayload();
    i32 Update(HardwareCoreState * state, HardwareSpriteBufferState * sprites,
        HardwareDisplayState * display, u8 * links, u8 * manager,
        MusicPlayer ** music);

    u8 unknown_00[8];
    i32 state;
    u8 unknown_0c[0x548];
};

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

typedef char UiStatePayloadSizeCheck[sizeof(UiStatePayload) == 0x554 ? 1 : -1];
typedef char UiStateOwnerSizeCheck[sizeof(UiStateOwner) == 4 ? 1 : -1];

// Verified field view of the native linked command. Initialization writes
// only these four fields; the upper nine bits retain their previous value.
// Their runtime meanings have not been established.
struct UnkUiPackedLinkCommand
{
    HardwareLinkBase ** previous_slot;
    HardwareLinkBase * next;
    void ** vtable;
    unsigned unk_0c_00 : 5;
    unsigned unk_0c_05 : 10;
    unsigned unk_0c_15 : 4;
    unsigned unk_0c_19 : 4;
    unsigned unk_0c_23 : 9;
};

typedef char UnkUiPackedLinkCommandSizeCheck[
    sizeof(UnkUiPackedLinkCommand) == 0x10 ? 1 : -1];

// Native field views for the following UI helpers. Unknown prefixes and
// byte fields remain unknown until their owning classes are recovered.
struct UnkUiReferenceObject
{
    HardwareLinkVirtualFunction const * vtable;
    void * value;
    u8 unk_08;
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

struct UnkUiSelectionData
{
    HardwareLinkVirtualFunction const * vtable;
    HardwareResourceEntry * palette;
    UnkUiSelectionRowOwner rows[3];
    u16 unk_14;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
    UnkUiSelectionEntry & Entry(int row, int column)
    {
        return rows[row]->Entry(column);
    }
};

struct UnkUiSelectionDimensions
{
    u16 width;
    u16 height;
    UnkUiSelectionDimensions(u16 first, u16 second) : width(first), height(second) {}
};

struct UnkUiSelectionLinkCommand
{
    HardwareLinkBase ** previous_slot;
    HardwareLinkBase * next;
    void ** vtable;
    u32 unk_0c;
    u32 unk_10;
    u16 unk_14_00 : 14;
    u16 unk_14_14 : 1;
    u16 unk_14_15 : 1;
};

typedef char UnkUiReferenceObjectSizeCheck[
    sizeof(UnkUiReferenceObject) == 0x0C ? 1 : -1];
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
typedef char UnkUiSelectionLinkCommandSizeCheck[
    sizeof(UnkUiSelectionLinkCommand) == 0x18 ? 1 : -1];

EXTERN_C

bool EmitUiTextGlyph(UnkUiSelectionData * object, u32 code)
    SECTION(".text.ui_text_output_callbacks");
void ReturnUiTextCursor(UnkUiSelectionData * object)
    SECTION(".text.ui_text_output_callbacks");
void AdvanceUiTextLine(UnkUiSelectionData * object)
    SECTION(".text.ui_text_output_callbacks");
void ClearUiTextPage(UnkUiSelectionData * object)
    SECTION(".text.ui_text_output_callbacks");
// Preserve the native stored-byte result, rather than normalizing it.
u8 GetUiTextStopFlag(UnkUiSelectionData const * object)
    SECTION(".text.ui_text_output_callbacks");

extern HardwareLinkVirtualFunction const vtable_unk_080E7868[];
extern HardwareLinkVirtualFunction const vtable_unk_080E7878[];
extern HardwareLinkVirtualFunction const vtable_unk_080E7898[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78A8[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78B0[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78C0[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78D0[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78E0[];

UnkUiPackedLinkCommand * func_08050EE4(UnkUiPackedLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4)
    SECTION(".text.ui_state_adapters");

UnkUiReferenceObject * func_08050F60(UnkUiReferenceObject * object,
    void * const * value, u8 arg_2);
u8 func_08050F70(UnkUiSelectionData const * object);
void func_08050F74(UnkUiSelectionData * object, u32 arg_1, u32 arg_2);

// Native renderer: emits up to three rows of seven selection OAM entries.
// Its body remains shared assembly until the C++ reconstruction matches.
void func_08050FA0(UnkUiSelectionData * object, HardwareSpriteBufferState * sprites);

void func_080510E8(UnkUiSelectionData * object)
    SECTION(".text.ui_state_selection");
UnkUiSelectionData * func_0805116C(UnkUiSelectionData * object,
    HardwareResourceEntry * palette, HardwareStateOwner const & state)
    SECTION(".text.ui_state_selection");
int func_080512B8(UnkUiSelectionData const * object, int index)
    SECTION(".text.ui_state_selection");
UnkUiSelectionRow * func_080512C8(UnkUiSelectionData const * object, u32 index)
    SECTION(".text.ui_state_selection");
UnkUiSelectionRow * func_080512D0(UnkUiSelectionData const * object, u32 index)
    SECTION(".text.ui_state_selection");
UnkUiSelectionLinkCommand * func_080512D8(UnkUiSelectionLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, bool arg_4)
    SECTION(".text.ui_state_selection");

// Existing UI adapter ABI. The menu supplies a text address as arg_r1;
// the payload's other scalar argument domains are still unresolved.
void func_08050D5C(void * const * object) SECTION(".text.ui_state_adapters");
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
};

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

#endif // UI_STATE_HH
