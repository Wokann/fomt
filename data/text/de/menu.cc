#include "menu_data.hh"

#if defined(FOMT_MENU_TEXT_LABELS)

char const gText_Menu_Diary[] =
    "Tagebuch";
char const gText_Menu_Rucksack[] =
    "Rucksack";
char const gText_Menu_WorldMap[] =
    "Weltkarte";
char const gText_Menu_FarmMap[] =
    "Farmkarte";
char const gText_Menu_Earnings[] =
    "Erträge";
char const gText_Menu_Memo[] =
    "Memo";
char const gText_Menu_Tutorial[] =
    "Anleitung";

#else
#error "Include this file through src/menu_data.cc with a text partition."
#endif
