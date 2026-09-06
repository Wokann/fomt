#ifndef NPC_RUNTIME_DATA_HH
#define NPC_RUNTIME_DATA_HH

#include "prelude.h"

// The unrecovered enclosing class constructs an Npc in its first 0x14 bytes
// before initializing these fields.  Keep that base as raw storage until the
// enclosing constructor and class name have been recovered.
struct NpcRuntimeData
{
    u8 npc_base[0x14];
    char name[0x10];
    u8 unknown_24;
    u8 unknown_25;
    bool flag_26_0 : 1;
    u8 : 7;
};

EC char * func_0809EACC(NpcRuntimeData * self);
EC u8 func_0809EAD0(NpcRuntimeData const * self);
EC u8 func_0809EAD8(NpcRuntimeData const * self);
EC bool func_0809EAE0(NpcRuntimeData const * self);
EC void func_0809EAEC(NpcRuntimeData * self);

#endif // NPC_RUNTIME_DATA_HH
