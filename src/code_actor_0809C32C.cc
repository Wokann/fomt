#include "prelude.h"

#include "actor_state.hh"

EC u32 func_0809C32C(ActorStateSlots const & self)
{
    u32 result = 0;
    i32 value = self.unk_06[1];

    value = -value;
    if ((-self.unk_00[1] | value) >= 0)
        goto end;

    value = self.unk_06[0];
    value = -value;
    if ((-self.unk_00[0] | value) >= 0)
        goto end;

    value = self.unk_06[2];
    value = -value;
    if ((-self.unk_00[2] | value) >= 0)
        goto end;

    value = self.unk_06[3];
    value = -value;
    if ((-self.unk_00[3] | value) >= 0)
        goto end;

    value = self.unk_06[4];
    value = -value;
    if ((-self.unk_00[4] | value) >= 0)
        goto end;

    value = self.unk_06[5];
    value = -value;
    result = (u32)(-self.unk_00[5] | value) >> 31;

end:
    return result;
}
