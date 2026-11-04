#include "obj_palette_pool.hh"

ObjPalettePoolState * gObjPalettePool;

ObjPalettePoolOwner::ObjPalettePoolOwner()
{
    if (gObjPalettePool == nullptr)
    {
        gObjPalettePool = new ObjPalettePoolState;
    }

    gObjPalettePool->owner_ref_count++;

}

ObjPalettePoolOwner::ObjPalettePoolOwner(ObjPalettePoolOwner const &)
{
    gObjPalettePool->owner_ref_count++;

}

ObjPalettePoolOwner::~ObjPalettePoolOwner()
{
    gObjPalettePool->owner_ref_count--;

    if (gObjPalettePool->owner_ref_count == 0)
    {
        if (gObjPalettePool != nullptr)
            delete gObjPalettePool;

        gObjPalettePool = nullptr;
    }
}

void ObjPalettePoolOwner::Reserve(unsigned int from, unsigned int count)
{
    ObjPalettePoolState * h = gObjPalettePool;

    if (h->reserved_count != 0)
    {
        for (unsigned int i = h->reserved_first, end = h->reserved_first + h->reserved_count; i < end; i++)
        {
            if (h->IsOccupied(i))
            {
                h->FreeEntry(&h->GetEntry(i));
                h->ClearOccupied(i);
            }
        }

        h->reserved_count = 0;
    }

    if (count != 0)
    {
        unsigned int to = count + from;

        for (unsigned int i = 0; i < ARRAY_COUNT(h->entries); i++)
        {
            if (h->IsOccupied(i))
            {
                if (from <= i && i < to)
                {
                    h->GetEntry(i).allocated.generation = 0;
                    h->FreeEntry(&h->GetEntry(i));
                    h->ClearOccupied(i);
                    h->allocated_count--;
                }
            }
        }

        unsigned int alloc_mask = 0;
        unsigned int target_mask = ((1 << count) - 1u) << from;

        for (;;)
        {
            ObjPalettePoolEntry * ent = h->AllocEntry(h->first_free);

            if (ent == nullptr)
                goto alloc_loop; /* break doesn't match D= */

            h->SetOccupied(h->IndexOf(ent));
            alloc_mask |= 1u << h->IndexOf(ent);

            if ((alloc_mask & target_mask) == target_mask)
                break;
        }

    alloc_loop:
        for (unsigned int i = 0; (alloc_mask & ~target_mask) != 0 && i < ARRAY_COUNT(h->entries); i++)
        {
            unsigned int bit = 1u << i;

            if (alloc_mask & bit & ~target_mask)
            {
                h->FreeEntry(&h->GetEntry(i));
                h->ClearOccupied(i);

                alloc_mask &= ~bit;
            }
        }

        h->reserved_first = from;
        h->reserved_count = count;
    }
}

EXTERN_C

u32 AllocateObjPaletteHandle(void *)
{
    ObjPalettePoolState * state = gObjPalettePool;
    ObjPalettePoolEntry * const current = state->first_free;
    ObjPalettePoolEntry * entry = state->AllocEntry(current);
    u32 result;
    if (entry != 0) {
        u32 index = state->IndexOf(entry);
        state->SetOccupied(index);
        ++state->allocated_count;
        entry->allocated.reference_count = 1;
        u32 generation = state->last_generation + 1;
        if (generation > 0xFFFF)
            generation = 1;
        current->allocated.generation = generation;
        state->last_generation = generation;
        ObjPaletteHandle handle(index, *current);
        result = handle.value;
        goto done;
    }
    result = 0;
done:
    return result;
}

void ReleaseObjPaletteHandle(void * self, u32 handle)
{
    ObjPalettePoolState * h = gObjPalettePool;
    ObjPaletteHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->IsOccupied(idx))
        {
            ObjPalettePoolEntry & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.allocated.generation;
            if (valid)
            {
                if (--ent.allocated.reference_count == 0)
                {
                    ent.allocated.generation = 0;
                    h->FreeEntry(&ent);
                    h->ClearOccupied(idx);
                    h->allocated_count--;
                }
            }
        }
    }
}

u32 RetainObjPaletteHandle(void * self, u32 handle)
{
    ObjPalettePoolState * h = gObjPalettePool;
    ObjPaletteHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->IsOccupied(idx))
        {
            ObjPalettePoolEntry & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.allocated.generation;
            if (valid)
            {
                u16 old_count = ent.allocated.reference_count;
                if (++ent.allocated.reference_count != 0)
                    return handle;
                ent.allocated.reference_count = old_count;
            }
        }
    }

    return 0;
}

u32 GetObjPaletteBank(void * self, u32 handle)
{
    ObjPalettePoolState * h = gObjPalettePool;
    ObjPaletteHandle packed;
    packed.value = handle;
    u32 result;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->IsOccupied(idx))
        {
            bool valid = packed.fields.generation == h->GetEntry(idx).allocated.generation;
            result = idx;
            if (valid)
                goto done;
        }
    }

    result = -1u;
done:
    return result;
}

u32 GetObjPaletteHandleReferenceCount(void * self, u32 handle)
{
    ObjPalettePoolState * h = gObjPalettePool;
    ObjPaletteHandle packed;
    packed.value = handle;

    if (handle != 0)
    {
        unsigned int idx = packed.Index();
        if (h->IsOccupied(idx))
        {
            ObjPalettePoolEntry & ent = h->GetEntry(idx);
            bool valid = packed.fields.generation == ent.allocated.generation;
            if (valid)
                return ent.allocated.reference_count;
        }
    }

    return 0;
}

u16 GetAllocatedObjPaletteCount(void)
{
    return gObjPalettePool->allocated_count;
}

u32 GetObjPaletteCapacity(void)
{
    return ARRAY_COUNT(gObjPalettePool->entries);
}

EXTERN_C_END

// The original shared helper lives later in the linkonce code area, rather
// than beside the pool's lifetime and reservation entries above.
EC SECTION(".text.obj_palette_free_list") ObjPalettePoolEntry * InitializeObjPaletteFreeList(
    ObjPalettePoolEntry * entries, int count,
    ObjPalettePoolEntry * tail)
{
    ObjPalettePoolEntry * cursor = entries + (count - 1);
    cursor->next_free = tail;
    while (cursor != entries)
    {
        ObjPalettePoolEntry * next = cursor;
        --cursor;
        cursor->next_free = next;
    }
    return cursor;
}
