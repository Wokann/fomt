#ifndef ENTITY_LOCATION_HH
#define ENTITY_LOCATION_HH

#include "prelude.h"

struct GameSceneState;

// The native state-level entry used by current-map position updates.
// Actor IDs through slot 73 also update facing; other IDs use AEntity location.
// Coordinates narrow to signed 16 bits and the stored map narrows to 10 bits.
void RelocateEntityToMap(GameSceneState * current, i32 entity_id, u32 map,
    i32 x, i32 y, u32 facing);

#endif // ENTITY_LOCATION_HH
