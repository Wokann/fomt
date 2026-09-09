#include "sram_proxy.hh"

extern u32 func_080D379C(u32 source, void *destination);
u32 func_080006E4(void *unused, void *destination, u32 offset, u32 size)
{
    register void *destination_register asm("r5");
    register u32 offset_register asm("r4");
    register u32 size_register asm("r2");

    destination_register = destination;
    offset_register = offset;
    size_register = size;
    __asm__ volatile ("" : "+r"(size_register));
    gUnk_03000400 = 0;
    if (size_register == 0)
        return 0;

    func_080D379C(0x0E000000 | offset_register, destination_register);
    return 1;
}
