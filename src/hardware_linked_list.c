#include "hardware_linked_list.hh"

extern void * vtable_unk_080E5BE8[];
extern void * vtable_unk_080E5BB4[];
extern void __builtin_delete(void * pointer);
extern void func_08009984(void * object);

void func_080098AC(void * object, u32 flags)
{
    struct HardwareLink * link = (struct HardwareLink *)object;
    link->vtable = vtable_unk_080E5BE8;
    if (link->next != 0) {
        struct HardwareLink * next = link->next;
        next->next = link->prev;
        link->prev->next = next;
    }
    if (flags & 1)
        __builtin_delete(object);
}

u32 func_080098D8(void)
{
    return 1;
}

void func_080098DC(void * object, u32 flags)
{
    void ** fields = (void **)object;
    fields[2] = vtable_unk_080E5BB4;
    func_08009984(object);
    func_080098AC((u8 *)object + 0x10, 2);
    func_080098AC(object, flags);
}
