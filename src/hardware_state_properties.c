#include "hardware_state_properties.hh"

u16 func_08007E8C(void)
{
    // The meaning of the halfword at this state offset is not yet known.
    return *(u16 *)(gUnk_03000408 + 0x920);
}

u32 func_08007EA0(void)
{
    return 0x100;
}
