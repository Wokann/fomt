#include "new_game_name_entry_ui_text.hh"

// The native name-entry path reads the first thirteen glyph codes.  The
// declared capacity preserves its seven trailing zero slots as part of this
// fixed table, rather than treating them as an unrelated padding array.
u16 const gNewGameNameEntryUiCharacterCodes[20]
    SECTION(".rodata.name_entry_ui_character_codes") =
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９．ｍ位");

char const gText_NewGameNameEntry_Placeholder[] =
    "＿＿＿＿＿＿";

char const gText_NewGameNameEntry_NameLabel[] ALIGN(4) =
    "なまえ";

char const gText_NewGameNameEntry_ModeKatakana[] ALIGN(4) =
    "カナ　　　記号　　　終了";

char const gText_NewGameNameEntry_ModeSymbols[] ALIGN(4) =
    "記号　　　かな　　　終了";

char const gText_NewGameNameEntry_ModeHiragana[] ALIGN(4) =
    "かな　　　カナ　　　終了";

char const gText_NewGameNameEntry_Confirm[] ALIGN(4) =
    "この名前でいい？";

char const gText_NewGameNameEntry_Yes[] ALIGN(4) =
    "はい";

char const gText_NewGameNameEntry_No[] ALIGN(4) =
    "いいえ";
