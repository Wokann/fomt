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
#endif

EXTERN_C

void func_0800956C(struct HardwareLinkedList * list);
void func_0800959C(struct HardwareLinkedList * list, u32 flags);
void func_080095C0(struct HardwareLinkedList * list, struct HardwareLink * link);
void func_080095FC(struct HardwareLinkedList * list, struct HardwareLink * link);
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
