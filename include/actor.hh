#ifndef ACTOR_HH
#define ACTOR_HH

#include "fomt_constants.hh"
#include "prelude.h"

struct PACKED ALIGN(2) Location
{
    Location() {}

    Location(u32 map, u32 x, u32 y)
        : map(static_cast<MaryMapId>(map)), x(x), y(y)
    {
    }

    u32 GetMap() const { return map; }
    i16 GetX() const { return x; }
    i16 GetY() const { return y; }

    /* +00 */ MaryMapId map : 10;
    /* +01 */ i16 x : 16;
    /* +03 */ i16 y : 16;
};

struct ActorLocation : public Location
{
    ActorLocation() {}
    ActorLocation(Location const & location, int facing)
        : Location(location), facing(facing)
    {
    }

    /* +06 */ u8 facing;
};

typedef char LocationSizeCheck[sizeof(Location) == 6 ? 1 : -1];
typedef char ActorLocationSizeCheck[sizeof(ActorLocation) == 8 ? 1 : -1];
typedef char ActorLocationFacingCheck[offsetof(ActorLocation, facing) == 6 ? 1 : -1];

struct Actor
{
    Actor(ActorLocation const & location);
    Actor(Actor const & other);

    void SetLocation(ActorLocation const & location);

    ActorLocation location;
};

#endif // ACTOR_HH
