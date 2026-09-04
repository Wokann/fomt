#include "new_game_menu_text.hh"

// Fixed-width labels displayed by the new-game menu. Array widths preserve
// original ROM fields; ordinary C++ supplies their zero-fill.
#if defined(FOMT_NEW_GAME_MENU_TEXT_LABELS)

char const gText_NewGameMenu_Diary[8] =
    "Diary";

char const gText_NewGameMenu_Save[8] =
    "Save";

char const gText_NewGameMenu_Load[8] =
    "Load";

char const gText_NewGameMenu_Blank[4] =
    "";

char const gText_NewGameMenu_Data1[8] =
    "Data 1";

char const gText_NewGameMenu_Data2[8] =
    "Data 2";

char const gText_NewGameMenu_ControlSettings[8] =
    "Buttons";

char const gText_NewGameMenu_ControlOption1[4] =
    "1";

char const gText_NewGameMenu_ControlOption2[4] =
    "2";

char const gText_NewGameMenu_ClockDisplay[8] =
    "Clock";

char const gText_NewGameMenu_Yes[4] =
    "Yes";

char const gText_NewGameMenu_No[4] =
    "No";

char const gText_NewGameMenu_FaceDisplay[8] =
    "Face";

char const gText_NewGameMenu_NameDisplay[8] =
    "Name";

#else
#error "Include this file through src/new_game_menu_data.cc with a text partition."
#endif
