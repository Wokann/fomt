#include "prelude.h"

u32 func_0809D7D8(u32 unused, u32 value)
{
    switch (value)
    {
    case 0xFF:
        return 0x37;
    case 0x1E:
    case 0x46:
    case 0x5A:
        return 0x1E;
    case 0x28:
    case 0x3C:
    case 0x50:
        return 0x1F;
    case 0x32:
    case 0x64:
    case 0x96:
    case 0xC8:
        return 0x20;
    case 0x6E:
    case 0x82:
    case 0xAA:
    case 0xBE:
        return 0x2A;
    case 0x78:
    case 0x8C:
    case 0xA0:
    case 0xB4:
        return 0x2B;
    }

    if (value <= 0x14)
        return value;
    if (value > 0xFA)
        return 0x36;
    if (value <= 0x63)
        return value % 10 + 0x14;
    if (value > 0xC7)
        return value % 10 + 0x2B;
    return value % 10 + 0x20;
}
