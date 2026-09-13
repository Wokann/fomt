#ifndef STAFF_CREDITS_HH
#define STAFF_CREDITS_HH

#include "prelude.h"

// fomt-text recovers each original fixed storage field from the selected ROM.
// The maintained credit source itself remains unconstrained visible text.
template <unsigned int Size>
struct StaffCreditsTextStorage
{
    char bytes[Size];
};

// Native scrolling code walks this null-terminated row-pointer table.
extern char const * const gStaffCreditsLines[];
extern char const gCppRuntimeBadAlloc_StaffCredits[];

#endif // STAFF_CREDITS_HH
