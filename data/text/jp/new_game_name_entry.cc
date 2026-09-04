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
