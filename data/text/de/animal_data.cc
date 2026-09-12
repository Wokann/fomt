#include "animal_data.hh"

// The hard-coded animal memorial message is assembled from these pieces.
char const gText_AnimalMemorial_LineBreak[] =
    "\r\n";

char const gText_AnimalMemorial_Continue[] =
    "{Press}";

char const gText_AnimalMemorial_PageBreak[] =
    "\p";

char const gText_AnimalMemorial_Header[] =
    "Tiere der Farm an einer";

char const gText_AnimalMemorial_FarmPrefix[] =
    "Krankheit";

// The German disease-message routine has no suffix between the farm name and
// its final sentence.  This ordinary empty string occupies the original
// alignment byte; it is not an assembler alias.
char const gText_AnimalMemorial_FarmSuffix[] ALIGN(1) =
    "";

char const gText_AnimalMemorial_PassedAway[] =
    "Tiere der Farm.";

char const gText_AnimalMemorial_NamesIntro[] =
    "Dies sind ihre Namen.";

char const gText_AnimalMemorial_PrayerIntro[] =
    "Lasst uns alle für ihren";

char const gText_AnimalMemorial_PrayerEnding[] =
    "ewigen Frieden beten.";

// The second German routine uses its own pair of source strings.  Its
// pointer table is structurally different from the first one in the ROM.
char const gText_AnimalMemorial_DeathHeader[] =
    "Heute starb/en ein Tier/";

char const gText_AnimalMemorial_DeathFarmPrefix[] =
    "Tiere Farm.";

char const gCppRuntimeBadAlloc_AnimalMemorial[] =
    "bad_alloc";
char const gCppRuntimeError_AnimalMemorial[] =
    "Error";
char const gText_AnimalMemorialFallbackNone[] =
    "N/A ";
