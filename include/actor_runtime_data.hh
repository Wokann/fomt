#ifndef ACTOR_RUNTIME_DATA_HH
#define ACTOR_RUNTIME_DATA_HH

#include "actor.hh"

struct Unk_Actor_0809BFE8 : Actor
{
    Unk_Actor_0809BFE8();

    u32 unk_08_0 : 7;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
};

struct Unk_Actor_0809C0AC
{
    u32 unk_00;
    u32 unk_04;
};

// The hut initializer reads three bytes from each four-byte record.
// The last byte is natural record alignment, not a separate runtime field.
struct ALIGN(4) HarvestSpriteHutPosition
{
    u8 x;
    u8 y;
    u8 facing;
};

typedef char HarvestSpriteHutPositionSizeCheck[sizeof(HarvestSpriteHutPosition) == 4 ? 1 : -1];
typedef char HarvestSpriteHutPositionFacingCheck[offsetof(HarvestSpriteHutPosition, facing) == 2 ? 1 : -1];

extern "C" HarvestSpriteHutPosition const gHarvestSpriteHutPositions[7];

#endif // ACTOR_RUNTIME_DATA_HH
