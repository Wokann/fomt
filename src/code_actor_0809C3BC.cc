#include "prelude.h"

#include "actor_state.hh"

EC u32 func_0809C22C(void const *, u32 value);

EC void func_0809C3BC(ActorStateSlots & self, u32 value)
{
    u32 const index = func_0809C22C(&self, value);

    if (self.unk_00[index] == 0)
    {
        self.unk_00[index] = 1;
        self.unk_0C[index] = 0;
    }
}
