#include "new_game_status_text.hh"

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[] =
    "年目";

char const gText_NewGameStatus_SeasonSeparator[] ALIGN(4) =
    "の月";

char const gText_NewGameStatus_DaySuffix[] ALIGN(4) =
    "日";

char const gText_NewGameStatus_OpenParen[] ALIGN(4) =
    "（";

char const gText_NewGameStatus_CloseParen[] ALIGN(4) =
    "）";

char const gText_NewGameStatus_FarmSuffix[] ALIGN(4) =
    "牧場";

char const gText_NewGameStatus_ReadDiary[] ALIGN(4) =
    "日記を読む";

char const gText_NewGameStatus_WriteDiary[] ALIGN(4) =
    "日記をつける";

char const gText_NewGameStatus_NoSavedData[] ALIGN(4) =
    "セーブデータがありません。";
