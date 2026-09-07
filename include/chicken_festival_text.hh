#ifndef CHICKEN_FESTIVAL_TEXT_HH
#define CHICKEN_FESTIVAL_TEXT_HH

#include "prelude.h"

enum
{
    CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT = 20,
    CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH = 13,
};

// Direct-indexed fixed-width rows, not a pointer table.
extern char const gText_ChickenFestival_ContestantNames[CHICKEN_FESTIVAL_CONTESTANT_NAME_COUNT][CHICKEN_FESTIVAL_CONTESTANT_NAME_WIDTH];

#endif // CHICKEN_FESTIVAL_TEXT_HH
