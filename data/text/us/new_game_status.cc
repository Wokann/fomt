#include "new_game_status_text.hh"

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[8] SECTION(".rodata.new_game_status_labels") =
    "Years";

char const gText_NewGameStatus_SeasonSeparator[4] SECTION(".rodata.new_game_status_labels") =
    " ";

char const gText_NewGameStatus_DaySuffix[8] SECTION(".rodata.new_game_status_labels") =
    " Day";

char const gText_NewGameStatus_OpenParen[4] SECTION(".rodata.new_game_status_labels") =
    " (";

char const gText_NewGameStatus_CloseParen[4] SECTION(".rodata.new_game_status_labels") =
    ")";

char const gText_NewGameStatus_FarmSuffix[8] SECTION(".rodata.new_game_status_labels") =
    " Farm";

char const gText_NewGameStatus_ReadDiary[12] SECTION(".rodata.new_game_status_labels") =
    "Read diary.";

char const gText_NewGameStatus_WriteDiary[16] SECTION(".rodata.new_game_status_labels") =
    "Write in diary.";

char const gText_NewGameStatus_NoSavedData[24] SECTION(".rodata.new_game_status_labels") =
    "There is no saved data.";
