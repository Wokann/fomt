#ifndef ANIMAL_DATA_HH
#define ANIMAL_DATA_HH

#include "prelude.h"
#include "actor_movement.hh"


struct PACKED FarmHouseDrawTilePosition
{
    u8 x;
    u8 y;
};

struct FarmHouseEntityPosition
{
    i16 x;
    i16 y;
};

extern FarmHouseDrawTilePosition const gFarmHouseUpgradeDrawPositions[];
extern FarmHouseEntityPosition const gFarmHouseOriginalRelocationPositions[];
extern FarmHouseEntityPosition const gFarmHouseFirstExtensionRelocationPositions[];
extern FarmHouseEntityPosition const gFarmHouseSecondExtensionRelocationPositions[];

extern u32 const gUnk_080F0748[];
extern u32 const gUnk_080F0770[];
extern u8 const gUnk_080F0800[];
extern u8 const gUnk_080F0807[];



#endif // ANIMAL_DATA_HH
