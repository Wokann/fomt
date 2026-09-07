#include "chicken_festival_text.hh"

// Direct-indexed chicken-festival contestant names. The fixed 13-byte rows
// retain the original US display-space padding.

char const gText_ChickenFestival_ContestantNames[20][13] SECTION(".rodata.chicken_festival_contestant_names") ALIGN(1) = {
    "Saber",
    "Homer",
    "Beowolf",
    "Bones",
    "Sarge",
    "Hawkeye",
    "Shamus",
    "Bruno",
    "Sharpy",
    "Buzz",
    "Junior",
    "Byron",
    "King",
    "Caesar",
    "Kellog",
    "Skip",
    "Cash",
    "Lioin",
    "Lance",
    "Spike"
};
