#include "prelude.h"
#pragma implementation "hardware_interrupt_guard.hh"
#include "hardware_interrupt_guard.hh"
#include "gbaio.h"

void HardwareInterruptList::Clear()
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    HardwareLinkedList::Clear();
}

HardwareInterruptList::~HardwareInterruptList()
{
    HardwareInterruptList::Clear();
}

void HardwareInterruptList::Append(HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    HardwareLinkedList::Append(link);
}

void HardwareInterruptList::Remove(HardwareLinkBase * link)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    HardwareLinkedList::Remove(link);
}

void HardwareInterruptList::Splice(HardwareLinkedList * source)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    HardwareLinkedList::Splice(source);
}

void HardwareInterruptList::Swap(HardwareLinkedList * other)
{
    InterruptGuard guard(INTR_FLAG_VBLANK);
    HardwareLinkedList::Swap(other);
}
