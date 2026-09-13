#ifndef LIBRARY_DATA_HH
#define LIBRARY_DATA_HH

#include "prelude.h"

extern char const gCppRuntimeBadAlloc_LibraryInfo[];

// func_08079A64 reads this as 32-bit source slots before storing each low
// halfword in the active Library entry list.
extern u32 const gLibraryInitialEntryIds[];

extern char const gText_Library_Menu[];
extern char const gCppRuntimeBadAlloc_LibraryMenu[];

#endif // LIBRARY_DATA_HH
