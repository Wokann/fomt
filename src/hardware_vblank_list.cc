#include "hardware_vblank_list.hh"
#include "gbaio.h"
#include "hardware_interrupt_guard.hh"

void RemoveHardwareVBlankCommand(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Remove(link);
}

void SpliceHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * source)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Splice(source);
}

void SwapHardwareVBlankCommands(HardwareLinkedList * list, HardwareLinkedList * other)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    list->HardwareLinkedList::Swap(other);
}
