#include "prelude.h"

#include "actor_state.hh"

EC u32 func_0809C38C(ActorStateSlots const & self)
{
    u32 result = 0;

    if (self.unk_06[1] == 0)
        goto end;
    if (self.unk_06[0] == 0)
        goto end;
    if (self.unk_06[2] == 0)
        goto end;
    if (self.unk_06[3] == 0)
        goto end;
    if (self.unk_06[4] == 0)
        goto end;

    result = (u32)-self.unk_06[5] >> 31;

end:
    return result;
}
