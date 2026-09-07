#ifndef ANIMAL_FESTIVAL_RANKING_HH
#define ANIMAL_FESTIVAL_RANKING_HH

#include "prelude.h"

// The score-table axes remain native-code work; the storage order is exact.
extern u16 const gAnimalFestivalRankingScoreTable[];

struct AnimalFestivalRankingEntry
{
    u8 animal_index;
    u16 score;
};

#endif // ANIMAL_FESTIVAL_RANKING_HH
