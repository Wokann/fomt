#include "prelude.h"

struct AnimalFestivalRankingEntry
{
    u8 animal_index;
    u16 score;
};

extern "C" void CopyAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry const * entries,
    AnimalFestivalRankingEntry * output,
    u32 index)
    SECTION(".text.copy_animal_festival_ranking_entry");

extern "C" void CopyAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry const * entries,
    AnimalFestivalRankingEntry * output,
    u32 index)
{
    entries += index;
    output->animal_index = entries->animal_index;
    output->score = entries->score;
}

extern "C" void SetAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry * entries,
    AnimalFestivalRankingEntry const * input,
    u32 index)
    SECTION(".text.set_animal_festival_ranking_entry");

extern "C" void SetAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry * entries,
    AnimalFestivalRankingEntry const * input,
    u32 index)
{
    entries += index;
    entries->animal_index = input->animal_index;
    entries->score = input->score;
}
