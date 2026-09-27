#ifndef HARDWARE_LINKED_LIST_HH
#define HARDWARE_LINKED_LIST_HH

#include "prelude.h"

struct HardwareLink {
    struct HardwareLink * next;
    struct HardwareLink * prev;
    void ** vtable;
};

EXTERN_C

void func_080098AC(void * object, u32 flags);
u32 func_080098D8(void);
void func_080098DC(void * object, u32 flags);

EXTERN_C_END

#endif // HARDWARE_LINKED_LIST_HH
