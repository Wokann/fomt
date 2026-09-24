#ifndef STAFF_CREDITS_HH
#define STAFF_CREDITS_HH

#include "prelude.h"

// fomt-text derives each aligned storage field and shared pointer from the
// visible credit rows. No baseline ROM is needed during compilation.
template <unsigned int Size>
struct StaffCreditsTextStorage
{
    char bytes[Size];
};

// Native scrolling code walks this null-terminated row-pointer table.
extern char const * const gStaffCreditsLines[];
extern char const gCppRuntimeBadAlloc_StaffCredits[];

#endif // STAFF_CREDITS_HH
