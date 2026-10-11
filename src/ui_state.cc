#include "ui_state.hh"

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

UiStateOwner::UiStateOwner(u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4,
    HardwareStateOwner const & shared, HardwareResource const & resources)
{
    value = new UiStatePayload(arg_1, arg_2, arg_3, arg_4, shared, resources);
}

UiStateOwner::~UiStateOwner()
{
    delete value;
}

i32 UiStateOwner::GetState() const
{
    return value->state;
}

i32 UiStateOwner::Update(HardwareCoreState * state,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    u8 * links, u8 * manager, MusicPlayer ** music) const
{
    return value->Update(state, sprites, display, links, manager, music);
}

// These adapters follow the owner methods in the same native ROM block.
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

EC void * func_08050DF0(void * const * object)
{
    FirstFieldQueryData * const data = static_cast<FirstFieldQueryData *>(*object);

    if (data->mode == 6)
        return nullptr;

    return data->result;
}

#include FOMT_TEXT_INCLUDE(ui_state.cc)

UiTextLayoutPositionTable const gUiTextLayoutPositionTable = {
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

UiSharedResourceData const gUiSharedResourceData = {
    gUnk_UiSharedResourceData_000,
    0x120,
    gUnk_UiSharedResourceData_001,
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

EC UnkUiPackedLinkCommand * func_08050EE4(UnkUiPackedLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4)
{
    object->previous_slot = nullptr;
    object->next = nullptr;
#if defined(REGION_JP)
    object->vtable = (void **)vtable_unk_080E7868;
#else
    object->vtable = (void **)vtable_unk_080E7878;
#endif
    object->unk_0c_00 = arg_1;
    object->unk_0c_05 = arg_2;
    object->unk_0c_15 = arg_3;
    object->unk_0c_19 = arg_4;
    return object;
}

EC UnkUiReferenceObject * func_08050F60(UnkUiReferenceObject * object,
    void * const * value, u8 arg_2)
{
#if defined(REGION_JP)
    object->vtable = vtable_unk_080E7898;
#else
    object->vtable = vtable_unk_080E78A8;
#endif
    object->value = *value;
    object->unk_08 = arg_2;
    return object;
}

EC u8 func_08050F70(UnkUiSelectionData const * object)
{
    return object->unk_1a;
}

EC void func_08050F74(UnkUiSelectionData * object, u32 const arg_1,
    u32 const arg_2)
{
    u32 second_index = arg_2;
    if (second_index > 2)
        second_index %= 3;
    object->unk_16 = second_index;

    u32 first_index = arg_1;
    if (first_index > 27)
        first_index %= 28;
    object->unk_14 = first_index;
    object->unk_19 = 0;
}
