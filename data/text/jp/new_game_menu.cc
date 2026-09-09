#include "new_game_menu_text.hh"

// New-game menu labels.  Four-byte label boundaries preserve only the original
// ROM layout; the strings themselves have no fixed field width.
#if defined(FOMT_NEW_GAME_MENU_TEXT_LABELS)

char const gText_NewGameMenu_Diary[] =
    "日記";

char const gText_NewGameMenu_Save[] ALIGN(4) =
    "セーブ";

char const gText_NewGameMenu_Load[] ALIGN(4) =
    "ロード";

char const gText_NewGameMenu_Blank[] ALIGN(4) =
    "";

char const gText_NewGameMenu_Data1[] ALIGN(4) =
    "その１";

char const gText_NewGameMenu_Data2[] ALIGN(4) =
    "その２";

char const gText_NewGameMenu_ControlSettings[] ALIGN(4) =
    "移動設定";

char const gText_NewGameMenu_ClockDisplay[] ALIGN(4) =
    "時計の表示";

char const gText_NewGameMenu_Yes[] ALIGN(4) =
    "あり";

char const gText_NewGameMenu_No[] ALIGN(4) =
    "なし";

char const gText_NewGameMenu_FaceDisplay[] ALIGN(4) =
    "顔の表示";

char const gText_NewGameMenu_NameDisplay[] ALIGN(4) =
    "名前の表示";

#else
#error "Include this file through src/new_game_menu_data.cc with a text partition."
#endif
