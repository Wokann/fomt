#include "hardware_refcount.hh"
#include "hardware_state_properties.hh"
#include <algorithm>

HardwareSharedState * gUnk_03000408;

EXTERN_C
void __builtin_delete(void *);
EXTERN_C_END

HardwareSharedStateOwner::HardwareSharedStateOwner(HardwareSharedStateOwner const &)
{
    // The adjacent release routine frees the shared state at zero owners.
    ++gUnk_03000408->reference_count;
}

HardwareSharedStateOwner::~HardwareSharedStateOwner()
{
    HardwareSharedState * state = gUnk_03000408;
    u32 * refcount = &state->reference_count;
    u32 remaining = *refcount - 1;
    *refcount = remaining;
    if (remaining == 0) {
        if (state != 0)
            __builtin_delete(state);
        gUnk_03000408 = (HardwareSharedState *)remaining;
    }
}

u32 AllocateHardwareSharedStateHandle(void *, u32 size_shift)
    SECTION(".text.hardware_shared_state_handles");
u32 AllocateHardwareSharedStateHandle(void *, u32 size_shift)
{
    HardwareSharedState * state = gUnk_03000408;
    u32 value;
    u32 const first = state->tile_tree.Allocate(size_shift);
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
        state->tile_tree.Free(first, size_shift);
    }
    value = 0;
done:
    return value;
}

void ReleaseHardwareSharedStateHandle(void *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
void ReleaseHardwareSharedStateHandle(void *, u32 value)
{
    HardwareSharedState * state = gUnk_03000408;
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
                    state->tile_tree.Free(entry.data.params.tile_index, entry.data.params.size_shift);
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
    HardwareSharedState * state = gUnk_03000408;
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

u32 GetHardwareSharedStateTileIndex(void const *, u32 value)
    SECTION(".text.hardware_shared_state_handles");
u32 GetHardwareSharedStateTileIndex(void const *, u32 value)
{
    HardwareSharedState * state = gUnk_03000408;
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
    HardwareSharedState * state = gUnk_03000408;
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
    HardwareSharedState * state = gUnk_03000408;
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

void FillHardwareTileTree64(HardwareTileTree64 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void FillHardwareTileTree64(HardwareTileTree64 * tree)
{
    tree->children[0].bits = ~0u;
    tree->children[1].bits = ~0u;
    tree->full = true;
    tree->empty = false;
}

void FillHardwareTileTree128(HardwareTileTree128 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void FillHardwareTileTree128(HardwareTileTree128 * tree)
{
    FillHardwareTileTree64(&tree->children[0]);
    FillHardwareTileTree64(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void FillHardwareTileTree256(HardwareTileTree256 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void FillHardwareTileTree256(HardwareTileTree256 * tree)
{
    FillHardwareTileTree128(&tree->children[0]);
    FillHardwareTileTree128(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void FillHardwareTileTree512(HardwareTileTree512 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void FillHardwareTileTree512(HardwareTileTree512 * tree)
{
    FillHardwareTileTree256(&tree->children[0]);
    FillHardwareTileTree256(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void ClearHardwareTileTree64(HardwareTileTree64 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void ClearHardwareTileTree64(HardwareTileTree64 * tree)
{
    tree->children[1].bits = 0;
    tree->children[0].bits = 0;
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree128(HardwareTileTree128 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void ClearHardwareTileTree128(HardwareTileTree128 * tree)
{
    ClearHardwareTileTree64(&tree->children[1]);
    ClearHardwareTileTree64(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree256(HardwareTileTree256 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void ClearHardwareTileTree256(HardwareTileTree256 * tree)
{
    ClearHardwareTileTree128(&tree->children[1]);
    ClearHardwareTileTree128(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearHardwareTileTree512(HardwareTileTree512 *)
    SECTION(".text.hardware_shared_state_tile_tree");
void ClearHardwareTileTree512(HardwareTileTree512 * tree)
{
    ClearHardwareTileTree256(&tree->children[1]);
    ClearHardwareTileTree256(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void HardwareTileTree64::Reserve(u32 offset, u32 length)
{
    if (offset > 63 || length == 0)
        return;
    if (offset == 0 && length > 63) {
        FillHardwareTileTree64(this);
        return;
    }
    if (offset <= 31) {
        u32 first_capacity = 32 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].bits |= ((1u << count) - 1) << offset;
    }
    if (offset + length > 32) {
        u32 second_offset = offset > 31 ? offset - 32 : 0;
        u32 second_length = offset + length;
        second_length -= 32;
        second_length -= second_offset;
        children[1].bits |= ((1u << second_length) - 1) << second_offset;
    }
    u32 active = 0;
    if (children[0].IsFull())
        if (children[1].IsFull())
            active = 1;
    full = active;
    empty = false;
}

void HardwareTileTree64::Unreserve(u32 offset, u32 length)
{
    if (offset > 63 || length == 0)
        return;
    if (offset == 0 && length > 63) {
        ClearHardwareTileTree64(this);
        return;
    }
    if (offset <= 31) {
        u32 first_capacity = 32 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].bits &= ~(((1u << count) - 1) << offset);
    }
    if (offset + length > 32) {
        u32 second_offset = offset > 31 ? offset - 32 : 0;
        u32 second_length = offset + length;
        second_length -= 32;
        second_length -= second_offset;
        children[1].bits &= ~(((1u << second_length) - 1) << second_offset);
    }
    full = false;
    u32 active = 0;
    if (children[0].IsEmpty())
        if (children[1].IsEmpty())
            active = 1;
    empty = active;
}

// Split a partial request at the child boundary; each child owns its
// relative offset. The unchanged end is shared by the range check
// and the second-child length calculation.
void HardwareTileTree128::Reserve(u32 offset, u32 length)
{
    if (offset > 127 || length == 0)
        return;
    if (offset == 0 && length > 127) {
        FillHardwareTileTree128(this);
        return;
    }
    if (offset <= 63) {
        u32 first_capacity = 64 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].Reserve(offset, count);
    }
    u32 const end = offset + length;
    if (end > 64) {
        u32 second_offset = offset > 63 ? offset - 64 : 0;
        u32 second_length = end;
        second_length -= 64;
        second_length -= second_offset;
        children[1].Reserve(second_offset, second_length);
    }
    u32 active = 0;
    if (children[0].full != 0)
        active = (0u - children[1].full) >> 31;
    full = active;
    empty = false;
}

void HardwareTileTree256::Reserve(u32 offset, u32 length)
{
    if (offset > 255 || length == 0)
        return;
    if (offset == 0 && length > 255) {
        FillHardwareTileTree256(this);
        return;
    }
    if (offset <= 127) {
        u32 first_capacity = 128 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].Reserve(offset, count);
    }
    u32 const end = offset + length;
    if (end > 128) {
        u32 second_offset = offset > 127 ? offset - 128 : 0;
        u32 second_length = end;
        second_length -= 128;
        second_length -= second_offset;
        children[1].Reserve(second_offset, second_length);
    }
    u32 active = 0;
    if (children[0].full != 0)
        active = (0u - children[1].full) >> 31;
    full = active;
    empty = false;
}

void HardwareTileTree512::Reserve(u32 offset, u32 length)
{
    if (offset > 511 || length == 0)
        return;
    if (offset == 0 && length > 511) {
        FillHardwareTileTree512(this);
        return;
    }
    if (offset <= 255) {
        u32 first_capacity = 256 - offset;
        u32 count = std::min(length, first_capacity);
        children[0].Reserve(offset, count);
    }
    if (offset + length > 256) {
        u32 second_offset = offset > 255 ? offset - 256 : 0;
        u32 second_length = offset + length;
        second_length -= 256;
        second_length -= second_offset;
        children[1].Reserve(second_offset, second_length);
    }
    u32 active = 0;
    if (children[0].full != 0)
        active = (0u - children[1].full) >> 31;
    full = active;
    empty = false;
}

void HardwareTileTree128::Unreserve(u32 offset, u32 length)
{
    if (offset > 127 || length == 0)
        return;
    if (offset == 0 && length > 127) {
        ClearHardwareTileTree128(this);
        return;
    }
    HardwareTileTree64 * first = &children[0];
    if (offset <= 63) {
        u32 first_capacity = 64 - offset;
        u32 count = std::min(length, first_capacity);
        first->Unreserve(offset, count);
    }
    u32 const end = offset + length;
    if (end > 64) {
        u32 second_offset = offset > 63 ? offset - 64 : 0;
        u32 second_length = end;
        second_length -= 64;
        second_length -= second_offset;
        children[1].Unreserve(second_offset, second_length);
    }
    full = false;
    u32 active = 0;
    if (first->empty != 0) {
        HardwareTileTree64 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

void HardwareTileTree256::Unreserve(u32 offset, u32 length)
{
    if (offset > 255 || length == 0)
        return;
    if (offset == 0 && length > 255) {
        ClearHardwareTileTree256(this);
        return;
    }
    HardwareTileTree128 * first = &children[0];
    if (offset <= 127) {
        u32 first_capacity = 128 - offset;
        u32 count = std::min(length, first_capacity);
        first->Unreserve(offset, count);
    }
    u32 const end = offset + length;
    if (end > 128) {
        u32 second_offset = offset > 127 ? offset - 128 : 0;
        u32 second_length = end;
        second_length -= 128;
        second_length -= second_offset;
        children[1].Unreserve(second_offset, second_length);
    }
    full = false;
    u32 active = 0;
    if (first->empty != 0) {
        HardwareTileTree128 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

void HardwareTileTree512::Unreserve(u32 offset, u32 length)
{
    if (offset > 511 || length == 0)
        return;
    if (offset == 0 && length > 511) {
        ClearHardwareTileTree512(this);
        return;
    }
    HardwareTileTree256 * first = &children[0];
    if (offset <= 255) {
        u32 first_capacity = 256 - offset;
        u32 count = std::min(length, first_capacity);
        first->Unreserve(offset, count);
    }
    if (offset + length > 256) {
        u32 second_offset = offset > 255 ? offset - 256 : 0;
        u32 second_length = offset + length;
        second_length -= 256;
        second_length -= second_offset;
        children[1].Unreserve(second_offset, second_length);
    }
    full = false;
    u32 active = 0;
    if (first->empty != 0) {
        HardwareTileTree256 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

// Each level selects the first non-full child and keeps the parent's flags
// consistent with the children. The return value is a tile offset, not a handle.
u32 HardwareTileTree64::Allocate(u32 size_shift)
{
    u32 index;
    ObjTileBitmap32 * child;
    if (size_shift <= 5) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u8 const child_full = child->IsFull();
            if (child_full == 0) {
                u32 offset = child->Allocate(size_shift);
                u32 valid = 0;
                if (offset <= 0x1F)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    u32 active = 0;
                    if (children[0].IsFull())
                        if (children[1].IsFull())
                            active = 1;
                    full = active;
                    return (index << 5) | offset;
                }
            }
        }
    } else if (size_shift == 6 && empty != 0) {
        FillHardwareTileTree64(this);
        return 0;
    }
    return 64;
}

u32 HardwareTileTree128::Allocate(u32 size_shift)
{
    u32 index;
    HardwareTileTree64 * child;
    if (size_shift <= 6) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u8 const child_full = child->full;
            if (child_full == 0) {
                u32 offset = child->Allocate(size_shift);
                u32 valid = 0;
                if (offset <= 0x3F)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    u32 active = 0;
                    if (children[0].full != 0)
                        active = (0u - children[1].full) >> 31;
                    full = active;
                    return (index << 6) | offset;
                }
            }
        }
    } else if (size_shift == 7 && empty != 0) {
        FillHardwareTileTree128(this);
        return 0;
    }
    return 128;
}

u32 HardwareTileTree256::Allocate(u32 size_shift)
{
    u32 index;
    HardwareTileTree128 * child;
    if (size_shift <= 7) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u8 const child_full = child->full;
            if (child_full == 0) {
                u32 offset = child->Allocate(size_shift);
                u32 valid = 0;
                if (offset <= 0x7F)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    u32 active = 0;
                    if (children[0].full != 0)
                        active = (0u - children[1].full) >> 31;
                    full = active;
                    return (index << 7) | offset;
                }
            }
        }
    } else if (size_shift == 8 && empty != 0) {
        FillHardwareTileTree256(this);
        return 0;
    }
    return 256;
}

u32 HardwareTileTree512::Allocate(u32 size_shift)
{
    u32 index;
    HardwareTileTree256 * child;
    if (size_shift <= 8) {
        for (index = 0, child = children; (int)index <= 1; ++child, ++index) {
            u8 const child_full = child->full;
            if (child_full == 0) {
                u32 offset = child->Allocate(size_shift);
                u32 valid = 0;
                if (offset <= 0xFF)
                    valid = 1;
                if (valid != 0) {
                    empty = child_full;
                    u32 active = 0;
                    if (children[0].full != 0)
                        active = (0u - children[1].full) >> 31;
                    full = active;
                    return (index << 8) | offset;
                }
            }
        }
    } else if (size_shift == 9 && empty != 0) {
        FillHardwareTileTree512(this);
        return 0;
    }
    return 512;
}

// The offset stays relative to the root: each child selects its own half,
// and the existing 32-tile leaf helper masks off the upper index bits.
void HardwareTileTree64::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 5) {
        u32 use_second = offset & 32;
        ObjTileBitmap32 * first = &children[0];
        ObjTileBitmap32 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->IsEmpty())
            if (children[1].IsEmpty())
                active = 1;
        empty = active;
    } else if (size_shift == 6) {
        ClearHardwareTileTree64(this);
    }
}

void HardwareTileTree128::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 6) {
        u32 use_second = offset & 64;
        HardwareTileTree64 * first = &children[0];
        HardwareTileTree64 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0)
            active = (0u - children[1].empty) >> 31;
        empty = active;
    } else if (size_shift == 7) {
        ClearHardwareTileTree128(this);
    }
}

void HardwareTileTree256::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 7) {
        u32 use_second = offset & 128;
        HardwareTileTree128 * first = &children[0];
        HardwareTileTree128 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            HardwareTileTree128 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 8) {
        ClearHardwareTileTree256(this);
    }
}

void HardwareTileTree512::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 8) {
        u32 use_second = offset & 256;
        HardwareTileTree256 * first = &children[0];
        HardwareTileTree256 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            HardwareTileTree256 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 9) {
        ClearHardwareTileTree512(this);
    }
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
