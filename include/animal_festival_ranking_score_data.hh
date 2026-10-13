#ifndef ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH
#define ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH

#include "prelude.h"

// Ten gauge-limit tiers, each with ten NPC opponent base scores. The native
// rows cover gauge-limit values 0..250; the original lookup is unchecked.
extern u16 const gAnimalFestivalRankingScoreTable[10][10];
extern char const gCppRuntimeBadAlloc_AnimalFestivalRankingScoreData[];

// These native-code tables are kept flat until their axes are decompiled.
extern u8 const gUnk_080FA246[];
extern u8 const gUnk_080FA264[];
extern u8 const gUnk_080FA2E8[];
extern u16 const gUnk_080FA36C[];
extern u8 const gAnimalFestivalRewardChanceWeights[];
extern u32 const gAnimalFestivalRewardArticleIds[];

#endif // ANIMAL_FESTIVAL_RANKING_SCORE_DATA_HH
