#include "new_game_menu_text.hh"

// The regional fixed-width text fields precede this original pointer order.
#if defined(REGION_JP)
#define FOMT_NEW_GAME_TEXT_MENU
#include "data/text/jp/new_game.cc"
#undef FOMT_NEW_GAME_TEXT_MENU
#else
#define FOMT_NEW_GAME_TEXT_MENU
#include "data/text/us/new_game.cc"
#undef FOMT_NEW_GAME_TEXT_MENU
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

// The main New Game text run follows the menu labels in the native ROM.  The
// preset animal-name branch is compiled separately at its later physical slot.
#if defined(REGION_JP)
#include "data/text/jp/new_game.cc"
#else
#include "data/text/us/new_game.cc"
#endif
