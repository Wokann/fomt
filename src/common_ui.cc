#include "common_ui.hh"

// These regional headers supply C/C++ IDs from the same list Mary compiles.
#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#elif defined(REGION_DE)
#include "data/scripts/de/fomt_scripts.mary.h"
#else
#include "data/scripts/us/fomt_scripts.mary.h"
#endif

#include FOMT_TEXT_INCLUDE(common_ui_1.cc)

// Indexed by FARMING_TUTORIAL_CROPS / FARMING_TUTORIAL_ANIMALS.
// The following runtime text retains the original alignment padding.
u16 const gFarmingTutorialScriptIds[] = {
    EventScript_TutorialEvent_CropFarmingInstructions,
    EventScript_SystemMenu_SelectAnimalCategory,
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
