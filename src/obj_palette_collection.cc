#include "obj_palette_collection.hh"

#include "obj_palette_pool.hh"
#include "allocation_failure.hh"

#include <memory>
#include <algorithm>
#include <new>
#include <stdlib.h>

EXTERN_C

extern void free(void * pointer);

EXTERN_C_END

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

ObjPaletteCollection::ObjPaletteCollection(u8 const & count)
    : storage(new ObjPaletteCollectionStorage(count))
{
}

ObjPaletteCollection::ObjPaletteCollection() : storage(0)
{
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

ObjPaletteCollection::~ObjPaletteCollection()
{
    if (storage != 0)
        delete storage;
}

ObjPaletteCollectionEntry ObjPaletteCollection::Get() const
{
    if (storage != 0) {
        ObjPaletteCollectionStorage * current = storage;
        ObjPaletteCollectionEntry * end = current->end;
        ObjPaletteCollectionEntry * cursor = current->cursor;
        if (cursor != end) {
            ObjPaletteCollectionEntry * first = cursor;
            do {
                ObjPaletteCollectionEntry * entry = cursor;
                cursor++;
                if (cursor == end)
                    cursor = current->start;
                if (GetObjPaletteHandleReferenceCount(entry, entry->handle) == 1) {
                    current->cursor = cursor;
                    cursor = entry;
                    break;
                }
            } while (cursor != first);
        }
        return *cursor;
    }
    return ObjPaletteCollectionEntry();
}

void ObjPaletteCollectionStorage::Reserve(u32 count)
{
    if (static_cast<u32>(allocation.end - start) < count) {
        u32 old_size = end - start;
        ObjPaletteCollectionEntry * replacement;
        if (start != 0) {
            replacement = AllocateAndCopy(count, start, end);
            std::destroy(start, end);
            if (start != 0)
                free(start);
        } else {
            replacement = Allocate(count);
        }
        // These offsets describe entries in the newly allocated heap buffer.
        ObjPaletteCollectionEntry * new_end = reinterpret_cast<ObjPaletteCollectionEntry *>(
            old_size * sizeof(ObjPaletteCollectionEntry) + reinterpret_cast<u32>(replacement));
        ObjPaletteCollectionEntry * new_capacity_end = reinterpret_cast<ObjPaletteCollectionEntry *>(
            count * sizeof(ObjPaletteCollectionEntry) + reinterpret_cast<u32>(replacement));
        start = replacement;
        end = new_end;
        allocation.end = new_capacity_end;
    }
}
