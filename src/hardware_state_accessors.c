#include "hardware_state_accessors.hh"

// The owner holds one pointer to the display state. Only these three offsets
// are established here; the surrounding state layout remains unclassified.
u8 * func_08008910(void * const * state)
{
    return (u8 *)*state + 0x24;
}

u8 * func_08008918(void * const * state)
{
    return (u8 *)*state + 0x34;
}

u8 * func_08008920(void * const * state)
{
    return (u8 *)*state + 0x8C;
}
