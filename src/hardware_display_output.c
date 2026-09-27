#include "hardware_display_output.hh"
#include "gbasvc.h"

extern void func_08008E64(void const * source, void * destination, u32 size);

void func_080096F0(void * object)
{
    func_08008E64(object, (void *)0x04000000, 0x54);
    *(volatile u16 *)0x04000054 = *(u16 *)((u8 *)object + 0x54);
}

void func_08009710(void * object)
{
    CpuFastSet(object, (void *)0x04000000, 0x10);
    CpuSet((u8 *)object + 0x40, (void *)0x04000040, 0x04000005);
    *(volatile u16 *)0x04000014 = *(u16 *)((u8 *)object + 0x14);
}

void * func_08009744(void * object, u8 byte1, u8 byte3)
{
    u8 * bytes = (u8 *)object;
    u8 * entry;
    u8 * end;

    bytes[1] = byte1 & 0x7F;
    bytes[0] = byte1 & 0x7F;
    bytes[3] = byte3 & 0x1F;
    bytes[2] = byte3 & 0x1F;
    entry = bytes + 4;
    end = bytes + 0x404;
    do {
        entry[1] = 2;
        entry += 8;
    } while (entry != end);
    return object;
}

void func_0800977C(void * object)
{
    func_08008E64((u8 *)object + 4, (void *)0x07000000, 0x400);
}

void func_08009790(void * object)
{
    CpuFastSet((u8 *)object + 4, (void *)0x07000000, 0x100);
}
