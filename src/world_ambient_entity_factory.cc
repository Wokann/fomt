#include "world_ambient_entity_factory.hh"
#include "world_ambient_sprites.hh"
#include <new>

extern "C" AEntity * CreateWorldAmbientEntity(GameObject * world, GameStateActorRecord * records)
{
    return new WorldAmbientEntity(world, records);
}
