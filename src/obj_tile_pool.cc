#include "obj_tile_pool.hh"
#include <algorithm>

ObjTilePoolState * gObjTilePool;

EXTERN_C
void __builtin_delete(void *);
EXTERN_C_END

asm_unified(
    ".text\n"
    ".thumb\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start InitializeObjTilePoolOwner\n"
    "InitializeObjTilePoolOwner: @ 0x08007874\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0x30\n"
    "    str r0, [sp, #8]\n"
    "    ldr r0, .L080079B4 @ =gObjTilePool\n"
    "    ldr r4, [r0]\n"
    "    cmp r4, #0\n"
    "    beq .L0800788C\n"
    "    b .L08007992\n"
    ".L0800788C:\n"
    "    ldr r0, .L080079B8 @ =OBJ_TILE_POOL_BYTES\n"
    "    bl __builtin_new\n"
    "    mov r8, r0\n"
    "    str r4, [sp]\n"
    "    mov r1, r8\n"
    "    adds r1, #" STRINGIFY(OBJ_TILE_POOL_FREE_LIST_OFFSET) "\n"
    "    mov r2, sp\n"
    "    adds r2, #4\n"
    "    str r2, [sp, #0x2c]\n"
    "    cmp r8, r1\n"
    "    beq .L080078AC\n"
    "    movs r2, #0\n"
    ".L080078A6:\n"
    "    stm r0!, {r2}\n"
    "    cmp r0, r1\n"
    "    bne .L080078A6\n"
    ".L080078AC:\n"
    "    mov r0, r8\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_POOL_ENTRIES_OFFSET) "\n"
    "    movs r1, #(" STRINGIFY(OBJ_TILE_HANDLE_COUNT) " >> 1)\n"
    "    lsls r1, r1, #1\n"
    "    movs r2, #0\n"
    "    bl InitializeObjTileFreeList\n"
    "    mov r1, r8\n"
    "    str r0, [r1, #" STRINGIFY(OBJ_TILE_POOL_FREE_LIST_OFFSET) "]\n"
    "    ldr r1, .L080079BC @ =OBJ_TILE_POOL_TREE_OFFSET\n"
    "    add r1, r8\n"
    "    movs r0, #0\n"
    "    strb r0, [r1]\n"
    "    movs r0, #1\n"
    "    strb r0, [r1, #1]\n"
    "    ldr r2, .L080079C0 @ =(OBJ_TILE_POOL_TREE_OFFSET + OBJ_TILE_TREE_CHILDREN_OFFSET)\n"
    "    add r2, r8\n"
    "    movs r4, #1\n"
    "    mov r0, r8\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_POOL_FREE_LIST_OFFSET) "\n"
    "    str r0, [sp, #0x20]\n"
    "    str r1, [sp, #0xc]\n"
#if ((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    "    movs r1, #(" STRINGIFY(OBJ_TILE_POOL_COUNT_OFFSET) " >> 4)\n"
    "    lsls r1, r1, #4\n"
#else
    "    ldr r1, .LObjTilePoolCountOffsetInit\n"
#endif
    "    add r1, r8\n"
    "    str r1, [sp, #0x10]\n"
    "    ldr r0, .L080079C4 @ =OBJ_TILE_POOL_REFCOUNT_OFFSET\n"
    "    add r0, r8\n"
    "    str r0, [sp, #0x14]\n"
    "    ldr r1, .L080079C8 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET\n"
    "    add r1, r8\n"
    "    str r1, [sp, #0x18]\n"
    "    ldr r0, .L080079CC @ =OBJ_TILE_POOL_RESERVED_COUNT_OFFSET\n"
    "    add r0, r8\n"
    "    str r0, [sp, #0x1c]\n"
    "    movs r7, #0\n"
    "    mov ip, r4\n"
    "    movs r6, #1\n"
    "    rsbs r6, r6, #0\n"
    ".L080078FA:\n"
    "    strb r7, [r2]\n"
    "    mov r1, ip\n"
    "    strb r1, [r2, #1]\n"
    "    adds r0, r2, #" STRINGIFY(OBJ_TILE_TREE_CHILDREN_OFFSET) "\n"
    "    movs r3, #1\n"
    "    adds r2, #" STRINGIFY(OBJ_TILE_TREE512_BYTES) "\n"
    "    str r2, [sp, #0x28]\n"
    "    subs r4, #1\n"
    "    str r4, [sp, #0x24]\n"
    ".L0800790C:\n"
    "    strb r7, [r0]\n"
    "    mov r2, ip\n"
    "    strb r2, [r0, #1]\n"
    "    adds r2, r0, #" STRINGIFY(OBJ_TILE_TREE_CHILDREN_OFFSET) "\n"
    "    movs r1, #1\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_TREE256_BYTES) "\n"
    "    mov sb, r0\n"
    "    subs r3, #1\n"
    "    mov sl, r3\n"
    ".L0800791E:\n"
    "    strb r7, [r2]\n"
    "    mov r0, ip\n"
    "    strb r0, [r2, #1]\n"
    "    adds r0, r2, #" STRINGIFY(OBJ_TILE_TREE_CHILDREN_OFFSET) "\n"
    "    movs r3, #1\n"
    "    adds r4, r2, #0\n"
    "    adds r4, #" STRINGIFY(OBJ_TILE_TREE128_BYTES) "\n"
    "    subs r5, r1, #1\n"
    ".L0800792E:\n"
    "    strb r7, [r0]\n"
    "    mov r1, ip\n"
    "    strb r1, [r0, #1]\n"
    "    adds r1, r0, #" STRINGIFY(OBJ_TILE_TREE_CHILDREN_OFFSET) "\n"
    "    movs r2, #1\n"
    "    adds r0, #" STRINGIFY(OBJ_TILE_TREE64_BYTES) "\n"
    "    subs r3, #1\n"
    ".L0800793C:\n"
    "    stm r1!, {r7}\n"
    "    subs r2, #1\n"
    "    cmp r2, r6\n"
    "    bne .L0800793C\n"
    "    cmp r3, r6\n"
    "    bne .L0800792E\n"
    "    adds r2, r4, #0\n"
    "    adds r1, r5, #0\n"
    "    cmp r1, r6\n"
    "    bne .L0800791E\n"
    "    mov r0, sb\n"
    "    mov r3, sl\n"
    "    cmp r3, r6\n"
    "    bne .L0800790C\n"
    "    ldr r2, [sp, #0x28]\n"
    "    ldr r4, [sp, #0x24]\n"
    "    cmp r4, r6\n"
    "    bne .L080078FA\n"
    "    movs r0, #0\n"
    "    ldr r2, [sp, #0x10]\n"
    "    strh r0, [r2]\n"
    "    ldr r1, [sp, #0x14]\n"
    "    str r0, [r1]\n"
    "    ldr r2, [sp, #0x18]\n"
    "    strh r0, [r2]\n"
    "    ldr r1, [sp, #0x1c]\n"
    "    strh r0, [r1]\n"
    "    str r0, [sp, #4]\n"
    "    mov r0, r8\n"
    "    ldr r2, [sp, #0x20]\n"
    "    cmp r8, r2\n"
    "    beq .L08007986\n"
    "    ldr r1, [sp, #0x2c]\n"
    "    ldr r3, [r1]\n"
    ".L08007980:\n"
    "    stm r0!, {r3}\n"
    "    cmp r0, r2\n"
    "    bne .L08007980\n"
    ".L08007986:\n"
    "    ldr r0, [sp, #0xc]\n"
    "    bl Clear__15ObjTileTree1024\n"
    "    mov r2, r8\n"
    "    ldr r0, .L080079B4 @ =gObjTilePool\n"
    "    str r2, [r0]\n"
    ".L08007992:\n"
    "    ldr r0, .L080079B4 @ =gObjTilePool\n"
    "    ldr r1, [r0]\n"
    "    ldr r2, .L080079C4 @ =OBJ_TILE_POOL_REFCOUNT_OFFSET\n"
    "    adds r1, r1, r2\n"
    "    ldr r0, [r1]\n"
    "    adds r0, #1\n"
    "    str r0, [r1]\n"
    "    ldr r0, [sp, #8]\n"
    "    add sp, #0x30\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "    .align 2, 0\n"
    ".L080079B4: .word gObjTilePool\n"
    ".L080079B8: .word " STRINGIFY(OBJ_TILE_POOL_BYTES) "\n"
    ".L080079BC: .word " STRINGIFY(OBJ_TILE_POOL_TREE_OFFSET) "\n"
    ".L080079C0: .word (" STRINGIFY(OBJ_TILE_POOL_TREE_OFFSET) " + " STRINGIFY(OBJ_TILE_TREE_CHILDREN_OFFSET) ")\n"
    ".L080079C4: .word " STRINGIFY(OBJ_TILE_POOL_REFCOUNT_OFFSET) "\n"
    ".L080079C8: .word " STRINGIFY(OBJ_TILE_POOL_RESERVED_FIRST_OFFSET) "\n"
    ".L080079CC: .word " STRINGIFY(OBJ_TILE_POOL_RESERVED_COUNT_OFFSET) "\n"
#if !((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    ".LObjTilePoolCountOffsetInit: .word " STRINGIFY(OBJ_TILE_POOL_COUNT_OFFSET) "\n"
#endif
);

ObjTilePoolOwner::ObjTilePoolOwner(ObjTilePoolOwner const &)
{
    // The adjacent release routine frees the shared state at zero owners.
    ++gObjTilePool->reference_count;
}

ObjTilePoolOwner::~ObjTilePoolOwner()
{
    ObjTilePoolState * state = gObjTilePool;
    u32 * refcount = &state->reference_count;
    u32 remaining = *refcount - 1;
    *refcount = remaining;
    if (remaining == 0) {
        if (state != 0)
            __builtin_delete(state);
        gObjTilePool = (ObjTilePoolState *)remaining;
    }
}

asm_unified(
    ".text\n"
    ".thumb\n"
    "thumb_func_start SetObjTileReservation\n"
    "SetObjTileReservation: @ 0x08007A28\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sl\n"
    "    mov r6, sb\n"
    "    mov r5, r8\n"
    "    push {r5, r6, r7}\n"
    "    sub sp, #0x18\n"
    "    str r1, [sp]\n"
    "    str r2, [sp, #4]\n"
    "    ldr r0, .L08007B44 @ =gObjTilePool\n"
    "    ldr r5, [r0]\n"
    "    ldr r0, .L08007B48 @ =OBJ_TILE_POOL_RESERVED_COUNT_OFFSET\n"
    "    adds r4, r5, r0\n"
    "    ldrh r0, [r4]\n"
    "    cmp r0, #0\n"
    "    beq .L08007A5A\n"
    "    ldr r1, .L08007B4C @ =OBJ_TILE_POOL_TREE_OFFSET\n"
    "    adds r0, r5, r1\n"
    "    ldr r2, .L08007B50 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET\n"
    "    adds r1, r5, r2\n"
    "    ldrh r1, [r1]\n"
    "    ldrh r2, [r4]\n"
    "    bl Unreserve__15ObjTileTree1024UiUi\n"
    "    movs r0, #0\n"
    "    strh r0, [r4]\n"
    ".L08007A5A:\n"
    "    ldr r0, [sp, #4]\n"
    "    cmp r0, #0\n"
    "    beq .L08007B32\n"
    "    ldr r1, [sp]\n"
    "    adds r1, r1, r0\n"
    "    str r1, [sp, #8]\n"
    "    movs r7, #0\n"
#if ((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    "    movs r2, #(" STRINGIFY(OBJ_TILE_POOL_COUNT_OFFSET) " >> 4)\n"
    "    lsls r2, r2, #4\n"
#else
    "    ldr r2, .LObjTilePoolCountOffsetReserve\n"
#endif
    "    adds r0, r5, r2\n"
    "    ldrh r1, [r0]\n"
    "    str r4, [sp, #0x14]\n"
    "    subs r2, #" STRINGIFY(OBJ_TILE_TREE1024_BYTES) "\n"
    "    adds r2, r5, r2\n"
    "    str r2, [sp, #0xc]\n"
    "    ldr r2, .L08007B50 @ =OBJ_TILE_POOL_RESERVED_FIRST_OFFSET\n"
    "    adds r2, r5, r2\n"
    "    str r2, [sp, #0x10]\n"
    "    mov sl, r0\n"
    "    cmp r1, #0\n"
    "    beq .L08007B18\n"
    "    movs r0, #" STRINGIFY(OBJ_TILE_POOL_ENTRIES_OFFSET) "\n"
    "    adds r0, r0, r5\n"
    "    mov r8, r0\n"
    "    mov r6, r8\n"
    ".L08007A8C:\n"
    "    movs r0, #0\n"
    "    cmp r7, #(" STRINGIFY(OBJ_TILE_HANDLE_COUNT) " - 1)\n"
    "    bhi .L08007AAA\n"
    "    lsrs r1, r7, #" STRINGIFY(OBJ_TILE_SLOT_WORD_SHIFT) "\n"
    "    lsls r1, r1, #2\n"
    "    adds r1, r5, r1\n"
    "    movs r0, #(" STRINGIFY(OBJ_TILE_SLOT_WORD_BITS) " - 1)\n"
    "    ands r0, r7\n"
    "    movs r2, #1\n"
    "    lsls r2, r0\n"
    "    ldr r1, [r1]\n"
    "    ands r1, r2\n"
    "    rsbs r0, r1, #0\n"
    "    orrs r0, r1\n"
    "    lsrs r0, r0, #0x1f\n"
    ".L08007AAA:\n"
    "    cmp r0, #0\n"
    "    beq .L08007B04\n"
    "    ldrh r0, [r6]\n"
    "    lsls r4, r0, #(32 - " STRINGIFY(OBJ_TILE_INDEX_BITS) ")\n"
    "    lsrs r3, r4, #(32 - " STRINGIFY(OBJ_TILE_INDEX_BITS) ")\n"
    "    ldrb r0, [r6, #1]\n"
    "    lsls r2, r0, #(32 - (" STRINGIFY(OBJ_TILE_INDEX_BITS) " - 8) - " STRINGIFY(OBJ_TILE_SIZE_SHIFT_BITS) ")\n"
    "    lsrs r1, r2, #(32 - " STRINGIFY(OBJ_TILE_SIZE_SHIFT_BITS) ")\n"
    "    movs r0, #1\n"
    "    mov sb, r0\n"
    "    lsls r0, r1\n"
    "    adds r0, r3, r0\n"
    "    ldr r1, [sp]\n"
    "    cmp r1, r0\n"
    "    bhs .L08007B04\n"
    "    ldr r0, [sp, #8]\n"
    "    cmp r3, r0\n"
    "    bhs .L08007B04\n"
    "    adds r1, r3, #0\n"
    "    lsrs r2, r2, #(32 - " STRINGIFY(OBJ_TILE_SIZE_SHIFT_BITS) ")\n"
    "    ldr r0, [sp, #0xc]\n"
    "    bl Free__15ObjTileTree1024UiUi\n"
    "    movs r0, #0\n"
    "    strh r0, [r6, #" STRINGIFY(OBJ_TILE_ENTRY_GENERATION_OFFSET) "]\n"
    "    ldr r0, [r5, #" STRINGIFY(OBJ_TILE_POOL_FREE_LIST_OFFSET) "]\n"
    "    str r0, [r6]\n"
    "    mov r1, r8\n"
    "    str r1, [r5, #" STRINGIFY(OBJ_TILE_POOL_FREE_LIST_OFFSET) "]\n"
    "    cmp r7, #(" STRINGIFY(OBJ_TILE_HANDLE_COUNT) " - 1)\n"
    "    bhi .L08007AFC\n"
    "    lsrs r2, r7, #" STRINGIFY(OBJ_TILE_SLOT_WORD_SHIFT) "\n"
    "    lsls r2, r2, #2\n"
    "    adds r2, r5, r2\n"
    "    movs r0, #(" STRINGIFY(OBJ_TILE_SLOT_WORD_BITS) " - 1)\n"
    "    ands r0, r7\n"
    "    mov r1, sb\n"
    "    lsls r1, r0\n"
    "    ldr r0, [r2]\n"
    "    bics r0, r1\n"
    "    str r0, [r2]\n"
    ".L08007AFC:\n"
    "    mov r2, sl\n"
    "    ldrh r0, [r2]\n"
    "    subs r0, #1\n"
    "    strh r0, [r2]\n"
    ".L08007B04:\n"
    "    adds r6, #" STRINGIFY(OBJ_TILE_POOL_ENTRY_BYTES) "\n"
    "    movs r0, #" STRINGIFY(OBJ_TILE_POOL_ENTRY_BYTES) "\n"
    "    add r8, r0\n"
    "    adds r7, #1\n"
    "    mov r1, sl\n"
    "    ldrh r0, [r1]\n"
    "    cmp r0, #0\n"
    "    beq .L08007B18\n"
    "    cmp r7, #(" STRINGIFY(OBJ_TILE_HANDLE_COUNT) " - 1)\n"
    "    bls .L08007A8C\n"
    ".L08007B18:\n"
    "    ldr r0, [sp, #0xc]\n"
    "    ldr r1, [sp]\n"
    "    ldr r2, [sp, #4]\n"
    "    bl Reserve__15ObjTileTree1024UiUi\n"
    "    mov r2, sp\n"
    "    ldrh r0, [r2]\n"
    "    ldr r2, [sp, #0x10]\n"
    "    strh r0, [r2]\n"
    "    mov r1, sp\n"
    "    ldrh r2, [r1, #4]\n"
    "    ldr r1, [sp, #0x14]\n"
    "    strh r2, [r1]\n"
    ".L08007B32:\n"
    "    add sp, #0x18\n"
    "    pop {r3, r4, r5}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    mov sl, r5\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
    "    .align 2, 0\n"
    ".L08007B44: .word gObjTilePool\n"
    ".L08007B48: .word " STRINGIFY(OBJ_TILE_POOL_RESERVED_COUNT_OFFSET) "\n"
    ".L08007B4C: .word " STRINGIFY(OBJ_TILE_POOL_TREE_OFFSET) "\n"
    ".L08007B50: .word " STRINGIFY(OBJ_TILE_POOL_RESERVED_FIRST_OFFSET) "\n"
#if !((OBJ_TILE_POOL_COUNT_OFFSET & 15) == 0 && (OBJ_TILE_POOL_COUNT_OFFSET >> 4) <= 255)
    ".LObjTilePoolCountOffsetReserve: .word " STRINGIFY(OBJ_TILE_POOL_COUNT_OFFSET) "\n"
#endif
);

u32 AllocateObjTileHandle(void *, u32 size_shift)
{
    ObjTilePoolState * state = gObjTilePool;
    u32 value;
    u32 const first = state->tile_tree.Allocate(size_shift);
    bool valid = first < TOTAL_OBJ_TILE_COUNT;
    if (valid) {
        ObjTileHandlePool & pool = state->pool;
        ObjTilePoolEntry * current = pool.first_free;
        ObjTilePoolEntry * entry = pool.AllocEntry(current);
        if (entry != 0) {
            u32 index = entry - pool.entries;
            if (index < ARRAY_COUNT(pool.entries))
                state->occupied[index / OBJ_TILE_SLOT_WORD_BITS] |= 1u << (index % OBJ_TILE_SLOT_WORD_BITS);
            ++state->allocation_count;
            entry->data.params.tile_index = first;
            entry->data.params.size_shift = size_shift;
            entry->data.params.reference_count = 1;
            u32 generation = state->next_generation + 1;
            if (generation > 0xFFFF)
                generation = 1;
            current->generation = generation;
            state->next_generation = generation;
            ObjTileHandle result;
            result.value = 0;
            result.fields.index = index;
            result.fields.generation = current->generation;
            value = result.value;
            goto done;
        }
        state->tile_tree.Free(first, size_shift);
    }
    value = 0;
done:
    return value;
}

void ReleaseObjTileHandle(void *, u32 value)
{
    ObjTilePoolState * state = gObjTilePool;
    if (value != 0) {
        ObjTileHandle handle;
        handle.value = value;
        u32 const index = handle.Index();
        if (state->IsAllocated(index)) {
            ObjTilePoolEntry & entry = state->pool.GetEntry(index);
            bool valid = handle.fields.generation == entry.generation;
            if (valid) {
                u16 remaining = --entry.data.params.reference_count;
                if (remaining == 0) {
                    state->tile_tree.Free(entry.data.params.tile_index, entry.data.params.size_shift);
                    entry.generation = remaining;
                    entry.data.next_free = state->pool.first_free;
                    state->pool.first_free = &entry;
                    if (index < ARRAY_COUNT(state->pool.entries))
                        state->occupied[index / OBJ_TILE_SLOT_WORD_BITS] &= ~(1u << (index % OBJ_TILE_SLOT_WORD_BITS));
                    --state->allocation_count;
                }
            }
        }
    }
}

u32 RetainObjTileHandle(void *, u32 value)
{
    ObjTilePoolState * state = gObjTilePool;
    if (value != 0) {
        ObjTileHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            ObjTilePoolEntry & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid) {
                u16 previous = entry.data.params.reference_count;
                if (++entry.data.params.reference_count != 0)
                    return value;
                entry.data.params.reference_count = previous;
            }
        }
    }
    return 0;
}

u32 GetObjTileIndex(void const *, u32 value)
{
    ObjTilePoolState * state = gObjTilePool;
    if (value != 0) {
        ObjTileHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            ObjTilePoolEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.tile_index;
        }
    }
    return 0xFFFFFFFFu;
}

u32 GetObjTileSizeShift(void *, u32 value)
{
    ObjTilePoolState * state = gObjTilePool;
    if (value != 0) {
        ObjTileHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            ObjTilePoolEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.size_shift;
        }
    }
    // Eleven is the original invalid-handle sentinel, not an allocation size.
    return 11;
}

u32 GetObjTileHandleReferenceCount(void *, u32 value)
{
    ObjTilePoolState * state = gObjTilePool;
    if (value != 0) {
        ObjTileHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            ObjTilePoolEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.reference_count;
        }
    }
    return 0;
}

u16 GetAllocatedObjTileHandleCount(void)
{
    return gObjTilePool->allocation_count;
}

u32 GetObjTileHandleCapacity(void)
{
    return ARRAY_COUNT(gObjTilePool->pool.entries);
}

void ObjTileTree1024::Fill()
{
    FillObjTileTree512(&children[0]);
    FillObjTileTree512(&children[1]);
    full = true;
    empty = false;
}

void ObjTileTree1024::Clear()
{
    ClearObjTileTree512(&children[1]);
    ClearObjTileTree512(&children[0]);
    full = false;
    empty = true;
}

void ObjTileTree1024::Reserve(u32 offset, u32 length)
{
    if (offset > TOTAL_OBJ_TILE_COUNT - 1 || length == 0)
        return;
    if (offset == 0 && length > TOTAL_OBJ_TILE_COUNT - 1) {
        Fill();
        return;
    }
    if (offset <= 511) {
        u32 first_capacity = 512 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].Reserve(offset, count);
    }
    if (offset + length > 512) {
        u32 second_offset = offset > 511 ? offset - 512 : 0;
        u32 second_length = offset + length;
        second_length -= 512;
        second_length -= second_offset;
        children[1].Reserve(second_offset, second_length);
    }
    u32 active = 0;
    if (children[0].full != 0)
        active = (0u - children[1].full) >> 31;
    full = active;
    empty = false;
}

void ObjTileTree1024::Unreserve(u32 offset, u32 length)
{
    if (offset > TOTAL_OBJ_TILE_COUNT - 1 || length == 0)
        return;
    if (offset == 0 && length > TOTAL_OBJ_TILE_COUNT - 1) {
        Clear();
        return;
    }
    u32 first_limit = 511;
    ObjTileTree512 * first = &children[0];
    if (offset <= first_limit) {
        u32 first_capacity = 512 - offset;
        u32 count = std::min(length, first_capacity);
        first->Unreserve(offset, count);
    }
    if (offset + length > 512) {
        u32 second_offset = offset > 511 ? offset - 512 : 0;
        u32 second_length = offset + length;
        second_length -= 512;
        second_length -= second_offset;
        children[1].Unreserve(second_offset, second_length);
    }
    full = false;
    u32 active = 0;
    if (first->empty != 0) {
        ObjTileTree512 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

u32 ObjTileTree1024::Allocate(u32 size_shift)
{
    u32 index;
    ObjTileTree512 * child;

    if (size_shift <= 9) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u32 offset;
            u32 active;
            u32 valid;
            // Snapshot the flag before the child allocator changes its state.
            u8 const child_full = child->full;
            if (child_full == 0) {
                offset = child->Allocate(size_shift);
                valid = 0;
                if (offset <= 0x1FF)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    active = 0;
                    if (children[0].full != 0)
                        active = (0u - children[1].full) >> 31;
                    full = active;
                    return (index << 9) | offset;
                }
            }
        }
    } else if (size_shift == 10 && empty != 0) {
        Fill();
        return 0;
    }
    return TOTAL_OBJ_TILE_COUNT;
}

void ObjTileTree1024::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 9) {
        u32 use_second = offset & 512;
        ObjTileTree512 * first = &children[0];
        ObjTileTree512 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            ObjTileTree512 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 10) {
        Clear();
    }
}

bool ObjTileTree1024::IsEmpty() const
{
    return empty;
}

bool ObjTileTree1024::IsFull() const
{
    return full;
}

ObjTileTree1024::ObjTileTree1024() : full(false), empty(true)
{
}
