#ifndef FARM_STATUS_SCREEN_DATA_HH
#define FARM_STATUS_SCREEN_DATA_HH

#include "prelude.h"

struct FarmStatusScreenResourceDescriptor
{
    u16 first;
    u16 second;
};

struct FarmStatusScreenBuildingPreview
{
    u8 const *primary_tilemap;
    u8 const *alternate_tilemap;
    u16 x;
    u16 y;
    u8 width;
    u8 height;
    u16 unused;
};

struct FarmStatusScreenExteriorStyleData
{
    u8 doghouse[3];
    u8 mailbox[3][3];
};

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

#if defined(REGION_JP)
extern u8 const gUnk_082AFC74[];
extern u8 const gUnk_082AFCD4[];
extern u8 const gUnk_082AFDC8[];
extern u8 const gUnk_082AFE70[];
extern u8 const gUnk_082AFED0[];
extern u8 const gUnk_082B0744[];
extern u8 const gUnk_082B07E0[];
extern u8 const gUnk_082B2F20[];
extern u8 const gUnk_082B2F80[];
extern u8 const gUnk_082B3074[];
extern u8 const gUnk_082B311C[];
extern u8 const gUnk_082B317C[];
extern u8 const gUnk_082B39F0[];
extern u8 const gUnk_082B3A8C[];
#elif defined(REGION_DE)
extern u8 const gUnk_082B0BB4[];
extern u8 const gUnk_082B0C14[];
extern u8 const gUnk_082B0D08[];
extern u8 const gUnk_082B0DB0[];
extern u8 const gUnk_082B0E10[];
extern u8 const gUnk_082B1684[];
extern u8 const gUnk_082B1720[];
extern u8 const gUnk_082B3E60[];
extern u8 const gUnk_082B3EC0[];
extern u8 const gUnk_082B3FB4[];
extern u8 const gUnk_082B405C[];
extern u8 const gUnk_082B40BC[];
extern u8 const gUnk_082B4930[];
extern u8 const gUnk_082B49CC[];
#else
extern u8 const gUnk_08529B18[];
extern u8 const gUnk_08529B78[];
extern u8 const gUnk_08529C6C[];
extern u8 const gUnk_08529D14[];
extern u8 const gUnk_08529D74[];
extern u8 const gUnk_0852A5E8[];
extern u8 const gUnk_0852A684[];
extern u8 const gUnk_0852CDC4[];
extern u8 const gUnk_0852CE24[];
extern u8 const gUnk_0852CF18[];
extern u8 const gUnk_0852CFC0[];
extern u8 const gUnk_0852D020[];
extern u8 const gUnk_0852D894[];
extern u8 const gUnk_0852D930[];
#endif

extern u16 const gFarmStatusScreenPreloadedGlyphs[];
extern char const gCppRuntimeBadAlloc_FarmStatusScreenGlyphs[];
extern FarmStatusScreenResourceDescriptor const gFarmStatusScreenResourceDescriptors[];
extern u16 const gFarmStatusScreenTileLookup[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenFarmHousePreviews[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenCoopPreviews[];
extern FarmStatusScreenBuildingPreview const gFarmStatusScreenBarnPreviews[];
extern FarmStatusScreenExteriorStyleData const gFarmStatusScreenExteriorStyleData;
extern char const gCppRuntimeBadAlloc_FarmStatusScreenTrailer[];

extern char const gCppRuntimeBadAlloc_FarmStatus[];
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

extern char const gCppRuntimeBadAlloc_AnimalContestBoundary[];
extern char const gText_AnimalContest_ChickenConfirmation[];
extern char const gText_AnimalContest_Yes[];
extern char const gText_AnimalContest_No[];
extern char const gText_AnimalContest_CowConfirmation[];
extern char const gText_AnimalContest_SheepConfirmation[];
extern char const gText_AnimalContest_BabyChickIneligible[];
extern char const gText_AnimalContest_AdultCowIneligible[];
extern char const gText_AnimalContest_AdultSheepIneligible[];
extern char const gText_AnimalContest_SickChickenIneligible[];
extern char const gText_AnimalContest_SickCowIneligible[];
extern char const gText_AnimalContest_SickSheepIneligible[];
extern char const gText_AnimalContest_PregnantCowIneligible[];
extern char const gText_AnimalContest_PregnantSheepIneligible[];
extern char const gText_AnimalContest_ShornSheepIneligible[];
extern char const gText_AnimalContest_ChickenSelectionPrompt[];
extern char const gText_AnimalContest_CowSelectionPrompt[];
extern char const gText_AnimalContest_SheepSelectionPrompt[];
extern char const gText_AnimalContest_ChickenEntryDeclinedResponse[];
extern char const gText_AnimalContest_LivestockEntryDeclinedResponse[];
extern char const gText_AnimalContest_FinalConfirmation[];
extern char const gText_AnimalContest_FinalYes[];
extern char const gText_AnimalContest_FinalNo[];

#if defined(REGION_JP)
extern char const gText_AnimalContest_ChickenEntryAccepted[];
extern char const gText_AnimalContest_CowEntryAccepted[];
extern char const gText_AnimalContest_SheepEntryAccepted[];
extern char const gText_AnimalContest_ChickenEntryDeclinedQuestion[];
extern char const gText_AnimalContest_LivestockEntryDeclinedQuestion[];
#else
extern char const gText_AnimalContest_EntryAccepted[];
extern char const gText_AnimalContest_EntryDeclinedQuestion[];
#endif

#endif // FARM_STATUS_SCREEN_DATA_HH
