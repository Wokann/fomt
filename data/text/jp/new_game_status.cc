#include "new_game_status_text.hh"

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[8] =
    "年目";

char const gText_NewGameStatus_SeasonSeparator[8] =
    "の月";

char const gText_NewGameStatus_DaySuffix[4] =
    "日";

char const gText_NewGameStatus_OpenParen[4] =
    "（";

char const gText_NewGameStatus_CloseParen[4] =
    "）";

char const gText_NewGameStatus_FarmSuffix[8] =
    "牧場";

char const gText_NewGameStatus_ReadDiary[12] =
    "日記を読む";

char const gText_NewGameStatus_WriteDiary[16] =
    "日記をつける";

char const gText_NewGameStatus_NoSavedData[28] =
    "セーブデータがありません。";
