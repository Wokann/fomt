#ifndef NPC_LOCATIONS_HH
#define NPC_LOCATIONS_HH

#include "actor.hh"

// Preset locations used by the NPC roster and actor location refreshes.
// The two south-town groups are distinguished by their verified coordinates;
// their character identities have not been established.
ActorLocation * InitializeSouthTownNpcLocation1(ActorLocation * location, u32 slot);
ActorLocation * InitializeSouthTownNpcLocation2(ActorLocation * location, u32 slot);
ActorLocation * InitializeYodelRanchHouseNpcLocation(ActorLocation * location);
ActorLocation * InitializeInnSecondFloorNpcLocation(ActorLocation * location);


#endif // NPC_LOCATIONS_HH
