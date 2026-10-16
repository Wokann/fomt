#include "hardware_manager.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_song.hh"
#include "hardware_linked_list.hh"

EXTERN_C
extern void * vtable_unk_080E5B0C[];
extern void * vtable_unk_080E5B18[];
extern void * vtable_unk_080E5B70[];
extern void * vtable_unk_080E5B90[];
extern void * vtable_unk_080E5B60[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5B3C[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5B48[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5B54[];
extern void * __builtin_new(u32 size);
extern void __builtin_delete(void * object);
EXTERN_C_END

HardwareManagerOwner::HardwareManagerOwner()
{
    // The node subclasses are still partial ABI views. Keep their verified
    // construction writes rather than inserting speculative constructors.
    u8 * state = (u8 *)__builtin_new(sizeof(HardwareManagerState));
    u32 zero = 0;
    *(u32 *)(state + 0x00) = zero;
    *(u32 *)(state + 0x04) = zero;
    *(void **)(state + 0x08) = vtable_unk_080E5B70;

    u8 * first = state + 0x0C;
    *(u32 *)(first + 0x00) = zero;
    *(u32 *)(first + 0x04) = zero;
    *(void **)(first + 0x08) = (void *)vtable_unk_080E5BB4;
    u8 * first_sentinel = state + 0x1C;
    *(void **)(first + 0x0C) = first_sentinel;
    *(u32 *)(first_sentinel + 0x00) = zero;
    *(u32 *)(first_sentinel + 0x04) = zero;
    *(void **)(first_sentinel + 0x08) = (void *)vtable_unk_080E5BD8;
    *(void **)(first + 0x10) = first + 0x0C;
    *(void **)(first + 0x14) = first_sentinel;
    *(void **)(first + 0x08) = vtable_unk_080E5B90;

    u8 * link = state + 0x28;
    *(u32 *)(link + 0x00) = zero;
    *(u32 *)(link + 0x04) = zero;
    *(void **)(link + 0x08) = vtable_unk_080E5B60;

    u8 * second = state + 0x34;
    *(u32 *)(second + 0x00) = zero;
    *(u32 *)(second + 0x04) = zero;
    *(void **)(second + 0x08) = (void *)vtable_unk_080E5BB4;
    u8 * second_sentinel = state + 0x44;
    *(void **)(second + 0x0C) = second_sentinel;
    *(u32 *)(second_sentinel + 0x00) = zero;
    *(u32 *)(second_sentinel + 0x04) = zero;
    *(void **)(second_sentinel + 0x08) = (void *)vtable_unk_080E5BD8;
    *(void **)(second + 0x10) = second + 0x0C;
    *(void **)(second + 0x14) = second_sentinel;
    *(void **)(second + 0x08) = vtable_unk_080E5B90;

    HardwareManagerVBlankBinding * resource =
        &reinterpret_cast<HardwareManagerState *>(state)->command_group.vblank;
    HardwareLinkedList * second_pointer = reinterpret_cast<HardwareLinkedList *>(second);
    func_080D78F8(resource, &second_pointer);
    *(void **)(second + 0x30) = vtable_unk_080E5B0C;
    *(void **)(second + 0x08) = vtable_unk_080E5B18;

    u8 * enabled = state + 0x68;
    *enabled = (u8)(func_08008D9C() ^ 1);
    if (*enabled != 0)
        func_08008D84();

    func_080095C0(reinterpret_cast<HardwareLinkedList *>(second),
        reinterpret_cast<HardwareLink *>(state));
    func_080095C0(reinterpret_cast<HardwareLinkedList *>(second),
        reinterpret_cast<HardwareLink *>(first));
    func_080095C0(reinterpret_cast<HardwareLinkedList *>(second),
        reinterpret_cast<HardwareLink *>(link));
    this->state = reinterpret_cast<HardwareManagerState *>(state);
}

HardwareManagerOwner::~HardwareManagerOwner()
{
    HardwareManagerState * object = state;
    if (object != 0) {
        if (object->unk_68 != 0)
            func_08008D90();
        HardwareManagerCommandGroup * group = &object->command_group;
        group->vblank.vtable = reinterpret_cast<HardwareLinkVirtualFunction const *>(vtable_unk_080E5B0C);
        group->commands.vtable = vtable_unk_080E5B18;
        func_080D7944(&group->vblank, 0);
        func_0800959C(&group->commands, 2);
        func_080098AC(&object->unk_28, 2);
        func_0800959C(&object->unk_0C, 2);
        func_080098AC(&object->unk_00, 2);
        __builtin_delete(object);
    }
}

void func_080D78E0(void)
{
    HardwareLinkedList * commands = gUnk_03000410->commands;
    typedef u32 (*Run)(HardwareLinkedList *);
    reinterpret_cast<Run *>(commands->vtable)[2](commands);
}

HardwareManagerVBlankBinding::HardwareManagerVBlankBinding(HardwareLinkedList * const & list)
{
    vtable = vtable_unk_080E5B3C;
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

void func_080D7990(HardwareLinkedList * list, HardwareLink * link)
{
    InterruptGuard guard(1);
    func_08009940(list, link);
}

void func_080D79CC(HardwareManagerVBlankBinding * binding, u32 flags)
{
    // The secondary table supplies the binding subobject, not the whole group.
    // Use its verified member layout until the full class hierarchy is recovered.
    HardwareManagerCommandGroup * group = reinterpret_cast<HardwareManagerCommandGroup *>(
        reinterpret_cast<u8 *>(binding) - offsetof(HardwareManagerCommandGroup, vblank));
    group->vblank.vtable = reinterpret_cast<HardwareLinkVirtualFunction const *>(vtable_unk_080E5B0C);
    group->commands.vtable = vtable_unk_080E5B18;
    func_080D7944(binding, 0);
    func_0800959C(&group->commands, flags);
}

void func_080D79F8(HardwareLinkedList * list, HardwareLink * link)
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

void func_080D7AD4(HardwareManagerCommandGroup * group, u32 flags)
{
    group->vblank.vtable = reinterpret_cast<HardwareLinkVirtualFunction const *>(vtable_unk_080E5B0C);
    group->commands.vtable = vtable_unk_080E5B18;
    func_080D7944(&group->vblank, 0);
    func_0800959C(&group->commands, flags);
}

void func_080D7B04(HardwareManagerPreviousBinding * binding, u32 flags)
{
    binding->vtable = vtable_unk_080E5B54;
    gUnk_03000410 = binding->previous;
    if (flags & 1)
        __builtin_delete(binding);
}

void func_080D7B2C(HardwareLinkBase * link, u32 flags)
{
    func_080098AC(link, flags);
}

void func_080D7B38(HardwareLinkBase * link, u32 flags)
{
    func_080098AC(link, flags);
}

void func_080D7B44(HardwareLink * link, u32 flags)
{
    func_080098AC(link, flags);
}
