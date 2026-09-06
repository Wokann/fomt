#include "counter_and_maximum.hh"

EC bool func_0809CD98(CounterAndMaximum * entries, u32 index, u32 value)
{
    u8 * base = reinterpret_cast<u8 *>(entries);
    u32 new_maximum = value;
    bool changed = false;
    u32 offset = index << 3;
    u32 * count = reinterpret_cast<u32 *>(base + offset);

    if (*count <= 999999999)
        ++*count;

    u8 * maximum_base = base;

    maximum_base += 4;
    u32 * maximum = reinterpret_cast<u32 *>(maximum_base + offset);

    if (new_maximum > *maximum)
    {
        *maximum = new_maximum;
        changed = true;
    }

    return changed;
}
