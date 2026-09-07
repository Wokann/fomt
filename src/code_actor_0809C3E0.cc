#include "prelude.h"

#include "actor_state.hh"

u8 const gActorStateMaxValues[] SECTION(".rodata.actor_state_max_values") = {
    10, 10, 255, 10, 10, 255,
};

EC u32 func_0809C3E0(ActorStateSlots & self, u32 index)
{
    u32 result = 0;

    if (self.unk_00[index] != 0)
    {
        u8 * const values = self.unk_0C;
        u8 & value = values[index];

        if (value < gActorStateMaxValues[index])
            ++value;
        else
        {
            self.unk_00[index] = 0;
            self.unk_06[index] = 1;
            result = 1;
        }
    }

    return result;
}
