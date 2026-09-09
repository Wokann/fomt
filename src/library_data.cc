#include "library_text.hh"

#define FOMT_LIBRARY_TEXT_OPENING_HOURS
#define FOMT_LIBRARY_TEXT_ATTRIBUTE SECTION(".rodata.library_opening_hours")
#if defined(REGION_JP)
#include "data/text/jp/library.cc"
#else
#include "data/text/us/library.cc"
#endif
#undef FOMT_LIBRARY_TEXT_ATTRIBUTE
#undef FOMT_LIBRARY_TEXT_OPENING_HOURS

#define FOMT_LIBRARY_TEXT_INFO
#define FOMT_LIBRARY_TEXT_ATTRIBUTE SECTION(".rodata.library_info")
#include "data/text/common/library_info.cc"
#undef FOMT_LIBRARY_TEXT_ATTRIBUTE
#undef FOMT_LIBRARY_TEXT_INFO

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

#define FOMT_LIBRARY_TEXT_MENU
#define FOMT_LIBRARY_TEXT_ATTRIBUTE SECTION(".rodata.library_menu")
#if defined(REGION_JP)
#include "data/text/jp/library_menu.cc"
#else
#include "data/text/us/library_menu.cc"
#endif
#undef FOMT_LIBRARY_TEXT_ATTRIBUTE
#undef FOMT_LIBRARY_TEXT_MENU
