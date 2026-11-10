#ifndef HARDWARE_MANAGER_LIFETIMES_HH
#define HARDWARE_MANAGER_LIFETIMES_HH

#include "hardware_manager.hh"

#pragma interface "hardware_manager_lifetimes.hh"

inline HardwareManagerCommandGroup::~HardwareManagerCommandGroup() {}

inline HardwareManagerBindingRestore::~HardwareManagerBindingRestore()
{
    gCurrentHardwareVBlankBinding = previous;
}


#endif // HARDWARE_MANAGER_LIFETIMES_HH
