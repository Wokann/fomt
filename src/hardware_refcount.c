#include "hardware_refcount.hh"

void * func_080079D0(void * owner)
{
    // The adjacent release routine decrements this word and frees the state
    // when it reaches zero. The rest of the pointed-to layout is unclassified.
    ++*(u32 *)(gUnk_03000408 + 0x924);
    return owner;
}
