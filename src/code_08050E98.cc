#include "prelude.h"

// Only the first owned pointer and its UI-adjacent flag byte are known.  The
// byte at offset 0x550 has a low six-bit field and unrelated high bits.
struct FirstFieldUiFlags
{
    u8 unused_00[0x550];
    unsigned low_flags : 6;
    unsigned unused_flags : 2;
};

struct FirstFieldUiOwner
{
    FirstFieldUiFlags * data;
};

EC u32 func_08050E98(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    // Both helpers report the field before changing it.
    u32 const old_flags = data->low_flags;
    data->low_flags &= ~flag_mask;
    return old_flags;
}

EC u32 func_08050EBC(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    u32 const old_flags = data->low_flags;
    data->low_flags |= flag_mask;
    return old_flags;
}
