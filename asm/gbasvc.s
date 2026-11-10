	.INCLUDE "asm/macro.inc"
	.include "six/asm/hw/irq.s"
	.include "six/asm/hw/memory.s"
	.include "six/asm/hw/svc.s"
	.SYNTAX UNIFIED

	thumb_func_start ArcTan2
ArcTan2: @ 0x080D3748
	svc #SVC_ARCTAN2
	bx lr

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x080D374C
	svc #SVC_CPUFASTSET
	bx lr

	thumb_func_start CpuSet
CpuSet: @ 0x080D3750
	svc #SVC_CPUSET
	bx lr

	thumb_func_start IntrWait
IntrWait: @ 0x080D3754
	movs r2, #0
	svc #SVC_INTRWAIT
	bx lr
	.align 2, 0

	thumb_func_start SoftReset
SoftReset: @ 0x080D375C
	ldr r3, .L080D376C
	movs r2, #0
	strb r2, [r3]
	ldr r1, .L080D3770
	mov sp, r1
	svc #SVC_REGISTERRAMRESET
	svc #SVC_SOFTRESET
	movs r0, r0
	.align 2, 0
.L080D376C: .word REG_IME
.L080D3770: .word IWRAM_END - 0x100

	thumb_func_start Sqrt
Sqrt: @ 0x080D3774
	svc #SVC_SQRT
	bx lr
