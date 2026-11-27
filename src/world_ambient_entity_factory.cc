#include "world_ambient_entity_factory.hh"
#include "world_ambient_sprites.hh"

inline WorldAmbientEntity::WorldAmbientEntity(GameObject * world, GameStateActorRecord * records)
    : AEntity(world, Location(0, 0, 0)), records(records), restore_saved_records(true)
{
}

extern "C" AEntity * CreateWorldAmbientEntity(GameObject * world, GameStateActorRecord * records)
{
    return new WorldAmbientEntity(world, records);
}
