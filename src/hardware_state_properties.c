#include "hardware_state_properties.hh"
#include "hardware_refcount.hh"

u16 func_08007E8C(void)
{
    // The meaning of the halfword at this state offset is not yet known.
    return ((HardwareSharedState *)gUnk_03000408)->unk_920;
}

u32 func_08007EA0(void)
{
    return 0x100;
}
