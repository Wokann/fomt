#ifndef HARDWARE_LINKED_LIST_LIFETIMES_HH
#define HARDWARE_LINKED_LIST_LIFETIMES_HH

#include "hardware_linked_list.hh"

// HardwareLink has no custom cleanup. Its class owner emits the implicit
// destructor, preserving the native direct call to HardwareLinkBase.

#endif // HARDWARE_LINKED_LIST_LIFETIMES_HH
