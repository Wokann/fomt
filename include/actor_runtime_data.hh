#ifndef ACTOR_RUNTIME_DATA_HH
#define ACTOR_RUNTIME_DATA_HH

#include "actor.hh"
#include "actor_state.hh"

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

EC u32 const gUnk_08103B10[];
EC u8 const gUnk_08103B38[][10];
EC u32 const gUnk_08103C3C[];
EC u8 const gUnk_08103C74[][14];
EC u32 const gUnk_08103F84[];
EC u8 const gUnk_08103F98[][5];
EC u32 const gUnk_08103FE4[];
EC u8 const gUnk_0810400C[][10];
extern char const gCppRuntimeBadAlloc_ActorSelectorTrailer[];
EC u8 const gUnk_081040EC[][4];

#endif // ACTOR_RUNTIME_DATA_HH
