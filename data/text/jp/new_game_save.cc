#include "new_game_save_text.hh"

char const gText_NewGameSave_SaveFailed[24] SECTION(".rodata.new_game_save_text") =
    "セーブに失敗しました。\x05";

char const gText_NewGameSave_LoadFailed[52] SECTION(".rodata.new_game_save_text") =
    "ロードに失敗しました\r\n"
    "セーブデータが壊れてるっぽい\x05";

char const gText_NewGameSave_LoadPrompt[20] SECTION(".rodata.new_game_save_text") =
    "ロードしていい？";

char const gText_NewGameSave_Affirmative[8] SECTION(".rodata.new_game_save_text") =
    "はい";

char const gText_NewGameSave_Negative[8] SECTION(".rodata.new_game_save_text") =
    "いいえ";

char const gText_NewGameSave_OverwritePrompt[20] SECTION(".rodata.new_game_save_text") =
    "上書きしていい？";

char const gCppRuntimeBadAlloc_NewGameSave[]
    SECTION(".rodata.new_game_save_trailer") =
        "bad_alloc";
char const gCppRuntimeError_NewGameSave[]
    SECTION(".rodata.new_game_save_trailer") ALIGN(4) =
        "Error";
