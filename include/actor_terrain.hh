#ifndef ACTOR_TERRAIN_HH
#define ACTOR_TERRAIN_HH

#include "prelude.h"

struct AActorEntity;

EXTERN_C
bool IsActorTerrainBlocked(AActorEntity const & actor);
EXTERN_C_END

#endif // ACTOR_TERRAIN_HH
