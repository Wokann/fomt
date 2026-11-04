#include "obj_tile_pool.hh"
#include <algorithm>

ObjTilePoolState * gObjTilePool;

EXTERN_C
void __builtin_delete(void *);
EXTERN_C_END

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

u32 AllocateObjTileHandle(void *, u32 size_shift)
    SECTION(".text.obj_tile_pool_handles");
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
    SECTION(".text.obj_tile_pool_handles");
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
    SECTION(".text.obj_tile_pool_handles");
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
    SECTION(".text.obj_tile_pool_handles");
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
    SECTION(".text.obj_tile_pool_handles");
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
    SECTION(".text.obj_tile_pool_handles");
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

void FillObjTileTree64(ObjTileTree64 *)
    SECTION(".text.obj_tile_tree");
void FillObjTileTree64(ObjTileTree64 * tree)
{
    tree->children[0].bits = ~0u;
    tree->children[1].bits = ~0u;
    tree->full = true;
    tree->empty = false;
}

void FillObjTileTree128(ObjTileTree128 *)
    SECTION(".text.obj_tile_tree");
void FillObjTileTree128(ObjTileTree128 * tree)
{
    FillObjTileTree64(&tree->children[0]);
    FillObjTileTree64(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void FillObjTileTree256(ObjTileTree256 *)
    SECTION(".text.obj_tile_tree");
void FillObjTileTree256(ObjTileTree256 * tree)
{
    FillObjTileTree128(&tree->children[0]);
    FillObjTileTree128(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void FillObjTileTree512(ObjTileTree512 *)
    SECTION(".text.obj_tile_tree");
void FillObjTileTree512(ObjTileTree512 * tree)
{
    FillObjTileTree256(&tree->children[0]);
    FillObjTileTree256(&tree->children[1]);
    tree->full = true;
    tree->empty = false;
}

void ClearObjTileTree64(ObjTileTree64 *)
    SECTION(".text.obj_tile_tree");
void ClearObjTileTree64(ObjTileTree64 * tree)
{
    tree->children[1].bits = 0;
    tree->children[0].bits = 0;
    tree->full = 0;
    tree->empty = 1;
}

void ClearObjTileTree128(ObjTileTree128 *)
    SECTION(".text.obj_tile_tree");
void ClearObjTileTree128(ObjTileTree128 * tree)
{
    ClearObjTileTree64(&tree->children[1]);
    ClearObjTileTree64(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearObjTileTree256(ObjTileTree256 *)
    SECTION(".text.obj_tile_tree");
void ClearObjTileTree256(ObjTileTree256 * tree)
{
    ClearObjTileTree128(&tree->children[1]);
    ClearObjTileTree128(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

void ClearObjTileTree512(ObjTileTree512 *)
    SECTION(".text.obj_tile_tree");
void ClearObjTileTree512(ObjTileTree512 * tree)
{
    ClearObjTileTree256(&tree->children[1]);
    ClearObjTileTree256(&tree->children[0]);
    tree->full = 0;
    tree->empty = 1;
}

// Full 32-bit child ranges retain the original agbcp/ARM shift-by-32 result.
// The Reserve/Unreserve bit expressions are not portable C++.
void ObjTileTree64::Reserve(u32 offset, u32 length)
{
    if (offset > 63 || length == 0)
        return;
    if (offset == 0 && length > 63) {
        FillObjTileTree64(this);
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

void ObjTileTree64::Unreserve(u32 offset, u32 length)
{
    if (offset > 63 || length == 0)
        return;
    if (offset == 0 && length > 63) {
        ClearObjTileTree64(this);
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
void ObjTileTree128::Reserve(u32 offset, u32 length)
{
    if (offset > 127 || length == 0)
        return;
    if (offset == 0 && length > 127) {
        FillObjTileTree128(this);
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

void ObjTileTree256::Reserve(u32 offset, u32 length)
{
    if (offset > 255 || length == 0)
        return;
    if (offset == 0 && length > 255) {
        FillObjTileTree256(this);
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

void ObjTileTree512::Reserve(u32 offset, u32 length)
{
    if (offset > 511 || length == 0)
        return;
    if (offset == 0 && length > 511) {
        FillObjTileTree512(this);
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

void ObjTileTree128::Unreserve(u32 offset, u32 length)
{
    if (offset > 127 || length == 0)
        return;
    if (offset == 0 && length > 127) {
        ClearObjTileTree128(this);
        return;
    }
    ObjTileTree64 * first = &children[0];
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
        ObjTileTree64 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

void ObjTileTree256::Unreserve(u32 offset, u32 length)
{
    if (offset > 255 || length == 0)
        return;
    if (offset == 0 && length > 255) {
        ClearObjTileTree256(this);
        return;
    }
    ObjTileTree128 * first = &children[0];
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
        ObjTileTree128 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

void ObjTileTree512::Unreserve(u32 offset, u32 length)
{
    if (offset > 511 || length == 0)
        return;
    if (offset == 0 && length > 511) {
        ClearObjTileTree512(this);
        return;
    }
    ObjTileTree256 * first = &children[0];
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
        ObjTileTree256 * second = &children[1];
        active = (0u - second->empty) >> 31;
    }
    empty = active;
}

// Each level selects the first non-full child and keeps the parent's flags
// consistent with the children. The return value is a tile offset, not a handle.
u32 ObjTileTree64::Allocate(u32 size_shift)
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
        FillObjTileTree64(this);
        return 0;
    }
    return 64;
}

u32 ObjTileTree128::Allocate(u32 size_shift)
{
    u32 index;
    ObjTileTree64 * child;
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
        FillObjTileTree128(this);
        return 0;
    }
    return 128;
}

u32 ObjTileTree256::Allocate(u32 size_shift)
{
    u32 index;
    ObjTileTree128 * child;
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
        FillObjTileTree256(this);
        return 0;
    }
    return 256;
}

u32 ObjTileTree512::Allocate(u32 size_shift)
{
    u32 index;
    ObjTileTree256 * child;
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
        FillObjTileTree512(this);
        return 0;
    }
    return 512;
}

// The offset stays relative to the root: each child selects its own half,
// and the existing 32-tile leaf helper masks off the upper index bits.
void ObjTileTree64::Free(u32 offset, u32 size_shift)
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
        ClearObjTileTree64(this);
    }
}

void ObjTileTree128::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 6) {
        u32 use_second = offset & 64;
        ObjTileTree64 * first = &children[0];
        ObjTileTree64 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0)
            active = (0u - children[1].empty) >> 31;
        empty = active;
    } else if (size_shift == 7) {
        ClearObjTileTree128(this);
    }
}

void ObjTileTree256::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 7) {
        u32 use_second = offset & 128;
        ObjTileTree128 * first = &children[0];
        ObjTileTree128 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            ObjTileTree128 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 8) {
        ClearObjTileTree256(this);
    }
}

void ObjTileTree512::Free(u32 offset, u32 size_shift)
{
    if (size_shift <= 8) {
        u32 use_second = offset & 256;
        ObjTileTree256 * first = &children[0];
        ObjTileTree256 * child = first;
        if (use_second)
            child = &children[1];
        child->Free(offset, size_shift);
        full = false;
        u32 active = 0;
        if (first->empty != 0) {
            ObjTileTree256 * second = &children[1];
            active = (0u - second->empty) >> 31;
        }
        empty = active;
    } else if (size_shift == 9) {
        ClearObjTileTree512(this);
    }
}

ObjTilePoolEntry * InitializeObjTileFreeList(
    ObjTilePoolEntry *, i32, ObjTilePoolEntry *)
    SECTION(".text.obj_tile_handle_free_list");
ObjTilePoolEntry * InitializeObjTileFreeList(
    ObjTilePoolEntry * entries, i32 count, ObjTilePoolEntry * tail)
{
    ObjTilePoolEntry * entry = entries + (count - 1);
    entry->data.next_free = tail;
    while (entry != entries) {
        ObjTilePoolEntry * next = entry;
        --entry;
        entry->data.next_free = next;
    }
    return entry;
}
