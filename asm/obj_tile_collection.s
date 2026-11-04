#include "obj_tile_collection.hh"

    .include "asm/macro.inc"
    .syntax unified

    .text

    thumb_func_start InitializeObjTileCollectionGroups
InitializeObjTileCollectionGroups:
    push {r4, r5, r6, r7, lr}
    mov r7, sl
    mov r6, r9
    mov r5, r8
    push {r5, r6, r7}
    sub sp, #0x30
    str r0, [sp, #0x14]
    str r1, [sp, #0x18]
#if OBJ_TILE_COLLECTION_STORAGE_BYTES <= 255
    movs r0, #OBJ_TILE_COLLECTION_STORAGE_BYTES
#else
    ldr r0, .LCollectionStorageSize
#endif
    bl __builtin_new
    str r0, [sp, #0x1c]
    adds r1, r0, #0
    movs r3, #(OBJ_TILE_COLLECTION_GROUP_COUNT - 1)
    movs r2, #0
    movs r4, #1
    negs r4, r4
.L080081B2:
    str r2, [r1]
    str r2, [r1, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    adds r0, r1, #0
    adds r0, #OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET
    str r2, [r0, #(OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET - OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET)]
    adds r1, #OBJ_TILE_COLLECTION_GROUP_BYTES
    subs r3, #1
    cmp r3, r4
    bne .L080081B2
    movs r0, #0
    str r0, [sp, #0x20]
.L080081C8:
    ldr r1, [sp, #0x18]
    ldr r2, [sp, #0x20]
    adds r0, r1, r2
#if OBJ_TILE_COLLECTION_GROUP_BYTES == 20
    lsls r1, r2, #2
    adds r1, r1, r2
    lsls r1, r1, #2
#else
    ldr r1, .LCollectionGroupSize
    muls r1, r2, r1
#endif
    ldr r2, [sp, #0x1c]
    adds r7, r1, r2
    ldrb r6, [r0]
    adds r0, r7, #0
    adds r1, r6, #0
    bl Reserve__22ObjTileCollectionGroupUi
    subs r0, r6, #1
    lsls r0, r0, #0x18
    lsrs r6, r0, #0x18
    ldr r0, [sp, #0x20]
    adds r0, #1
    str r0, [sp, #0x24]
    cmp r6, #0xff
    bne .L080081F4
    b .L08008336
.L080081F4:
    add r1, sp, #4
    mov r9, r1
.L080081F8:
    mov r0, r9
    bl InitializeObjTilePoolOwner
    mov r0, r9
    ldr r1, [sp, #0x20]
    bl AllocateObjTileHandle
    str r0, [sp, #8]
    ldr r4, [r7, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    ldr r0, [r7, #OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET]
    cmp r4, r0
    beq .L08008232
.L08008210:
    cmp r4, #0
    beq .L08008226
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    mov r2, r9
    ldr r1, [r2, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
    adds r0, r4, #0
    bl RetainObjTileHandle
    str r0, [r4, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
.L08008226:
    ldr r0, [r7, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    adds r0, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    str r0, [r7, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    subs r6, #1
    str r6, [sp, #0x28]
    b .L0800831A
.L08008232:
    mov r8, r4
    movs r0, #1
    str r0, [sp, #0x10]
    ldr r1, [r7]
    subs r0, r4, r1
    asrs r4, r0, #OBJ_TILE_COLLECTION_ENTRY_SHIFT
    str r4, [sp, #0xc]
    add r2, sp, #0x10
    add r0, sp, #0xc
    cmp r4, #1
    bcs .L0800824A
    adds r0, r2, #0
.L0800824A:
    ldr r0, [r0]
    adds r0, r4, r0
    cmp r0, #0
    beq .L0800826A
    lsls r4, r0, #OBJ_TILE_COLLECTION_ENTRY_SHIFT
    adds r0, r4, #0
    bl malloc
    str r4, [sp, #0x2c]
    cmp r0, #0
    bne .L08008266
    adds r0, r4, #0
    bl RetryMemoryAllocation
.L08008266:
    ldr r1, [r7]
    b .L08008270
.L0800826A:
    movs r0, #0
    movs r2, #0
    str r2, [sp, #0x2c]
.L08008270:
    adds r5, r0, #0
    mov sl, r5
    adds r5, r1, #0
    mov r4, sl
.L0800827C:
    subs r6, #1
    str r6, [sp, #0x28]
.L08008280:
    cmp r5, r8
    beq .L0800829C
.L08008284:
    cmp r4, #0
    beq .L08008294
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    ldr r1, [r5, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
    adds r0, r4, #0
    bl RetainObjTileHandle
    str r0, [r4, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
.L08008294:
    adds r5, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    adds r4, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    cmp r5, r8
    bne .L08008284
.L0800829C:
    adds r5, r4, #0
    ldr r0, [sp, #0x10]
    cmp r0, #1
    bne .L080082BE
    cmp r5, #0
    beq .L080082BA
    adds r0, r5, #0
    bl InitializeObjTilePoolOwner
    mov r0, r9
    ldr r1, [r0, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
    adds r0, r5, #0
    bl RetainObjTileHandle
    str r0, [r5, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
.L080082BA:
    adds r5, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    b .L080082E6
.L080082BE:
    adds r6, r0, #0
    adds r4, r5, #0
.L080082C2:
    cmp r6, #0
    beq .L080082E4
.L080082C6:
    cmp r4, #0
    beq .L080082DC
    adds r0, r4, #0
    bl InitializeObjTilePoolOwner
    mov r2, r9
    ldr r1, [r2, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
    adds r0, r4, #0
    bl RetainObjTileHandle
    str r0, [r4, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
.L080082DC:
    subs r6, #1
    adds r4, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    cmp r6, #0
    bne .L080082C6
.L080082E4:
    adds r5, r4, #0
.L080082E6:
    ldr r6, [r7, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    ldr r4, [r7]
.L080082EA:
    cmp r4, r6
    beq .L08008304
.L080082EE:
    ldr r1, [r4, #OBJ_TILE_COLLECTION_HANDLE_OFFSET]
    adds r0, r4, #0
    bl ReleaseObjTileHandle
    adds r0, r4, #0
    movs r1, #2
    bl _._16ObjTilePoolOwner
    adds r4, #OBJ_TILE_COLLECTION_ENTRY_BYTES
    cmp r4, r6
    bne .L080082EE
.L08008304:
    ldr r0, [r7]
    cmp r0, #0
    beq .L0800830E
    bl free
.L0800830E:
    ldr r0, [sp, #0x2c]
    add r0, sl
    mov r1, sl
    str r1, [r7]
    str r5, [r7, #OBJ_TILE_COLLECTION_GROUP_END_OFFSET]
    str r0, [r7, #OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET]
.L0800831A:
    ldr r1, [sp, #8]
    mov r0, r9
    bl ReleaseObjTileHandle
    mov r0, r9
    movs r1, #2
    bl _._16ObjTilePoolOwner
    ldr r2, [sp, #0x28]
    lsls r0, r2, #0x18
    lsrs r6, r0, #0x18
    cmp r6, #0xff
    beq .L08008336
    b .L080081F8
.L08008336:
    ldr r0, [r7]
    str r0, [r7, #OBJ_TILE_COLLECTION_GROUP_CURSOR_OFFSET]
    ldr r0, [sp, #0x24]
    str r0, [sp, #0x20]
    cmp r0, #(OBJ_TILE_COLLECTION_GROUP_COUNT - 1)
    bhi .L08008344
    b .L080081C8
.L08008344:
    ldr r1, [sp, #0x1c]
    ldr r2, [sp, #0x14]
    str r1, [r2]
    adds r0, r2, #0
    add sp, #0x30
    pop {r3, r4, r5}
    mov r8, r3
    mov r9, r4
    mov sl, r5
    pop {r4, r5, r6, r7}
    pop {r1}
    bx r1

#if OBJ_TILE_COLLECTION_STORAGE_BYTES > 255 || OBJ_TILE_COLLECTION_GROUP_BYTES != 20
    .align 2, 0
#endif
#if OBJ_TILE_COLLECTION_STORAGE_BYTES > 255
.LCollectionStorageSize: .word OBJ_TILE_COLLECTION_STORAGE_BYTES
#endif
#if OBJ_TILE_COLLECTION_GROUP_BYTES != 20
.LCollectionGroupSize: .word OBJ_TILE_COLLECTION_GROUP_BYTES
#endif
