#ifndef WEDDING_DATE_HH
#define WEDDING_DATE_HH

#include "prelude.h"

struct GameDate;

extern u8 const gUnk_FieldRenderSortedValues[];

// Tests the sorted exclusion list used when the script chooses a wedding day.
extern "C" bool IsWeddingDateUnavailable(GameDate const & date);

#endif // WEDDING_DATE_HH
