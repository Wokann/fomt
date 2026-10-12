#include "sram_proxy.hh"
#include "sram_proxy_2.hh"
#include "libsram.h"

extern u32 func_080D100C(u32 index, void (*handler)(void));

void func_0800063C(void)
{
}

void *func_08000640(void *source)
{
    if (gUnk_03000402 == 0)
    {
        gUnk_03000402 = 1;
        gUnk_03000400 = 0;
    }
    return source;
}

u32 func_08000664(void *destination)
{
    u8 bytes[8];
    u8 index;
    u32 offset;
    u32 limit;

    for (index = 0; index <= 7; index++)
        bytes[index] = 0xFF;

    offset = 0;
    limit = 0x8000;
    do
    {
        func_080006A4(destination, offset, bytes, 8);
        offset += 8;
    } while (offset < limit);

    return 1;
}

u32 func_080006A4(void *destination, u32 offset, void const *source, u32 size)
{
    register u32 offset_register asm("r4") = offset;
    register void const *source_register asm("r5") = source;
    register u32 size_register asm("r2") = size;
    register u16 *status_register asm("r1") = &gUnk_03000400;
    register u32 zero asm("r0") = 0;
    u32 result;

    // Preserve agbcc's interworking-era register order for this SRAM call.
    __asm__ volatile ("" : "+r"(offset_register), "+r"(source_register),
                         "+r"(size_register));
    __asm__ volatile ("" : "+r"(status_register));
    __asm__ volatile ("" : "+r"(zero));
    *status_register = zero;
    if (size_register)
    {
        result = 1;
        if (WriteSramFastAndVerify(source_register, (u8 *)(0x0E000000 | offset_register), size_register))
        {
            func_08000728(destination, 0x100);
            result = 0;
        }
        return result;
    }
    return zero;
}

u32 func_080006E4(void *unused, void *destination, u32 offset, u32 size)
{
    gUnk_03000400 = 0;
    if (size == 0)
        return 0;

    ReadSramFast((u8 const *)(0x0E000000 | offset), destination, size);
    return 1;
}

u32 func_08000714(u8 const *context, void (*handler)(void))
{
    u32 flags = context[4];
    u32 mask = 3;
    return func_080D100C((flags & mask) + 3, handler);
}

void func_08000728(void *destination, u16 flag)
{
    switch (flag)
    {
    case 1:
        gUnk_03000400 |= 1;
        break;
    case 2:
        gUnk_03000400 |= 2;
        break;
    case 0x100:
    case 0x200:
        gUnk_03000400 |= flag;
        break;
    case 4:
        gUnk_03000400 |= 4;
        break;
    case 0x20:
        gUnk_03000400 |= 0x20;
        break;
    case 8:
        gUnk_03000400 |= 8;
        break;
    case 0x10:
        gUnk_03000400 |= 0x10;
        break;
    case 0x40:
        gUnk_03000400 |= 0x40;
        break;
    case 0x80:
        gUnk_03000400 |= 0x80;
        break;
    }
}
