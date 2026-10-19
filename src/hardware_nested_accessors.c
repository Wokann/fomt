#include "hardware_nested_accessors.hh"

struct HardwareInterruptList * func_08008AE0(struct HardwareManagerOwner const * owner)
{
    return &owner->state->unk_0C;
}

struct HardwareInterruptList * func_08008AE8(struct HardwareManagerOwner const * owner)
{
    return &owner->state->unk_0C;
}
