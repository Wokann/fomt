#ifndef HARDWARE_LINKED_LIST_HH
#define HARDWARE_LINKED_LIST_HH

#include "prelude.h"

#ifdef __cplusplus
// Keep the ABI's out-of-line constructor in hardware_linked_list.cc while
// allowing the same member initialization to inline in owning objects.
#pragma interface "hardware_linked_list.hh"
#endif

// Commands and the list's sentinel share this native link base. The base
// construction restores its own table before a derived object installs one.
struct HardwareLinkBase {
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    void ** vtable;
#ifdef __cplusplus
    HardwareLinkBase() asm("func_08009A38") SECTION(".text.hardware_linked_list_tail");
#endif
};

struct HardwareLink
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLink ** previous_slot;
    struct HardwareLink * next;
    void ** vtable;
#else
    HardwareLink() SECTION(".text.hardware_link_constructor");
#endif
};

struct HardwareLinkedList {
    void * unk_00;
    void * unk_04;
    void ** vtable;
    struct HardwareLink * first;
    struct HardwareLink sentinel;
#ifdef __cplusplus
    HardwareLinkedList() asm("func_08009A04") SECTION(".text.hardware_linked_list_constructor");
#endif
};

EXTERN_C

typedef void (*HardwareLinkVirtualFunction)(void);
extern HardwareLinkVirtualFunction const vtable_unk_080E5BD8[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5BB4[];
extern HardwareLinkVirtualFunction const vtable_unk_080E5BE8[];
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
u32 func_08009A2C(struct HardwareLink * link) SECTION(".text.hardware_linked_list_tail");
void func_08009A38(struct HardwareLink * link) SECTION(".text.hardware_linked_list_tail");

EXTERN_C_END

#ifdef __cplusplus
inline HardwareLinkBase::HardwareLinkBase()
{
    vtable = (void **)vtable_unk_080E5BE8;
    previous_slot = 0;
    next = 0;
}

inline HardwareLink::HardwareLink()
    : HardwareLinkBase()
{
    vtable = (void **)vtable_unk_080E5BD8;
}

inline HardwareLinkedList::HardwareLinkedList()
    : unk_00(0), unk_04(0), vtable((void **)vtable_unk_080E5BB4),
      first(&sentinel), sentinel()
{
    sentinel.previous_slot = &first;
    sentinel.next = &sentinel;
}
#endif

typedef char HardwareLinkBase_size_check[sizeof(struct HardwareLinkBase) == 0x0C ? 1 : -1];
typedef char HardwareLink_size_check[sizeof(struct HardwareLink) == 0x0C ? 1 : -1];
typedef char HardwareLinkedList_size_check[sizeof(struct HardwareLinkedList) == 0x1C ? 1 : -1];
typedef char HardwareLinkedList_sentinel_check[offsetof(struct HardwareLinkedList, sentinel) == 0x10 ? 1 : -1];

#endif // HARDWARE_LINKED_LIST_HH
