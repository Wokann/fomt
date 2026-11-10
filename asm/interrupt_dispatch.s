    .include "asm/macro.inc"
    .syntax unified
    .section .iwram, "ax", %progbits

.include "six/asm/prelude.s"
.include "six/asm/hw/video.s"
.include "six/asm/hw/sound.s"
arm_func_start DispatchInterrupt
DispatchInterrupt:
    mov r2, #REG_BASE
    add r2, r2, #OFF_IE
    ldrb r1, [r2, #(REG_IME - REG_IE)]
    mrs r0, spsr
    ldr r3, [r2]
    push {r0, r1, r2, r3, lr}
    mov ip, #0
    mov r0, #IRQ_VBLANK
    and r1, r3, r3, lsr #16
    .LDispatchInterruptScan:
    tst r1, r0
    bne .LDispatchInterruptHandle
    add ip, ip, #2
    adds r0, r0, r0
    bne .LDispatchInterruptScan
    b .LDispatchInterruptReturn
    .LDispatchInterruptHandle:
    ldr r1, .LInterruptEnableMasks
    ldrh r1, [r1, ip]
    and r1, r1, r3
    orr r1, r1, r0, lsl #16
    ldr r3, .LInterruptHandlers
    ldr r3, [r3, ip, lsl #1]
    cmp r3, #MEM_ROM
    orrhs r1, r1, #IRQ_CARTRIDGE
    str r1, [r2]
    mov r1, #1
    strb r1, [r2, #(REG_IME - REG_IE)]
    ldr r2, .LInterruptBiosFlags
    ldrh r1, [r2]
    orr r1, r1, r0
    strh r1, [r2]
    mrs r0, apsr
    mov r1, r0
    bic r1, r1, #(PSR_I_BIT | PSR_F_BIT | PSR_MODE_MASK)
    orr r1, r1, #PSR_SYS_MODE
    msr cpsr_fc, r1
    push {r0, lr}
    cmp r3, #0
    mov lr, pc
    bxne r3
    pop {r0, lr}
    msr cpsr_fc, r0
    .LDispatchInterruptReturn:
    pop {r0, r1, r2, r3, lr}
    strh r3, [r2]
    msr spsr_fc, r0
    strb r1, [r2, #(REG_IME - REG_IE)]
    bx lr
.LInterruptEnableMasks: .word gInterruptNestingMasks
.LInterruptHandlers: .word gInterruptHandlers
.LInterruptBiosFlags: .word INTR_CHECK

arm_func_start ApplyInterruptEnableMask
ApplyInterruptEnableMask:
    cmp lr, #MEM_ROM
    ldr r3, .LInterruptEnableRegister
    ldrblo r2, [r3, #(REG_IME - REG_IE)]
    movhs r2, #1
    orrhs ip, r0, #(IRQ_CARTRIDGE << 16)
    strb r3, [r3, #(REG_IME - REG_IE)]
    ldrh r0, [r3]
    bic r1, r0, ip
    orr r1, r1, ip, lsr #16
    strh r1, [r3]
    strb r2, [r3, #(REG_IME - REG_IE)]
    bx lr
.LInterruptEnableRegister: .word REG_IE
