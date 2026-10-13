#ifndef ANIMAL_FESTIVAL_RANKING_HH
#define ANIMAL_FESTIVAL_RANKING_HH

#include "prelude.h"

struct AnimalFestivalRankingEntry
{
    u8 animal_index;
    u16 score;
};

// The save image's ten NPC opponent records use this same layout. The byte
// between animal_index and score is padding, not a third initialized field.
typedef char AnimalFestivalRankingEntrySizeCheck[sizeof(AnimalFestivalRankingEntry) == 4 ? 1 : -1];
typedef char AnimalFestivalRankingEntryScoreCheck[offsetof(AnimalFestivalRankingEntry, score) == 2 ? 1 : -1];

// Saved at +0x2C4C. Generate rejects duplicate IDs against all ten records,
// including old records not yet replaced; it does not clear storage first.
struct AnimalFestivalOpponents
{
    void Generate(u32 gauge_limit);

    AnimalFestivalRankingEntry entries[10];
};

typedef char AnimalFestivalOpponentsSizeCheck[sizeof(AnimalFestivalOpponents) == 40 ? 1 : -1];

extern "C" void CopyAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry const * entries,
    AnimalFestivalRankingEntry * output,
    u32 index);

extern "C" void SetAnimalFestivalRankingEntry(
    AnimalFestivalRankingEntry * entries,
    AnimalFestivalRankingEntry const * input,
    u32 index);

#endif // ANIMAL_FESTIVAL_RANKING_HH
