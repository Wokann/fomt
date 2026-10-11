#ifndef UI_STATE_HH
#define UI_STATE_HH

#include "prelude.h"
#include "hardware_linked_list.hh"

struct HardwareCoreState;
struct HardwareSpriteBufferState;
struct HardwareDisplayState;
struct HardwareStateOwner;
struct HardwareResource;
struct MusicPlayer;

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
struct UnkUiPackedLinkCommand : HardwareLinkBase
{
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

struct UnkUiSelectionData
{
    u8 unk_00[0x14];
    u16 unk_14;
    u16 unk_16;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1a;
};

typedef char UnkUiReferenceObjectSizeCheck[
    sizeof(UnkUiReferenceObject) == 0x0C ? 1 : -1];
typedef char UnkUiSelectionDataSizeCheck[
    sizeof(UnkUiSelectionData) == 0x1C ? 1 : -1];

EXTERN_C

extern HardwareLinkVirtualFunction const vtable_unk_080E7868[];
extern HardwareLinkVirtualFunction const vtable_unk_080E7878[];
extern HardwareLinkVirtualFunction const vtable_unk_080E7898[];
extern HardwareLinkVirtualFunction const vtable_unk_080E78A8[];

UnkUiPackedLinkCommand * func_08050EE4(UnkUiPackedLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4)
    SECTION(".text.ui_state_adapters");

UnkUiReferenceObject * func_08050F60(UnkUiReferenceObject * object,
    void * const * value, u8 arg_2);
u8 func_08050F70(UnkUiSelectionData const * object);
void func_08050F74(UnkUiSelectionData * object, u32 arg_1, u32 arg_2);

// Existing UI adapter ABI. The menu supplies a text address as arg_r1;
// the payload's other scalar argument domains are still unresolved.
void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3) SECTION(".text.ui_state_adapters");

EXTERN_C_END

enum
{
    UI_TEXT_LAYOUT_VARIANT_COUNT = 8,
    UI_TEXT_LAYOUT_SLOT_COUNT = 6,
};

// These native objects physically precede the layout-position table.  The
// full-width decimal formatter func_0804E98C reads two encoded bytes from
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

// Multiple UI constructors copy unk_00 for unk_04 bytes into VRAM and copy
// unk_08 into palette RAM.  The encoded resource payload formats remain raw.
struct UiSharedResourceData
{
    u8 const * unk_00;
    u32 unk_04;
    u8 const * unk_08;
};

extern u8 const gUnk_UiSharedResourceData_000[];
extern u8 const gUnk_UiSharedResourceData_001[];
extern UiSharedResourceData const gUiSharedResourceData;

#endif // UI_STATE_HH
