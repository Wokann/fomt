#include "prelude.h"
#include "hardware_manager.hh"
#include "gbaio.h"

#include <new>

HardwareManagerOwner::HardwareManagerOwner()
    : state(new HardwareManagerState)
{
}

HardwareManagerOwner::~HardwareManagerOwner()
{
    delete state;
}

HardwareInterruptList * GetHardwareManagerFrameCommands(HardwareManagerOwner const * owner)
{
    return &owner->state->frame_commands;
}

HardwareInterruptList * func_08008AE8(HardwareManagerOwner const * owner)
{
    return &owner->state->frame_commands;
}
