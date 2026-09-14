#include "farm_status_screen_data.hh"

char const gText_FarmStatus_OverviewTitle[] =
    " Property ";

char const gText_FarmStatus_CountFieldPadding[] =
    "  ";

char const gText_FarmStatus_GoldUnit[] =
    "G ";

char const gText_FarmStatus_Healthy[] =
    "Healthy ";

char const gText_FarmStatus_Unhappy[] =
    "Unhappy ";

char const gText_FarmStatus_Sick[] =
    "Sick    ";

char const gText_FarmStatus_Spring[] =
    "Spring";

char const gText_FarmStatus_Summer[] =
    "Summer";

char const gText_FarmStatus_Autumn[] =
    "Fall  ";

char const gText_FarmStatus_Winter[] =
    "Winter";

char const gText_FarmStatus_AgeUnit[] =
    "yr";

char const gText_FarmStatus_ChickenList[] =
    "List of Chickens";

char const gText_FarmStatus_CattleList[] =
    "List of Cattle";

char const gText_FarmStatus_SheepList[] =
    "List of Sheep ";

char const gText_FarmStatus_HarvestSpriteList[] =
    "Harvest Sprites ";

char const gText_FarmStatus_DayAbbreviation[] =
    "D ";

char const gText_FarmStatus_DaysRemaining[] =
    "left";

char const gText_FarmStatus_WorkAssignment[] =
    "work    ";

char const gText_FarmStatus_NotAssigned[] =
    "N/A         ";

char const gText_FarmStatus_EarningsReport[] =
    "Earnings Report ";

char const gText_FarmStatus_PlusSign[] =
    "+ ";

char const gText_FarmStatus_MinusSign[] =
    "- ";

char const gText_FarmStatus_YearLabel[] =
    "Year";

char const gText_FarmStatus_Income[] =
    "Income";

char const gText_FarmStatus_Expenses[] =
    "Expenses";

char const gText_FarmStatus_ToolLevelList[] =
    "Tool Level List ";

char const gText_FarmStatus_ToolShopLabel[] =
    "Shop  ";

char const gText_FarmStatus_ToolUpgradeQuestion[] =
    "Upgrade?";

char const gText_FarmStatus_PercentSign[] =
    "% ";

char const gCppRuntimeBadAlloc_FarmStatus[] =
    "bad_alloc";

AnimalStatusScreenPrefixText const gAnimalStatusScreenPrefixText = {
    "N/A ",
    {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    },
};

AnimalStatusScreenText const gAnimalStatusScreenText = {
    "Healthy ",
    "Unhappy ",
    "Sick    ",
    "Spring",
    "Summer",
    "Fall  ",
    "Winter",
    "Y ",
    "D ",
};

char const gText_AnimalContest_ChickenConfirmation[] =
    "Is this Chicken OK?";

char const gText_AnimalContest_Yes[] =
    "Yes";

char const gText_AnimalContest_No[] =
    "No";

char const gText_AnimalContest_CowConfirmation[] =
    "Is this Cow OK?";

char const gText_AnimalContest_SheepConfirmation[] =
    "Is this Sheep OK?";

char const gText_AnimalContest_BabyChickIneligible[] =
    "Baby Chicks can't compete.\r\n"
    "Choose another one?{Press}";

char const gText_AnimalContest_AdultCowIneligible[] =
    "Only adults can enter.\r\n"
    "Please select another Cow.{Press}";

char const gText_AnimalContest_AdultSheepIneligible[] =
    "Only adults can enter.\r\n"
    "Please select another Sheep.{Press}";

char const gText_AnimalContest_SickChickenIneligible[] =
    "Sorry, but this Chicken is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_SickCowIneligible[] =
    "Sorry, but this Cow is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_SickSheepIneligible[] =
    "Sorry, but this Sheep is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_PregnantCowIneligible[] =
    "Pregnant Cows can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_PregnantSheepIneligible[] =
    "Pregnant Sheep can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_ShornSheepIneligible[] =
    "Shorn Sheep can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_EntryAccepted[] =
    "It's a deal, then. I'll\r\n"
    "bring it to you.{Press}";

char const gText_AnimalContest_ChickenSelectionPrompt[] =
    "In that case, select a \r\n"
    "Chicken to compete.{Press}";

char const gText_AnimalContest_CowSelectionPrompt[] =
    "In that case, select a \r\n"
    "Cow to enter.{Press}";

char const gText_AnimalContest_SheepSelectionPrompt[] =
    "In that case, select a \r\n"
    "Sheep to enter.{Press}";

char const gText_AnimalContest_EntryDeclinedQuestion[] =
    "So you don't want to enter?";

char const gText_AnimalContest_ChickenEntryDeclinedResponse[] =
    "Alright. Think about\r\n"
    "it next time.{Press}";

char const gText_AnimalContest_LivestockEntryDeclinedResponse[] =
    "Alright. Think about\r\n"
    "competing next time.{Press}";

char const gCppRuntimeBadAlloc_AnimalContestBoundary[] =
    "bad_alloc";

char const gText_AnimalContest_FinalConfirmation[] =
    "Are you sure?";

char const gText_AnimalContest_FinalYes[] =
    "Yes";

char const gText_AnimalContest_FinalNo[] =
    "No";

u16 const gFarmStatusScreenPreloadedGlyphs[] = {
    "0123456789SpringSummerFall  Winter_Birthday",
};

char const gCppRuntimeBadAlloc_FarmStatusScreenGlyphs[] =
    "bad_alloc";
