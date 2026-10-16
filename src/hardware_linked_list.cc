#include "prelude.h"
#pragma implementation "hardware_linked_list.hh"
#include "hardware_linked_list.hh"

HardwareLinkBase::~HardwareLinkBase()
{
    if (previous_slot != 0) {
        *previous_slot = next;
        next->previous_slot = previous_slot;
    }
}

u8 HardwareLink::Run()
{
    return 1;
}

HardwareLinkedList::~HardwareLinkedList()
{
    HardwareLinkedList::Clear();
}

u8 HardwareLinkedList::Run()
{
    HardwareLinkBase * current = first;
    HardwareLinkBase * end = &sentinel;
    while (current != end) {
        HardwareLinkBase * node = current;
        current = node->next;
        if (!node->Run())
            Remove(node);
    }
    return 1;
}

void HardwareLinkedList::Append(HardwareLinkBase * link)
{
    if (link->previous_slot != 0) {
        *link->previous_slot = link->next;
        link->next->previous_slot = link->previous_slot;
    }
    *sentinel.previous_slot = link;
    link->previous_slot = sentinel.previous_slot;
    link->next = &sentinel;
    sentinel.previous_slot = &link->next;
}

void HardwareLinkedList::Remove(HardwareLinkBase * link)
{
    if (link->previous_slot != 0) {
        *link->previous_slot = link->next;
        link->next->previous_slot = link->previous_slot;
        link->previous_slot = 0;
        link->next = 0;
    }
}

void HardwareLinkedList::Clear()
{
    HardwareLinkBase * current = first;
    HardwareLinkBase * end = &sentinel;
    if (current != end) {
        do {
            HardwareLinkBase * node = current;
            current = current->next;
            node->previous_slot = 0;
            node->next = 0;
        } while (current != end);
    }
    first = &sentinel;
    sentinel.previous_slot = &first;
}

void HardwareLinkedList::Splice(HardwareLinkedList * source)
{
    *sentinel.previous_slot = source->first;
    source->first->previous_slot = sentinel.previous_slot;
    *source->sentinel.previous_slot = &sentinel;
    sentinel.previous_slot = source->sentinel.previous_slot;
    source->first = &source->sentinel;
    source->sentinel.previous_slot = &source->first;
}

void HardwareLinkedList::Swap(HardwareLinkedList * other)
{
    HardwareLinkBase * head = first;
    first = other->first;
    other->first = head;
    HardwareLinkBase ** tail = sentinel.previous_slot;
    HardwareLinkBase ** other_tail = other->sentinel.previous_slot;
    HardwareLinkBase * end = *tail;
    *tail = *other_tail;
    *other_tail = end;
}

u32 func_080099EC(struct HardwareLinkedList * list)
{
    return list->first == &list->sentinel;
}

u32 func_08009A2C(struct HardwareLinkBase * link)
{
    u32 value = (u32)link->previous_slot;
    return ((0 - value) | value) >> 31;
}
