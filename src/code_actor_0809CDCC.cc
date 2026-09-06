#include "counter_and_maximum.hh"

EC bool func_0809CDCC(CounterAndMaximum const * entries)
{
    bool result = true;

    for (u32 index = 8; index <= 58; ++index)
    {
        if (entries[index].count == 0)
            result = false;
    }

    return result;
}
