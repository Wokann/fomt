#include "hardware_refcount.hh"

extern void __builtin_delete(void *);

void * func_080079D0(void * owner)
{
    // The adjacent release routine decrements this word and frees the state
    // when it reaches zero. The rest of the pointed-to layout is unclassified.
    ++*(u32 *)(gUnk_03000408 + 0x924);
    return owner;
}

void func_080079E8(void * owner, u32 flags)
{
    u8 * state = gUnk_03000408;
    u32 * refcount = (u32 *)(state + 0x924);
    u32 remaining = *refcount - 1;
    *refcount = remaining;
    if (remaining == 0) {
        if (state != 0)
            __builtin_delete(state);
        gUnk_03000408 = (u8 *)remaining;
    }
    if (flags & 1)
        __builtin_delete(owner);
}
