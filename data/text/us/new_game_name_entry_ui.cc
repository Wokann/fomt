#include "new_game_name_entry_ui_text.hh"

char const gText_NewGameNameEntry_Placeholder[16] SECTION(".rodata.new_game_name_entry_ui") =
    "____________";

char const gText_NewGameNameEntry_NameLabel[8] SECTION(".rodata.new_game_name_entry_ui") =
    "Name  ";

// The two End entries reserve the same twenty on-screen cells for their
// respective half-width and full-width character pages.
char const gText_NewGameNameEntry_EndLatin[24] SECTION(".rodata.new_game_name_entry_ui") =
    "          "
    "          "
    "End";

char const gText_NewGameNameEntry_EndFullWidth[24] SECTION(".rodata.new_game_name_entry_ui") =
    "　　　　　"
    "　　　　　"
    "End";

char const gText_NewGameNameEntry_Confirm[24] SECTION(".rodata.new_game_name_entry_ui") =
    "Is this name correct?";

char const gText_NewGameNameEntry_Yes[4] SECTION(".rodata.new_game_name_entry_ui") =
    "Yes";

char const gText_NewGameNameEntry_No[4] SECTION(".rodata.new_game_name_entry_ui") =
    "No";

char const gCppRuntimeBadAlloc_NewGameNameEntryUi00[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi01[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi02[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi03[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi04[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi05[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi06[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi07[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi08[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi09[]
    SECTION(".rodata.new_game_name_entry_ui_trailer") ALIGN(4) =
        "bad_alloc";
