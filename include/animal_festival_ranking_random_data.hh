#ifndef ANIMAL_FESTIVAL_RANKING_RANDOM_DATA_HH
#define ANIMAL_FESTIVAL_RANKING_RANDOM_DATA_HH

#include "prelude.h"

struct AnimalFestivalRandomRangePair
{
    u32 first_minimum;
    u32 first_maximum;
    u32 second_minimum;
    u32 second_maximum;
};

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[];

#endif // ANIMAL_FESTIVAL_RANKING_RANDOM_DATA_HH
