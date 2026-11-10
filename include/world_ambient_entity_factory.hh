#ifndef WORLD_AMBIENT_ENTITY_FACTORY_HH
#define WORLD_AMBIENT_ENTITY_FACTORY_HH

#include "prelude.h"

struct AEntity;
struct GameObject;
struct GameStateActorRecord;

EXTERN_C
// World slot 84 owns the three saved ambient records through its controller.
AEntity * CreateWorldAmbientEntity(GameObject * world, GameStateActorRecord * records);
EXTERN_C_END

#endif // WORLD_AMBIENT_ENTITY_FACTORY_HH
