#ifndef HARDWARE_INTERRUPT_GUARD_HH
#define HARDWARE_INTERRUPT_GUARD_HH

#include "hardware_linked_list.hh"
#include "interrupt.hh"

#ifdef __cplusplus
// Restore only the interrupt bits that were enabled on entry. SRAM writes
// and hardware command updates use the same scoped protection.
class InterruptGuard {
public:
    explicit InterruptGuard(u16 mask) : enabled(mask & func_08000528(mask)) {}
    ~InterruptGuard()
    {
        if (enabled)
            func_080004F4(enabled);
    }

private:
    u16 enabled;
};

// The retained ABI cleanup below also refers to this compiler-owned table.
#pragma interface "hardware_interrupt_guard.hh"
struct HardwareInterruptList : HardwareLinkedList {
    virtual ~HardwareInterruptList() asm("func_0800959C");
    virtual void Append(HardwareLinkBase * link) asm("func_080095C0");
    virtual void Remove(HardwareLinkBase * link) asm("func_080095FC");
    virtual void Clear() asm("func_0800956C");
    virtual void Splice(HardwareLinkedList * source) asm("func_08009638");
    virtual void Swap(HardwareLinkedList * other) asm("func_08009674");
};
#pragma implementation
// Native ABI cleanup also needs the compiler's actual table symbol.
extern int (*__vt_21HardwareInterruptList[9])(...);
#else
struct HardwareInterruptList {
    struct HardwareLinkedList list;
};
#endif

EXTERN_C

void func_0800956C(struct HardwareLinkedList * list);
void func_0800959C(struct HardwareLinkedList * list, u32 flags);
void func_080095C0(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
void func_080095FC(struct HardwareLinkedList * list, struct HardwareLinkBase * link);
void func_08009638(struct HardwareLinkedList * list, struct HardwareLinkedList * source);
void func_08009674(struct HardwareLinkedList * list, struct HardwareLinkedList * other);

// The retail image retains these separate copies after the frame commands.
// Keep their real bodies and entries, rather than aliases to the earlier pair.
void func_080D788C(struct HardwareLinkedList * list)
    SECTION(".text.hardware_frame_commands_after");
void func_080D78BC(struct HardwareLinkedList * list, u32 flags)
    SECTION(".text.hardware_frame_commands_after");

EXTERN_C_END

#endif // HARDWARE_INTERRUPT_GUARD_HH
