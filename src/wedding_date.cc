#include "prelude.h"
#include "config.h"
#include "byte_search.h"
#include "wedding_date.hh"
#include "unknown_types.hh"

// Days are one-based constants; the sorted lookup key counts from Spring 1 = 0.
u8 const gUnk_FieldRenderSortedValues[] = {
    SEASON_SPRING * 30 + DAY_01 - 1,
    SEASON_SPRING * 30 + DAY_14 - 1,
    SEASON_SPRING * 30 + DAY_17 - 1,
    SEASON_SPRING * 30 + DAY_18 - 1,
    SEASON_SPRING * 30 + DAY_21 - 1,
    SEASON_SPRING * 30 + DAY_22 - 1,
    SEASON_SPRING * 30 + DAY_30 - 1,
    SEASON_SUMMER * 30 + DAY_01 - 1,
    SEASON_SUMMER * 30 + DAY_06 - 1,
    SEASON_SUMMER * 30 + DAY_07 - 1,
    SEASON_SUMMER * 30 + DAY_19 - 1,
    SEASON_SUMMER * 30 + DAY_20 - 1,
    SEASON_SUMMER * 30 + DAY_24 - 1,
    SEASON_FALL * 30 + DAY_02 - 1,
    SEASON_FALL * 30 + DAY_03 - 1,
    SEASON_FALL * 30 + DAY_08 - 1,
    SEASON_FALL * 30 + DAY_09 - 1,
    SEASON_FALL * 30 + DAY_13 - 1,
    SEASON_FALL * 30 + DAY_17 - 1,
    SEASON_FALL * 30 + DAY_18 - 1,
    SEASON_FALL * 30 + DAY_20 - 1,
    SEASON_FALL * 30 + DAY_21 - 1,
#if !defined(REGION_JP) || defined(BUGFIX)
    // JP omits the Pumpkin Festival from its wedding exclusions.
    SEASON_FALL * 30 + DAY_30 - 1,
#endif
    SEASON_WINTER * 30 + DAY_14 - 1,
    SEASON_WINTER * 30 + DAY_24 - 1,
#if !defined(REGION_JP) || defined(BUGFIX)
    // JP also omits Thomas's stocking-gift day.
    SEASON_WINTER * 30 + DAY_25 - 1,
#endif
    SEASON_WINTER * 30 + DAY_30 - 1,
};

bool IsWeddingDateUnavailable(GameDate const & date)
{
    u32 season = date.season;
    u32 day = date.day;
    u32 key = season * 30 + day;
    u8 const * first = gUnk_FieldRenderSortedValues;
    u8 const * end = first;
    end += ARRAY_COUNT(gUnk_FieldRenderSortedValues);
    u8 const * found = std::lower_bound(first, end, key, UnsignedByteLess());
    return found != end && !(key < *found);
}
