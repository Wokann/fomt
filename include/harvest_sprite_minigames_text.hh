#ifndef HARVEST_SPRITE_MINIGAMES_TEXT_HH
#define HARVEST_SPRITE_MINIGAMES_TEXT_HH

#include "prelude.h"

#define HARVEST_SPRITE_MINIGAMES_ANIMAL_HUSBANDRY_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_animal_husbandry")
#define HARVEST_SPRITE_MINIGAMES_CHICKEN_FESTIVAL_OPENING_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_chicken_festival_opening")
#define HARVEST_SPRITE_MINIGAMES_CHICKEN_FESTIVAL_INSTRUCTIONS_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_chicken_festival_instructions")
#define HARVEST_SPRITE_MINIGAMES_HARVEST_INSTRUCTIONS_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_harvest_instructions")
#define HARVEST_SPRITE_MINIGAMES_HARVEST_RESULTS_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_harvest_results")
#define HARVEST_SPRITE_MINIGAMES_WATERING_INSTRUCTIONS_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_watering_instructions")
#define HARVEST_SPRITE_MINIGAMES_WATERING_RESULTS_TEXT \
    SECTION(".rodata.harvest_sprite_minigames_watering_results")

extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Yes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_No[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Introduction[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_FeedingInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ChickenBehaviorInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_WatchInstructions[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_Start[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreSummary[];

#if defined(REGION_US)
extern char const gText_HarvestSpriteMiniGame_AnimalHusbandry_ScoreResultPrefix[];
#endif

extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalRoundAnnouncement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationNo[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_ExplanationYes[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_RoundOneStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_SemiFinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_FinalsStart[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Start[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Stop[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_WinnerSuffix[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Introduction[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Rules[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_Encouragement[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionAtRingEdge[];
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_CautionLeavingRing[];

#if defined(REGION_US)
extern char const gText_HarvestSpriteMiniGame_ChickenFestival_UnderstandAgain[];
#endif

extern char const gText_HarvestSpriteMiniGame_Harvest_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Yes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_No[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_FatigueWarning[];
extern char const gText_HarvestSpriteMiniGame_Harvest_RestInstructions[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Harvest_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Harvest_Start[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreSummary[];

extern char const gText_HarvestSpriteMiniGame_Watering_ExplanationQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_Yes[];
extern char const gText_HarvestSpriteMiniGame_Watering_No[];
extern char const gText_HarvestSpriteMiniGame_Watering_Introduction[];
extern char const gText_HarvestSpriteMiniGame_Watering_Instructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_SuccessInstructions[];
extern char const gText_HarvestSpriteMiniGame_Watering_MistakeWarning[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandQuestion[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandYes[];
extern char const gText_HarvestSpriteMiniGame_Watering_UnderstandAgain[];
extern char const gText_HarvestSpriteMiniGame_Watering_Start[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScorePrefix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultSuffix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreSummary[];

#if defined(REGION_US)
extern char const gText_HarvestSpriteMiniGame_Harvest_ScoreResultPrefix[];
extern char const gText_HarvestSpriteMiniGame_Watering_ScoreResultPrefix[];
#endif

#endif // HARVEST_SPRITE_MINIGAMES_TEXT_HH
