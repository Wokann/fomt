#include "prelude.h"
#include "types.h"

extern void func_080006A4(void *destination, u32 offset, void const *source, u32 size);

u32 func_080003DC(u32 unused, u32 index)
{
    register u32 multiplier asm("r0") = 0x3FEC;

    // Emits no instruction; keeps the original literal-load-and-multiply form.
    __asm__ volatile ("" : "+r"(multiplier));
    return index * multiplier + 0x28;
}

void func_08000470(void *destination, u32 value)
    SECTION(".text.sram_proxy_1_save_value");

void func_08000470(void *destination, u32 value)
{
    func_080006A4(destination, 0x24, &value, sizeof(value));
}
