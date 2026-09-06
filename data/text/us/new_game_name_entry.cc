#include "new_game_name_entry_text.hh"

char const gNewGameNameEntryCharacterRows[18][31] SECTION(".rodata.new_game_name_entry_characters") ALIGN(1) = {
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

// The US animal-name selection is a one-indexed, fixed-stride list.  Each
// string remains in its original 14-byte row so the native index × 14 lookup
// and its full-width display-space padding remain exact.
char const gText_NameEntry_PresetAnimalNames[30][14] SECTION(".rodata.name_entry_preset_animal_names") ALIGN(1) = {
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
