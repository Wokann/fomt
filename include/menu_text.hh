#ifndef MENU_TEXT_HH
#define MENU_TEXT_HH

#include "prelude.h"

// The seven-entry menu stores its IDs, label text, and label pointers as
// adjacent ROM arrays. The IDs and pointers are common; the labels are
// selected by the regional text source.
extern u32 const gMenuEntryIds[7];
extern char const * const gMenuEntryLabels[7];

extern char const gText_Menu_Diary[];
extern char const gText_Menu_Rucksack[];
extern char const gText_Menu_WorldMap[];
extern char const gText_Menu_FarmMap[];
extern char const gText_Menu_Earnings[];
extern char const gText_Menu_Memo[];
extern char const gText_Menu_Tutorial[];

#endif // MENU_TEXT_HH
