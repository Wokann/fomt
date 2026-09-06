#include "prelude.h"

struct SelectionState
{
    u8 unknown_000[0x590];
    i16 selection_index;
};

struct SelectionContext
{
    u8 unknown_000[8];
    SelectionState * state;
};

extern "C" void SetSelectionIndex(SelectionContext * context, i16 selection_index)
    SECTION(".text.set_selection_index");

extern "C" void SetSelectionIndex(SelectionContext * context, i16 selection_index)
{
    context->state->selection_index = selection_index;
}

extern "C" i16 GetSelectionIndex(SelectionContext const * context)
    SECTION(".text.get_selection_index");

extern "C" i16 GetSelectionIndex(SelectionContext const * context)
{
    return context->state->selection_index;
}
