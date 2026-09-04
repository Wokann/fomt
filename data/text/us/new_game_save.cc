#include "new_game_save_text.hh"

char const gText_NewGameSave_SaveFailed[16] SECTION(".rodata.new_game_save_text") =
    "Save failed.\x05";

char const gText_NewGameSave_LoadFailed[52] SECTION(".rodata.new_game_save_text") =
    "Load failed.\r\n"
    "The saved data may\r\n"
    "be corrupted.\x05";

char const gText_NewGameSave_LoadPrompt[8] SECTION(".rodata.new_game_save_text") =
    "Load?";

char const gText_NewGameSave_OverwritePrompt[12] SECTION(".rodata.new_game_save_text") =
    "Overwrite?";
