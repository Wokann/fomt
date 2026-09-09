#ifndef FARM_STATUS_TEXT_HH
#define FARM_STATUS_TEXT_HH

#include "prelude.h"

struct AnimalStatusScreenPrefixText
{
    char unavailable[6];
#if defined(REGION_JP)
    char digits[21];
    char digit_trailer[1];
#else
    char digits[10][2];
    char padding[2];
#endif
};

#if defined(REGION_JP)
struct AnimalStatusScreenText
{
    char healthy[8];
    char unhappy[8];
    char sick[8];
    char spring[4];
    char summer[4];
    char autumn[4];
    char winter[4];
    char age[4];
    char day[4];
};
#else
struct AnimalStatusScreenText
{
    char healthy[12];
    char unhappy[12];
    char sick[12];
    char spring[8];
    char summer[8];
    char autumn[8];
    char winter[8];
    char age[4];
    char day[4];
};
#endif

extern AnimalStatusScreenPrefixText const gAnimalStatusScreenPrefixText;
extern AnimalStatusScreenText const gAnimalStatusScreenText;

extern char const gText_FarmStatus_OverviewTitle[];
extern char const gText_FarmStatus_GoldUnit[];
extern char const gText_FarmStatus_Healthy[];
extern char const gText_FarmStatus_Unhappy[];
extern char const gText_FarmStatus_Sick[];
extern char const gText_FarmStatus_Spring[];
extern char const gText_FarmStatus_Summer[];
extern char const gText_FarmStatus_Autumn[];
extern char const gText_FarmStatus_Winter[];
extern char const gText_FarmStatus_AgeUnit[];
extern char const gText_FarmStatus_ChickenList[];
extern char const gText_FarmStatus_CattleList[];
extern char const gText_FarmStatus_SheepList[];
extern char const gText_FarmStatus_HarvestSpriteList[];
extern char const gText_FarmStatus_DaysRemaining[];
extern char const gText_FarmStatus_WorkAssignment[];
extern char const gText_FarmStatus_NotAssigned[];
extern char const gText_FarmStatus_EarningsReport[];
extern char const gText_FarmStatus_PlusSign[];
extern char const gText_FarmStatus_MinusSign[];
extern char const gText_FarmStatus_YearLabel[];
extern char const gText_FarmStatus_Income[];
extern char const gText_FarmStatus_Expenses[];
extern char const gText_FarmStatus_ToolLevelList[];
extern char const gText_FarmStatus_PercentSign[];

#if defined(REGION_JP)
extern char const gText_FarmStatus_CounterBirds[];
extern char const gText_FarmStatus_CounterHeads[];
extern char const gText_FarmStatus_CounterAnimals[];
extern char const gText_FarmStatus_CounterSheets[];
extern char const gText_FarmStatus_CounterPieces[];
extern char const gText_FarmStatus_CounterLongObjects[];
extern char const gText_FarmStatus_DayUnit[];
extern char const gText_FarmStatus_MonthSuffix[];
extern char const gText_FarmStatus_ToolUpgradeInProgress[];
extern char const gText_FarmStatus_ToolUpgradeAvailable[];
#else
extern char const gText_FarmStatus_CountFieldPadding[];
extern char const gText_FarmStatus_DayAbbreviation[];
extern char const gText_FarmStatus_ToolShopLabel[];
extern char const gText_FarmStatus_ToolUpgradeQuestion[];
#endif

#endif // FARM_STATUS_TEXT_HH
