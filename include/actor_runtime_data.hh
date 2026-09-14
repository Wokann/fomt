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

extern "C" u32 const gUnk_08103B10[];
extern "C" u8 const gUnk_08103B38[][10];
extern "C" u32 const gUnk_08103C3C[];
extern "C" u8 const gUnk_08103C74[][14];
extern "C" u32 const gUnk_08103F84[];
extern "C" u8 const gUnk_08103F98[][5];
extern "C" u32 const gUnk_08103FE4[];
extern "C" u8 const gUnk_0810400C[][10];
extern char const gCppRuntimeBadAlloc_ActorSelectorTrailer[];
extern "C" u8 const gUnk_081040EC[][4];

#endif // ACTOR_RUNTIME_DATA_HH
