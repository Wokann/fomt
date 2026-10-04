#include "hardware_refcount.hh"
#include "hardware_state_properties.hh"

EXTERN_C
void __builtin_delete(void *);
EXTERN_C_END

void * func_080079D0(void * owner)
{
    // The adjacent release routine frees the shared state at zero owners.
    ++((HardwareSharedState *)gUnk_03000408)->reference_count;
    return owner;
}

void func_080079E8(void * owner, u32 flags)
{
    HardwareSharedState * state = (HardwareSharedState *)gUnk_03000408;
    u32 * refcount = &state->reference_count;
    u32 remaining = *refcount - 1;
    *refcount = remaining;
    if (remaining == 0) {
        if (state != 0)
            __builtin_delete(state);
        gUnk_03000408 = (u8 *)remaining;
    }
    if (flags & 1)
        __builtin_delete(owner);
}

u32 AllocateHardwareSharedStateHandle(void *, u32 size_shift)
    SECTION(".text.hardware_shared_state_handles");
u32 AllocateHardwareSharedStateHandle(void *, u32 size_shift)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    u8 * tree = reinterpret_cast<u8 *>(&state->tile_tree);
    u32 value;
    u32 const first = func_08008020(tree, size_shift);
    bool valid = first < 1024;
    if (valid) {
        HardwareSharedStatePool & pool = state->pool;
        HardwareSharedStateEntry * current = pool.first_free;
        HardwareSharedStateEntry * entry = pool.AllocEntry(current);
        if (entry != 0) {
            u32 index = entry - pool.entries;
            if (index < 256)
                state->occupied[index / 32] |= 1u << (index % 32u);
            ++state->allocation_count;
            entry->data.params.tile_index = first;
            entry->data.params.size_shift = size_shift;
            entry->data.params.reference_count = 1;
            u32 generation = state->next_generation + 1;
            if (generation > 0xFFFF)
                generation = 1;
            current->generation = generation;
            state->next_generation = generation;
            HardwareSharedStateHandle result;
            result.value = 0;
            result.fields.index = index;
            result.fields.generation = current->generation;
            value = result.value;
            goto done;
        }
        func_080080A0(tree, first, size_shift);
    }
    value = 0;
done:
    return value;
}

void ReleaseHardwareSharedStateHandle(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
void ReleaseHardwareSharedStateHandle(void *, u32 value)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    if (value != 0) {
        HardwareSharedStateHandle handle;
        handle.value = value;
        u32 const index = handle.Index();
        if (state->IsAllocated(index)) {
            HardwareSharedStateEntry & entry = state->pool.GetEntry(index);
            bool valid = handle.fields.generation == entry.generation;
            if (valid) {
                u16 remaining = --entry.data.params.reference_count;
                if (remaining == 0) {
                    func_080080A0(reinterpret_cast<u8 *>(&state->tile_tree),
                        entry.data.params.tile_index, entry.data.params.size_shift);
                    entry.generation = remaining;
                    entry.data.next_free = state->pool.first_free;
                    state->pool.first_free = &entry;
                    if (index < 256)
                        state->occupied[index / 32] &= ~(1u << (index % 32u));
                    --state->allocation_count;
                }
            }
        }
    }
}

u32 RetainHardwareSharedStateHandle(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
u32 RetainHardwareSharedStateHandle(void *, u32 value)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    if (value != 0) {
        HardwareSharedStateHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            HardwareSharedStateEntry & entry = state->pool.GetEntry(handle.Index());
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

u32 GetHardwareSharedStateTileIndex(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
u32 GetHardwareSharedStateTileIndex(void *, u32 value)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    if (value != 0) {
        HardwareSharedStateHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            HardwareSharedStateEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.tile_index;
        }
    }
    return 0xFFFFFFFFu;
}

u32 GetHardwareSharedStateSizeShift(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
u32 GetHardwareSharedStateSizeShift(void *, u32 value)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    if (value != 0) {
        HardwareSharedStateHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            HardwareSharedStateEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.size_shift;
        }
    }
    // Eleven is the original invalid-handle sentinel, not an allocation size.
    return 11;
}

u32 GetHardwareSharedStateReferenceCount(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
u32 GetHardwareSharedStateReferenceCount(void *, u32 value)
{
    HardwareSharedState * state = reinterpret_cast<HardwareSharedState *>(gUnk_03000408);
    if (value != 0) {
        HardwareSharedStateHandle handle;
        handle.value = value;
        if (state->IsAllocated(handle.Index())) {
            HardwareSharedStateEntry const & entry = state->pool.GetEntry(handle.Index());
            bool valid = handle.fields.generation == entry.generation;
            if (valid)
                return entry.data.params.reference_count;
        }
    }
    return 0;
}

void ClearHardwareTileTree64(HardwareTileTree64 *)
    SECTION(".text.hardware_shared_state_tree_clear");
void ClearHardwareTileTree64(HardwareTileTree64 * tree)
{
    tree->children[1].bits = 0;
    tree->children[0].bits = 0;
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree128(HardwareTileTree128 *)
    SECTION(".text.hardware_shared_state_tree_clear");
void ClearHardwareTileTree128(HardwareTileTree128 * tree)
{
    ClearHardwareTileTree64(&tree->children[1]);
    ClearHardwareTileTree64(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree256(HardwareTileTree256 *)
    SECTION(".text.hardware_shared_state_tree_clear");
void ClearHardwareTileTree256(HardwareTileTree256 * tree)
{
    ClearHardwareTileTree128(&tree->children[1]);
    ClearHardwareTileTree128(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree512(HardwareTileTree512 *)
    SECTION(".text.hardware_shared_state_tree_clear");
void ClearHardwareTileTree512(HardwareTileTree512 * tree)
{
    ClearHardwareTileTree256(&tree->children[1]);
    ClearHardwareTileTree256(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

HardwareSharedStateEntry * InitializeHardwareSharedStateFreeList(
    HardwareSharedStateEntry *, i32, HardwareSharedStateEntry *)
    SECTION(".text.hardware_shared_state_free_list");
HardwareSharedStateEntry * InitializeHardwareSharedStateFreeList(
    HardwareSharedStateEntry * entries, i32 count, HardwareSharedStateEntry * tail)
{
    HardwareSharedStateEntry * entry = entries + (count - 1);
    entry->data.next_free = tail;
    while (entry != entries) {
        HardwareSharedStateEntry * next = entry;
        --entry;
        entry->data.next_free = next;
    }
    return entry;
}
