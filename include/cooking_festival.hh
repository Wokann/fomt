#ifndef COOKING_FESTIVAL_HH
#define COOKING_FESTIVAL_HH

#include "prelude.h"

EXTERN_C

// Indexed by the five Cooking Festival dish categories.  Each row gives the
// strict score thresholds for ratings 0 through 3; a score at or below every
// entry receives rating 4.
extern u8 const gCookingFestivalDishCategoryRatingThresholds[5][4];

EXTERN_C_END

#endif // COOKING_FESTIVAL_HH
