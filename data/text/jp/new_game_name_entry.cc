#include "new_game_name_entry_text.hh"

char const gNewGameNameEntryCharacterRows[18][31] SECTION(".rodata.new_game_name_entry_characters") ALIGN(1) = {
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

// The JP name-entry screen indexes this one-indexed table with index × 13.
// Keeping the rows fixed-width preserves the original full-width padding and
// the metadata lookup base located 14 bytes before the first valid entry.
u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue
    SECTION(".rodata.new_game_name_entry_preset_animal_names_runtime") =
        0x20;

char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[]
    SECTION(".rodata.new_game_name_entry_preset_animal_names_runtime") =
        "bad_alloc";

char const gText_NameEntry_PresetAnimalNames[30][13] SECTION(".rodata.name_entry_preset_animal_names") ALIGN(1) = {
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
