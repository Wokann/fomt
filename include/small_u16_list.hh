#ifndef SMALL_U16_LIST_HH
#define SMALL_U16_LIST_HH

#include "prelude.h"

// The observed prefix stores at most three u16 entries and a selected value.
// The halfword at +0x0A has not yet been classified.
struct SmallU16ListState
{
    u32 count;
    u16 entries[3];
    u16 unk_0A;
    u16 selected;

};

#endif // SMALL_U16_LIST_HH
