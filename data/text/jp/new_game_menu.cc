#include "new_game_menu_text.hh"

// Fixed-width labels displayed by the new-game menu. Array widths preserve
// original ROM fields; ordinary C++ supplies their zero-fill.
#if defined(FOMT_NEW_GAME_MENU_TEXT_LABELS)

char const gText_NewGameMenu_Diary[8] =
    "日記";

char const gText_NewGameMenu_Save[8] =
    "セーブ";

char const gText_NewGameMenu_Load[8] =
    "ロード";

char const gText_NewGameMenu_Blank[4] =
    "";

char const gText_NewGameMenu_Data1[8] =
    "その１";

char const gText_NewGameMenu_Data2[8] =
    "その２";

char const gText_NewGameMenu_ControlSettings[12] =
    "移動設定";

char const gText_NewGameMenu_ClockDisplay[12] =
    "時計の表示";

char const gText_NewGameMenu_Yes[8] =
    "あり";

char const gText_NewGameMenu_No[8] =
    "なし";

char const gText_NewGameMenu_FaceDisplay[12] =
    "顔の表示";

char const gText_NewGameMenu_NameDisplay[12] =
    "名前の表示";

#else
#error "Include this file through src/new_game_menu_data.cc with a text partition."
#endif
