#include "obj_tile_collection.hh"

#include <stdlib.h>

extern void __builtin_delete(void * pointer);

asm_unified(
    ".text\n"
    ".thumb\n"
    ".include \"asm/macro.inc\"\n"
    "    thumb_func_start InitializeObjTileCollectionGroups\n"
    "InitializeObjTileCollectionGroups:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, r9\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0x30\n"
    "    str r0, [sp, #0x14]\n"
    "    str r1, [sp, #0x18]\n"
#if OBJ_TILE_COLLECTION_STORAGE_BYTES <= 255
    "    movs r0, #" STRINGIFY(OBJ_TILE_COLLECTION_STORAGE_BYTES) "\n"
#else
    "    ldr r0, .LCollectionStorageSize\n"
#endif
    "    bl __builtin_new\n"
    "    str r0, [sp, #0x1c]\n"
    "    adds r1, r0, #0\n"
    "    movs r3, #(" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_COUNT) " - 1)\n"
    "    movs r2, #0\n"
    "    movs r4, #1\n"
    "    negs r4, r4\n"
    ".L080081B2:\n"
    "    str r2, [r1]\n"
    "    str r2, [r1, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    adds r0, r1, #0\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET) "\n"
    "    str r2, [r0, #(" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET) " - " STRINGIFY(OBJ_TILE_COLLECTION_GROUP_UNKNOWN_OFFSET) ")]\n"
    "    adds r1, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_BYTES) "\n"
    "    subs r3, #1\n"
    "    cmp r3, r4\n"
    "    bne .L080081B2\n"
    "    movs r0, #0\n"
    "    str r0, [sp, #0x20]\n"
    ".L080081C8:\n"
    "    ldr r1, [sp, #0x18]\n"
    "    ldr r2, [sp, #0x20]\n"
    "    adds r0, r1, r2\n"
#if OBJ_TILE_COLLECTION_GROUP_BYTES == 20
    "    lsls r1, r2, #2\n"
    "    adds r1, r1, r2\n"
    "    lsls r1, r1, #2\n"
#else
    "    ldr r1, .LCollectionGroupSize\n"
    "    muls r1, r2, r1\n"
#endif
    "    ldr r2, [sp, #0x1c]\n"
    "    adds r7, r1, r2\n"
    "    ldrb r6, [r0]\n"
    "    adds r0, r7, #0\n"
    "    adds r1, r6, #0\n"
    "    bl Reserve__22ObjTileCollectionGroupUi\n"
    "    subs r0, r6, #1\n"
    "    lsls r0, r0, #0x18\n"
    "    lsrs r6, r0, #0x18\n"
    "    ldr r0, [sp, #0x20]\n"
    "    adds r0, #1\n"
    "    str r0, [sp, #0x24]\n"
    "    cmp r6, #0xff\n"
    "    bne .L080081F4\n"
    "    b .L08008336\n"
    ".L080081F4:\n"
    "    add r1, sp, #4\n"
    "    mov r9, r1\n"
    ".L080081F8:\n"
    "    mov r0, r9\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    mov r0, r9\n"
    "    ldr r1, [sp, #0x20]\n"
    "    bl AllocateObjTileHandle\n"
    "    str r0, [sp, #8]\n"
    "    ldr r4, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    ldr r0, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET) "]\n"
    "    cmp r4, r0\n"
    "    beq .L08008232\n"
    ".L08008210:\n"
    "    cmp r4, #0\n"
    "    beq .L08008226\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    mov r2, r9\n"
    "    ldr r1, [r2, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    "    adds r0, r4, #0\n"
    "    bl RetainObjTileHandle\n"
    "    str r0, [r4, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    ".L08008226:\n"
    "    ldr r0, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    str r0, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    subs r6, #1\n"
    "    str r6, [sp, #0x28]\n"
    "    b .L0800831A\n"
    ".L08008232:\n"
    "    mov r8, r4\n"
    "    movs r0, #1\n"
    "    str r0, [sp, #0x10]\n"
    "    ldr r1, [r7]\n"
    "    subs r0, r4, r1\n"
    "    asrs r4, r0, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_SHIFT) "\n"
    "    str r4, [sp, #0xc]\n"
    "    add r2, sp, #0x10\n"
    "    add r0, sp, #0xc\n"
    "    cmp r4, #1\n"
    "    bcs .L0800824A\n"
    "    adds r0, r2, #0\n"
    ".L0800824A:\n"
    "    ldr r0, [r0]\n"
    "    adds r0, r4, r0\n"
    "    cmp r0, #0\n"
    "    beq .L0800826A\n"
    "    lsls r4, r0, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_SHIFT) "\n"
    "    adds r0, r4, #0\n"
    "    bl malloc\n"
    "    str r4, [sp, #0x2c]\n"
    "    cmp r0, #0\n"
    "    bne .L08008266\n"
    "    adds r0, r4, #0\n"
    "    bl RetryMemoryAllocation\n"
    ".L08008266:\n"
    "    ldr r1, [r7]\n"
    "    b .L08008270\n"
    ".L0800826A:\n"
    "    movs r0, #0\n"
    "    movs r2, #0\n"
    "    str r2, [sp, #0x2c]\n"
    ".L08008270:\n"
    "    adds r5, r0, #0\n"
    "    mov sl, r5\n"
    "    adds r5, r1, #0\n"
    "    mov r4, sl\n"
    ".L0800827C:\n"
    "    subs r6, #1\n"
    "    str r6, [sp, #0x28]\n"
    ".L08008280:\n"
    "    cmp r5, r8\n"
    "    beq .L0800829C\n"
    ".L08008284:\n"
    "    cmp r4, #0\n"
    "    beq .L08008294\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    ldr r1, [r5, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    "    adds r0, r4, #0\n"
    "    bl RetainObjTileHandle\n"
    "    str r0, [r4, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    ".L08008294:\n"
    "    adds r5, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    adds r4, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    cmp r5, r8\n"
    "    bne .L08008284\n"
    ".L0800829C:\n"
    "    adds r5, r4, #0\n"
    "    ldr r0, [sp, #0x10]\n"
    "    cmp r0, #1\n"
    "    bne .L080082BE\n"
    "    cmp r5, #0\n"
    "    beq .L080082BA\n"
    "    adds r0, r5, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    mov r0, r9\n"
    "    ldr r1, [r0, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    "    adds r0, r5, #0\n"
    "    bl RetainObjTileHandle\n"
    "    str r0, [r5, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    ".L080082BA:\n"
    "    adds r5, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    b .L080082E6\n"
    ".L080082BE:\n"
    "    adds r6, r0, #0\n"
    "    adds r4, r5, #0\n"
    ".L080082C2:\n"
    "    cmp r6, #0\n"
    "    beq .L080082E4\n"
    ".L080082C6:\n"
    "    cmp r4, #0\n"
    "    beq .L080082DC\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    mov r2, r9\n"
    "    ldr r1, [r2, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    "    adds r0, r4, #0\n"
    "    bl RetainObjTileHandle\n"
    "    str r0, [r4, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    ".L080082DC:\n"
    "    subs r6, #1\n"
    "    adds r4, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    cmp r6, #0\n"
    "    bne .L080082C6\n"
    ".L080082E4:\n"
    "    adds r5, r4, #0\n"
    ".L080082E6:\n"
    "    ldr r6, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    ldr r4, [r7]\n"
    ".L080082EA:\n"
    "    cmp r4, r6\n"
    "    beq .L08008304\n"
    ".L080082EE:\n"
    "    ldr r1, [r4, #" STRINGIFY(OBJ_TILE_COLLECTION_HANDLE_OFFSET) "]\n"
    "    adds r0, r4, #0\n"
    "    bl ReleaseObjTileHandle\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #2\n"
    "    bl _._16ObjTilePoolOwner\n"
    "    adds r4, #" STRINGIFY(OBJ_TILE_COLLECTION_ENTRY_BYTES) "\n"
    "    cmp r4, r6\n"
    "    bne .L080082EE\n"
    ".L08008304:\n"
    "    ldr r0, [r7]\n"
    "    cmp r0, #0\n"
    "    beq .L0800830E\n"
    "    bl free\n"
    ".L0800830E:\n"
    "    ldr r0, [sp, #0x2c]\n"
    "    add r0, sl\n"
    "    mov r1, sl\n"
    "    str r1, [r7]\n"
    "    str r5, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_END_OFFSET) "]\n"
    "    str r0, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_CAPACITY_OFFSET) "]\n"
    ".L0800831A:\n"
    "    ldr r1, [sp, #8]\n"
    "    mov r0, r9\n"
    "    bl ReleaseObjTileHandle\n"
    "    mov r0, r9\n"
    "    movs r1, #2\n"
    "    bl _._16ObjTilePoolOwner\n"
    "    ldr r2, [sp, #0x28]\n"
    "    lsls r0, r2, #0x18\n"
    "    lsrs r6, r0, #0x18\n"
    "    cmp r6, #0xff\n"
    "    beq .L08008336\n"
    "    b .L080081F8\n"
    ".L08008336:\n"
    "    ldr r0, [r7]\n"
    "    str r0, [r7, #" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_CURSOR_OFFSET) "]\n"
    "    ldr r0, [sp, #0x24]\n"
    "    str r0, [sp, #0x20]\n"
    "    cmp r0, #(" STRINGIFY(OBJ_TILE_COLLECTION_GROUP_COUNT) " - 1)\n"
    "    bhi .L08008344\n"
    "    b .L080081C8\n"
    ".L08008344:\n"
    "    ldr r1, [sp, #0x1c]\n"
    "    ldr r2, [sp, #0x14]\n"
    "    str r1, [r2]\n"
    "    adds r0, r2, #0\n"
    "    add sp, #0x30\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov r9, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "\n"
#if OBJ_TILE_COLLECTION_STORAGE_BYTES > 255 || OBJ_TILE_COLLECTION_GROUP_BYTES != 20
    "    .align 2, 0\n"
#endif
#if OBJ_TILE_COLLECTION_STORAGE_BYTES > 255
    ".LCollectionStorageSize: .word " STRINGIFY(OBJ_TILE_COLLECTION_STORAGE_BYTES) "\n"
#endif
#if OBJ_TILE_COLLECTION_GROUP_BYTES != 20
    ".LCollectionGroupSize: .word " STRINGIFY(OBJ_TILE_COLLECTION_GROUP_BYTES) "\n"
#endif
);

ObjTileCollection::ObjTileCollection() : storage(0)
{
}

ObjTileCollection::~ObjTileCollection()
{
    if (storage != 0) {
        struct ObjTileCollectionStorage * saved = storage;
        struct ObjTileCollectionGroup * group = saved->groups + ARRAY_COUNT(saved->groups);
        while (saved->groups != group) {
            struct ObjTileCollectionEntry * entry;
            struct ObjTileCollectionEntry * end;
            --group;
            end = group->end;
            entry = group->start;
            if (entry != end) {
                do {
                    entry->~ObjTileCollectionEntry();
                    ++entry;
                } while (entry != end);
            }
            if (group->start != 0)
                free(group->start);
        }
        __builtin_delete(saved);
    }
}

ObjTileCollectionEntry ObjTileCollection::Get(u32 group_index) const
{
    ObjTileCollectionStorage * saved = storage;
    if (saved != 0) {
        ObjTileCollectionGroup * group = reinterpret_cast<ObjTileCollectionGroup *>(
            group_index * sizeof(ObjTileCollectionGroup) + reinterpret_cast<u32>(saved));
        struct ObjTileCollectionEntry * end = group->end;
        struct ObjTileCollectionEntry * current = group->cursor;
        if (current != end) {
            struct ObjTileCollectionEntry * first = current;
            do {
                struct ObjTileCollectionEntry * candidate = current;
                ++current;
                if (current == end)
                    current = group->start;
                if (GetObjTileHandleReferenceCount(candidate, candidate->handle) == 1) {
                    group->cursor = current;
                    current = candidate;
                    break;
                }
            } while (current != first);
        }
        return *current;
    }
    return ObjTileCollectionEntry(group_index);
}
