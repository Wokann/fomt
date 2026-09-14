#include "common_ui.hh"

#include FOMT_TEXT_INCLUDE(common_ui_1.cc)

// This halfword table is selected by an unresolved native caller.
u16 const gUnk_080F19AE[] = {
    0x0427, 0x0423, 0x0000,
};

#include FOMT_TEXT_INCLUDE(common_ui_2.cc)

// This ordered ID list is read by the seven-entry menu constructor.
u32 const gMenuEntryIds[7] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
};

#include FOMT_TEXT_INCLUDE(common_ui_3.cc)

// The original label-pointer table follows the regional text bodies.
char const * const gMenuEntryLabels[7] = {
    gText_Menu_Diary,
    gText_Menu_Rucksack,
    gText_Menu_WorldMap,
    gText_Menu_FarmMap,
    gText_Menu_Earnings,
    gText_Menu_Memo,
    gText_Menu_Tutorial,
};

#include FOMT_TEXT_INCLUDE(common_ui_4.cc)

u8 const gUnk_080F1A66[] = {
    0x00, 0x11, 0x15, 0x1E, 0x24, 0x31, 0x35,
    0x3E, 0x44, 0x48, 0x4D, 0x50, 0x71, 0x77,
};

#include FOMT_TEXT_INCLUDE(common_ui_5.cc)
