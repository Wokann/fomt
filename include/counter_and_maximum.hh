#ifndef COUNTER_AND_MAXIMUM_HH
#define COUNTER_AND_MAXIMUM_HH

#include "prelude.h"

// One record tracks an incrementing count and the largest observed value.
struct CounterAndMaximum
{
    u32 count;
    u32 maximum;
};

#endif // COUNTER_AND_MAXIMUM_HH
