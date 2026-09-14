#include "farm_status_screen_data.hh"

char const gText_FarmStatus_OverviewTitle[] =
    " Eigentum ";

char const gText_FarmStatus_CountFieldPadding[] =
    "  ";

char const gText_FarmStatus_GoldUnit[] =
    "G ";

char const gText_FarmStatus_Healthy[] =
    "Gesund  ";

char const gText_FarmStatus_Unhappy[] =
    "Traurig ";

char const gText_FarmStatus_Sick[] =
    "Krank   ";

char const gText_FarmStatus_Spring[] =
    "Frühl.";

char const gText_FarmStatus_Summer[] =
    "Sommer";

char const gText_FarmStatus_Autumn[] =
    "Herbst";

char const gText_FarmStatus_Winter[] =
    "Winter";

char const gText_FarmStatus_AgeUnit[] =
    "J ";

char const gText_FarmStatus_ChickenList[] =
    "Liste der Hühner";

char const gText_FarmStatus_CattleList[] =
    "Liste der Rinder";

char const gText_FarmStatus_SheepList[] =
    "Liste der Schafe";

char const gText_FarmStatus_HarvestSpriteList[] =
    "Erntewichtel    ";

char const gText_FarmStatus_DayAbbreviation[] =
    "T ";

char const gText_FarmStatus_DaysRemaining[] =
    "links ";

char const gText_FarmStatus_WorkAssignment[] =
    "Arbeit";

char const gText_FarmStatus_NotAssigned[] =
    "k.A.        ";

char const gText_FarmStatus_EarningsReport[] =
    "Verdienstbericht";

char const gText_FarmStatus_PlusSign[] =
    "+ ";

char const gText_FarmStatus_MinusSign[] =
    "- ";

char const gText_FarmStatus_YearLabel[] =
    "Jahr";

char const gText_FarmStatus_Income[] =
    "Ertrag";

char const gText_FarmStatus_Expenses[] =
    "Ausgaben";

char const gText_FarmStatus_ToolLevelList[] =
    "Werkzeuglevel-Liste ";

char const gText_FarmStatus_ToolShopLabel[] =
    "Laden ";

char const gText_FarmStatus_ToolUpgradeQuestion[] =
    "Rüsten? ";

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
    "Gesund  ",
    "Traurig ",
    "Krank   ",
    "Frühl.",
    "Sommer",
    "Herbst",
    "Winter",
    "J ",
    "T ",
};

char const gText_AnimalContest_ChickenConfirmation[] =
    "Ist dieses Huhn OK?";

char const gText_AnimalContest_Yes[] =
    "Ja";

char const gText_AnimalContest_No[] =
    "Nein";

char const gText_AnimalContest_CowConfirmation[] =
    "Ist diese Kuh OK?";

char const gText_AnimalContest_SheepConfirmation[] =
    "Ist dieses Schaf OK?";

char const gText_AnimalContest_BabyChickIneligible[] =
    "Kleine Küken können\r\n"
    "nicht mitmachen. \r\n"
    "Ein anderes wählen?{Press}";

char const gText_AnimalContest_AdultCowIneligible[] =
    "Nur ausgewachsene\r\n"
    "Tiere können mitmachen.\r\n"
    "Wähle eine andere Kuh.{Press}";

char const gText_AnimalContest_AdultSheepIneligible[] =
    "Nur ausgewachsene\r\n"
    "Tiere können mitmachen.\r\n"
    "Wähle bitte ein{Press}\r\n"
    "anderes Schaf.{Press}";

char const gText_AnimalContest_SickChickenIneligible[] =
    "Tut mir leid, aber dieses \r\n"
    "Huhn ist krank. {Press}";

char const gText_AnimalContest_SickCowIneligible[] =
    "Tut mir leid, aber diese \r\n"
    "Kuh ist krank. \r\n"
    "Eine andere wählen?{Press}";

char const gText_AnimalContest_SickSheepIneligible[] =
    "Tut mir leid, aber dieses \r\n"
    "Schaf ist krank\r\n"
    ".Ein anderes wählen?{Press}";

char const gText_AnimalContest_PregnantCowIneligible[] =
    "Trächtige Kühe\r\n"
    "können nicht mitmachen.\r\n"
    "Wähle bitte eine andere.{Press}";

char const gText_AnimalContest_PregnantSheepIneligible[] =
    "Trächtige Schafe\r\n"
    "können nicht mitmachen.\r\n"
    "Wähle bitte ein anderes.{Press}";

char const gText_AnimalContest_ShornSheepIneligible[] =
    "Geschorene Schafe\r\n"
    "können nicht mitmachen.\r\n"
    "Wähle bitte ein anderes.{Press}";

char const gText_AnimalContest_EntryAccepted[] =
    "Ok, abgemacht. Ich werde es\r\n"
    "dir bringen.{Press}";

char const gText_AnimalContest_ChickenSelectionPrompt[] =
    "Wenn das so ist, wähle\r\n"
    "ein Huhn zum Mitmachen.{Press}";

char const gText_AnimalContest_CowSelectionPrompt[] =
    "Wenn das so ist, wähle \r\n"
    "eine Kuh zum Mitmachen.{Press}";

char const gText_AnimalContest_SheepSelectionPrompt[] =
    "Wenn das so ist, wähle \r\n"
    "ein Schaf zum Mitmachen.{Press}";

char const gText_AnimalContest_EntryDeclinedQuestion[] =
    "Du willst nicht mitmachen?";

char const gText_AnimalContest_ChickenEntryDeclinedResponse[] =
    "Ok. Überlege, ob du nächstes\r\n"
    "Mal dabei sein willst.{Press}";

char const gText_AnimalContest_LivestockEntryDeclinedResponse[] =
    "Ok. Überlege, ob du nächstes\r\n"
    "Mal mitmachen willst.{Press}";

char const gCppRuntimeBadAlloc_AnimalContestBoundary[] =
    "bad_alloc";

char const gText_AnimalContest_FinalConfirmation[] =
    "Bist du sicher?";

char const gText_AnimalContest_FinalYes[] =
    "Ja";

char const gText_AnimalContest_FinalNo[] =
    "Nein";

u16 const gFarmStatusScreenPreloadedGlyphs[] = {
    "0123456789Frühl.SommerHerbstWinter_Geburtstag ",
};

char const gCppRuntimeBadAlloc_FarmStatusScreenGlyphs[] =
    "bad_alloc";
