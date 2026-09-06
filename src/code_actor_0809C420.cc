#include "prelude.h"

#include "actor_state.hh"

EC void func_0809C420(ActorStateSlots & self, u32 index)
{
    if (self.unk_00[index] != 0)
    {
        if (index == 0 || index == 3)
            self.unk_0C[index] = 0;
    }
}
