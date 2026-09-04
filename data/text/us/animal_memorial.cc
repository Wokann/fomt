#include "animal_memorial_text.hh"

// The hard-coded animal memorial message is assembled from these pieces.
char const gText_AnimalMemorial_LineBreak[] SECTION(".rodata.animal_memorial") =
    "\r\n";

char const gText_AnimalMemorial_Continue[] SECTION(".rodata.animal_memorial") =
    "{Press}";

char const gText_AnimalMemorial_PageBreak[] SECTION(".rodata.animal_memorial") =
    "\p";

char const gText_AnimalMemorial_Header[] SECTION(".rodata.animal_memorial") =
    "Today, an animal/animals";

char const gText_AnimalMemorial_FarmPrefix[] SECTION(".rodata.animal_memorial") =
    "from ";

char const gText_AnimalMemorial_FarmSuffix[] SECTION(".rodata.animal_memorial") =
    " Farm";

char const gText_AnimalMemorial_PassedAway[] SECTION(".rodata.animal_memorial") =
    "passed away.";

char const gText_AnimalMemorial_NamesIntro[] SECTION(".rodata.animal_memorial") =
    "These are their names.";

char const gText_AnimalMemorial_PrayerIntro[] SECTION(".rodata.animal_memorial") =
    "Let us all pray for their";

char const gText_AnimalMemorial_PrayerEnding[] SECTION(".rodata.animal_memorial") =
    "everlasting peace.";
