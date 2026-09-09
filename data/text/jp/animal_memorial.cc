#include "animal_memorial_text.hh"

#ifndef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE
#define FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE
#define FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE_LOCAL
#endif

// The hard-coded animal memorial message is assembled from these pieces.
char const gText_AnimalMemorial_LineBreak[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "\r\n";

char const gText_AnimalMemorial_Continue[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "{Press}";

char const gText_AnimalMemorial_PageBreak[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "\p";

char const gText_AnimalMemorial_Header[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "今日";

char const gText_AnimalMemorial_FarmPrefix[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "牧場の動物が";

char const gText_AnimalMemorial_PassedAway[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "病気で死にました。";

char const gText_AnimalMemorial_NamesIntro[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "今から名前を読み上げます。";

char const gText_AnimalMemorial_PrayerIntro[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "ここにいるみんなで";

char const gText_AnimalMemorial_PrayerEnding[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "めいふくをいのりましょう。";

char const gText_AnimalMemorial_PassedNaturalLife[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "天寿をまっとうしました。";

char const gCppRuntimeBadAlloc_AnimalMemorial[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "bad_alloc";
char const gCppRuntimeError_AnimalMemorial[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "Error";
char const gText_AnimalMemorialFallbackNone[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "なし";

#ifdef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE
#endif
