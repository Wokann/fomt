#include "obj_tile_pool.hh"

    .include "asm/macro.inc"
    .syntax unified

    .section .text.obj_tile_pool_init, "ax", %progbits

    thumb_func_start InitializeObjTilePoolOwner
InitializeObjTilePoolOwner: @ 0x08007874
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    str r0, [sp, #8]
    ldr r0, .L080079B4 @ =gObjTilePool
    ldr r4, [r0]
    cmp r4, #0
    beq .L0800788C
    b .L08007992
.L0800788C:
    ldr r0, .L080079B8 @ =OBJ_TILE_POOL_BYTES
    bl __builtin_new
    mov r8, r0
    str r4, [sp]
    mov r1, r8
    adds r1, #OBJ_TILE_POOL_FREE_LIST_OFFSET
    mov r2, sp
    adds r2, #4
    str r2, [sp, #0x2c]
    cmp r8, r1
    beq .L080078AC
    movs r2, #0
.L080078A6:
    stm r0!, {r2}
    cmp r0, r1
    bne .L080078A6
.L080078AC:
    mov r0, r8
    adds r0, #OBJ_TILE_POOL_ENTRIES_OFFSET
    movs r1, #(OBJ_TILE_HANDLE_COUNT >> 1)
    lsls r1, r1, #1
    movs r2, #0
    bl InitializeObjTileFreeList
    mov r1, r8
    str r0, [r1, #OBJ_TILE_POOL_FREE_LIST_OFFSET]
    ldr r1, .L080079BC @ =OBJ_TILE_POOL_TREE_OFFSET
    add r1, r8
    movs r0, #0
    strb r0, [r1]
    movs r0, #1
    strb r0, [r1, #1]
    ldr r2, .L080079C0 @ =(OBJ_TILE_POOL_TREE_OFFSET + OBJ_TILE_TREE_CHILDREN_OFFSET)
    add r2, r8
    movs r4, #1
    mov r0, r8
    adds r0, #OBJ_TILE_POOL_FREE_LIST_OFFSET
    str r0, [sp, #0x20]
    str r1, [sp, #0xc]
#if ((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    movs r1, #(OBJ_TILE_POOL_COUNT_OFFSET >> 4)
    lsls r1, r1, #4
#else
    ldr r1, .LObjTilePoolCountOffsetInit
#endif
    add r1, r8
    str r1, [sp, #0x10]
    ldr r0, .L080079C4 @ =OBJ_TILE_POOL_REFCOUNT_OFFSET
    add r0, r8
    str r0, [sp, #0x14]
    ldr r1, .L080079C8 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET
    add r1, r8
    str r1, [sp, #0x18]
    ldr r0, .L080079CC @ =OBJ_TILE_POOL_RESERVED_COUNT_OFFSET
    add r0, r8
    str r0, [sp, #0x1c]
    movs r7, #0
    mov ip, r4
    movs r6, #1
    rsbs r6, r6, #0
.L080078FA:
    strb r7, [r2]
    mov r1, ip
    strb r1, [r2, #1]
    adds r0, r2, #OBJ_TILE_TREE_CHILDREN_OFFSET
    movs r3, #1
    adds r2, #OBJ_TILE_TREE512_BYTES
    str r2, [sp, #0x28]
    subs r4, #1
    str r4, [sp, #0x24]
.L0800790C:
    strb r7, [r0]
    mov r2, ip
    strb r2, [r0, #1]
    adds r2, r0, #OBJ_TILE_TREE_CHILDREN_OFFSET
    movs r1, #1
    adds r0, #OBJ_TILE_TREE256_BYTES
    mov sb, r0
    subs r3, #1
    mov sl, r3
.L0800791E:
    strb r7, [r2]
    mov r0, ip
    strb r0, [r2, #1]
    adds r0, r2, #OBJ_TILE_TREE_CHILDREN_OFFSET
    movs r3, #1
    adds r4, r2, #0
    adds r4, #OBJ_TILE_TREE128_BYTES
    subs r5, r1, #1
.L0800792E:
    strb r7, [r0]
    mov r1, ip
    strb r1, [r0, #1]
    adds r1, r0, #OBJ_TILE_TREE_CHILDREN_OFFSET
    movs r2, #1
    adds r0, #OBJ_TILE_TREE64_BYTES
    subs r3, #1
.L0800793C:
    stm r1!, {r7}
    subs r2, #1
    cmp r2, r6
    bne .L0800793C
    cmp r3, r6
    bne .L0800792E
    adds r2, r4, #0
    adds r1, r5, #0
    cmp r1, r6
    bne .L0800791E
    mov r0, sb
    mov r3, sl
    cmp r3, r6
    bne .L0800790C
    ldr r2, [sp, #0x28]
    ldr r4, [sp, #0x24]
    cmp r4, r6
    bne .L080078FA
    movs r0, #0
    ldr r2, [sp, #0x10]
    strh r0, [r2]
    ldr r1, [sp, #0x14]
    str r0, [r1]
    ldr r2, [sp, #0x18]
    strh r0, [r2]
    ldr r1, [sp, #0x1c]
    strh r0, [r1]
    str r0, [sp, #4]
    mov r0, r8
    ldr r2, [sp, #0x20]
    cmp r8, r2
    beq .L08007986
    ldr r1, [sp, #0x2c]
    ldr r3, [r1]
.L08007980:
    stm r0!, {r3}
    cmp r0, r2
    bne .L08007980
.L08007986:
    ldr r0, [sp, #0xc]
    bl Clear__15ObjTileTree1024
    mov r2, r8
    ldr r0, .L080079B4 @ =gObjTilePool
    str r2, [r0]
.L08007992:
    ldr r0, .L080079B4 @ =gObjTilePool
    ldr r1, [r0]
    ldr r2, .L080079C4 @ =OBJ_TILE_POOL_REFCOUNT_OFFSET
    adds r1, r1, r2
    ldr r0, [r1]
    adds r0, #1
    str r0, [r1]
    ldr r0, [sp, #8]
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1
    .align 2, 0
.L080079B4: .word gObjTilePool
.L080079B8: .word OBJ_TILE_POOL_BYTES
.L080079BC: .word OBJ_TILE_POOL_TREE_OFFSET
.L080079C0: .word (OBJ_TILE_POOL_TREE_OFFSET + OBJ_TILE_TREE_CHILDREN_OFFSET)
.L080079C4: .word OBJ_TILE_POOL_REFCOUNT_OFFSET
.L080079C8: .word OBJ_TILE_POOL_RESERVED_FIRST_OFFSET
.L080079CC: .word OBJ_TILE_POOL_RESERVED_COUNT_OFFSET
#if !((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
.LObjTilePoolCountOffsetInit: .word OBJ_TILE_POOL_COUNT_OFFSET
#endif
    .section .text.obj_tile_pool_reservation, "ax", %progbits

    thumb_func_start SetObjTileReservation
SetObjTileReservation: @ 0x08007A28
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, sb
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x18
    str r1, [sp]
    str r2, [sp, #4]
    ldr r0, .L08007B44 @ =gObjTilePool
    ldr r5, [r0]
    ldr r0, .L08007B48 @ =OBJ_TILE_POOL_RESERVED_COUNT_OFFSET
    adds r4, r5, r0
    ldrh r0, [r4]
    cmp r0, #0
    beq .L08007A5A
    ldr r1, .L08007B4C @ =OBJ_TILE_POOL_TREE_OFFSET
    adds r0, r5, r1
    ldr r2, .L08007B50 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET
    adds r1, r5, r2
    ldrh r1, [r1]
    ldrh r2, [r4]
    bl Unreserve__15ObjTileTree1024UiUi
    movs r0, #0
    strh r0, [r4]
.L08007A5A:
    ldr r0, [sp, #4]
    cmp r0, #0
    beq .L08007B32
    ldr r1, [sp]
    adds r1, r1, r0
    str r1, [sp, #8]
    movs r7, #0
#if ((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    movs r2, #(OBJ_TILE_POOL_COUNT_OFFSET >> 4)
    lsls r2, r2, #4
#else
    ldr r2, .LObjTilePoolCountOffsetReserve
#endif
    adds r0, r5, r2
    ldrh r1, [r0]
    str r4, [sp, #0x14]
    subs r2, #OBJ_TILE_TREE1024_BYTES
    adds r2, r5, r2
    str r2, [sp, #0xc]
    ldr r2, .L08007B50 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET
    adds r2, r5, r2
    str r2, [sp, #0x10]
    mov sl, r0
    cmp r1, #0
    beq .L08007B18
    movs r0, #OBJ_TILE_POOL_ENTRIES_OFFSET
    adds r0, r0, r5
    mov r8, r0
    mov r6, r8
.L08007A8C:
    movs r0, #0
    cmp r7, #(OBJ_TILE_HANDLE_COUNT - 1)
    bhi .L08007AAA
    lsrs r1, r7, #OBJ_TILE_SLOT_WORD_SHIFT
    lsls r1, r1, #2
    adds r1, r5, r1
    movs r0, #(OBJ_TILE_SLOT_WORD_BITS - 1)
    ands r0, r7
    movs r2, #1
    lsls r2, r0
    ldr r1, [r1]
    ands r1, r2
    rsbs r0, r1, #0
    orrs r0, r1
    lsrs r0, r0, #0x1f
.L08007AAA:
    cmp r0, #0
    beq .L08007B04
    ldrh r0, [r6]
    lsls r4, r0, #(32 - OBJ_TILE_INDEX_BITS)
    lsrs r3, r4, #(32 - OBJ_TILE_INDEX_BITS)
    ldrb r0, [r6, #1]
    lsls r2, r0, #(32 - (OBJ_TILE_INDEX_BITS - 8) - OBJ_TILE_SIZE_SHIFT_BITS)
    lsrs r1, r2, #(32 - OBJ_TILE_SIZE_SHIFT_BITS)
    movs r0, #1
    mov sb, r0
    lsls r0, r1
    adds r0, r3, r0
    ldr r1, [sp]
    cmp r1, r0
    bhs .L08007B04
    ldr r0, [sp, #8]
    cmp r3, r0
    bhs .L08007B04
    adds r1, r3, #0
    lsrs r2, r2, #(32 - OBJ_TILE_SIZE_SHIFT_BITS)
    ldr r0, [sp, #0xc]
    bl Free__15ObjTileTree1024UiUi
    movs r0, #0
    strh r0, [r6, #OBJ_TILE_ENTRY_GENERATION_OFFSET]
    ldr r0, [r5, #OBJ_TILE_POOL_FREE_LIST_OFFSET]
    str r0, [r6]
    mov r1, r8
    str r1, [r5, #OBJ_TILE_POOL_FREE_LIST_OFFSET]
    cmp r7, #(OBJ_TILE_HANDLE_COUNT - 1)
    bhi .L08007AFC
    lsrs r2, r7, #OBJ_TILE_SLOT_WORD_SHIFT
    lsls r2, r2, #2
    adds r2, r5, r2
    movs r0, #(OBJ_TILE_SLOT_WORD_BITS - 1)
    ands r0, r7
    mov r1, sb
    lsls r1, r0
    ldr r0, [r2]
    bics r0, r1
    str r0, [r2]
.L08007AFC:
    mov r2, sl
    ldrh r0, [r2]
    subs r0, #1
    strh r0, [r2]
.L08007B04:
    adds r6, #OBJ_TILE_POOL_ENTRY_BYTES
    movs r0, #OBJ_TILE_POOL_ENTRY_BYTES
    add r8, r0
    adds r7, #1
    mov r1, sl
    ldrh r0, [r1]
    cmp r0, #0
    beq .L08007B18
    cmp r7, #(OBJ_TILE_HANDLE_COUNT - 1)
    bls .L08007A8C
.L08007B18:
    ldr r0, [sp, #0xc]
    ldr r1, [sp]
    ldr r2, [sp, #4]
    bl Reserve__15ObjTileTree1024UiUi
    mov r2, sp
    ldrh r0, [r2]
    ldr r2, [sp, #0x10]
    strh r0, [r2]
    mov r1, sp
    ldrh r2, [r1, #4]
    ldr r1, [sp, #0x14]
    strh r2, [r1]
.L08007B32:
    add sp, #0x18
    pop {r3, r4, r5}
    mov r8, r3
    mov sb, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r0}
    bx r0
    .align 2, 0
.L08007B44: .word gObjTilePool
.L08007B48: .word OBJ_TILE_POOL_RESERVED_COUNT_OFFSET
.L08007B4C: .word OBJ_TILE_POOL_TREE_OFFSET
.L08007B50: .word OBJ_TILE_POOL_RESERVED_FIRST_OFFSET
#if !((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
.LObjTilePoolCountOffsetReserve: .word OBJ_TILE_POOL_COUNT_OFFSET
#endif
