#include "ui_state.hh"
#include "ui_text_layout.hh"

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

UiSharedResourceData const gUiSharedResourceData = {
    gUnk_UiSharedResourceData_000,
    0x120,
    gUnk_UiSharedResourceData_001,
};

extern "C" void SetUiObjectStateTwoIfNonzero(void * object)
    SECTION(".text.set_ui_object_state_two_if_nonzero");

extern "C" void ClearUiObjectStateIfNonzero(void * object)
    SECTION(".text.clear_ui_object_state_if_nonzero");

extern "C" void ClearUiActionStateFlag01DC(void * object)
    SECTION(".text.clear_ui_action_state_flag_01dc");

extern "C" void ClearUiActionStateFlag01F0(void * object)
    SECTION(".text.clear_ui_action_state_flag_01f0");

extern "C" void SetUiObjectStateTwoIfNonzero(void * object)
{
    UiObjectState * state = (UiObjectState *)object;

    if (state->state != 0)
    {
        state->state = 2;
    }
}

extern "C" void ClearUiObjectStateIfNonzero(void * object)
{
    UiObjectState * state = (UiObjectState *)object;

    if (state->state != 0)
    {
        state->state = 0;
    }
}

extern "C" void ClearUiActionStateFlag01DC(void * object)
{
    UiActionState * state = (UiActionState *)object;

    state->flags_01dc.active = 0;
}

extern "C" void ClearUiActionStateFlag01F0(void * object)
{
    UiActionState * state = (UiActionState *)object;

    state->flags_01f0.active = 0;
}

// These adapters form one contiguous UI-state block in the original ROM.
// The owning high-level UI class is still unknown, so retain the recovered
// entry-point names and only model fields that the code demonstrably uses.
EC void func_08050D5C(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D68(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D74(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D80(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D8C(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
EC void func_08050DA0(void * const * object, u32 arg_r1, u32 arg_r2)
    SECTION(".text.ui_state_adapters");
EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
    SECTION(".text.ui_state_adapters");
EC void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3) SECTION(".text.ui_state_adapters");

EC u8 func_08050DD8(void * const * object)
    SECTION(".text.ui_state_adapters");
EC u8 func_08050DE4(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void * func_08050DF0(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050E0C(void * const * object, u32 arg_r1, u32 arg_r2,
    u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3)
    SECTION(".text.ui_state_adapters");
EC void func_08050E30(void * const * object, u32 arg_r1, u32 arg_r2,
    u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2)
    SECTION(".text.ui_state_adapters");
EC void func_08050E50(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
EC void func_08050E5C(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050E68(void * const * object, char const * text)
    SECTION(".text.ui_state_adapters");
EC void func_08050E74(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050E80(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
EC void func_08050E8C(void * const * object)
    SECTION(".text.ui_state_adapters");

EC void func_0805039C(void * object);
EC void func_080503E4(void * object);
EC void func_08050424(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3);
EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);
EC void func_08050AD8(void * object, u32 arg_r1);
EC void func_08050B50(void * object, char const * text);
EC void func_08050C2C(void * object, u32 arg_r1);
EC void func_08050C64(void * object);

EC void func_08050D5C(void * const * object)
{
    func_0805039C(*object);
}

EC void func_08050D68(void * const * object)
{
    func_080503E4(*object);
}

EC void func_08050D74(void * const * object)
{
    SetUiObjectStateTwoIfNonzero(*object);
}

EC void func_08050D80(void * const * object)
{
    ClearUiObjectStateIfNonzero(*object);
}

EC void func_08050D8C(void * const * object, u32 arg_r1)
{
    func_08050424(*object, arg_r1, 0x100, 0);
}

EC void func_08050DA0(void * const * object, u32 arg_r1, u32 arg_r2)
{
    func_08050424(*object, arg_r1, 0x100, arg_r2);
}

EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
{
    func_08050424(*object, arg_r1, arg_r2, 0);
}

EC void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3)
{
    func_08050424(*object, arg_r1, arg_r2, arg_r3);
}

struct FirstFieldStatusByte
{
    u8 unused_00[0x0D];
    u8 value;
};

EC u8 func_08050DD8(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 0;
    return value;
}

EC u8 func_08050DE4(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 1;
    return value;
}

struct FirstFieldQueryData
{
    u8 unused_00[8];
    u32 mode;
    u8 unused_0c[0x14C];
    void * result;
};

EC void * func_08050DF0(void * const * object)
{
    FirstFieldQueryData * const data = static_cast<FirstFieldQueryData *>(*object);

    if (data->mode == 6)
        return nullptr;

    return data->result;
}

extern char const gCppRuntimeBadAlloc_PreUiTextLayout[]
    SECTION(".rodata.ui_state_adapters") ALIGN(4) =
    "bad_alloc";

extern char const gUnk_PreUiTextLayoutDigitRows[10][3]
    SECTION(".rodata.ui_state_adapters") ALIGN(4) = {
        "０", "１", "２", "３", "４",
        "５", "６", "７", "８", "９",
    };

extern char const gUnk_PreUiTextLayoutFullWidthSpace[]
    SECTION(".rodata.ui_state_adapters") ALIGN(4) =
    "　";
extern char const gUnk_PreUiTextLayoutFullWidthHyphen[]
    SECTION(".rodata.ui_state_adapters") ALIGN(4) =
    "－";

extern char const gCppRuntimeBadAlloc_PostUiTextLayoutGlyphRows[]
    SECTION(".rodata.ui_state_adapters") ALIGN(4) =
    "bad_alloc";

UiTextLayoutPositionTable const gUiTextLayoutPositionTable
    SECTION(".rodata.ui_state_adapters") = {
    0x00,
    {
        { 0x08, 0x09, 0x00, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x40, 0x41, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x42 },
        { 0x09, 0x0A, 0x00, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x42, 0x00, 0x00 },
    },
};

EC void func_08050E0C(void * const * object, u32 arg_r1, u32 arg_r2,
    u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3)
{
    func_08050478(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1,
        arg_sp2, arg_sp3);
}

EC void func_08050E30(void * const * object, u32 arg_r1, u32 arg_r2,
    u32 arg_r3, u32 arg_sp0, u32 arg_sp1, u32 arg_sp2)
{
    func_08050664(*object, arg_r1, arg_r2, arg_r3, arg_sp0, arg_sp1,
        arg_sp2);
}

EC void func_08050E50(void * const * object, u32 arg_r1)
{
    func_08050AD8(*object, arg_r1);
}

EC void func_08050E5C(void * const * object)
{
    ClearUiActionStateFlag01DC(*object);
}

EC void func_08050E68(void * const * object, char const * text)
{
    func_08050B50(*object, text);
}

EC void func_08050E74(void * const * object)
{
    ClearUiActionStateFlag01F0(*object);
}

EC void func_08050E80(void * const * object, u32 arg_r1)
{
    func_08050C2C(*object, arg_r1);
}

EC void func_08050E8C(void * const * object)
{
    func_08050C64(*object);
}

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

EC u32 func_08050E98(FirstFieldUiOwner & object, u32 const flag_mask)
    SECTION(".text.ui_state_adapters");
EC u32 func_08050EBC(FirstFieldUiOwner & object, u32 const flag_mask)
    SECTION(".text.ui_state_adapters");

EC u32 func_08050E98(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    u32 const old_flags = data->low_flags;
    data->low_flags &= ~flag_mask;
    return old_flags;
}

EC u32 func_08050EBC(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    u32 const old_flags = data->low_flags;
    data->low_flags |= flag_mask;
    return old_flags;
}
