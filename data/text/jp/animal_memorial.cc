#include "animal_memorial_text.hh"

// The hard-coded animal memorial message is assembled from these pieces.
char const gText_AnimalMemorial_LineBreak[] SECTION(".rodata.animal_memorial") =
    "\r\n";

char const gText_AnimalMemorial_Continue[] SECTION(".rodata.animal_memorial") =
    "{Press}";

char const gText_AnimalMemorial_PageBreak[] SECTION(".rodata.animal_memorial") =
    "\p";

char const gText_AnimalMemorial_Header[] SECTION(".rodata.animal_memorial") =
    "今日";

char const gText_AnimalMemorial_FarmPrefix[] SECTION(".rodata.animal_memorial") =
    "牧場の動物が";

char const gText_AnimalMemorial_PassedAway[] SECTION(".rodata.animal_memorial") =
    "病気で死にました。";

char const gText_AnimalMemorial_NamesIntro[] SECTION(".rodata.animal_memorial") =
    "今から名前を読み上げます。";

char const gText_AnimalMemorial_PrayerIntro[] SECTION(".rodata.animal_memorial") =
    "ここにいるみんなで";

char const gText_AnimalMemorial_PrayerEnding[] SECTION(".rodata.animal_memorial") =
    "めいふくをいのりましょう。";

char const gText_AnimalMemorial_PassedNaturalLife[28] SECTION(".rodata.animal_memorial") =
    "天寿をまっとうしました。";
