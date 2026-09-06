#include "actor_state.hh"

EC u8 func_0809E02C(ActorStateFlagBits const & state)
{
    u8 result = state.flag_624_1;
    if (state.flag_624_2)
        ++result;
    if (state.flag_624_3)
        ++result;
    if (state.flag_624_4)
        ++result;
    if (state.flag_624_5)
        ++result;
    if (state.flag_624_6)
        ++result;
    if (state.flag_624_7)
        ++result;
    if (state.flag_625_0)
        ++result;
    if (state.flag_625_1)
        ++result;
    return result;
}
