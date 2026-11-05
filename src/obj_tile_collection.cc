#include "obj_tile_collection.hh"

#include "allocation_failure.hh"

#include <memory>
#include <stdlib.h>

extern void __builtin_delete(void * pointer);
extern void free(void * pointer);

inline void * ObjTileCollectionGroup::AllocateBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == 0)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline ObjTileCollectionEntry * ObjTileCollectionGroup::Allocate(u32 count)
{
    return count != 0
        ? static_cast<ObjTileCollectionEntry *>(AllocateBytes(count * sizeof(ObjTileCollectionEntry)))
        : 0;
}

inline ObjTileCollectionEntry * ObjTileCollectionGroup::AllocateAndCopy(u32 count,
    ObjTileCollectionEntry * first, ObjTileCollectionEntry * last)
{
    ObjTileCollectionEntry * result = Allocate(count);
    ObjTileCollectionEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return result;
}

void ObjTileCollectionGroup::Reserve(u32 count)
{
    if (static_cast<u32>(capacity_end - start) < count) {
        u32 old_size = end - start;
        ObjTileCollectionEntry * replacement;
        if (start != 0) {
            replacement = AllocateAndCopy(count, start, end);
            std::destroy(start, end);
            if (start != 0)
                free(start);
        } else {
            replacement = Allocate(count);
        }
        // Boundaries are byte counts within this newly allocated heap buffer,
        // not ROM addresses or regional offsets. Compute both before commit.
        ObjTileCollectionEntry * new_end = reinterpret_cast<ObjTileCollectionEntry *>(
            old_size * sizeof(ObjTileCollectionEntry) + reinterpret_cast<u32>(replacement));
        ObjTileCollectionEntry * new_capacity_end = reinterpret_cast<ObjTileCollectionEntry *>(
            count * sizeof(ObjTileCollectionEntry) + reinterpret_cast<u32>(replacement));
        start = replacement;
        end = new_end;
        capacity_end = new_capacity_end;
    }
}

ObjTileCollection::ObjTileCollection() : storage(0)
{
}

ObjTileCollection::~ObjTileCollection()
{
    if (storage != 0) {
        struct ObjTileCollectionStorage * saved = storage;
        struct ObjTileCollectionGroup * group = saved->groups + ARRAY_COUNT(saved->groups);
        while (saved->groups != group) {
            struct ObjTileCollectionEntry * entry;
            struct ObjTileCollectionEntry * end;
            --group;
            end = group->end;
            entry = group->start;
            if (entry != end) {
                do {
                    entry->~ObjTileCollectionEntry();
                    ++entry;
                } while (entry != end);
            }
            if (group->start != 0)
                free(group->start);
        }
        __builtin_delete(saved);
    }
}

ObjTileCollectionEntry ObjTileCollection::Get(u32 group_index) const
{
    ObjTileCollectionStorage * saved = storage;
    if (saved != 0) {
        ObjTileCollectionGroup * group = reinterpret_cast<ObjTileCollectionGroup *>(
            group_index * sizeof(ObjTileCollectionGroup) + reinterpret_cast<u32>(saved));
        struct ObjTileCollectionEntry * end = group->end;
        struct ObjTileCollectionEntry * current = group->cursor;
        if (current != end) {
            struct ObjTileCollectionEntry * first = current;
            do {
                struct ObjTileCollectionEntry * candidate = current;
                ++current;
                if (current == end)
                    current = group->start;
                if (GetObjTileHandleReferenceCount(candidate, candidate->handle) == 1) {
                    group->cursor = current;
                    current = candidate;
                    break;
                }
            } while (current != first);
        }
        return *current;
    }
    return ObjTileCollectionEntry(group_index);
}
