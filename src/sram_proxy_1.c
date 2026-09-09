#include "types.h"

u32 func_080003DC(u32 unused, u32 index)
{
    register u32 multiplier asm("r0") = 0x3FEC;

    // Emits no instruction; keeps the original literal-load-and-multiply form.
    __asm__ volatile ("" : "+r"(multiplier));
    return index * multiplier + 0x28;
}
