#include "counter_and_maximum.hh"

EC u32 func_0809CDEC(CounterAndMaximum const * entries)
{
    u32 result = 0;

    for (u32 index = 8; index <= 58; ++index)
    {
        result += entries[index].count;

        if (result > 999999999)
            result = 1000000000;
    }

    return result;
}
