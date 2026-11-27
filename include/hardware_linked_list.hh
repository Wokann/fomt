#ifndef HARDWARE_LINKED_LIST_HH
#define HARDWARE_LINKED_LIST_HH

#include "prelude.h"

#ifndef __cplusplus
struct HardwareLinkedList;
struct HardwareLinkBase;

// C ABI view of the compiler-owned HardwareLinkedList virtual methods.
// C++ callers use the corresponding declarations on the classes below.
struct HardwareLinkedListVTable {
    void const * metadata[2];
    u8 (*run)(struct HardwareLinkedList *);
    void (*destroy)(struct HardwareLinkedList *, u32);
    void (*append)(struct HardwareLinkedList *, struct HardwareLinkBase *);
    void (*remove)(struct HardwareLinkedList *, struct HardwareLinkBase *);
    void (*clear)(struct HardwareLinkedList *);
    void (*splice)(struct HardwareLinkedList *, struct HardwareLinkedList *);
    void (*swap)(struct HardwareLinkedList *, struct HardwareLinkedList *);
};

#endif

#ifdef __cplusplus
// The class owner emits the tables and the implicit HardwareLink destructor.
#pragma interface "hardware_linked_list_lifetimes.hh"
#endif

struct HardwareLinkBase {
    struct HardwareLinkBase ** previous_slot;
    struct HardwareLinkBase * next;
#ifdef __cplusplus
    HardwareLinkBase() asm("func_08009A38");
    u32 IsLinked() const asm("func_08009A2C");
    // The native list consumes the boolean result from the low byte.
    virtual bool Run() = 0;
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
    virtual bool Run() asm("func_080098D8");
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
    struct HardwareLinkedListVTable const * vtable;
#endif
    struct HardwareLinkBase * first;
    struct HardwareLink sentinel;
#ifdef __cplusplus
    HardwareLinkedList() asm("func_08009A04");
    virtual bool Run() asm("func_08009908");
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
u32 func_08009A2C(struct HardwareLinkBase * link);
void func_08009A38(struct HardwareLinkBase * link);

EXTERN_C_END

#ifdef __cplusplus
#pragma interface "hardware_linked_list.hh"
// The retained constructors and query belong to the earlier list code.
inline HardwareLinkBase::HardwareLinkBase()
    : previous_slot(0), next(0)
{
}

inline u32 HardwareLinkBase::IsLinked() const
{
    u32 value = (u32)previous_slot;
    return ((0 - value) | value) >> 31;
}

inline HardwareLinkedList::HardwareLinkedList()
    : HardwareLinkBase(), first(&sentinel), sentinel()
{
    sentinel.previous_slot = &first;
    sentinel.next = &sentinel;
}
#endif


#ifdef __cplusplus
#include "hardware_linked_list_lifetimes.hh"

// The build preprocesses headers into one stream. Restore ordinary linkage
// inference for subsequent classes instead of exporting their inline bodies.
#endif

#endif // HARDWARE_LINKED_LIST_HH
