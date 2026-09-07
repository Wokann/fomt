#include "prelude.h"

#include "actor_state.hh"
#include "field_data.hh"

u8 const gActorStateMaxValues[] SECTION(".rodata.actor_state_max_values") = {
    10, 10, 255, 10, 10, 255,
};

extern u8 const gUnk_ActorDataSelection_00_00[];
extern u8 const gUnk_ActorDataSelection_00_04[];
extern u8 const gUnk_ActorDataSelection_01_00[];
extern u8 const gUnk_ActorDataSelection_01_04[];
extern u8 const gUnk_ActorDataSelection_02_00[];
extern u8 const gUnk_ActorDataSelection_02_04[];
extern u8 const gUnk_ActorDataSelection_03_00[];
extern u8 const gUnk_ActorDataSelection_03_04[];
extern u8 const gUnk_ActorDataSelection_04_00[];
extern u8 const gUnk_ActorDataSelection_04_04[];
extern u8 const gUnk_ActorDataSelection_05_00[];
extern u8 const gUnk_ActorDataSelection_05_04[];
extern u8 const gUnk_ActorDataSelection_06_00[];
extern u8 const gUnk_ActorDataSelection_06_04[];
extern u8 const gUnk_ActorDataSelection_07_00[];
extern u8 const gUnk_ActorDataSelection_07_04[];
extern u8 const gUnk_ActorDataSelection_08_00[];
extern u8 const gUnk_ActorDataSelection_08_04[];
extern u8 const gUnk_ActorDataSelection_09_00[];
extern u8 const gUnk_ActorDataSelection_09_04[];
extern u8 const gUnk_ActorDataSelection_10_00[];
extern u8 const gUnk_ActorDataSelection_10_04[];
extern u8 const gUnk_ActorDataSelection_11_00[];
extern u8 const gUnk_ActorDataSelection_11_04[];
extern u8 const gUnk_ActorDataSelection_13_00[];
extern u8 const gUnk_ActorDataSelection_13_04[];

extern char const gCppRuntimeBadAlloc_ActorDataSelectionPrefix[] =
    "bad_alloc";

ActorDataSelectionEntry const gActorDataSelectionEntries[] = {
    { gUnk_ActorDataSelection_00_00, gUnk_ActorDataSelection_00_04, 0x15, 0x0C, 0x0000 },
    { gUnk_ActorDataSelection_01_00, gUnk_ActorDataSelection_01_04, 0x0A, 0x02, 0x0000 },
    { gUnk_ActorDataSelection_02_00, gUnk_ActorDataSelection_02_04, 0x24, 0x1B, 0x0000 },
    { gUnk_ActorDataSelection_03_00, gUnk_ActorDataSelection_03_04, 0x15, 0x1B, 0x0000 },
    { gUnk_ActorDataSelection_04_00, gUnk_ActorDataSelection_04_04, 0x21, 0x19, 0x0000 },
    { gUnk_ActorDataSelection_05_00, gUnk_ActorDataSelection_05_04, 0x0B, 0x19, 0x0000 },
    { gUnk_ActorDataSelection_06_00, gUnk_ActorDataSelection_06_04, 0x1F, 0x10, 0x0000 },
    { gUnk_ActorDataSelection_07_00, gUnk_ActorDataSelection_07_04, 0x05, 0x10, 0x0000 },
    { gUnk_ActorDataSelection_08_00, gUnk_ActorDataSelection_08_04, 0x15, 0x0E, 0x0000 },
    { gUnk_ActorDataSelection_09_00, gUnk_ActorDataSelection_09_04, 0x0B, 0x02, 0x0000 },
    { gUnk_ActorDataSelection_10_00, gUnk_ActorDataSelection_10_04, 0x25, 0x02, 0x0000 },
    { gUnk_ActorDataSelection_11_00, gUnk_ActorDataSelection_11_04, 0x06, 0x02, 0x0000 },
    { reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 31), reinterpret_cast<u8 const *>(gFieldRenderRectDescriptors + 30), 0x01, 0x02, 0x0000 },
    { gUnk_ActorDataSelection_13_00, gUnk_ActorDataSelection_13_04, 0x69, 0x3E, 0x0000 },
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
