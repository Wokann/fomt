#include "prelude.h"

#include "actor_state.hh"

extern "C" u32 func_0809C22C(void const *, u32 value);

extern "C" u8 func_0809C444(ActorStateSlots & self, u32 value)
{
    u8 result = 0;
    u32 index = func_0809C22C(&self, value);

    if (self.unk_00[index] != 0)
    {
        if (index == 0 || index == 3)
            result = func_0809C3E0(self, index);
    }

    return result;
}
