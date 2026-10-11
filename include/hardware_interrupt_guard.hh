#ifndef HARDWARE_INTERRUPT_GUARD_HH
#define HARDWARE_INTERRUPT_GUARD_HH

#include "hardware_blend_object.hh"
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

void func_0800956C(struct HardwareBlendObject * object);
void func_0800959C(struct HardwareBlendObject * object, u32 flags);
void func_080095C0(struct HardwareBlendObject * object, u32 value);
void func_080095FC(struct HardwareBlendObject * object, u32 value);
void func_08009638(struct HardwareBlendObject * object, u32 value);
void func_08009674(struct HardwareBlendObject * object, u32 value);

EXTERN_C_END

#endif // HARDWARE_INTERRUPT_GUARD_HH
