#include "new_game_menu_text.hh"

// New-game menu labels.  Four-byte label boundaries preserve only the original
// ROM layout; the strings themselves have no fixed field width.
#if defined(FOMT_NEW_GAME_MENU_TEXT_LABELS)

char const gText_NewGameMenu_Diary[] =
    "Diary";

char const gText_NewGameMenu_Save[] ALIGN(4) =
    "Save";

char const gText_NewGameMenu_Load[] ALIGN(4) =
    "Load";

char const gText_NewGameMenu_Blank[] ALIGN(4) =
    "";

char const gText_NewGameMenu_Data1[] ALIGN(4) =
    "Data 1";

char const gText_NewGameMenu_Data2[] ALIGN(4) =
    "Data 2";

char const gText_NewGameMenu_ControlSettings[] ALIGN(4) =
    "Buttons";

char const gText_NewGameMenu_ControlOption1[] ALIGN(4) =
    "1";

char const gText_NewGameMenu_ControlOption2[] ALIGN(4) =
    "2";

char const gText_NewGameMenu_ClockDisplay[] ALIGN(4) =
    "Clock";

char const gText_NewGameMenu_Yes[] ALIGN(4) =
    "Yes";

char const gText_NewGameMenu_No[] ALIGN(4) =
    "No";

char const gText_NewGameMenu_FaceDisplay[] ALIGN(4) =
    "Face";

char const gText_NewGameMenu_NameDisplay[] ALIGN(4) =
    "Name";

#else
#error "Include this file through src/new_game_menu_data.cc with a text partition."
#endif
