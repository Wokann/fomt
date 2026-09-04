#include "new_game_help_text.hh"

char const gText_NewGameHelp_Controls[80] SECTION(".rodata.new_game_help_text") =
    "操作　　　　その１　その２\r\n"
    "十字ボタン　歩く　　走る\r\n"
    "Ｒボタン　　走る　　歩く";

char const gText_NewGameHelp_ClockDisplay[52] SECTION(".rodata.new_game_help_text") =
    "マップ画面で時計を表示するの\r\n"
    "かどうかを決める。";

char const gText_NewGameHelp_FaceDisplay[80] SECTION(".rodata.new_game_help_text") =
    "メッセージウインドウで\r\n"
    "しゃべっている人の顔を表示\r\n"
    "するのかどうかを決める。";

char const gText_NewGameHelp_NameDisplay[80] SECTION(".rodata.new_game_help_text") =
    "メッセージウインドウで\r\n"
    "しゃべっている人の名前を表示\r\n"
    "するのかどうかを決める。";
