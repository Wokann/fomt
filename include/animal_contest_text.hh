#ifndef ANIMAL_CONTEST_TEXT_HH
#define ANIMAL_CONTEST_TEXT_HH

#include "prelude.h"

#define ANIMAL_CONTEST_TEXT SECTION(".rodata.animal_contest")
#define ANIMAL_CONTEST_CONFIRMATION_TEXT SECTION(".rodata.animal_contest_confirmation")
#define ANIMAL_CONTEST_STATUS_PREFIX_TEXT SECTION(".rodata.animal_contest_status_prefix")
#define ANIMAL_CONTEST_STATUS_TEXT SECTION(".rodata.animal_contest_status")

struct AnimalContestStatusPrefixText
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
struct AnimalContestStatusText
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
struct AnimalContestStatusText
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

extern AnimalContestStatusPrefixText const gAnimalContestStatusPrefixText;
extern AnimalContestStatusText const gAnimalContestStatusText;

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

#endif // ANIMAL_CONTEST_TEXT_HH
