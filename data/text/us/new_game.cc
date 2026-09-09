#include "new_game_status_text.hh"
#include "new_game_help_text.hh"
#include "new_game_save_text.hh"
#include "new_game_identity_text.hh"
#include "new_game_name_entry_text.hh"
#include "new_game_name_entry_ui_text.hh"

#if !defined(FOMT_NEW_GAME_TEXT_PRESET)

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[] =
    "Years";

char const gText_NewGameStatus_SeasonSeparator[] ALIGN(4) =
    " ";

char const gText_NewGameStatus_DaySuffix[] ALIGN(4) =
    " Day";

char const gText_NewGameStatus_OpenParen[] ALIGN(4) =
    " (";

char const gText_NewGameStatus_CloseParen[] ALIGN(4) =
    ")";

char const gText_NewGameStatus_FarmSuffix[] ALIGN(4) =
    " Farm";

char const gText_NewGameStatus_ReadDiary[] ALIGN(4) =
    "Read diary.";

char const gText_NewGameStatus_WriteDiary[] ALIGN(4) =
    "Write in diary.";

char const gText_NewGameStatus_NoSavedData[] ALIGN(4) =
    "There is no saved data.";

char const gText_NewGameHelp_Controls[] =
    "Controls        1       2\r\n"
    "Control Pad     Walk    Run\r\n"
    "R Button        Run     Walk";

char const gText_NewGameHelp_ClockDisplay[] ALIGN(4) =
    "Show or hide the Clock \r\n"
    "in the Map Window";

char const gText_NewGameHelp_FaceDisplay[] ALIGN(4) =
    "Show or hide the face of \r\n"
    "the person you're talking\r\n"
    "to in the Message Window\x05";

char const gText_NewGameHelp_NameDisplay[] ALIGN(4) =
    "Show or hide the name of \r\n"
    "the person you're talking\r\n"
    "to in the Message Window\x05";

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

char const gText_NewGameIdentity_PlayerPrefix[] =
    "Your  ";

char const gText_NewGameIdentity_FarmPrefix[] ALIGN(4) =
    "Farm's";

char const gText_NewGameIdentity_DogPrefix[] ALIGN(4) =
    "Dog's ";

char const gCppRuntimeBadAlloc_NewGameIdentityPrefix[] ALIGN(4) =
    "bad_alloc";

char const gText_NewGameIdentity_PlayerName[] ALIGN(4) =
    "Your name     ";

char const gText_NewGameIdentity_PlayerBirthday[] ALIGN(4) =
    "Your birthday ";

char const gText_NewGameIdentity_FarmName[] ALIGN(4) =
    "Farm name     ";

char const gText_NewGameIdentity_DogName[] ALIGN(4) =
    "Dog's name    ";

char const gText_NewGameIdentity_Confirm[] ALIGN(4) =
    "Is this OK?";

char const gText_NewGameIdentity_Yes[] ALIGN(4) =
    "Yes";

char const gText_NewGameIdentity_No[] ALIGN(4) =
    "No";

char const gCppRuntimeBadAlloc_NewGameIdentityLabels[] ALIGN(4) =
    "bad_alloc";

char const gNewGameNameEntryCharacterRows[18][31] ALIGN(1) = {
    // Latin keyboard.
    "A B C D E F G H I J K L M N O ",
    "P Q R S T U V W X Y Z o \xB6 \xB7 % ",
    "a b c d e f g h i j k l m n o ",
    "p q r s t u v w x y z ' . \xA5 * ",
    "0 1 2 3 4 5 6 7 8 9 + - x ~ / ",
    "< > ( ) \xA2 \xA3 & ! ? \xB1 \xB2 \xB3 \xB4     ",

    // Full-width keyboard, retained twice as stored in the US ROM.
    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？♀♂♪♡　　",

    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？♀♂♪♡　　",
};

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

char const gCppRuntimeBadAlloc_NewGameNameEntryUi00[] =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi01[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi02[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi03[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi04[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi05[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi06[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi07[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi08[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_NewGameNameEntryUi09[] ALIGN(4) =
    "bad_alloc";

#else

// The US animal-name selection is a one-indexed, fixed-stride list.  Each
// string remains in its original 14-byte row so the native index × 14 lookup
// and its full-width display-space padding remain exact.
u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue =
    0x20;

char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[] =
    "bad_alloc";

char const gText_NameEntry_PresetAnimalNames[30][14] ALIGN(1) = {
    "Fido",
    "Sox",
    "Sam",
    "Lady　",
    "Princess　",
    "Ginger　　",
    "Max　　　　",
    "Sam　　",
    "Rocky",
    "Buster　　　",
    "Charlie",
    "Rusty　　",
    "Zoe",
    "Daisy　",
    "Molly　　　",
    "Jess　　",
    "Tricky　　　",
    "Brewster　　",
    "Isis　",
    "Myst　　",
    "Amanda",
    "Amber　　",
    "Panda　",
    "Angel　　　　",
    "Fifi　　",
    "Echo　　　　",
    "Nic",
    "Quartz",
    "Betty",
    "Gertrude　",
};

#endif
