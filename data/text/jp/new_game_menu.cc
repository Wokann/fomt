#include "new_game_menu_text.hh"

// Fixed-width labels displayed by the new-game menu.  Array widths preserve
// the original field boundaries and let the C++ initializer supply zero-fill.
char const gText_NewGameMenu_Diary[8] SECTION(".rodata.new_game_menu_labels") =
    "日記";

char const gText_NewGameMenu_Save[8] SECTION(".rodata.new_game_menu_labels") =
    "セーブ";

char const gText_NewGameMenu_Load[8] SECTION(".rodata.new_game_menu_labels") =
    "ロード";

char const gText_NewGameMenu_Blank[4] SECTION(".rodata.new_game_menu_labels") =
    "";

char const gText_NewGameMenu_Data1[8] SECTION(".rodata.new_game_menu_labels") =
    "その１";

char const gText_NewGameMenu_Data2[8] SECTION(".rodata.new_game_menu_labels") =
    "その２";

char const gText_NewGameMenu_ControlSettings[12] SECTION(".rodata.new_game_menu_labels") =
    "移動設定";

char const gText_NewGameMenu_ClockDisplay[12] SECTION(".rodata.new_game_menu_labels") =
    "時計の表示";

char const gText_NewGameMenu_Yes[8] SECTION(".rodata.new_game_menu_labels") =
    "あり";

char const gText_NewGameMenu_No[8] SECTION(".rodata.new_game_menu_labels") =
    "なし";

char const gText_NewGameMenu_FaceDisplay[12] SECTION(".rodata.new_game_menu_labels") =
    "顔の表示";

char const gText_NewGameMenu_NameDisplay[12] SECTION(".rodata.new_game_menu_labels") =
    "名前の表示";
