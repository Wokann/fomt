#include "hardware_interrupt_guard.hh"

extern void * const vtable_unk_080E5B90[];

EXTERN_C

void func_0800956C(struct HardwareLinkedList * list)
{
    InterruptGuard guard(1);
    func_08009984(list);
}

void func_0800959C(struct HardwareLinkedList * list, u32 flags)
{
    list->vtable = (void **)vtable_unk_080E5B90;
    func_0800956C(list);
    func_080098DC(list, flags);
}

void func_080095C0(struct HardwareLinkedList * list, struct HardwareLink * link)
{
    InterruptGuard guard(1);
    func_08009940(list, link);
}

void func_080095FC(struct HardwareLinkedList * list, struct HardwareLink * link)
{
    InterruptGuard guard(1);
    func_08009968(list, link);
}

void func_08009638(struct HardwareLinkedList * list, struct HardwareLinkedList * source)
{
    InterruptGuard guard(1);
    func_080099B0(list, source);
}

void func_08009674(struct HardwareLinkedList * list, struct HardwareLinkedList * other)
{
    InterruptGuard guard(1);
    func_080099D4(list, other);
}

void func_080D788C(struct HardwareLinkedList * list)
{
    InterruptGuard guard(1);
    func_08009984(list);
}

void func_080D78BC(struct HardwareLinkedList * list, u32 flags)
{
    list->vtable = (void **)vtable_unk_080E5B90;
    // This retained cleanup calls the original clear entry, not its copy.
    func_0800956C(list);
    func_080098DC(list, flags);
}

EXTERN_C_END
