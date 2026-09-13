#include "library_data.hh"

#include FOMT_TEXT_INCLUDE(library_data.cc)

// func_08079A64 loads one 32-bit source slot at a time, then stores its low
// halfword into the active Library entry list.  Keep the original word width.
u32 const gLibraryInitialEntryIds[] ALIGN(4) = {
        0x00000002,
        0x00000088,
        0x00000003,
        0x00000004,
        0x00000005,
        0x00000006,
        0x00000007,
        0x00000008,
    };

#include FOMT_TEXT_INCLUDE(library_data_1.cc)
