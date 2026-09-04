#include "new_game_menu_text.hh"

// Preserve the original table order separately from regional text storage.
// REGION_JP maps the two control-choice semantic names to the stored data
// labels in new_game_menu_text.hh, retaining the original direct pointers.
char const * const gNewGameMenuLabels[18] SECTION(".rodata.new_game_menu_label_pointers") = {
    gText_NewGameMenu_Diary,
    gText_NewGameMenu_Save,
    gText_NewGameMenu_Load,
    gText_NewGameMenu_Blank,
    gText_NewGameMenu_Data1,
    gText_NewGameMenu_Data2,
    gText_NewGameMenu_ControlSettings,
    gText_NewGameMenu_ControlOption1,
    gText_NewGameMenu_ControlOption2,
    gText_NewGameMenu_ClockDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
    gText_NewGameMenu_FaceDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
    gText_NewGameMenu_NameDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
};
