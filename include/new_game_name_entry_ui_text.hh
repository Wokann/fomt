#ifndef NEW_GAME_NAME_ENTRY_UI_TEXT_HH
#define NEW_GAME_NAME_ENTRY_UI_TEXT_HH

#include "prelude.h"

extern char const gText_NewGameNameEntry_Placeholder[];
extern char const gText_NewGameNameEntry_NameLabel[];
extern char const gText_NewGameNameEntry_Confirm[];
extern char const gText_NewGameNameEntry_Yes[];
extern char const gText_NewGameNameEntry_No[];

#if defined(REGION_JP)
extern char const gText_NewGameNameEntry_ModeKatakana[];
extern char const gText_NewGameNameEntry_ModeSymbols[];
extern char const gText_NewGameNameEntry_ModeHiragana[];
#else
extern char const gText_NewGameNameEntry_EndLatin[];
extern char const gText_NewGameNameEntry_EndFullWidth[];
#endif

#endif // NEW_GAME_NAME_ENTRY_UI_TEXT_HH
