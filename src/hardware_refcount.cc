#include "hardware_refcount.hh"

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
