#include "new_game_status_text.hh"

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[8] =
    "Years";

char const gText_NewGameStatus_SeasonSeparator[4] =
    " ";

char const gText_NewGameStatus_DaySuffix[8] =
    " Day";

char const gText_NewGameStatus_OpenParen[4] =
    " (";

char const gText_NewGameStatus_CloseParen[4] =
    ")";

char const gText_NewGameStatus_FarmSuffix[8] =
    " Farm";

char const gText_NewGameStatus_ReadDiary[12] =
    "Read diary.";

char const gText_NewGameStatus_WriteDiary[16] =
    "Write in diary.";

char const gText_NewGameStatus_NoSavedData[24] =
    "There is no saved data.";
