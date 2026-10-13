#include "npc_locations.hh"

static inline void InitializeNpcLocation(ActorLocation * destination, Location const & position, int facing)
{
    // Copy only the six-byte position and set facing.  The temporary position
    // keeps its uninitialized spare bits; final destination padding is not written.
    *static_cast<Location *>(destination) = position;
    destination->facing = facing;
}

ActorLocation * InitializeSouthTownNpcLocation1(ActorLocation * location, u32 slot)
{
    switch (slot)
    {
    case 0:
    default:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 392, 344), FACING_DOWN);
        break;
    case 1:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 376, 296), FACING_DOWN);
        break;
    case 2:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 392, 248), FACING_DOWN);
        break;
    }
    return location;
}

ActorLocation * InitializeSouthTownNpcLocation2(ActorLocation * location, u32 slot)
{
    switch (slot)
    {
    case 0:
    default:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 960, 408), FACING_DOWN);
        break;
    case 1:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 1096, 416), FACING_DOWN);
        break;
    case 2:
        InitializeNpcLocation(location, Location(MAP_SOUTH_SIDE_TOWN, 1176, 344), FACING_DOWN);
        break;
    }
    return location;
}

ActorLocation * InitializeYodelRanchHouseNpcLocation(ActorLocation * location)
{
    InitializeNpcLocation(location, Location(MAP_YODEL_RANCH_HOUSE_1F, 184, 72), FACING_DOWN);
    return location;
}

ActorLocation * InitializeInnSecondFloorNpcLocation(ActorLocation * location)
{
    InitializeNpcLocation(location, Location(MAP_INN_2F, 240, 256), FACING_DOWN);
    return location;
}
