#include "menu_data.hh"

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

#if defined(REGION_JP)
#define FOMT_MENU_TEXT_LABELS
#include "data/text/jp/menu.cc"
#undef FOMT_MENU_TEXT_LABELS
#else
#define FOMT_MENU_TEXT_LABELS
#include "data/text/us/menu.cc"
#undef FOMT_MENU_TEXT_LABELS
#endif

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

#define FOMT_MENU_TEXT_RUNTIME_FIRST
#include "data/text/common/menu.cc"
#undef FOMT_MENU_TEXT_RUNTIME_FIRST

u8 const gUnk_080F1A66[] = {
    0x00, 0x11, 0x15, 0x1E, 0x24, 0x31, 0x35,
    0x3E, 0x44, 0x48, 0x4D, 0x50, 0x71, 0x77,
};

#define FOMT_MENU_TEXT_RUNTIME_THIRD
#include "data/text/common/menu.cc"
#undef FOMT_MENU_TEXT_RUNTIME_THIRD
