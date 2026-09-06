#include "prelude.h"

struct PackedValue
{
    u8 unused[11];
    u8 high;
    u8 low;
};

struct PackedValueOwner
{
    PackedValue const * value;
};

EC u32 func_0803BE9C(PackedValueOwner const & owner)
{
    u32 const mask = 0x7F;
    u32 const high = owner.value->high >> 7;
    u32 const low = owner.value->low;
    return ((low & mask) << 1) | high;
}
