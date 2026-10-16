#include "prelude.h"
#pragma implementation "hardware_interrupt_guard.hh"
#include "hardware_interrupt_guard.hh"

void HardwareInterruptList::Clear()
{
    InterruptGuard guard(1);
    HardwareLinkedList::Clear();
}

HardwareInterruptList::~HardwareInterruptList()
{
    HardwareInterruptList::Clear();
}

void HardwareInterruptList::Append(HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    HardwareLinkedList::Append(link);
}

void HardwareInterruptList::Remove(HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    HardwareLinkedList::Remove(link);
}

void HardwareInterruptList::Splice(HardwareLinkedList * source)
{
    InterruptGuard guard(1);
    HardwareLinkedList::Splice(source);
}

void HardwareInterruptList::Swap(HardwareLinkedList * other)
{
    InterruptGuard guard(1);
    HardwareLinkedList::Swap(other);
}

void func_080D788C(struct HardwareLinkedList * list)
{
    InterruptGuard guard(1);
    func_08009984(list);
}

// This distinct retail cleanup is a native ABI entry, not the compiler's
// HardwareInterruptList destructor. The vptr follows the two link fields.
void func_080D78BC(struct HardwareLinkedList * list, u32 flags)
{
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(list) + 8) =
        reinterpret_cast<void **>(__vt_21HardwareInterruptList);
    // This retained cleanup calls the original clear entry, not its copy.
    func_0800956C(list);
    func_080098DC(list, flags);
}
