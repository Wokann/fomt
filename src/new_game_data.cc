#include "new_game_data.hh"

#include FOMT_TEXT_INCLUDE(new_game_data_1.cc)

// The menu renderer indexes this native 18-entry table directly.  The JP ROM
// reuses its two data labels for the two control-choice entries, while the
// western ROMs store their own control-option text objects at those slots.
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

#include FOMT_TEXT_INCLUDE(new_game_data_2.cc)
