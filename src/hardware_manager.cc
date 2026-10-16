#include "prelude.h"
#pragma implementation "hardware_manager.hh"
#include "hardware_manager.hh"

void * operator new(unsigned long);
void operator delete(void *);

EXTERN_C
extern void __builtin_delete(void * object);
EXTERN_C_END

HardwareManagerOwner::HardwareManagerOwner()
    : state(new HardwareManagerState)
{
}

HardwareManagerOwner::~HardwareManagerOwner()
{
    delete state;
}

void func_080D78E0(void)
{
    HardwareLinkedList * commands = gUnk_03000410->commands;
    commands->Run();
}

HardwareManagerVBlankBinding::HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
{
    commands = list;
    u32 mask = 1;
    enabled = mask & func_08000528(1);
    HardwareManagerVBlankBinding * old_binding = gUnk_03000410;
    gUnk_03000410 = this;
    previous.previous = old_binding;
    previous.vtable = vtable_unk_080E5B48;
    previous_handler = func_080D100C(0, func_080D78E0);
    func_0800050C(1);
}

void func_080D7990(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    func_08009940(list, link);
}

void func_080D79F8(HardwareLinkedList * list, HardwareLinkBase * link)
{
    InterruptGuard guard(1);
    func_08009968(list, link);
}

void func_080D7A34(HardwareLinkedList * list, HardwareLinkedList * source)
{
    InterruptGuard guard(1);
    func_080099B0(list, source);
}

void func_080D7A70(HardwareLinkedList * list, HardwareLinkedList * other)
{
    InterruptGuard guard(1);
    func_080099D4(list, other);
}

void func_080D7AAC(HardwareManagerPreviousBinding * binding, u32 flags)
{
    binding->vtable = vtable_unk_080E5B54;
    gUnk_03000410 = binding->previous;
    if (flags & 1)
        __builtin_delete(binding);
}

void func_080D7B04(HardwareManagerPreviousBinding * binding, u32 flags)
{
    binding->vtable = vtable_unk_080E5B54;
    gUnk_03000410 = binding->previous;
    if (flags & 1)
        __builtin_delete(binding);
}

extern HardwareLinkVirtualFunction const vtable_unk_080E5B48[] = {
    nullptr,
    nullptr,
    reinterpret_cast<HardwareLinkVirtualFunction>(func_080D7B04),
};

extern HardwareLinkVirtualFunction const vtable_unk_080E5B54[] = {
    nullptr,
    nullptr,
    reinterpret_cast<HardwareLinkVirtualFunction>(func_080D7AAC),
};
