#include "animal_festival_ranking.hh"
#include "animal_festival_ranking_score_data.hh"

#include <stdlib.h>

// The caller extracts Dog::frisbee_gauge_limit, not the calendar year. Keep
// the original unchecked tier lookup and signed rand() >> 8 arithmetic.
void AnimalFestivalOpponents::Generate(u32 gauge_limit)
{
    u32 tier;
    if (gauge_limit != 0)
        tier = (gauge_limit - 1) / 25;
    else
        tier = 0;

    for (int i = 0; i <= 9; ++i) {
        bool unique;
        do {
            entries[i].animal_index = (rand() >> 8) % 30 + 1;
            unique = true;
            for (int j = 0; j <= 9; ++j) {
                if (i != j && entries[i].animal_index == entries[j].animal_index)
                    unique = false;
            }
        } while (!unique);

        entries[i].score = gAnimalFestivalRankingScoreTable[tier][i]
            + (rand() >> 8) % 10;
    }
}

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
{
    entries += index;
    entries->animal_index = input->animal_index;
    entries->score = input->score;
}
