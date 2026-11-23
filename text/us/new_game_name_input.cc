NewGameNameEntryCharacterTable const gNewGameNameEntryCharacterRows ALIGN(1) = {{
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
    "＜＞（）「」＆！？\x81\x8A\x81\x89\x81\xF4\x81\xCD　　",

    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ",
    "ＰＱＲＳＴＵＶＷＸＹＺ○☆★％",
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏ",
    "ｐｑｒｓｔｕｖｗｘｙｚ’．·＊",
    "０１２３４５６７８９＋－×～／",
    "＜＞（）「」＆！？\x81\x8A\x81\x89\x81\xF4\x81\xCD　　",
}};

extern char const gText_NewGameNameEntry_Placeholder[] =
    "____________";

extern char const gText_NewGameNameEntry_NameLabel[] ALIGN(4) =
    "Name  ";

extern char const gText_NewGameNameEntry_EndLatin[] ALIGN(4) =
    "          "
    "          "
    "End";

extern char const gText_NewGameNameEntry_EndFullWidth[] ALIGN(4) =
    "　　　　　"
    "　　　　　"
    "End";

extern char const gText_NewGameNameEntry_Confirm[] ALIGN(4) =
    "Is this name correct?";

extern char const gText_NewGameNameEntry_Yes[] ALIGN(4) =
    "Yes";

extern char const gText_NewGameNameEntry_No[] ALIGN(4) =
    "No";
