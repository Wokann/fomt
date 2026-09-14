#include "prelude.h"

#include "actor_state.hh"

extern "C" u32 func_0809C22C(void const *, u32 value);

extern "C" u8 func_0809C4B4(ActorStateSlots & self, u32 value)
{
    u32 index = func_0809C22C(&self, value);
    u8 result = 0;

    if (self.unk_00[index] != 0)
    {
        if (index == 5 || index == 2)
            result = func_0809C3E0(self, index);
    }

    return result;
}
