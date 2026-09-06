#include "counter_and_maximum.hh"

// The caller-visible return value is the original array pointer.
EC CounterAndMaximum * func_0809CD78(CounterAndMaximum * entries)
{
    CounterAndMaximum * entry = entries;

    // The tracked table has entries 0 through 58 inclusive.
    for (i32 remaining = 58; remaining != -1; --remaining)
    {
        entry->count = 0;
        entry->maximum = 0;
        ++entry;
    }

    return entries;
}
