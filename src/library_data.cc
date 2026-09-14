#include "library_data.hh"

#include FOMT_TEXT_INCLUDE(library_data_1.cc)

// func_08079A64 loads one 32-bit source slot at a time, then stores its low
// halfword into the active Library entry list.  Keep the original word width.
u32 const gLibraryInitialEntryIds[] = {
        0x00000002,
        0x00000088,
        0x00000003,
        0x00000004,
        0x00000005,
        0x00000006,
        0x00000007,
        0x00000008,
    };

// The library UI selects one of two fixed 12-byte fields by adding either
// zero or twelve to this sequence. Its embedded NUL is therefore a real
// field separator, not object-end padding.
#include FOMT_TEXT_INCLUDE(library_data_2.cc)
#include FOMT_TEXT_INCLUDE(library_data_3.cc)
