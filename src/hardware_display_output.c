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

void func_080097A4(u8 * buffer)
{
    u8 * parameter_cursor = buffer + 4;
    u8 * oam = (u8 *)0x07000000;
    u8 * end = buffer + 4 + buffer[0] * 8;
    u32 priority = 0;
    do {
        u8 * entry = buffer + 4;
        if (entry != end) {
            do {
                u16 attributes = *(u16 *)(entry + 4);
                if ((attributes & 0x0C00) == priority) {
                    *(u32 *)oam = *(u32 *)entry;
                    *(u16 *)(oam + 4) = attributes;
                    *(u16 *)(oam + 6) = *(u16 *)(parameter_cursor + 6);
                    parameter_cursor += 8;
                    oam += 8;
                }
                entry += 8;
            } while (entry != end);
        }
        priority += 0x400;
    } while (priority <= 0xFFF);

    if (oam != (u8 *)0x07000400) {
        u32 hidden = 0x200;
        u8 * last = (u8 *)0x07000400;
        do {
            *(u32 *)oam = hidden;
            *(u16 *)(oam + 6) = *(u16 *)(parameter_cursor + 6);
            parameter_cursor += 8;
            oam += 8;
        } while (oam != last);
    }
}
