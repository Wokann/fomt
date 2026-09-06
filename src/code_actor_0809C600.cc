#include "small_u16_list.hh"

extern "C" u16 * func_080E3DB4(u16 * first, u16 * last, u16 const * value);

EC void func_0809C600(SmallU16ListState & state, u16 value)
{
    u16 * const first = state.entries;
    u16 * const end = state.entries + state.count;

    if (func_080E3DB4(first, end, &value) == end)
    {
        u16 const * const value_pointer = &value;
        u32 const count = state.count;

        if (count <= 2)
        {
            u16 * const entry = state.entries + count;

            if (entry != nullptr)
                *entry = *value_pointer;
            state.count = count + 1;
        }
    }
}
