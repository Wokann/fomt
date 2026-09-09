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
    "Today, an animal/animals";

char const gText_AnimalMemorial_FarmPrefix[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "from ";

char const gText_AnimalMemorial_FarmSuffix[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    " Farm";

char const gText_AnimalMemorial_PassedAway[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "passed away.";

char const gText_AnimalMemorial_NamesIntro[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "These are their names.";

char const gText_AnimalMemorial_PrayerIntro[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "Let us all pray for their";

char const gText_AnimalMemorial_PrayerEnding[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "everlasting peace.";

char const gCppRuntimeBadAlloc_AnimalMemorial[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "bad_alloc";
char const gCppRuntimeError_AnimalMemorial[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "Error";
char const gText_AnimalMemorialFallbackNone[] FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE =
    "N/A ";

#ifdef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE_LOCAL
#undef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE
#endif
