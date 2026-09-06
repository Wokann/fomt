#include "prelude.h"

struct EntityUiUnknownState
{
    u8 unknown_00[0x41];
    u8 unknown_41;
};

// The ROM leaf unconditionally returns false.  Its caller-facing purpose is
// not mapped yet.
extern "C" bool func_080324B8()
    SECTION(".text.entity_ui_default_no_action");

// The semantic name of byte 0x41 is still unknown; preserve the exact leaf
// write while its callers and owning entity layout are recovered.
extern "C" void func_08033B7C(void * entity)
    SECTION(".text.entity_ui_unknown_flag");

extern "C" bool func_080324B8()
{
    return false;
}

extern "C" void func_08033B7C(void * entity)
{
    EntityUiUnknownState * state = (EntityUiUnknownState *)entity;

    state->unknown_41 = 0;
}
