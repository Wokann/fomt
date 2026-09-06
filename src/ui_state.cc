#include "prelude.h"

struct UiObjectState
{
    u8 unknown_00[8];
    i32 state;
};

extern "C" void SetUiObjectStateTwoIfNonzero(void * object)
    SECTION(".text.set_ui_object_state_two_if_nonzero");

extern "C" void ClearUiObjectStateIfNonzero(void * object)
    SECTION(".text.clear_ui_object_state_if_nonzero");

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
