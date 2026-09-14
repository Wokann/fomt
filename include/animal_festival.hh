#ifndef ANIMAL_FESTIVAL_HH
#define ANIMAL_FESTIVAL_HH

#include "prelude.h"

struct AnimalFestivalRandomRangePair
{
    u32 first_minimum;
    u32 first_maximum;
    u32 second_minimum;
    u32 second_maximum;
};

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[];

enum
{
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT = 40,
    ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH = 13,
};

// Direct-indexed fixed-width rows, not a pointer table.
extern char const gCppRuntimeBadAlloc_AnimalFestivalLivestockContestantNames[];
extern char const gText_AnimalFestival_LivestockContestantNames[ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT][ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_WIDTH];

// Native code indexes each contestant row as four unclassified byte values.
extern u8 const gAnimalFestivalLivestockContestantValues[][4];

#endif // ANIMAL_FESTIVAL_HH
