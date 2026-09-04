#include "menu_text.hh"

// This ordered ID list is read by the seven-entry menu constructor.
u32 const gMenuEntryIds[7] SECTION(".rodata.menu_entry_ids") = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
};

// Keep the original pointer order separate from the localized text bodies.
char const * const gMenuEntryLabels[7] SECTION(".rodata.menu_label_pointers") = {
    gText_Menu_Diary,
    gText_Menu_Rucksack,
    gText_Menu_WorldMap,
    gText_Menu_FarmMap,
    gText_Menu_Earnings,
    gText_Menu_Memo,
    gText_Menu_Tutorial,
};
