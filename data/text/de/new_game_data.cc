#include "new_game_data.hh"

char const gText_NewGameMenu_Diary[] =
    "Tagebuch";

char const gText_NewGameMenu_Save[] ALIGN(4) =
    "Spch.";

char const gText_NewGameMenu_Load[] ALIGN(4) =
    "Laden";

char const gText_NewGameMenu_Blank[] ALIGN(4) =
    "";

char const gText_NewGameMenu_Data1[] ALIGN(4) =
    "Dat.1";

char const gText_NewGameMenu_Data2[] ALIGN(4) =
    "Dat.2";

char const gText_NewGameMenu_ControlSettings[] ALIGN(4) =
    "Knöpfe";

char const gText_NewGameMenu_ControlOption1[] ALIGN(4) =
    "1";

char const gText_NewGameMenu_ControlOption2[] ALIGN(4) =
    "2";

char const gText_NewGameMenu_ClockDisplay[] ALIGN(4) =
    "Uhr";

char const gText_NewGameMenu_Yes[] ALIGN(4) =
    "Ja";

char const gText_NewGameMenu_No[] ALIGN(4) =
    "Nein";

char const gText_NewGameMenu_FaceDisplay[] ALIGN(4) =
    "Gesicht";

char const gText_NewGameMenu_NameDisplay[] ALIGN(4) =
    "Name";

// Native menu order.  The US ROM stores two dedicated control-option strings,
// unlike the JP aliases used for the corresponding two entries.
char const * const gNewGameMenuLabels[18] = {
    gText_NewGameMenu_Diary,
    gText_NewGameMenu_Save,
    gText_NewGameMenu_Load,
    gText_NewGameMenu_Blank,
    gText_NewGameMenu_Data1,
    gText_NewGameMenu_Data2,
    gText_NewGameMenu_ControlSettings,
    gText_NewGameMenu_ControlOption1,
    gText_NewGameMenu_ControlOption2,
    gText_NewGameMenu_ClockDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
    gText_NewGameMenu_FaceDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
    gText_NewGameMenu_NameDisplay,
    gText_NewGameMenu_Yes,
    gText_NewGameMenu_No,
};

// Fixed-width fragments copied by the new-game status renderer and its
// save-data prompts.  C++ array initialization preserves the zero-fill.
char const gText_NewGameStatus_YearSuffix[] =
    "Jahre";

char const gText_NewGameStatus_SeasonSeparator[] ALIGN(4) =
    " ";

char const gText_NewGameStatus_DaySuffix[] ALIGN(4) =
    " Tag";

char const gText_NewGameStatus_OpenParen[] ALIGN(4) =
    " (";

char const gText_NewGameStatus_CloseParen[] ALIGN(4) =
    ")";

char const gText_NewGameStatus_FarmSuffix[] ALIGN(4) =
    " Farm";

char const gText_NewGameStatus_ReadDiary[] ALIGN(4) =
    "Tagebuch lesen";

char const gText_NewGameStatus_WriteDiary[] ALIGN(4) =
    "Ins Tagebuch schreiben";

char const gText_NewGameStatus_NoSavedData[] ALIGN(4) =
    "Es gibt keine\r\n"
    "gespeicherten Daten.";

char const gText_NewGameHelp_Controls[] =
    "Steuerung      1      2\r\n"
    "Steuerkreuz    Gehen  Rennen\r\n"
    "Knopf R        Rennen Gehen";

char const gText_NewGameHelp_ClockDisplay[] ALIGN(4) =
    "Uhr im Kartenfenster \r\n"
    "anzeigen oder verbergen{Press}";

char const gText_NewGameHelp_FaceDisplay[] ALIGN(4) =
    "Das Gesicht der Person, mit\r\n"
    "der du sprichst, im Fenster\r\n"
    "anzeigen oder verbergen.{Press}";

char const gText_NewGameHelp_NameDisplay[] ALIGN(4) =
    "Den Namen der Person, mit \r\n"
    "der du sprichst, im Fenster\r\n"
    "anzeigen oder verbergen.{Press}";

char const gText_NewGameSave_SaveFailed[] =
    "Speichern fehlgeschlagen.{Press}";

char const gText_NewGameSave_LoadFailed[] ALIGN(4) =
    "Laden fehlgeschlagen.\r\n"
    "Die gespeicherten Daten\r\n"
    "könnten korrupt sein.{Press}";

char const gText_NewGameSave_LoadPrompt[] ALIGN(4) =
    "Laden?";

char const gText_NewGameSave_OverwritePrompt[] ALIGN(4) =
    "Überschreiben?";

char const gCppRuntimeBadAlloc_NewGameSave[] =
    "bad_alloc";
char const gCppRuntimeError_NewGameSave[] ALIGN(4) =
    "Error";

char const gText_NewGameIdentity_PlayerPrefix[] =
    "Dein  ";

char const gText_NewGameIdentity_FarmPrefix[] ALIGN(4) =
    "der Farm";

char const gText_NewGameIdentity_DogPrefix[] ALIGN(4) =
    "d. Hundes";

char const gCppRuntimeBadAlloc_NewGameIdentityPrefix[] ALIGN(4) =
    "bad_alloc";

char const gText_NewGameIdentity_PlayerName[] ALIGN(4) =
    "Dein Name     ";

char const gText_NewGameIdentity_PlayerBirthday[] ALIGN(4) =
    "Dein Geburtst.";

char const gText_NewGameIdentity_FarmName[] ALIGN(4) =
    "Name der Farm ";

char const gText_NewGameIdentity_DogName[] ALIGN(4) =
    "Hundname      ";

char const gText_NewGameIdentity_Confirm[] ALIGN(4) =
    "Ist das OK?";

char const gText_NewGameIdentity_Yes[] ALIGN(4) =
    "Ja";

char const gText_NewGameIdentity_No[] ALIGN(4) =
    "Nein";

char const gCppRuntimeBadAlloc_NewGameIdentityLabels[] ALIGN(4) =
    "bad_alloc";

char const gNewGameNameEntryCharacterRows[21][31] ALIGN(1) = {
    // Latin keyboard.
    "A B C D E F G H I J K L M N O ",
    "P Q R S T U V W X Y Z o \xB6 \xB7 % ",
    "a b c d e f g h i j k l m n o ",
    "p q r s t u v w x y z ' . \xA5 * ",
    "0 1 2 3 4 5 6 7 8 9 + - x ~ / ",
    "< > ( ) \xA2 \xA3 & ! ? \xB1 \xB2 \xB3 \xB4 ä ü ",
    "ö ß Ä Ö Ü                     ",

    // Full-width keyboard, retained twice as stored in the US ROM.
    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？\x81\x8A\x81\x89\x81\xF4\x81\xCD　　",
    "",

    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？\x81\x8A\x81\x89\x81\xF4\x81\xCD　　",
    "",
};

char const gText_NewGameNameEntry_Placeholder[] =
    "____________";

char const gText_NewGameNameEntry_NameLabel[] ALIGN(4) =
    "Name  ";

// The DE keyboard stores one Latin end label after its three seven-row pages.
char const gText_NewGameNameEntry_EndLatin[] ALIGN(4) =
    "          "
    "          "
    "Ende";

char const gText_NewGameNameEntry_Confirm[] ALIGN(4) =
    "Ist dieser Name richtig?";

char const gText_NewGameNameEntry_Yes[] ALIGN(4) =
    "Ja";

char const gText_NewGameNameEntry_No[] ALIGN(4) =
    "Nein";

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
