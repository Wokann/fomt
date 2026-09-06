#include "animal_contest_text.hh"

#define ANIMAL_CONTEST_TEXT SECTION(".rodata.animal_contest")
#define ANIMAL_CONTEST_CONFIRMATION_TEXT SECTION(".rodata.animal_contest_confirmation")

char const gText_AnimalContest_ChickenConfirmation[] ANIMAL_CONTEST_TEXT =
    "Is this Chicken OK?";

char const gText_AnimalContest_Yes[] ANIMAL_CONTEST_TEXT =
    "Yes";

char const gText_AnimalContest_No[] ANIMAL_CONTEST_TEXT =
    "No";

char const gText_AnimalContest_CowConfirmation[] ANIMAL_CONTEST_TEXT =
    "Is this Cow OK?";

char const gText_AnimalContest_SheepConfirmation[] ANIMAL_CONTEST_TEXT =
    "Is this Sheep OK?";

char const gText_AnimalContest_BabyChickIneligible[] ANIMAL_CONTEST_TEXT =
    "Baby Chicks can't compete.\r\n"
    "Choose another one?{Press}";

char const gText_AnimalContest_AdultCowIneligible[] ANIMAL_CONTEST_TEXT =
    "Only adults can enter.\r\n"
    "Please select another Cow.{Press}";

char const gText_AnimalContest_AdultSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "Only adults can enter.\r\n"
    "Please select another Sheep.{Press}";

char const gText_AnimalContest_SickChickenIneligible[] ANIMAL_CONTEST_TEXT =
    "Sorry, but this Chicken is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_SickCowIneligible[] ANIMAL_CONTEST_TEXT =
    "Sorry, but this Cow is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_SickSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "Sorry, but this Sheep is \r\n"
    "sick. Choose another one?{Press}";

char const gText_AnimalContest_PregnantCowIneligible[] ANIMAL_CONTEST_TEXT =
    "Pregnant Cows can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_PregnantSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "Pregnant Sheep can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_ShornSheepIneligible[] ANIMAL_CONTEST_TEXT =
    "Shorn Sheep can't enter.\r\n"
    "Please select another.{Press}";

char const gText_AnimalContest_EntryAccepted[] ANIMAL_CONTEST_TEXT =
    "It's a deal, then. I'll\r\n"
    "bring it to you.{Press}";

char const gText_AnimalContest_ChickenSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "In that case, select a \r\n"
    "Chicken to compete.{Press}";

char const gText_AnimalContest_CowSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "In that case, select a \r\n"
    "Cow to enter.{Press}";

char const gText_AnimalContest_SheepSelectionPrompt[] ANIMAL_CONTEST_TEXT =
    "In that case, select a \r\n"
    "Sheep to enter.{Press}";

char const gText_AnimalContest_EntryDeclinedQuestion[] ANIMAL_CONTEST_TEXT =
    "So you don't want to enter?";

char const gText_AnimalContest_ChickenEntryDeclinedResponse[] ANIMAL_CONTEST_TEXT =
    "Alright. Think about\r\n"
    "it next time.{Press}";

char const gText_AnimalContest_LivestockEntryDeclinedResponse[] ANIMAL_CONTEST_TEXT =
    "Alright. Think about\r\n"
    "competing next time.{Press}";

char const gText_AnimalContest_FinalConfirmation[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "Are you sure?";

char const gText_AnimalContest_FinalYes[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "Yes";

char const gText_AnimalContest_FinalNo[] ANIMAL_CONTEST_CONFIRMATION_TEXT =
    "No";

extern AnimalContestStatusPrefixText const gAnimalContestStatusPrefixText
    ANIMAL_CONTEST_STATUS_PREFIX_TEXT = {
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

extern AnimalContestStatusText const gAnimalContestStatusText
    ANIMAL_CONTEST_STATUS_TEXT = {
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

#undef ANIMAL_CONTEST_CONFIRMATION_TEXT
#undef ANIMAL_CONTEST_TEXT
