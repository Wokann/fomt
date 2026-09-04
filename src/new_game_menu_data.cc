#include "new_game_menu_text.hh"

// The regional fixed-width text fields precede this original pointer order.
#if defined(REGION_JP)
#define FOMT_NEW_GAME_MENU_TEXT_LABELS
#include "data/text/jp/new_game_menu.cc"
#undef FOMT_NEW_GAME_MENU_TEXT_LABELS
#else
#define FOMT_NEW_GAME_MENU_TEXT_LABELS
#include "data/text/us/new_game_menu.cc"
#undef FOMT_NEW_GAME_MENU_TEXT_LABELS
#endif

// REGION_JP maps the two control-choice semantic names to the stored data
// labels in new_game_menu_text.hh, retaining the original direct pointers.
char const * const gNewGameMenuLabels[18] = {
    gText_NewGameMenu_Diary,
    gText_NewGameMenu_Save,
    gText_NewGameMenu_Load,
    gText_NewGameMenu_Blank,
    gText_NewGameMenu_Data1,
    gText_NewGameMenu_Data2,
    gText_NewGameMenu_ControlSettings,
#if defined(REGION_JP)
    gText_NewGameMenu_Data1,
    gText_NewGameMenu_Data2,
#else
    gText_NewGameMenu_ControlOption1,
    gText_NewGameMenu_ControlOption2,
#endif
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
