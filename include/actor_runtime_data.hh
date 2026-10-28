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

typedef char ActorRuntimeStateSizeCheck[sizeof(Unk_Actor_0809BFE8) == 0x18 ? 1 : -1];
typedef char ActorRuntimeStateSelectorCheck[offsetof(Unk_Actor_0809BFE8, unk_0C) == 0x0C ? 1 : -1];
typedef char ActorRuntimeStatePairSizeCheck[sizeof(Unk_Actor_0809C0AC) == 8 ? 1 : -1];

extern "C" {
unsigned int func_0809C060(Unk_Actor_0809BFE8 const & self);
void func_0809C068(Unk_Actor_0809BFE8 & self, int amount);
void func_0809C098(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0A0(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0AC(Unk_Actor_0809BFE8 & self, Unk_Actor_0809C0AC const & value);
void func_0809C0BC(Unk_Actor_0809BFE8 & self, u32 const & value);
void func_0809C0C8(Unk_Actor_0809BFE8 & self, u32 const & value);

// Reset the location to MAP_NONE at (0, 0), select state 0, and restore the
// low seven-bit value to 100. Other payload words and high bits are retained.
void ResetActorRuntimeState(Unk_Actor_0809BFE8 & self);
}

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
