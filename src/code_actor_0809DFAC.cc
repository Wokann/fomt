#include "actor_state.hh"

EC u8 func_0809DFAC(ActorStateFlagBits const & state)
{
    u8 result = state.flag_625_5;
    if (state.flag_625_6)
        ++result;
    if (state.flag_625_7)
        ++result;
    if (state.flag_626_0)
        ++result;
    if (state.flag_626_1)
        ++result;
    if (state.flag_626_2)
        ++result;
    if (state.flag_626_3)
        ++result;
    if (state.flag_626_4)
        ++result;
    if (state.flag_626_5)
        ++result;
    return result;
}
