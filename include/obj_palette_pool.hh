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

#include "obj_palette_pool_storage.hh"

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


struct ObjPaletteCollectionEntry {
    ObjPalettePoolOwner owner;
    u32 handle;

    ObjPaletteCollectionEntry()
    {
        handle = AllocateObjPaletteHandle(this);
    }

    ObjPaletteCollectionEntry(ObjPaletteCollectionEntry const & value)
    {
        handle = RetainObjPaletteHandle(this, value.handle);
    }

    u32 GetIndex()
    {
        return GetObjPaletteBank(this, handle);
    }

    ~ObjPaletteCollectionEntry()
    {
        ReleaseObjPaletteHandle(this, handle);
    }
};

#endif // OBJ_PALETTE_POOL_HH
