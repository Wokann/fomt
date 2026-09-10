#include "prelude.h"

#include "actor_state.hh"
#include "field_render_rect_descriptors.hh"

u8 const gActorStateMaxValues[] SECTION(".rodata.actor_state_max_values") = {
    10, 10, 255, 10, 10, 255,
};

extern char const gCppRuntimeBadAlloc_ActorDataSelectionPrefix[] =
    "bad_alloc";

ActorDataSelectionEntry const gActorDataSelectionEntries[] = {
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 53), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 54), 0x15, 0x0C, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 55), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 56), 0x0A, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 57), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 58), 0x24, 0x1B, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 59), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 60), 0x15, 0x1B, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 61), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 62), 0x21, 0x19, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 63), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 64), 0x0B, 0x19, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 65), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 66), 0x1F, 0x10, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 67), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 68), 0x05, 0x10, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 73), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 74), 0x15, 0x0E, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 75), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 76), 0x0B, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 69), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 70), 0x25, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 71), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 72), 0x06, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 31), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 30), 0x01, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 77), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 78), 0x69, 0x3E, 0x0000 },
};

extern char const gCppRuntimeBadAlloc_ActorDataSelectionTrailer[] =
    "bad_alloc";

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
