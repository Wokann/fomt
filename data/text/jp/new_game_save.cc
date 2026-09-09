#include "new_game_save_text.hh"

char const gText_NewGameSave_SaveFailed[] =
    "セーブに失敗しました。\x05";

char const gText_NewGameSave_LoadFailed[] ALIGN(4) =
    "ロードに失敗しました\r\n"
    "セーブデータが壊れてるっぽい\x05";

char const gText_NewGameSave_LoadPrompt[] ALIGN(4) =
    "ロードしていい？";

char const gText_NewGameSave_Affirmative[] ALIGN(4) =
    "はい";

char const gText_NewGameSave_Negative[] ALIGN(4) =
    "いいえ";

char const gText_NewGameSave_OverwritePrompt[] ALIGN(4) =
    "上書きしていい？";

char const gCppRuntimeBadAlloc_NewGameSave[] =
    "bad_alloc";
char const gCppRuntimeError_NewGameSave[] ALIGN(4) =
    "Error";
