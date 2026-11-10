#ifndef MAP_SELECTION_H
#define MAP_SELECTION_H

#include "prelude.h"

EXTERN_C

// Logical map IDs select one of the regional MapData records.
u32 SelectMapDataId(i32 map, u32 season, u32 house, u32 coop, u32 barn);

EXTERN_C_END

#endif // MAP_SELECTION_H
