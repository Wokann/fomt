#include "counter_and_maximum.hh"

EC u32 func_0809CE24(CounterAndMaximum const * entries, u32 index)
{
    index <<= 3;
    u8 const * maximum = reinterpret_cast<u8 const *>(entries);

    maximum += 4;
    maximum += index;
    return *reinterpret_cast<u32 const *>(maximum);
}
