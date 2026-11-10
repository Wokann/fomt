#ifndef OBJ_PALETTE_COLLECTION_STORAGE_HH
#define OBJ_PALETTE_COLLECTION_STORAGE_HH

#include "obj_palette_pool.hh"
#include "allocation_failure.hh"

#include <memory>
#include <algorithm>
#include <new>
#include <stdlib.h>


// Neither native default nor copy construction writes these bytes.
// Keep their meaning unknown rather than inventing allocator state.
struct ObjPaletteCollectionStoragePrefix {
    u8 unk_00[4];
    ObjPaletteCollectionStoragePrefix() {}
    ObjPaletteCollectionStoragePrefix(ObjPaletteCollectionStoragePrefix const &) {}
};

struct ObjPaletteCollectionStorageBounds {
    ObjPaletteCollectionStoragePrefix prefix;
    ObjPaletteCollectionEntry * end;
    ObjPaletteCollectionStorageBounds(ObjPaletteCollectionStoragePrefix const & prefix)
        : prefix(prefix), end(0) {}
};

struct ObjPaletteCollectionStorage {
    explicit ObjPaletteCollectionStorage(u8 const & count, ObjPaletteCollectionStoragePrefix const & prefix = ObjPaletteCollectionStoragePrefix());
    ~ObjPaletteCollectionStorage();
    struct ObjPaletteCollectionEntry * start;
    struct ObjPaletteCollectionEntry * end;
    ObjPaletteCollectionStorageBounds allocation;
    struct ObjPaletteCollectionEntry * cursor;

    // Reserve is used before population; it does not retarget an existing cursor.
    void Reserve(u32 count);

private:
    ObjPaletteCollectionEntry * CopyEntries(ObjPaletteCollectionEntry const * first,
        ObjPaletteCollectionEntry const * last, ObjPaletteCollectionEntry * result);
    ObjPaletteCollectionEntry * FillEntries(ObjPaletteCollectionEntry * first,
        u32 count, ObjPaletteCollectionEntry const & value);
    void Grow(ObjPaletteCollectionEntry * old_end, u32 count, ObjPaletteCollectionEntry const & value);
    void PushBack(ObjPaletteCollectionEntry const & value);
    static void * AllocateBytes(u32 bytes);
    ObjPaletteCollectionEntry * Allocate(u32 count);
    ObjPaletteCollectionEntry * AllocateAndCopy(u32 count,
        ObjPaletteCollectionEntry * first, ObjPaletteCollectionEntry * last);
};

typedef char ObjPaletteCollectionStoragePrefixSizeCheck[sizeof(ObjPaletteCollectionStoragePrefix) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionStorageBoundsSizeCheck[sizeof(ObjPaletteCollectionStorageBounds) == 8 ? 1 : -1];
typedef char ObjPaletteCollectionStorageBoundsEndCheck[offsetof(ObjPaletteCollectionStorageBounds, end) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionEntrySizeCheck[sizeof(ObjPaletteCollectionEntry) == 8 ? 1 : -1];
typedef char ObjPaletteCollectionEntryHandleCheck[offsetof(ObjPaletteCollectionEntry, handle) == 4 ? 1 : -1];
typedef char ObjPaletteCollectionStorageSizeCheck[sizeof(ObjPaletteCollectionStorage) == 20 ? 1 : -1];
typedef char ObjPaletteCollectionStorageCapacityCheck[(offsetof(ObjPaletteCollectionStorage, allocation) + offsetof(ObjPaletteCollectionStorageBounds, end)) == 12 ? 1 : -1];
typedef char ObjPaletteCollectionStorageCursorCheck[offsetof(ObjPaletteCollectionStorage, cursor) == 16 ? 1 : -1];

inline void * ObjPaletteCollectionStorage::AllocateBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == 0)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline ObjPaletteCollectionEntry * ObjPaletteCollectionStorage::Allocate(u32 count)
{
    return count != 0
        ? static_cast<ObjPaletteCollectionEntry *>(AllocateBytes(count * sizeof(ObjPaletteCollectionEntry)))
        : 0;
}

inline ObjPaletteCollectionEntry * ObjPaletteCollectionStorage::AllocateAndCopy(u32 count,
    ObjPaletteCollectionEntry * first, ObjPaletteCollectionEntry * last)
{
    ObjPaletteCollectionEntry * result = Allocate(count);
    ObjPaletteCollectionEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return result;
}

inline ObjPaletteCollectionEntry * ObjPaletteCollectionStorage::CopyEntries(
    ObjPaletteCollectionEntry const * first, ObjPaletteCollectionEntry const * last,
    ObjPaletteCollectionEntry * result)
{
    ObjPaletteCollectionEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return current;
}

inline ObjPaletteCollectionEntry * ObjPaletteCollectionStorage::FillEntries(
    ObjPaletteCollectionEntry * first, u32 count, ObjPaletteCollectionEntry const & value)
{
    ObjPaletteCollectionEntry * current = first;
    for (; count != 0; --count, ++current)
        std::construct(current, value);
    return current;
}

inline void ObjPaletteCollectionStorage::Grow(ObjPaletteCollectionEntry * old_end,
    u32 count, ObjPaletteCollectionEntry const & value)
{
    u32 old_size = old_end - start;
    u32 new_size = old_size + std::max(old_size, count);
    ObjPaletteCollectionEntry * replacement = Allocate(new_size);
    ObjPaletteCollectionEntry * current = replacement;
    current = CopyEntries(start, old_end, current);
    if (count == 1) {
        std::construct(current, value);
        ++current;
    } else {
        current = FillEntries(current, count, value);
    }
    std::destroy(start, end);
    if (start != nullptr)
        free(start);
    ObjPaletteCollectionEntry * new_capacity_end = replacement + new_size;
    start = replacement;
    end = current;
    allocation.end = new_capacity_end;
}

inline void ObjPaletteCollectionStorage::PushBack(ObjPaletteCollectionEntry const & value)
{
    if (end != allocation.end) {
        std::construct(end, value);
        ++end;
    } else {
        Grow(end, 1, value);
    }
}

inline ObjPaletteCollectionStorage::ObjPaletteCollectionStorage(u8 const & count, ObjPaletteCollectionStoragePrefix const & prefix)
    : start(0), end(0), allocation(prefix)
{
    u8 remaining = count;
    Reserve(remaining);
    --remaining;
    if (remaining != 0xFF) {
        do {
            ObjPaletteCollectionEntry const & entry = ObjPaletteCollectionEntry();
            PushBack(entry);
        } while (--remaining != 0xFF);
    }
    cursor = start;
}

inline ObjPaletteCollectionStorage::~ObjPaletteCollectionStorage()
{
    ObjPaletteCollectionEntry * last = end;
    ObjPaletteCollectionEntry * current = start;
    while (current != last) {
        current->~ObjPaletteCollectionEntry();
        ++current;
    }
    if (start != 0)
        free(start);
}

#endif // OBJ_PALETTE_COLLECTION_STORAGE_HH
