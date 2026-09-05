#ifndef ANIMAL_MEMORIAL_TEXT_HH
#define ANIMAL_MEMORIAL_TEXT_HH

#include "prelude.h"

// The animal memorial system message is assembled from these direct string
// pointers at runtime. The Japanese sentence order needs no FarmSuffix field.
extern char const gText_AnimalMemorial_LineBreak[];
extern char const gText_AnimalMemorial_Continue[];
extern char const gText_AnimalMemorial_PageBreak[];
extern char const gText_AnimalMemorial_Header[];
extern char const gText_AnimalMemorial_FarmPrefix[];
#if !defined(REGION_JP)
extern char const gText_AnimalMemorial_FarmSuffix[];
#endif
extern char const gText_AnimalMemorial_PassedAway[];
extern char const gText_AnimalMemorial_NamesIntro[];
extern char const gText_AnimalMemorial_PrayerIntro[];
extern char const gText_AnimalMemorial_PrayerEnding[];
#if defined(REGION_JP)
extern char const gText_AnimalMemorial_PassedNaturalLife[];
#endif

#endif // ANIMAL_MEMORIAL_TEXT_HH
