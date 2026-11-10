#include "random.hh"

u32 RandomBelow(u32 limit)
{
    u32 sample = rand() & 0xFFFF;
    return (sample * limit) >> 16;
}
