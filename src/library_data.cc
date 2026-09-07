#include "library_text.hh"

// This is a ten-byte string object in the original layout.  The following
// entry-ID table begins at the next four-byte boundary.
char const gCppRuntimeBadAlloc_LibraryInfo[]
    SECTION(".rodata.library_info_runtime") ALIGN(1) =
        "bad_alloc";

// func_08079A64 loads one 32-bit source slot at a time, then stores its low
// halfword into the active Library entry list.  Keep the original word width.
u32 const gLibraryInitialEntryIds[]
    SECTION(".rodata.library_initial_entry_ids") ALIGN(4) = {
        0x00000002,
        0x00000088,
        0x00000003,
        0x00000004,
        0x00000005,
        0x00000006,
        0x00000007,
        0x00000008,
    };
