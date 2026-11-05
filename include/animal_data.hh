#ifndef ANIMAL_DATA_HH
#define ANIMAL_DATA_HH

#include "prelude.h"
#include "actor_behavior.hh"

// The animal memorial message is assembled by native code from these direct
// text pointers. The US version has a separate farm-name suffix, while JP has
// a natural-life sentence instead.
extern char const gText_AnimalMemorial_LineBreak[];
extern char const gText_AnimalMemorial_Continue[];
extern char const gText_AnimalMemorial_PageBreak[];
extern char const gText_AnimalMemorial_Header[];
extern char const gText_AnimalMemorial_FarmPrefix[];
#if !defined(REGION_JP)
extern char const gText_AnimalMemorial_FarmSuffix[];
#endif
extern char const gText_AnimalMemorial_PassedAway[];
extern char const gText_AnimalMemorial_NamesIntro[];
extern char const gText_AnimalMemorial_PrayerIntro[];
extern char const gText_AnimalMemorial_PrayerEnding[];
#if defined(REGION_DE)
extern char const gText_AnimalMemorial_DeathHeader[];
extern char const gText_AnimalMemorial_DeathFarmPrefix[];
#endif
#if defined(REGION_JP)
extern char const gText_AnimalMemorial_PassedNaturalLife[];
#endif
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

extern u8 const gUnk_080F0748[];
extern u8 const gUnk_080F0770[];
extern u8 const gUnk_080F0800[];

extern ActorBehaviorTiming const gUnk_080F0838[2][2][13];
extern u16 const gUnk_080F0908[2][13];
extern ActorBehaviorTiming const gUnk_080F093C[28];
extern u16 const gUnk_080F09AC[2][7];
extern ActorBehaviorTiming const gUnk_080F09C8[40];
extern u16 const gUnk_080F0A68[10];
extern ActorBehaviorTiming const gUnk_080F0A7C[112];
extern u16 const gUnk_080F0C3C[28];
extern ActorBehaviorTiming const gUnk_080F0C74[112];
extern u16 const gUnk_080F0E34[28];
#endif // ANIMAL_DATA_HH
