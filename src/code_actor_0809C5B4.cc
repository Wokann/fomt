#include "prelude.h"

// The caller-visible flag word accepts indices 0 through 13.
EC void func_0809C5B4(u32 & flags, u32 index)
{
    if (index <= 13)
        flags |= 1 << (index & 31);
}
