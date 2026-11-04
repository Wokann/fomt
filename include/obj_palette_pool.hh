#ifndef OBJ_PALETTE_POOL_HH
#define OBJ_PALETTE_POOL_HH

#include "prelude.h"
#include "gbaio.h"

// A lifetime reference to the OBJ 4bpp palette-bank pool; its destructor updates
// the global owner count rather than reading fields from the receiver.
struct ObjPalettePoolOwner
{
    ObjPalettePoolOwner() asm("ConstructObjPalettePoolOwner");
    ObjPalettePoolOwner(ObjPalettePoolOwner const &) asm("CopyConstructObjPalettePoolOwner");
    ~ObjPalettePoolOwner();
    void Reserve(unsigned int from, unsigned int count) asm("ReserveObjPaletteBanks");
};

typedef char ObjPalettePoolOwnerSizeCheck[sizeof(ObjPalettePoolOwner) == 4 ? 1 : -1];

EXTERN_C
// ABI declarations for still-native callers. These name the actual members
// above, not separate wrappers or storage aliases.
void * ConstructObjPalettePoolOwner(void * self);
void * CopyConstructObjPalettePoolOwner(void * self, void const * other);
void ReserveObjPaletteBanks(void * self, unsigned int from, unsigned int count);
EXTERN_C_END

union ObjPalettePoolEntry
{
    ObjPalettePoolEntry * next_free;

    struct
    {
        u16 reference_count;
        u16 generation;
    } allocated;
};

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

extern ObjPalettePoolState * gObjPalettePool;

// The allocated handle uses bits 0..3 for the slot and bits 4..19 for its
// generation. Validation ignores the remaining bits.
union ObjPaletteHandle
{
    u32 value;
    struct
    {
        u32 index : 4;
        u32 generation : 16;
        u32 : 12;
    } fields;

    ObjPaletteHandle() {}
    ObjPaletteHandle(u32 index, ObjPalettePoolEntry const & entry) : value(0)
    {
        fields.index = index;
        fields.generation = entry.allocated.generation;
    }

    u32 Index() const { return fields.index; }
};

typedef char ObjPaletteHandleSizeCheck[sizeof(ObjPaletteHandle) == 4 ? 1 : -1];

EXTERN_C

// These entries use the shared allocator, not the receiver passed in r0.
u32 AllocateObjPaletteHandle(void * self);
// Null, inactive and stale-generation handles leave the pool unchanged.
// Dropping the last reference returns the slot to the free list.
void ReleaseObjPaletteHandle(void * self, u32 handle);
// Return the original handle on success, or zero on validation failure
// or 16-bit reference-count overflow; overflow restores the old count.
u32 RetainObjPaletteHandle(void * self, u32 handle);
// Invalid handles return UINT32_MAX here, but zero from the count query.
u32 GetObjPaletteBank(void * self, u32 handle);
u32 GetObjPaletteHandleReferenceCount(void * self, u32 handle);

// Number of allocated banks, excluding reserved banks and extra references.
u16 GetAllocatedObjPaletteCount(void);
u32 GetObjPaletteCapacity(void);

EXTERN_C_END


#endif // OBJ_PALETTE_POOL_HH
