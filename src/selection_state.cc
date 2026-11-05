#include "selection_state.hh"

extern "C" void SetSelectionIndex(SelectionContext * context, i16 selection_index)
{
    context->state->selection_index = selection_index;
}

extern "C" i16 GetSelectionIndex(SelectionContext const * context)
{
    return context->state->selection_index;
}
