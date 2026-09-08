#include "cooking_festival.hh"

EXTERN_C

// The native scoring path indexes this table with category * 4 and byte
// loads.  Its original physical location is byte-aligned in both regions.
u8 const gCookingFestivalDishCategoryRatingThresholds[5][4] ALIGN(1) = {
    { 100, 80, 50, 30 },
    { 80, 60, 30, 10 },
    { 80, 50, 20, 10 },
    { 100, 70, 40, 20 },
    { 80, 60, 30, 20 },
};

EXTERN_C_END
