    .include "asm/macro.inc"
    .syntax unified
    .thumb

    @ Only the lake buried-item row selector remains native.
    .ifdef REGION_JP
    .section .text.GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .align 2, 0
    .global GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .thumb_func
GetLakeBuriedItemTableIndex__C14MineFloorStateUi:
    push	{lr}
    adds	r0, r1, #0
    cmp	r0, #9
    bls .Ljp_0809D20A
    movs	r0, #25
    cmp	r1, #255	@ 0xff
    beq .Ljp_0809D20A
    movs	r0, #24
    cmp	r1, #79	@ 0x4f
    bhi .Ljp_0809D20A
    movs	r0, #10
    movs	r2, #19
    cmp	r1, #19
    bcc .Ljp_0809D20A
    cmp	r1, #19
    bne .Ljp_0809D1F8
    movs	r0, #11
    b .Ljp_0809D20A
.Ljp_0809D1F8:
    adds	r0, #2
    adds	r2, #10
    cmp	r2, #79	@ 0x4f
    bhi .Ljp_0809D20A
    cmp	r1, r2
    bcc .Ljp_0809D20A
    cmp	r1, r2
    bne .Ljp_0809D1F8
    adds	r0, #1
.Ljp_0809D20A:
    pop	{r1}
    bx	r1
    .align 2, 0

    .else
    .section .text.GetLakeBuriedItemTableIndex__C14MineFloorStateUi
    .align 2, 0
    thumb_func_start GetLakeBuriedItemTableIndex__C14MineFloorStateUi
GetLakeBuriedItemTableIndex__C14MineFloorStateUi: @ 0x0809D79C
    push {lr}
    adds r0, r1, #0
    cmp r0, #9
    bls .L0809D7D2
    movs r0, #0x19
    cmp r1, #0xff
    beq .L0809D7D2
    movs r0, #0x18
    cmp r1, #0x4f
    bhi .L0809D7D2
    movs r0, #0xa
    movs r2, #0x13
    cmp r1, #0x13
    blo .L0809D7D2
    cmp r1, #0x13
    bne .L0809D7C0
    movs r0, #0xb
    b .L0809D7D2
.L0809D7C0:
    adds r0, #2
    adds r2, #0xa
    cmp r2, #0x4f
    bhi .L0809D7D2
    cmp r1, r2
    blo .L0809D7D2
    cmp r1, r2
    bne .L0809D7C0
    adds r0, #1
.L0809D7D2:
    pop {r1}
    bx r1
    .align 2, 0

    .endif
