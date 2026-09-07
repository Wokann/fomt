#ifndef ANIMAL_CONTEST_TEXT_HH
#define ANIMAL_CONTEST_TEXT_HH

#include "prelude.h"

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

#endif // ANIMAL_CONTEST_TEXT_HH
