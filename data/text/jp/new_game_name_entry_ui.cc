#include "new_game_name_entry_ui_text.hh"

// The native name-entry path reads the first thirteen glyph codes.  The
// declared capacity preserves its seven trailing zero slots as part of this
// fixed table, rather than treating them as an unrelated padding array.
u16 const gNewGameNameEntryUiCharacterCodes[20]
    SECTION(".rodata.name_entry_ui_character_codes") =
    FOMT_GLYPH_SEQUENCE("０１２３４５６７８９．ｍ位");

char const gText_NewGameNameEntry_Placeholder[16] SECTION(".rodata.new_game_name_entry_ui") =
    "＿＿＿＿＿＿";

char const gText_NewGameNameEntry_NameLabel[8] SECTION(".rodata.new_game_name_entry_ui") =
    "なまえ";

char const gText_NewGameNameEntry_ModeKatakana[28] SECTION(".rodata.new_game_name_entry_ui") =
    "カナ　　　記号　　　終了";

char const gText_NewGameNameEntry_ModeSymbols[28] SECTION(".rodata.new_game_name_entry_ui") =
    "記号　　　かな　　　終了";

char const gText_NewGameNameEntry_ModeHiragana[28] SECTION(".rodata.new_game_name_entry_ui") =
    "かな　　　カナ　　　終了";

char const gText_NewGameNameEntry_Confirm[20] SECTION(".rodata.new_game_name_entry_ui") =
    "この名前でいい？";

char const gText_NewGameNameEntry_Yes[8] SECTION(".rodata.new_game_name_entry_ui") =
    "はい";

char const gText_NewGameNameEntry_No[8] SECTION(".rodata.new_game_name_entry_ui") =
    "いいえ";

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
