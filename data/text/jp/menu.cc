#include "menu_data.hh"

#if defined(FOMT_MENU_TEXT_LABELS)

char const gText_Menu_Diary[] =
    "日記";
char const gText_Menu_Rucksack[] =
    "装備·持ち物";
char const gText_Menu_WorldMap[] =
    "全体マップ";
char const gText_Menu_FarmMap[] =
    "牧場マップ";
char const gText_Menu_Earnings[] =
    "家計簿";
char const gText_Menu_Memo[] =
    "いろいろ";
char const gText_Menu_Tutorial[] =
    "遊び方";

#else
#error "Include this file through src/menu_data.cc with a text partition."
#endif
