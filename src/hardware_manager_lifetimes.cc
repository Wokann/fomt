#pragma implementation "hardware_manager_lifetimes.hh"
#include "prelude.h"

#pragma interface "hardware_manager_lifetimes.hh"
// Complete native destructor entry; the class declaration retains its C++ ABI.
extern "C" inline NAKED void DestroyPreviousVBlankBinding(void *, u32)
    asm("_._30HardwareManagerPreviousBinding");
extern "C" inline NAKED void DestroyPreviousVBlankBinding(void *, u32)
{
        asm_unified(
            "    push {lr}\n"
            "    adds r3, r0, #0\n"
            "    ldr r0, .Lbinding_2_pool_0\n"
            "    str r0, [r3, #4]\n"
            "    ldr r2, .Lbinding_2_pool_1\n"
            "    ldr r0, [r3, #0]\n"
            "    str r0, [r2, #0]\n"
            "    movs r0, #1\n"
            "    ands r0, r1\n"
            "    cmp r0, #0\n"
            "    beq .Lbinding_2_branch_0\n"
            "    adds r0, r3, #0\n"
            "    bl __builtin_delete\n"
            ".Lbinding_2_branch_0:\n"
            "    pop {r0}\n"
            "    bx r0\n"
            "    .align 2, 0\n"
            ".Lbinding_2_pool_0: .word __vt_29HardwareManagerBindingRestore\n"
            "    .align 2, 0\n"
            ".Lbinding_2_pool_1: .word gCurrentHardwareVBlankBinding\n"
            "    .align 2, 0\n"
        );
}

#include "hardware_manager_lifetimes.hh"
