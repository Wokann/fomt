#ifndef OBJ_PALETTE_POOL_STORAGE_HH
#define OBJ_PALETTE_POOL_STORAGE_HH

#include "prelude.h"
#include "gbaio.h"

union ObjPalettePoolEntry
{
    ObjPalettePoolEntry * next_free;

    struct
    {
        u16 reference_count;
        u16 generation;
    } allocated;
};

// count must be positive; the last entry links to tail.
EC ObjPalettePoolEntry * InitializeObjPaletteFreeList(
    ObjPalettePoolEntry * entries, int count,
    ObjPalettePoolEntry * tail);

// OBJ palette RAM has sixteen 16-colour banks, addressed by OAM's four-bit
// palette field. Derive software traversal limits from this actual array.
struct ObjPalettePoolState
{
    ObjPalettePoolState()
    {
        first_free = InitializeObjPaletteFreeList(entries, ARRAY_COUNT(entries), 0);
        occupied_mask = 0;
        allocated_count = 0;
        owner_ref_count = 0;
        reserved_first = 0;
        reserved_count = 0;
        occupied_mask = 0;
    }

    bool IsOccupied(unsigned int idx) const { return idx < ARRAY_COUNT(entries) && (occupied_mask & (1 << (idx % (sizeof(occupied_mask) * 8)))) != 0; }

    void ClearOccupied(unsigned int idx)
    {
        if (idx < ARRAY_COUNT(entries))
            occupied_mask &= ~(1 << (idx % (sizeof(occupied_mask) * 8)));
    }

    void SetOccupied(unsigned int idx)
    {
        if (idx < ARRAY_COUNT(entries))
            occupied_mask |= (1 << (idx % (sizeof(occupied_mask) * 8)));
    }

    ObjPalettePoolEntry & GetEntry(unsigned int idx) { return entries[idx]; }

    unsigned int IndexOf(ObjPalettePoolEntry const * ent) const { return ent - entries; }

    void FreeEntry(ObjPalettePoolEntry * ent)
    {
        ent->next_free = first_free;
        first_free = ent;
    }

    ObjPalettePoolEntry * AllocEntry(ObjPalettePoolEntry * ent)
    {
        ObjPalettePoolEntry * prev = first_free;

        if (ent != nullptr)
            first_free = ent->next_free;

        return prev;
    }

    /* +00 */ ObjPalettePoolEntry * first_free;
    /* +04 */ ObjPalettePoolEntry entries[OBJ_PLTT_SIZE / PLTT_SIZE_4BPP];
    // Occupancy includes reserved banks; allocated_count excludes them.
    /* +44 */ u32 occupied_mask;
    /* +48 */ u16 allocated_count;
    // Native construction leaves this generation counter uninitialized.
    /* +4A */ u16 last_generation;
    /* +4C */ u32 owner_ref_count;
    /* +50 */ u8 reserved_first;
    /* +51 */ u8 reserved_count;
};

#endif // OBJ_PALETTE_POOL_STORAGE_HH
