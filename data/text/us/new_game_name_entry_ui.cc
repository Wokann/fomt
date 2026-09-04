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
