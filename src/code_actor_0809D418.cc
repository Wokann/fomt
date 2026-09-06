#include "prelude.h"

EC u32 func_0809D418(u32 unused, u32 value)
{
    u32 result = 0;

    if (value != 0)
    {
        if (value <= 9)
        {
            result = 1;
        }
        else if (value <= 0x63)
        {
            result = 2;
            u32 next = 0x14;
            if (value >= next)
            {
                do
                {
                    ++result;
                    next += 0x14;
                } while (next <= 0x63 && value >= next);
            }
        }
        else if (value == 0x64)
        {
            result = 7;
        }
        else if (value <= 0xF9)
        {
            result = 8;
            u32 next = 0x82;
            if (value >= next)
            {
                do
                {
                    ++result;
                    next += 0x1E;
                } while (next <= 0xF9 && value >= next);
            }
        }
        else
        {
            result = 0xE;
            if (value <= 0xFE)
                result = 0xD;
        }
    }

    return result;
}
