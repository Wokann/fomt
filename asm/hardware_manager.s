    .section .text, "ax", %progbits
    .syntax unified
    .thumb
    .align 2, 0

    @ HardwareManagerVBlankBinding::~HardwareManagerVBlankBinding().
    @ The C++ lifetime model is known; two instruction operands still differ.
    .global _._28HardwareManagerVBlankBinding
    .type _._28HardwareManagerVBlankBinding, %function
    .thumb_func
_._28HardwareManagerVBlankBinding:
    push {r4, r5, lr}
    adds r4, r0, #0
    adds r5, r1, #0
    ldr r0, .LVBlankBindingVTable
    str r0, [r4, #0x14]
    movs r0, #1
    bl DisableInterrupts
    ldr r1, [r4, #0x10]
    movs r0, #0
    bl ExchangeInterruptHandler
    ldr r0, .LVBlankRestoreVTable
    str r0, [r4, #0x0c]
    ldr r1, .LVBlankCurrentBinding
    ldr r0, [r4, #8]
    str r0, [r1]
    ldrh r0, [r4, #4]
    cmp r0, #0
    beq .LVBlankInterruptRestored
    bl EnableInterrupts
.LVBlankInterruptRestored:
    movs r0, #1
    ands r5, r0
    cmp r5, #0
    beq .LVBlankBindingDestroyed
    adds r0, r4, #0
    bl __builtin_delete
.LVBlankBindingDestroyed:
    pop {r4, r5}
    pop {r0}
    bx r0
    .align 2, 0
.LVBlankBindingVTable: .4byte __vt_28HardwareManagerVBlankBinding
.LVBlankRestoreVTable: .4byte __vt_29HardwareManagerBindingRestore
.LVBlankCurrentBinding: .4byte gCurrentHardwareVBlankBinding
    .size _._28HardwareManagerVBlankBinding, . - _._28HardwareManagerVBlankBinding
