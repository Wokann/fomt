#ifndef WORLD_AMBIENT_CONSTRUCTION_HH
#define WORLD_AMBIENT_CONSTRUCTION_HH

#include "world_ambient_sprites.hh"
#include <new>

inline void WorldAmbientSpriteOwners::Append(WorldAmbientSprite * sprite)
{
    if (count < CAPACITY) {
        new (&(*this)[count]) Owner(sprite);
        ++count;
    }
}

#endif // WORLD_AMBIENT_CONSTRUCTION_HH
