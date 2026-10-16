#include "prelude.h"
#pragma implementation "hardware_linked_list.hh"
#include "hardware_linked_list.hh"

typedef u8 (*HardwareLinkTest)(struct HardwareLink * node);
typedef void (*HardwareLinkRemove)(struct HardwareLinkedList * list, struct HardwareLink * node);

HardwareLinkBase::~HardwareLinkBase()
{
    vtable = (void **)vtable_unk_080E5BE8;
    if (previous_slot != 0) {
        *previous_slot = next;
        next->previous_slot = previous_slot;
    }
}

EXTERN_C

u32 func_080098D8(void)
{
    return 1;
}

void func_080098DC(void * object, u32 flags)
{
    void ** fields = (void **)object;
    fields[2] = (void *)vtable_unk_080E5BB4;
    func_08009984((struct HardwareLinkedList *)object);
    func_080098AC((u8 *)object + 0x10, 2);
    func_080098AC(object, flags);
}

u32 func_08009908(struct HardwareLinkedList * list)
{
    struct HardwareLink * current = list->first;
    struct HardwareLink * sentinel = &list->sentinel;
    struct HardwareLink * node;
    HardwareLinkTest test;
    HardwareLinkRemove remove;

    while (current != sentinel) {
        node = current;
        current = node->next;
        test = ((HardwareLinkTest *)node->vtable)[2];
        if (!test(node)) {
            remove = ((HardwareLinkRemove *)list->vtable)[5];
            remove(list, node);
        }
    }
    return 1;
}

void func_08009940(struct HardwareLinkedList * list, struct HardwareLink * link)
{
    if (link->previous_slot != 0) {
        *link->previous_slot = link->next;
        link->next->previous_slot = link->previous_slot;
    }
    *list->sentinel.previous_slot = link;
    link->previous_slot = list->sentinel.previous_slot;
    link->next = &list->sentinel;
    list->sentinel.previous_slot = &link->next;
}

void func_08009968(struct HardwareLinkedList * list, struct HardwareLink * link)
{
    (void)list;
    if (link->previous_slot != 0) {
        *link->previous_slot = link->next;
        link->next->previous_slot = link->previous_slot;
        link->previous_slot = 0;
        link->next = 0;
    }
}

void func_08009984(struct HardwareLinkedList * list)
{
    struct HardwareLink * current = list->first;
    struct HardwareLink * sentinel = &list->sentinel;
    struct HardwareLink * node;
    if (current != sentinel) {
        do {
            node = current;
            current = current->next;
            node->previous_slot = 0;
            node->next = 0;
        } while (current != sentinel);
    }
    {
        u8 * end = (u8 *)&list->sentinel;
        list->first = (struct HardwareLink *)end;
        list->sentinel.previous_slot = (struct HardwareLink **)(end - 4);
    }
}

void func_080099B0(struct HardwareLinkedList * destination, struct HardwareLinkedList * source)
{
    *destination->sentinel.previous_slot = source->first;
    source->first->previous_slot = destination->sentinel.previous_slot;
    *source->sentinel.previous_slot = &destination->sentinel;
    destination->sentinel.previous_slot = source->sentinel.previous_slot;
    source->first = &source->sentinel;
    source->sentinel.previous_slot = &source->first;
}

void func_080099D4(struct HardwareLinkedList * first, struct HardwareLinkedList * second)
{
    struct HardwareLink * first_head = first->first;
    struct HardwareLink ** first_tail;
    struct HardwareLink ** second_tail;
    struct HardwareLink * first_end;
    first->first = second->first;
    second->first = first_head;
    first_tail = first->sentinel.previous_slot;
    second_tail = second->sentinel.previous_slot;
    first_end = *first_tail;
    *first_tail = *second_tail;
    *second_tail = first_end;
}

u32 func_080099EC(struct HardwareLinkedList * list)
{
    return list->first == &list->sentinel;
}

EXTERN_C_END

EXTERN_C

u32 func_08009A2C(struct HardwareLink * link)
{
    u32 value = (u32)link->previous_slot;
    return ((0 - value) | value) >> 31;
}

EXTERN_C_END
