#ifndef ANIMAL_FESTIVAL_RANKING_HH
#define ANIMAL_FESTIVAL_RANKING_HH

#include "prelude.h"

struct AnimalFestivalRankingEntry
{
    u8 animal_index;
    u16 score;
};

extern "C" void CopyAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry const * entries,
    AnimalFestivalRankingEntry * output,
    u32 index);

extern "C" void SetAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry * entries,
    AnimalFestivalRankingEntry const * input,
    u32 index);

#endif // ANIMAL_FESTIVAL_RANKING_HH
