#include "prelude.h"

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
