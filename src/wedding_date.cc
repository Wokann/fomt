#include "prelude.h"
#include "config.h"
#include "byte_search.h"
#include "wedding_date.hh"
#include "unknown_types.hh"

// Days are one-based constants; the sorted lookup key counts from Spring 1 = 0.
u8 const gUnk_FieldRenderSortedValues[] = {
    DATE_NEW_YEAR_FESTIVAL,
    DATE_SPRING_THANKSGIVING,
    DATE_SPRING_HORSE_RACE - 1,
    DATE_SPRING_HORSE_RACE,
    DATE_COOKING_FESTIVAL - 1,
    DATE_COOKING_FESTIVAL,
    DATE_BEACH_DAY - 1,
    DATE_BEACH_DAY,
    DATE_CHICKEN_FESTIVAL - 1,
    DATE_CHICKEN_FESTIVAL,
    DATE_COW_FESTIVAL - 1,
    DATE_COW_FESTIVAL,
    DATE_FIREWORKS_FESTIVAL,
    DATE_MUSIC_FESTIVAL - 1,
    DATE_MUSIC_FESTIVAL,
    DATE_HARVEST_FESTIVAL - 1,
    DATE_HARVEST_FESTIVAL,
    DATE_FULL_MOON_FESTIVAL,
    DATE_FALL_HORSE_RACE - 1,
    DATE_FALL_HORSE_RACE,
    DATE_SHEEP_FESTIVAL - 1,
    DATE_SHEEP_FESTIVAL,
#if defined(BUGFIX) || defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    // JP omits the Pumpkin Festival from its wedding exclusions.
    DATE_PUMPKIN_FESTIVAL,
#endif
    DATE_WINTER_THANKSGIVING,
    DATE_STARRY_NIGHT_FESTIVAL,
#if defined(BUGFIX) || defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    // JP also omits Thomas's stocking-gift day.
    DATE_THOMAS_STOCKING_GIFT,
#endif
    DATE_YEAR_END_GATHERING,
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
