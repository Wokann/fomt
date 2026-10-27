#include "sram_access.hh"
#include "libsram.h"
#include "interrupt.hh"

// Shared by the SRAM access contexts; startup zeroes this ordinary BSS.
u16 gSramAccessStatus;
u8 gSramAccessInitialized;

void func_0800063C(void)
{
}

SramAccess::SramAccess()
{
    if (gSramAccessInitialized == 0)
    {
        gSramAccessInitialized = 1;
        gSramAccessStatus = 0;
    }
}

bool SramAccess::Erase()
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
        Write(offset, bytes, sizeof(bytes));
        offset += 8;
    } while (offset < limit);

    return true;
}

bool SramAccess::Write(u32 offset, void const *source, u32 size)
{
    gSramAccessStatus = 0;
    if (size == 0)
        return false;

    bool success = true;
    if (WriteSramFastAndVerify(static_cast<u8 const *>(source),
            reinterpret_cast<u8 *>(0x0E000000 | offset), size) != 0) {
        AddStatusFlag(0x100);
        success = false;
    }
    return success;
}

bool SramAccess::Read(void *destination, u32 offset, u32 size)
{
    gSramAccessStatus = 0;
    if (size == 0)
        return false;

    ReadSramFast((u8 const *)(0x0E000000 | offset), static_cast<u8 *>(destination), size);
    return true;
}

u32 func_08000714(u8 const *context, void (*handler)(void))
{
    u32 flags = context[4];
    u32 mask = 3;
    return (u32)ExchangeInterruptHandler((flags & mask) + 3, handler);
}

void SramAccess::AddStatusFlag(u16 flag)
{
    switch (flag)
    {
    case 1:
        gSramAccessStatus |= 1;
        break;
    case 2:
        gSramAccessStatus |= 2;
        break;
    case 0x100:
    case 0x200:
        gSramAccessStatus |= flag;
        break;
    case 4:
        gSramAccessStatus |= 4;
        break;
    case 0x20:
        gSramAccessStatus |= 0x20;
        break;
    case 8:
        gSramAccessStatus |= 8;
        break;
    case 0x10:
        gSramAccessStatus |= 0x10;
        break;
    case 0x40:
        gSramAccessStatus |= 0x40;
        break;
    case 0x80:
        gSramAccessStatus |= 0x80;
        break;
    }
}
