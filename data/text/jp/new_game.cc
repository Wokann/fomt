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
    "年目";

char const gText_NewGameStatus_SeasonSeparator[] ALIGN(4) =
    "の月";

char const gText_NewGameStatus_DaySuffix[] ALIGN(4) =
    "日";

char const gText_NewGameStatus_OpenParen[] ALIGN(4) =
    "（";

char const gText_NewGameStatus_CloseParen[] ALIGN(4) =
    "）";

char const gText_NewGameStatus_FarmSuffix[] ALIGN(4) =
    "牧場";

char const gText_NewGameStatus_ReadDiary[] ALIGN(4) =
    "日記を読む";

char const gText_NewGameStatus_WriteDiary[] ALIGN(4) =
    "日記をつける";

char const gText_NewGameStatus_NoSavedData[] ALIGN(4) =
    "セーブデータがありません。";

char const gText_NewGameHelp_Controls[] =
    "操作　　　　その１　その２\r\n"
    "十字ボタン　歩く　　走る\r\n"
    "Ｒボタン　　走る　　歩く";

char const gText_NewGameHelp_ClockDisplay[] ALIGN(4) =
    "マップ画面で時計を表示するの\r\n"
    "かどうかを決める。";

char const gText_NewGameHelp_FaceDisplay[] ALIGN(4) =
    "メッセージウインドウで\r\n"
    "しゃべっている人の顔を表示\r\n"
    "するのかどうかを決める。";

char const gText_NewGameHelp_NameDisplay[] ALIGN(4) =
    "メッセージウインドウで\r\n"
    "しゃべっている人の名前を表示\r\n"
    "するのかどうかを決める。";

char const gText_NewGameSave_SaveFailed[] =
    "セーブに失敗しました。\x05";

char const gText_NewGameSave_LoadFailed[] ALIGN(4) =
    "ロードに失敗しました\r\n"
    "セーブデータが壊れてるっぽい\x05";

char const gText_NewGameSave_LoadPrompt[] ALIGN(4) =
    "ロードしていい？";

char const gText_NewGameSave_Affirmative[] ALIGN(4) =
    "はい";

char const gText_NewGameSave_Negative[] ALIGN(4) =
    "いいえ";

char const gText_NewGameSave_OverwritePrompt[] ALIGN(4) =
    "上書きしていい？";

char const gCppRuntimeBadAlloc_NewGameSave[] =
    "bad_alloc";
char const gCppRuntimeError_NewGameSave[] ALIGN(4) =
    "Error";

char const gText_NewGameIdentity_PlayerPrefix[] =
    "キミの";

char const gText_NewGameIdentity_FarmPrefix[] ALIGN(4) =
    "牧場の";

char const gText_NewGameIdentity_DogPrefix[] ALIGN(4) =
    "犬　の";

char const gCppRuntimeBadAlloc_NewGameIdentityPrefix[] ALIGN(4) =
    "bad_alloc";

char const gText_NewGameIdentity_BirthMonthSuffix[] ALIGN(4) =
    "の月";

char const gText_NewGameIdentity_BirthDaySuffix[] ALIGN(4) =
    "日";

char const gText_NewGameIdentity_PlayerName[] ALIGN(4) =
    "キミのなまえ";

char const gText_NewGameIdentity_PlayerBirthday[] ALIGN(4) =
    "キミの誕生日";

char const gText_NewGameIdentity_FarmName[] ALIGN(4) =
    "牧場のなまえ";

char const gText_NewGameIdentity_DogName[] ALIGN(4) =
    "犬　のなまえ";

char const gText_NewGameIdentity_Confirm[] ALIGN(4) =
    "これでいい？";

char const gText_NewGameIdentity_Yes[] ALIGN(4) =
    "はい";

char const gText_NewGameIdentity_No[] ALIGN(4) =
    "いいえ";

char const gCppRuntimeBadAlloc_NewGameIdentityLabels[] ALIGN(4) =
    "bad_alloc";

char const gNewGameNameEntryCharacterRows[18][31] ALIGN(1) = {
    // Hiragana keyboard.
    "あいうえおまみむめもがぎぐげご",
    "かきくけこや　ゆ　よざじずぜぞ",
    "さしすせそらりるれろだぢづでど",
    "たちつてとわ　を　んばびぶべぼ",
    "なにぬねのゃゅょっーぱぴぷぺぽ",
    "はひふへほぁぃぅぇぉ　　　　　",

    // Katakana keyboard.
    "アイウエオマミムメモガギグゲゴ",
    "カキクケコヤ　ユ　ヨザジズゼゾ",
    "サシスセソラリルレロダヂヅデド",
    "タチツテトワ　ヲ　ンバビブベボ",
    "ナニヌネノャュョッーパピプペポ",
    "ハヒフヘホァィゥェォ　　　　　",

    // Full-width Latin keyboard.
    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？♀♂♪♡　　",
};

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

// The JP name-entry screen indexes this one-indexed table with index × 13.
// Keeping the rows fixed-width preserves the original full-width padding and
// the metadata lookup base located 14 bytes before the first valid entry.
u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue =
    0x20;

char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[] =
    "bad_alloc";

char const gText_NameEntry_PresetAnimalNames[30][13] ALIGN(1) = {
    "アーガイル　",
    "アヴァロン　",
    "アンコロモチ",
    "カタナ　　　",
    "カンデンチ　",
    "さくや　　　",
    "桜丸　　　　",
    "シシオー　　",
    "シャリオン　",
    "ジロー　　　",
    "セラフィック",
    "チョビチ　　",
    "トリスタン　",
    "とんこつ丸　",
    "日輪丸　　　",
    "バウワウ　　",
    "ハナビ　　　",
    "ぷにぷに　　",
    "ブロンディ　",
    "ぽん太　　　",
    "マメタロウ　",
    "マローン　　",
    "モロキュウ　",
    "夜叉　　　　",
    "ゆうなぎ　　",
    "ハナ　　　　",
    "ランブル　　",
    "リーソクツモ",
    "リヴァイアン",
    "ロケッツ　　",
};

#endif
