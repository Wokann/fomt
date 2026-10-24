    .ifdef REGION_JP
    @ JP revision 0 counterpart, expressed as real Thumb instructions and relocations.
    @ Actor behavior uses region-specific tables and branch targets.  The JP
    @ object stays byte-exact, with each external entry at its real location.

    .section .text.code_actor_0809C4E4
    .syntax unified
    .thumb
    .align 2, 0
    .Lcode_actor_0809C4E4:
    movs	r1, #0
    str	r1, [r0, #0]
    bx	lr
    .align 2, 0

    .section .text.code_actor_0809C4EC
    .align 2, 0
    .Lcode_actor_0809C4EC:
    push	{lr}
    adds	r3, r0, #0
    movs	r2, #0
    cmp	r1, #13
    bhi .Ljp_0809BF40
    movs	r0, #31
    ands	r0, r1
    movs	r2, #1
    lsls	r2, r0
    ldr	r1, [r3, #0]
    ands	r1, r2
    negs	r0, r1
    orrs	r0, r1
    lsrs	r2, r0, #31
.Ljp_0809BF40:
    movs	r0, #1
    eors	r0, r2
    pop	{r1}
    bx	r1
    .section .text.code_actor_0809C5B4
    .Lcode_actor_0809C5B4:

    .section .text.code_actor_0809C5D0
    .Lcode_actor_0809C5D0:

    .section .text.code_actor_0809C5EC
    .Lcode_actor_0809C5EC:

    .else
    .INCLUDE "asm/macro.inc"
    .SYNTAX UNIFIED
    .thumb

    .section .text.code_actor_0809C4E4
.L0809C4E4:

    .section .text.code_actor_0809C4EC
.L0809C4EC:
    .byte 0x00, 0xB5, 0x03, 0x1C
    .byte 0x00, 0x22, 0x0D, 0x29, 0x08, 0xD8, 0x1F, 0x20, 0x08, 0x40, 0x01, 0x22, 0x82, 0x40, 0x19, 0x68
    .byte 0x11, 0x40, 0x48, 0x42, 0x08, 0x43, 0xC2, 0x0F, 0x01, 0x20, 0x50, 0x40, 0x02, 0xBC, 0x08, 0x47

    .section .text.code_actor_0809C5B4
.L0809C5B4:

    .section .text.code_actor_0809C5D0
.L0809C5D0:

    .section .text.code_actor_0809C5EC
.L0809C5EC:

    .endif
