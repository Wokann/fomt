#include "prelude.h"

#include "actor_state.hh"

EC u32 func_0809C22C(void const *, u32 value);
EC u32 func_0809C3E0(ActorStateSlots &, u32 index);
EC void func_0809C420(ActorStateSlots &, u32 index);

EC u8 func_0809C474(ActorStateSlots & self, u32 value)
{
    u32 index = func_0809C22C(&self, value);
    u8 result = 0;

    if (self.unk_00[index] != 0)
    {
        if (index == 1 || index == 4)
            result = func_0809C3E0(self, index);

        if (index == 0 || index == 3)
            func_0809C420(self, index);
    }

    return result;
}
