#ifndef WORLD_LIGHTING_HH
#define WORLD_LIGHTING_HH

#include "prelude.h"
#include "time_of_day.hh"

struct GameSceneWorld;

EXTERN_C
void RefreshWorldMapTimeOfDayPalette(GameSceneWorld & world);
TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorld & world, u32 hour);
// Native palette/cache rebuild; force is a byte, not a new boolean restriction.
void UpdateWorldTimeOfDayPalettes(GameSceneWorld & world, u32 hour, u32 minute, u8 force);
EXTERN_C_END

#endif // WORLD_LIGHTING_HH
