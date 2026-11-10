#pragma implementation "ui_vcount_lifetimes.hh"
#include "prelude.h"

#pragma interface "ui_vcount_lifetimes.hh"
// Complete native destructor entry; the class declaration retains its C++ ABI.
extern "C" inline NAKED void DestroyUiVCountRegistration(void *, u32)
    asm("_._27UiVCountContextRegistration");
extern "C" inline NAKED void DestroyUiVCountRegistration(void *, u32)
{
        asm_unified(
            "    push {lr}\n"
            "    adds r3, r0, #0\n"
            "    ldr r0, .Lbinding_1_pool_0\n"
            "    str r0, [r3, #4]\n"
            "    ldr r2, .Lbinding_1_pool_1\n"
            "    ldr r0, [r3, #0]\n"
            "    str r0, [r2, #0]\n"
            "    movs r0, #1\n"
            "    ands r0, r1\n"
            "    cmp r0, #0\n"
            "    beq .Lbinding_1_branch_0\n"
            "    adds r0, r3, #0\n"
            "    bl __builtin_delete\n"
            ".Lbinding_1_branch_0:\n"
            "    pop {r0}\n"
            "    bx r0\n"
            "    .align 2, 0\n"
            ".Lbinding_1_pool_0: .word __vt_20UiVCountContextScope\n"
            "    .align 2, 0\n"
            ".Lbinding_1_pool_1: .word gUiVCountContext\n"
            "    .align 2, 0\n"
        );
}

#include "ui_vcount_lifetimes.hh"
