#include "new_game_name_entry_ui_text.hh"

// The native US name-entry UI iterates over the first thirteen codes. Keep
// the remaining original zero slots in this one table rather than treating
// them as an unrelated padding array.
extern u16 const gNewGameNameEntryUiCharacterCodes[]
    SECTION(".rodata.name_entry_ui_character_codes") = {
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036,
    0x0037, 0x0038, 0x0039, 0x002E, 0x006D, 0x0023,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

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
