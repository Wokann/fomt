#ifndef SELECTION_STATE_HH
#define SELECTION_STATE_HH

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

EXTERN_C

void SetSelectionIndex(SelectionContext * context, i16 selection_index);
i16 GetSelectionIndex(SelectionContext const * context);

EXTERN_C_END

#endif // SELECTION_STATE_HH
