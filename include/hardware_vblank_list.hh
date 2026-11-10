#ifndef HARDWARE_VBLANK_LIST_HH
#define HARDWARE_VBLANK_LIST_HH

#include "hardware_linked_list.hh"

EXTERN_C

// Retained interrupt-protected operations following the command-group thunk.
void RemoveHardwareVBlankCommand(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
void SpliceHardwareVBlankCommands(struct HardwareLinkedList * list, struct HardwareLinkedList * source);
void SwapHardwareVBlankCommands(struct HardwareLinkedList * list, struct HardwareLinkedList * other);

EXTERN_C_END

#endif // HARDWARE_VBLANK_LIST_HH
