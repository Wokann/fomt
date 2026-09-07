#include "menu_data.hh"

#if defined(FOMT_MENU_TEXT_LABELS)

char const gText_Menu_Diary[] =
    "Diary";
char const gText_Menu_Rucksack[] =
    "Rucksack";
char const gText_Menu_WorldMap[] =
    "World Map";
char const gText_Menu_FarmMap[] =
    "Farm Map";
char const gText_Menu_Earnings[] =
    "Earnings";
char const gText_Menu_Memo[] =
    "Memo";
char const gText_Menu_Tutorial[] =
    "Tutorial";

#else
#error "Include this file through src/menu_data.cc with a text partition."
#endif
