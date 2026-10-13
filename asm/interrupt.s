.include "asm/macro.inc"

.syntax unified
.thumb

@ These ROM wrappers enter the ARM interrupt-mask routine in IWRAM through
@ the interworking helper. Keep that ABI explicit until ordinary C matches
@ without fixed registers, empty asm, or changing unrelated calls.
.section .text.interrupt_enable
thumb_func_start func_080004F4
func_080004F4:
    push {lr}
    lsls r0, r0, #16
    ldr r1, .Lenable_mask_target
    bl _call_via_r1
    lsls r0, r0, #16
    lsrs r0, r0, #16
    pop {r1}
    bx r1
    .align 2, 0
.Lenable_mask_target:
    .word func_03000A1C
thumb_func_end func_080004F4

.section .text.interrupt_disable
thumb_func_start func_08000528
func_08000528:
    push {lr}
    lsls r0, r0, #16
    lsrs r0, r0, #16
    ldr r1, .Ldisable_mask_target
    bl _call_via_r1
    lsls r0, r0, #16
    lsrs r0, r0, #16
    pop {r1}
    bx r1
    .align 2, 0
.Ldisable_mask_target:
    .word func_03000A1C
thumb_func_end func_08000528
