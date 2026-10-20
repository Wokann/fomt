#ifndef WORLD_LIGHTING_HH
#define WORLD_LIGHTING_HH

#include "prelude.h"
#include "time_of_day.hh"

struct GameSceneWorldPrefix;

EXTERN_C
void RefreshWorldMapTimeOfDayPalette(GameSceneWorldPrefix & world);
TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorldPrefix & world, u32 hour);
// Native palette/cache rebuild; force is a byte, not a new boolean restriction.
void UpdateWorldTimeOfDayPalettes(GameSceneWorldPrefix & world, u32 hour, u32 minute, u8 force);
EXTERN_C_END

#endif // WORLD_LIGHTING_HH
