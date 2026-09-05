#ifndef FESTIVAL_CONTESTANT_TEXT_HH
#define FESTIVAL_CONTESTANT_TEXT_HH

#include "prelude.h"

enum
{
    FESTIVAL_CONTESTANT_NAME_WIDTH = 13,
    FESTIVAL_CONTESTANT_NAME_SET0_COUNT = 30,
    FESTIVAL_CONTESTANT_NAME_SET1_COUNT = 40,
    FESTIVAL_CONTESTANT_NAME_SET2_COUNT = 20,
};

// These direct-indexed arrays retain the three original fixed-size name sets.
// Their event-specific ownership remains intentionally unassigned until the
// consumers are decompiled.
extern char const gText_FestivalContestantNames_Set0[FESTIVAL_CONTESTANT_NAME_SET0_COUNT][FESTIVAL_CONTESTANT_NAME_WIDTH];
extern char const gText_FestivalContestantNames_Set1[FESTIVAL_CONTESTANT_NAME_SET1_COUNT][FESTIVAL_CONTESTANT_NAME_WIDTH];
extern char const gText_FestivalContestantNames_Set2[FESTIVAL_CONTESTANT_NAME_SET2_COUNT][FESTIVAL_CONTESTANT_NAME_WIDTH];

#endif // FESTIVAL_CONTESTANT_TEXT_HH
