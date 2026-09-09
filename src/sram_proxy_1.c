#include "sram_signature.hh"
#include "sram_proxy.hh"
#include "types.h"

#include <string.h>

u8 func_080002E0(void *source)
{
    u8 header[0x20];
    u32 flags;
    u32 state;
    u8 result;

    func_080006E4(source, header, 0, sizeof(header));
    if (gUnk_03000400 != 0)
        return 0;

    flags = 0;
    func_080006E4(source, &flags, 0x20, sizeof(flags));
    if (gUnk_03000400 != 0)
        return 0;

    state = 0;
    func_080006E4(source, &state, 0x24, sizeof(state));
    if (gUnk_03000400 != 0)
        return 0;

    result = 0;
    if (memcmp(header, gSramImageSignature, sizeof(header)) == 0)
    {
        if ((flags & 3) == flags)
        {
            if (state <= 1)
                result = 1;
        }
    }

    return result;
}

void func_08000358(void *destination)
{
    u32 zero;

    func_080006A4(destination, 0, gSramImageSignature, 0x20);
    if (gUnk_03000400 != 0)
        return;

    zero = 0;
    func_080006A4(destination, 0x20, &zero, sizeof(zero));
    if (gUnk_03000400 != 0)
        return;

    func_080006A4(destination, 0x24, &zero, sizeof(zero));
}

u32 func_080003A0(void *source)
{
    u32 value;

    if (!func_080002E0(source))
        return 0;

    value = 0;
    func_080006E4(source, &value, 0x20, sizeof(value));
    if (gUnk_03000400 != 0)
        return 0;

    return value;
}

u32 func_080003DC(u32 unused, u32 index)
{
    register u32 multiplier asm("r0") = 0x3FEC;

    // Emits no instruction; keeps the original literal-load-and-multiply form.
    __asm__ volatile ("" : "+r"(multiplier));
    return index * multiplier + 0x28;
}

void func_080003E8(void *source, u32 index)
{
    u32 value = 0;

    func_080006E4(source, &value, 0x20, sizeof(value));
    if (gUnk_03000400 == 0)
    {
        value |= 1 << index;
        func_080006A4(source, 0x20, &value, sizeof(value));
    }
}

void func_0800042C(void *source, u32 index)
{
    u32 value = 0;

    func_080006E4(source, &value, 0x20, sizeof(value));
    if (gUnk_03000400 == 0)
    {
        value &= ~(1 << index);
        func_080006A4(source, 0x20, &value, sizeof(value));
    }
}

void func_08000470(void *destination, u32 value)
{
    func_080006A4(destination, 0x24, &value, sizeof(value));
}

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
