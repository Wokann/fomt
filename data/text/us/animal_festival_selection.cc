#include "animal_festival_selection.hh"

char const gText_AnimalStatusScreen_Unavailable[] =
    "N/A ";

// The renderer reads ten halfword glyph codes, without a string terminator.
u16 const gAnimalStatusScreenDigitGlyphs[] ALIGN(2) = {
    "0123456789",
};

char const gText_AnimalStatusScreen_Healthy[] =
    "Healthy ";

char const gText_AnimalStatusScreen_Unhappy[] =
    "Unhappy ";

char const gText_AnimalStatusScreen_Sick[] =
    "Sick    ";

char const gText_AnimalStatusScreen_Spring[] =
    "Spring";

char const gText_AnimalStatusScreen_Summer[] =
    "Summer";

char const gText_AnimalStatusScreen_Autumn[] =
    "Fall  ";

char const gText_AnimalStatusScreen_Winter[] =
    "Winter";

char const gText_AnimalStatusScreen_Age[] =
    "Y ";

char const gText_AnimalStatusScreen_Day[] =
    "D ";

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
