#include "hardware_interrupt_guard.hh"

extern void * const vtable_unk_080E5B90[];

EXTERN_C
void func_080098DC(void * object, u32 flags);
void func_08009984(void * object);
void func_08009940(void * object, u32 value);
void func_08009968(void * object, u32 value);
void func_080099B0(void * object, u32 value);
void func_080099D4(void * object, u32 value);
EXTERN_C_END

EXTERN_C

void func_0800956C(struct HardwareBlendObject * object)
{
    InterruptGuard guard(1);
    func_08009984(object);
}

void func_0800959C(struct HardwareBlendObject * object, u32 flags)
{
    object->vtable = vtable_unk_080E5B90;
    func_0800956C(object);
    func_080098DC(object, flags);
}

void func_080095C0(struct HardwareBlendObject * object, u32 value)
{
    InterruptGuard guard(1);
    func_08009940(object, value);
}

void func_080095FC(struct HardwareBlendObject * object, u32 value)
{
    InterruptGuard guard(1);
    func_08009968(object, value);
}

void func_08009638(struct HardwareBlendObject * object, u32 value)
{
    InterruptGuard guard(1);
    func_080099B0(object, value);
}

void func_08009674(struct HardwareBlendObject * object, u32 value)
{
    InterruptGuard guard(1);
    func_080099D4(object, value);
}

EXTERN_C_END
