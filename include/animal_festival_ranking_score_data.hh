#ifndef ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH
#define ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH

#include "prelude.h"

// The score-table axes remain native-code work; the storage order is exact.
extern u16 const gAnimalFestivalRankingScoreTable[];
extern char const gCppRuntimeBadAlloc_AnimalFestivalRankingScoreData[];

// These native-code tables are kept flat until their axes are decompiled.
extern u8 const gUnk_080FA246[];
extern u8 const gUnk_080FA264[];
extern u8 const gUnk_080FA2E8[];
extern u16 const gUnk_080FA36C[];
extern u8 const gAnimalFestivalRewardChanceWeights[];
extern u32 const gAnimalFestivalRewardArticleIds[];

#endif // ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH
