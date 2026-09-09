#include "animal_festival_ranking.hh"

#include "frisbee_text.hh"
#include "item.hh"

// The still-native animal-festival ranking path reads a halfword from this
// shared score table. The exact axes have not been named yet, so preserve the
// original flat ordering rather than inventing a matrix interpretation.
extern u16 const gAnimalFestivalRankingScoreTable[]
    SECTION(".rodata.animal_festival_ranking_score_table") = {
    150, 130, 110, 100, 90, 80, 70, 60, 50, 40,
    190, 180, 170, 160, 150, 140, 130, 120, 110, 100,
    280, 260, 250, 240, 230, 220, 210, 190, 170, 150,
    380, 350, 330, 320, 300, 290, 260, 220, 200, 190,
    450, 430, 410, 400, 390, 380, 360, 320, 300, 260,
    510, 500, 480, 450, 410, 400, 390, 380, 360, 300,
    600, 580, 560, 500, 460, 450, 440, 400, 390, 380,
    650, 640, 630, 600, 590, 580, 550, 530, 490, 450,
    710, 700, 690, 650, 630, 600, 590, 580, 550, 520,
    850, 800, 790, 750, 740, 710, 690, 680, 650, 630,
};

// This runtime literal follows the ranking score table in the original ROM.
// It is not a separate Frisbee text resource.
char const gCppRuntimeBadAlloc_FrisbeeScoreboard[]
    SECTION(".rodata.animal_festival_ranking_scoreboard_trailer") =
        "bad_alloc";

// These three tables are indexed by still-native festival code. Their exact
// dimensions have not been recovered, so retain the original flat ordering.
extern u8 const gUnk_080FA246[]
    SECTION(".rodata.animal_festival_ranking_data") ALIGN(1) = {
    0x00, 0x32, 0x64, 0x64, 0x64, 0x64, 0x00, 0x0A, 0x64, 0x64,
    0x64, 0x64, 0x00, 0x00, 0x32, 0x64, 0x64, 0x64, 0x00, 0x00,
    0x00, 0x32, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x32, 0x64,
};

extern u8 const gUnk_080FA264[]
    SECTION(".rodata.animal_festival_ranking_data") ALIGN(1) = {
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x02,
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02,
    0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};

extern u8 const gUnk_080FA2E8[]
    SECTION(".rodata.animal_festival_ranking_data") ALIGN(1) = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};

extern u16 const gUnk_080FA36C[]
    SECTION(".rodata.animal_festival_ranking_data") ALIGN(1) = {
    0x0635, 0x0641, 0x064D,
};

// Both arrays are selected with the same native-code index.
extern u8 const gAnimalFestivalRewardChanceWeights[]
    SECTION(".rodata.animal_festival_ranking_data") ALIGN(1) = {
    3, 10, 10, 15, 20, 20, 12, 10,
};

extern u32 const gAnimalFestivalRewardArticleIds[]
    SECTION(".rodata.animal_festival_ranking_reward_article_ids") ALIGN(4) = {
    ARTICLE_FOSSIL_OF_FISH,
    ARTICLE_AGATE,
    ARTICLE_GOLD,
    ARTICLE_SILVER,
    ARTICLE_COPPER,
    ARTICLE_BRANCHES,
    ARTICLE_FISH_BONES,
    ARTICLE_EMPTY_CAN,
};

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[]
    SECTION(".rodata.animal_festival_ranking_random_range_pairs") ALIGN(4) = {
    { 0, 250, 0, 250 },
    { 0, 90, 0, 250 },
    { 150, 250, 0, 250 },
    { 100, 149, 0, 250 },
    { 0, 70, 0, 250 },
    { 100, 250, 0, 250 },
    { 0, 250, 0, 250 },
};

extern u8 const gAnimalFestivalLivestockContestantValues[][4]
    SECTION(".rodata.animal_festival_livestock_contestant_values") ALIGN(1) = {
    { 70, 80, 40, 90 },
    { 30, 20, 40, 40 },
    { 20, 20, 20, 20 },
    { 100, 100, 100, 100 },
    { 30, 40, 40, 40 },
    { 0, 100, 0, 0 },
    { 70, 90, 90, 70 },
    { 20, 30, 30, 50 },
    { 10, 50, 70, 20 },
    { 40, 70, 50, 50 },
    { 30, 60, 40, 70 },
    { 40, 50, 30, 30 },
    { 100, 0, 0, 0 },
    { 60, 70, 60, 70 },
    { 10, 40, 20, 20 },
    { 0, 60, 60, 0 },
    { 20, 30, 50, 30 },
    { 40, 0, 30, 40 },
    { 0, 50, 0, 50 },
    { 0, 0, 0, 0 },
    { 50, 50, 50, 50 },
    { 60, 50, 40, 50 },
    { 10, 20, 30, 40 },
    { 40, 20, 40, 30 },
    { 0, 30, 10, 20 },
    { 0, 0, 100, 0 },
    { 30, 20, 0, 90 },
    { 0, 0, 0, 100 },
    { 50, 20, 60, 10 },
    { 10, 30, 20, 50 },
    { 20, 40, 20, 40 },
    { 30, 30, 40, 20 },
    { 90, 0, 0, 60 },
    { 70, 20, 40, 30 },
    { 30, 50, 40, 20 },
    { 50, 0, 50, 0 },
    { 20, 70, 40, 30 },
    { 20, 10, 40, 50 },
    { 30, 40, 40, 20 },
    { 60, 10, 40, 80 },
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
