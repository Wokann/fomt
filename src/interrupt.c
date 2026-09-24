#include "interrupt.hh"
#include "gbaio.h"
#include "gbasvc.h"

extern void func_03000958(void);
extern u16 func_03000A1C(u32 value);
extern void func_080D100C(u32 index, void (*handler)(void));
extern u16 func_080D101C(u32 index, u16 value);
extern void *__builtin_new(u32 size);
extern void __builtin_delete(void *pointer);

void func_080004C4(void)
{
    u32 index;
    func_08000528(0xFFFF);
    *(void (**)(void))0x03007FFC = func_03000958;
    for (index = 0; index <= 13; index++)
        func_080D100C(index, 0);
}

u16 func_080004F4(u32 value)
{
    register u32 shifted asm("r0") = value << 16;
    register u16 (*handler)(u32) asm("r1") = func_03000A1C;

    // agbcc otherwise turns this IWRAM ARM call into an out-of-range Thumb BL.
    __asm__ volatile ("" : "+r"(shifted));
    __asm__ volatile ("" : "+r"(handler));
    return handler(shifted);
}

u16 func_0800050C(u16 value)
{
    REG_IF = value;
    return func_080004F4(value);
}

u16 func_08000528(u16 value)
{
    register u32 normalized asm("r0") = (u16)value;
    register u16 (*handler)(u32) asm("r1") = func_03000A1C;

    __asm__ volatile ("" : "+r"(normalized));
    __asm__ volatile ("" : "+r"(handler));
    return handler(normalized);
}

u16 func_08000540(u32 index, u16 value)
{
    return func_080D101C(index, value);
}

void func_08000554(u16 value)
{
    IntrWait(0, value);
}

void func_08000568(u16 value)
{
    IntrWait(1, value);
}

u32 func_0800057C(u32 unused, u32 value)
{
    return value;
}

u32 func_08000580(u32 unused, u32 value)
{
    return value;
}

void *func_08000584(u32 size)
{
    return __builtin_new(size);
}

void func_08000590(void *pointer)
{
    __builtin_delete(pointer);
}
