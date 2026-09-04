#ifndef NEW_GAME_MENU_TEXT_HH
#define NEW_GAME_MENU_TEXT_HH

#include "prelude.h"

// The new-game menu consumes this exact 18-entry pointer order.  Text fields
// are regional, while the table preserves the original regional pointer reuse.
extern char const * const gNewGameMenuLabels[18];

extern char const gText_NewGameMenu_Diary[];
extern char const gText_NewGameMenu_Save[];
extern char const gText_NewGameMenu_Load[];
extern char const gText_NewGameMenu_Blank[];
extern char const gText_NewGameMenu_Data1[];
extern char const gText_NewGameMenu_Data2[];
extern char const gText_NewGameMenu_ControlSettings[];
extern char const gText_NewGameMenu_ClockDisplay[];
extern char const gText_NewGameMenu_Yes[];
extern char const gText_NewGameMenu_No[];
extern char const gText_NewGameMenu_FaceDisplay[];
extern char const gText_NewGameMenu_NameDisplay[];

#if !defined(REGION_JP)
extern char const gText_NewGameMenu_ControlOption1[];
extern char const gText_NewGameMenu_ControlOption2[];
#endif

#endif // NEW_GAME_MENU_TEXT_HH
