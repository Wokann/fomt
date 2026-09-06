#ifndef FARM_STATUS_TEXT_HH
#define FARM_STATUS_TEXT_HH

#include "prelude.h"

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
