#include "new_game_name_entry_ui_text.hh"

// The native name-entry path reads the first thirteen glyph codes.  The
// declared capacity preserves its eight trailing zero slots as part of this
// fixed table, rather than treating them as an unrelated padding array.
u16 const gNewGameNameEntryUiCharacterCodes[21]
    SECTION(".rodata.name_entry_ui_character_codes") =
    FOMT_GLYPH_SEQUENCE("0123456789.m#");

char const gText_NewGameNameEntry_Placeholder[] =
    "____________";

char const gText_NewGameNameEntry_NameLabel[] ALIGN(4) =
    "Name  ";

// The two End entries reserve the same twenty on-screen cells for their
// respective half-width and full-width character pages.
char const gText_NewGameNameEntry_EndLatin[] ALIGN(4) =
    "          "
    "          "
    "End";

char const gText_NewGameNameEntry_EndFullWidth[] ALIGN(4) =
    "　　　　　"
    "　　　　　"
    "End";

char const gText_NewGameNameEntry_Confirm[] ALIGN(4) =
    "Is this name correct?";

char const gText_NewGameNameEntry_Yes[] ALIGN(4) =
    "Yes";

char const gText_NewGameNameEntry_No[] ALIGN(4) =
    "No";
