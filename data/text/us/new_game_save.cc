#include "new_game_save_text.hh"

char const gText_NewGameSave_SaveFailed[] =
    "Save failed.\x05";

char const gText_NewGameSave_LoadFailed[] ALIGN(4) =
    "Load failed.\r\n"
    "The saved data may\r\n"
    "be corrupted.\x05";

char const gText_NewGameSave_LoadPrompt[] ALIGN(4) =
    "Load?";

char const gText_NewGameSave_OverwritePrompt[] ALIGN(4) =
    "Overwrite?";

char const gCppRuntimeBadAlloc_NewGameSave[] =
    "bad_alloc";
char const gCppRuntimeError_NewGameSave[] ALIGN(4) =
    "Error";
