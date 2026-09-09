#include "prelude.h"
#include "types.h"

extern void func_080006A4(void *destination, u32 offset, void const *source, u32 size);
extern void func_080006E4(void *source, void *destination, u32 offset, u32 size);
extern u8 func_080002E0(void *source);
extern u16 gUnk_03000400;

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

u32 func_08000488(void *source)
    SECTION(".text.sram_proxy_1_read_value");

u32 func_08000488(void *source)
{
    u32 value;

    if (!func_080002E0(source))
        return 0;

    value = 0;
    func_080006E4(source, &value, 0x24, sizeof(value));
    if (gUnk_03000400 != 0)
        return 0;

    return value;
}
