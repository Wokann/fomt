#ifndef HARDWARE_LINKED_LIST_HH
#define HARDWARE_LINKED_LIST_HH

#include "prelude.h"

struct HardwareLink {
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    void ** vtable;
};

struct HardwareLinkedList {
    void * unk_00;
    void * unk_04;
    void ** vtable;
    struct HardwareLink * first;
    struct HardwareLink ** tail_slot;
};

EXTERN_C

void func_080098AC(void * object, u32 flags);
u32 func_080098D8(void);
void func_080098DC(void * object, u32 flags);
u32 func_08009908(struct HardwareLinkedList * list);
void func_08009940(struct HardwareLinkedList * list, struct HardwareLink * link);
void func_08009968(struct HardwareLinkedList * list, struct HardwareLink * link);
void func_08009984(struct HardwareLinkedList * list);
void func_080099B0(struct HardwareLinkedList * destination, struct HardwareLinkedList * source);
void func_080099D4(struct HardwareLinkedList * first, struct HardwareLinkedList * second);
u32 func_080099EC(struct HardwareLinkedList * list);

EXTERN_C_END

#endif // HARDWARE_LINKED_LIST_HH
