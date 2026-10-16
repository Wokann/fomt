#ifndef HARDWARE_LINKED_LIST_HH
#define HARDWARE_LINKED_LIST_HH

#include "prelude.h"

#ifdef __cplusplus
// Emit the retail out-of-line constructors here while allowing their normal
// member initialization to inline in owning objects.
#pragma interface "hardware_linked_list.hh"
#endif

struct HardwareLinkBase {
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
#ifdef __cplusplus
    HardwareLinkBase() asm("func_08009A38") SECTION(".text.hardware_linked_list_tail");
    virtual u8 Run() = 0;
    virtual ~HardwareLinkBase() asm("func_080098AC");
#else
    void ** vtable;
#endif
};

struct HardwareLink
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#else
    HardwareLink() SECTION(".text.hardware_link_constructor");
    virtual u8 Run() asm("func_080098D8");
    // The compiler-generated destructor forwards directly to the link base.
#endif
};

struct HardwareLinkedList
#ifdef __cplusplus
    : HardwareLinkBase
#endif
{
#ifndef __cplusplus
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
    void ** vtable;
#endif
    struct HardwareLinkBase * first;
    struct HardwareLink sentinel;
#ifdef __cplusplus
    HardwareLinkedList() asm("func_08009A04") SECTION(".text.hardware_linked_list_constructor");
    virtual u8 Run() asm("func_08009908");
    virtual ~HardwareLinkedList() asm("func_080098DC");
    virtual void Append(HardwareLinkBase * link) asm("func_08009940");
    virtual void Remove(HardwareLinkBase * link) asm("func_08009968");
    virtual void Clear() asm("func_08009984");
    virtual void Splice(HardwareLinkedList * source) asm("func_080099B0");
    virtual void Swap(HardwareLinkedList * other) asm("func_080099D4");
#endif
};

EXTERN_C

typedef void (*HardwareLinkVirtualFunction)(void);

// Direct native entry points for the remaining C and assembly callers.
void func_080098AC(void * object, u32 flags);
u32 func_080098D8(void);
void func_080098DC(void * object, u32 flags);
u32 func_08009908(struct HardwareLinkedList * list);
void func_08009940(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
void func_08009968(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
void func_08009984(struct HardwareLinkedList * list);
void func_080099B0(struct HardwareLinkedList * destination, struct HardwareLinkedList * source);
void func_080099D4(struct HardwareLinkedList * first, struct HardwareLinkedList * second);
u32 func_080099EC(struct HardwareLinkedList * list);
u32 func_08009A2C(struct HardwareLinkBase * link) SECTION(".text.hardware_linked_list_tail");
void func_08009A38(struct HardwareLinkBase * link) SECTION(".text.hardware_linked_list_tail");

EXTERN_C_END

#ifdef __cplusplus
inline HardwareLinkBase::HardwareLinkBase()
    : previous_slot(0), next(0)
{
}

inline HardwareLink::HardwareLink()
    : HardwareLinkBase()
{
}

inline HardwareLinkedList::HardwareLinkedList()
    : HardwareLinkBase(), first(&sentinel), sentinel()
{
    sentinel.previous_slot = &first;
    sentinel.next = &sentinel;
}
#endif

typedef char HardwareLinkBase_size_check[sizeof(struct HardwareLinkBase) == 0x0C ? 1 : -1];
typedef char HardwareLink_size_check[sizeof(struct HardwareLink) == 0x0C ? 1 : -1];
typedef char HardwareLinkedList_size_check[sizeof(struct HardwareLinkedList) == 0x1C ? 1 : -1];
typedef char HardwareLinkedList_first_check[offsetof(struct HardwareLinkedList, first) == 0x0C ? 1 : -1];
typedef char HardwareLinkedList_sentinel_check[offsetof(struct HardwareLinkedList, sentinel) == 0x10 ? 1 : -1];

#ifdef __cplusplus
// The build preprocesses headers into one stream. Restore ordinary linkage
// inference for subsequent classes instead of exporting their inline bodies.
#pragma implementation
#endif

#endif // HARDWARE_LINKED_LIST_HH
