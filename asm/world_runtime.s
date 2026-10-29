    .syntax unified
    .cpu arm7tdmi
    .thumb
    .section .text, "ax", %progbits
    .align 2, 0

    @ Native world storage lifecycle and retained OBJ palette banks.

    .global __18GameSceneWorldDataG22GameSceneWorldMapOwner
    .type __18GameSceneWorldDataG22GameSceneWorldMapOwner, %function
    .thumb_func
__18GameSceneWorldDataG22GameSceneWorldMapOwner:
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov sl, r1
	ldr r0, [r1]
	movs r1, #0
	mov r2, sl
	str r1, [r2]
	str r0, [r5]
	movs r7, #0xca
	lsls r7, r7, #1
	adds r0, r5, r7
	str r1, [r0]
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r3, r5, r0
	movs r2, #0x15
	movs r1, #0xff
	mov ip, r1
	movs r4, #0
	movs r7, #1
	mov r8, r7
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, #0xa0
	adds r1, r5, r0
.L080AC6B0:
	ldrb r0, [r1]
	mov r7, ip
	orrs r0, r7
	strb r0, [r1]
	strb r4, [r1, #1]
	strb r4, [r1, #2]
	mov r0, r8
	strb r0, [r1, #3]
	adds r1, #0x84
	subs r2, #1
	cmp r2, r6
	bne .L080AC6B0
	ldr r1, .L080AC814 @ =0x00000B78
	adds r4, r3, r1
	movs r6, #0xc
	ldr r2, .L080AC818 @ =0x00000C14
	adds r7, r3, r2
	ldr r0, .L080AC81C @ =0x00000C15
	adds r0, r0, r3
	mov r8, r0
	ldr r1, .L080AC820 @ =0x0000102C
	adds r1, r5, r1
	str r1, [sp, #8]
	adds r2, r5, #4
	str r2, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r0, r5, r0
	str r0, [sp, #0xc]
	movs r1, #0
	mov sb, r1
.L080AC6EE:
	adds r0, r4, #0
	bl func_08007128
	adds r0, r4, #0
	bl AllocateHardwarePoolHandle
	adds r1, r0, #0
	str r1, [r4, #4]
	adds r0, r4, #0
	bl GetHardwarePoolHandleIndex
	strb r0, [r4, #8]
	movs r0, #0xff
	strb r0, [r4, #9]
	mov r2, sb
	strb r2, [r4, #0xa]
	adds r4, #0xc
	subs r6, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	bne .L080AC6EE
	movs r4, #0
	strb r4, [r7]
	mov r7, r8
	strb r4, [r7]
	movs r1, #0xdb
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, .L080AC824 @ =gActorIndexedResourceArchive
	bl __22IndexedResourceArchivePCUc
	movs r2, #0xde
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, .L080AC828 @ =gUnk_086678A0
	bl __22IndexedResourceArchivePCUc
	movs r7, #0xe1
	lsls r7, r7, #4
	adds r0, r5, r7
	ldr r1, .L080AC82C @ =gUnk_0871EF00
	bl __22IndexedResourceArchivePCUc
	movs r1, #0xe4
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, .L080AC830 @ =gUnk_086FAA80
	bl __22IndexedResourceArchivePCUc
	movs r2, #0xe7
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, .L080AC834 @ =gUnk_0871D51C
	bl __22IndexedResourceArchivePCUc
	adds r7, #0x90
	adds r0, r5, r7
	ldr r1, .L080AC838 @ =gUnk_0871EDD4
	bl __22IndexedResourceArchivePCUc
	movs r1, #0xed
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, .L080AC83C @ =gUnk_0871ECAC
	bl __22IndexedResourceArchivePCUc
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, .L080AC840 @ =gUnk_08667060
	bl __22IndexedResourceArchivePCUc
	adds r7, #0x90
	adds r0, r5, r7
	ldr r1, .L080AC844 @ =gUnk_08727A74
	bl __22IndexedResourceArchivePCUc
	movs r1, #0xf6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, .L080AC848 @ =gUnk_08726CCC
	bl __22IndexedResourceArchivePCUc
	movs r2, #0xf9
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, .L080AC84C @ =gUnk_08727368
	bl __22IndexedResourceArchivePCUc
	adds r7, #0x90
	adds r0, r5, r7
	ldr r1, .L080AC850 @ =gUnk_08725DA0
	bl __22IndexedResourceArchivePCUc
	movs r1, #0xff
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, .L080AC854 @ =gUnk_086F2FAC
	bl __22IndexedResourceArchivePCUc
	movs r2, #0x81
	lsls r2, r2, #5
	adds r0, r5, r2
	str r4, [r0]
	adds r7, #0x64
	adds r0, r5, r7
	str r4, [r0]
	ldr r0, .L080AC858 @ =0x00001028
	adds r1, r5, r0
	str r4, [r1]
	movs r0, #0
	ldr r2, [sp, #8]
	strh r4, [r2]
	strh r4, [r2, #2]
	strb r0, [r1, #9]
	str r4, [sp]
	ldr r0, [sp, #4]
	ldr r1, [sp, #0xc]
	cmp r0, r1
	beq .L080AC7E8
	movs r2, #0
.L080AC7E2:
	stm r0!, {r2}
	cmp r0, r1
	bne .L080AC7E2
.L080AC7E8:
	mov r7, sl
	ldr r1, [r7]
	cmp r1, #0
	beq .L080AC800
	adds r0, r1, #0
	adds r0, #0x90
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080AC800:
	adds r0, r5, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
.L080AC814: .4byte 0x00000B78
.L080AC818: .4byte 0x00000C14
.L080AC81C: .4byte 0x00000C15
.L080AC820: .4byte 0x0000102C
.L080AC824: .4byte gActorIndexedResourceArchive
.L080AC828:
    .ifdef REGION_JP
    .4byte gUnk_083ED9FC
    .else
    .4byte gUnk_086678A0
    .endif
.L080AC82C:
    .ifdef REGION_JP
    .4byte gUnk_084A5068
    .else
    .4byte gUnk_0871EF00
    .endif
.L080AC830:
    .ifdef REGION_JP
    .4byte gUnk_08480BDC
    .else
    .4byte gUnk_086FAA80
    .endif
.L080AC834:
    .ifdef REGION_JP
    .4byte gUnk_084A3678
    .else
    .4byte gUnk_0871D51C
    .endif
.L080AC838:
    .ifdef REGION_JP
    .4byte gUnk_084A4F3C
    .else
    .4byte gUnk_0871EDD4
    .endif
.L080AC83C:
    .ifdef REGION_JP
    .4byte gUnk_084A4E14
    .else
    .4byte gUnk_0871ECAC
    .endif
.L080AC840:
    .ifdef REGION_JP
    .4byte gUnk_083ED1BC
    .else
    .4byte gUnk_08667060
    .endif
.L080AC844:
    .ifdef REGION_JP
    .4byte gUnk_084ADBDC
    .else
    .4byte gUnk_08727A74
    .endif
.L080AC848:
    .ifdef REGION_JP
    .4byte gUnk_084ACE34
    .else
    .4byte gUnk_08726CCC
    .endif
.L080AC84C:
    .ifdef REGION_JP
    .4byte gUnk_084AD4D0
    .else
    .4byte gUnk_08727368
    .endif
.L080AC850:
    .ifdef REGION_JP
    .4byte gUnk_084ABF08
    .else
    .4byte gUnk_08725DA0
    .endif
.L080AC854:
    .ifdef REGION_JP
    .4byte gUnk_08479108
    .else
    .4byte gUnk_086F2FAC
    .endif
.L080AC858: .4byte 0x00001028
    .size __18GameSceneWorldDataG22GameSceneWorldMapOwner, . - __18GameSceneWorldDataG22GameSceneWorldMapOwner

    .global _._18GameSceneWorldData
    .type _._18GameSceneWorldData, %function
    .thumb_func
_._18GameSceneWorldData:
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r6, #0
	adds r4, r5, #4
.L080AC866:
	ldr r1, [r4]
	cmp r1, #0
	beq .L080AC878
	ldr r0, [r1, #0x14]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080AC878:
	adds r4, #4
	adds r6, #1
	cmp r6, #0x63
	bls .L080AC866
	ldr r1, .L080AC95C @ =0x00001028
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq .L080AC896
	ldr r0, [r1, #0x24]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080AC896:
	ldr r2, .L080AC960 @ =0x00001024
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0
	beq .L080AC8A6
	movs r1, #3
    .ifdef REGION_JP
    bl func_080AAD1C
    .else
    bl func_080AB2E4
    .endif
.L080AC8A6:
	movs r1, #0x81
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq .L080AC8B8
	movs r1, #3
	bl _._22EntityAuxiliarySprites
.L080AC8B8:
	movs r2, #0xff
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r1, .L080AC964 @ =__vt_23IndexedResourceProvider
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x30
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xd1
	lsls r0, r0, #4
	adds r6, r5, r0
	cmp r6, #0
	beq .L080AC932
	ldr r1, .L080AC968 @ =0x00000DAC
	adds r4, r5, r1
	cmp r6, r4
	beq .L080AC932
.L080AC91C:
	subs r4, #0xc
	ldr r1, [r4, #4]
	adds r0, r4, #0
	bl ReleaseHardwarePoolHandle
	adds r0, r4, #0
	movs r1, #2
	bl _._17HardwarePoolOwner
	cmp r6, r4
	bne .L080AC91C
.L080AC932:
	ldr r1, [r5]
	cmp r1, #0
	beq .L080AC948
	adds r0, r1, #0
	adds r0, #0x90
	ldr r0, [r0]
	ldr r2, [r0, #8]
	adds r0, r1, #0
	movs r1, #3
	bl _call_via_r2
.L080AC948:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq .L080AC956
	adds r0, r5, #0
	bl __builtin_delete
.L080AC956:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
.L080AC95C: .4byte 0x00001028
.L080AC960: .4byte 0x00001024
.L080AC964: .4byte __vt_23IndexedResourceProvider
.L080AC968: .4byte 0x00000DAC
    .size _._18GameSceneWorldData, . - _._18GameSceneWorldData

    .global AcquirePaletteBank__21GameScenePaletteCacheUi
    .type AcquirePaletteBank__21GameScenePaletteCacheUi, %function
    .thumb_func
AcquirePaletteBank__21GameScenePaletteCacheUi:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r0, r5, #5
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r4, r0
	adds r6, r0, #0
	adds r6, #0xa0
	ldrb r0, [r6]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x1f
	cmp r7, #0
	beq .L080AC9A4
	movs r2, #0
	ldrsb r2, [r6, r2]
	ldr r0, .L080AC9A0 @ =0x00000B78
	adds r1, r4, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
.L080AC99A:
	ldrb r0, [r1, #8]
	b .L080AC9E4
	.align 2, 0
.L080AC9A0: .4byte 0x00000B78
.L080AC9A4:
	ldr r0, .L080AC9D8 @ =0x00000C14
	adds r2, r4, r0
	ldrb r3, [r2]
	cmp r3, #0xd
	bhs .L080AC9E0
	adds r1, r3, #0
	adds r0, r1, #1
	strb r0, [r2]
	ldr r0, .L080AC9DC @ =0x00000B78
	adds r2, r4, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #9
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq .L080AC9CC
	strb r5, [r1, #9]
	strb r7, [r1, #0xa]
.L080AC9CC:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, r3
	beq .L080AC99A
	strb r3, [r6]
	b .L080AC99A
	.align 2, 0
.L080AC9D8: .4byte 0x00000C14
.L080AC9DC: .4byte 0x00000B78
.L080AC9E0:
	movs r0, #1
	rsbs r0, r0, #0
.L080AC9E4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
    .size AcquirePaletteBank__21GameScenePaletteCacheUi, . - AcquirePaletteBank__21GameScenePaletteCacheUi
