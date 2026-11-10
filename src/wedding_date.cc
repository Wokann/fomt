#include "prelude.h"
#include "byte_search.h"
#include "wedding_date.hh"
#include "unknown_types.hh"

u8 const gUnk_FieldRenderSortedValues[] = {
        0x00, 0x0D, 0x10, 0x11, 0x14, 0x15, 0x1D, 0x1E, 0x23,
        0x24, 0x30, 0x31, 0x35, 0x3D, 0x3E, 0x43, 0x44, 0x48,
        0x4C, 0x4D, 0x4F, 0x50,
#if !defined(REGION_JP)
        0x59,
#endif
        0x67, 0x71,
#if !defined(REGION_JP)
        0x72,
#endif
        0x77,
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
