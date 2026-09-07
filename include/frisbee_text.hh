#ifndef FRISBEE_TEXT_HH
#define FRISBEE_TEXT_HH

#include "prelude.h"

#define FRISBEE_SCOREBOARD_TEXT SECTION(".rodata.frisbee_scoreboard")

// Static UI text used by the Frisbee practice and tournament flow.
// The regional source files define the same semantic labels at their
// independently matched ROM locations.
extern char const gText_Frisbee_ExplanationQuestion[];
extern char const gText_Frisbee_Yes[];
extern char const gText_Frisbee_No[];
extern char const gText_Frisbee_ExplanationCursorTiming[];
extern char const gText_Frisbee_ExplanationGreenZone[];
extern char const gText_Frisbee_ExplanationRedZone[];
extern char const gText_Frisbee_ExplanationPractice[];
extern char const gText_Frisbee_ExplanationTournament[];
extern char const gText_Frisbee_ExplainAgain[];
extern char const gText_Frisbee_ThrowAgain[];
extern char const gText_Frisbee_TournamentFinished[];
extern char const gText_Frisbee_PlayAgain[];
extern char const gText_Frisbee_DogNoLongerWantsToPlay[];
extern char const gText_Frisbee_FoundItem[];
extern char const gText_Frisbee_FoundNothing[];
extern char const gText_Frisbee_TournamentScoreboard[];
extern char const gCppRuntimeBadAlloc_FrisbeeScoreboard[];

#endif // FRISBEE_TEXT_HH
