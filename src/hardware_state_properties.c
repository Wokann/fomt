#include "hardware_state_properties.hh"
#include "hardware_refcount.hh"

extern void func_080D6EEC(void *);
extern void func_080D6F5C(void *);

u16 func_08007E8C(void)
{
    // The meaning of the halfword at this state offset is not yet known.
    return ((HardwareSharedState *)gUnk_03000408)->unk_920;
}

u32 func_08007EA0(void)
{
    return 0x100;
}

void func_08007EA8(u8 * state)
{
    register u32 inactive;
    register u32 active;
    func_080D6EEC(state + 4);
    func_080D6EEC(state + 0x80);
    inactive = 0;
    active = 1;
    state[0] = active;
    state[1] = inactive;
}

void func_08007EC8(u8 * state)
{
    func_080D6F5C(state + 0x80);
    func_080D6F5C(state + 4);
    state[0] = 0;
    state[1] = 1;
}
