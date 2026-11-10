#include "animal_festival_ranking.hh"

#include <stdlib.h>

extern u16 const gAnimalFestivalRankingScoreTable[10][10] = {
    { 150, 130, 110, 100, 90, 80, 70, 60, 50, 40 },
    { 190, 180, 170, 160, 150, 140, 130, 120, 110, 100 },
    { 280, 260, 250, 240, 230, 220, 210, 190, 170, 150 },
    { 380, 350, 330, 320, 300, 290, 260, 220, 200, 190 },
    { 450, 430, 410, 400, 390, 380, 360, 320, 300, 260 },
    { 510, 500, 480, 450, 410, 400, 390, 380, 360, 300 },
    { 600, 580, 560, 500, 460, 450, 440, 400, 390, 380 },
    { 650, 640, 630, 600, 590, 580, 550, 530, 490, 450 },
    { 710, 700, 690, 650, 630, 600, 590, 580, 550, 520 },
    { 850, 800, 790, 750, 740, 710, 690, 680, 650, 630 },
};

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
