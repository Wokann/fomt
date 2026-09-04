#include "new_game_menu_text.hh"

// Fixed-width labels displayed by the new-game menu.  Array widths preserve
// the original field boundaries and let the C++ initializer supply zero-fill.
char const gText_NewGameMenu_Diary[8] SECTION(".rodata.new_game_menu_labels") =
    "Diary";

char const gText_NewGameMenu_Save[8] SECTION(".rodata.new_game_menu_labels") =
    "Save";

char const gText_NewGameMenu_Load[8] SECTION(".rodata.new_game_menu_labels") =
    "Load";

char const gText_NewGameMenu_Blank[4] SECTION(".rodata.new_game_menu_labels") =
    "";

char const gText_NewGameMenu_Data1[8] SECTION(".rodata.new_game_menu_labels") =
    "Data 1";

char const gText_NewGameMenu_Data2[8] SECTION(".rodata.new_game_menu_labels") =
    "Data 2";

char const gText_NewGameMenu_ControlSettings[8] SECTION(".rodata.new_game_menu_labels") =
    "Buttons";

char const gText_NewGameMenu_ControlOption1[4] SECTION(".rodata.new_game_menu_labels") =
    "1";

char const gText_NewGameMenu_ControlOption2[4] SECTION(".rodata.new_game_menu_labels") =
    "2";

char const gText_NewGameMenu_ClockDisplay[8] SECTION(".rodata.new_game_menu_labels") =
    "Clock";

char const gText_NewGameMenu_Yes[4] SECTION(".rodata.new_game_menu_labels") =
    "Yes";

char const gText_NewGameMenu_No[4] SECTION(".rodata.new_game_menu_labels") =
    "No";

char const gText_NewGameMenu_FaceDisplay[8] SECTION(".rodata.new_game_menu_labels") =
    "Face";

char const gText_NewGameMenu_NameDisplay[8] SECTION(".rodata.new_game_menu_labels") =
    "Name";
