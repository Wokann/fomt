#include "hardware_resource.hh"

#include "obj_palette_pool.hh"
#include "new.hh"

#include <memory>
#include <algorithm>
#include <new>
#include <stdlib.h>

EXTERN_C

extern void free(void * pointer);

EXTERN_C_END

inline void * HardwareResourceStorage::AllocateBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == 0)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline HardwareResourceEntry * HardwareResourceStorage::Allocate(u32 count)
{
    return count != 0
        ? static_cast<HardwareResourceEntry *>(AllocateBytes(count * sizeof(HardwareResourceEntry)))
        : 0;
}

inline HardwareResourceEntry * HardwareResourceStorage::AllocateAndCopy(u32 count,
    HardwareResourceEntry * first, HardwareResourceEntry * last)
{
    HardwareResourceEntry * result = Allocate(count);
    HardwareResourceEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return result;
}

inline HardwareResourceEntry * HardwareResourceStorage::CopyEntries(
    HardwareResourceEntry const * first, HardwareResourceEntry const * last,
    HardwareResourceEntry * result)
{
    HardwareResourceEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return current;
}

inline HardwareResourceEntry * HardwareResourceStorage::FillEntries(
    HardwareResourceEntry * first, u32 count, HardwareResourceEntry const & value)
{
    HardwareResourceEntry * current = first;
    for (; count != 0; --count, ++current)
        std::construct(current, value);
    return current;
}

inline void HardwareResourceStorage::Grow(HardwareResourceEntry * old_end,
    u32 count, HardwareResourceEntry const & value)
{
    u32 old_size = old_end - start;
    u32 new_size = old_size + std::max(old_size, count);
    HardwareResourceEntry * replacement = Allocate(new_size);
    HardwareResourceEntry * current = replacement;
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
    HardwareResourceEntry * new_capacity_end = replacement + new_size;
    start = replacement;
    end = current;
    allocation.end = new_capacity_end;
}

inline void HardwareResourceStorage::PushBack(HardwareResourceEntry const & value)
{
    if (end != allocation.end) {
        std::construct(end, value);
        ++end;
    } else {
        Grow(end, 1, value);
    }
}

inline HardwareResourceStorage::HardwareResourceStorage(u8 const & count, HardwareResourceStoragePrefix const & prefix)
    : start(0), end(0), allocation(prefix)
{
    u8 remaining = count;
    Reserve(remaining);
    --remaining;
    if (remaining != 0xFF) {
        do {
            HardwareResourceEntry const & entry = HardwareResourceEntry();
            PushBack(entry);
        } while (--remaining != 0xFF);
    }
    cursor = start;
}

HardwareResource::HardwareResource(u8 const & count)
    : storage(new HardwareResourceStorage(count))
{
}

HardwareResource::HardwareResource() : storage(0)
{
}

inline HardwareResourceStorage::~HardwareResourceStorage()
{
    HardwareResourceEntry * last = end;
    HardwareResourceEntry * current = start;
    while (current != last) {
        current->~HardwareResourceEntry();
        ++current;
    }
    if (start != 0)
        free(start);
}

HardwareResource::~HardwareResource()
{
    if (storage != 0)
        delete storage;
}

HardwareResourceEntry HardwareResource::Get() const
{
    if (storage != 0) {
        HardwareResourceStorage * current = storage;
        HardwareResourceEntry * end = current->end;
        HardwareResourceEntry * cursor = current->cursor;
        if (cursor != end) {
            HardwareResourceEntry * first = cursor;
            do {
                HardwareResourceEntry * entry = cursor;
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
    return HardwareResourceEntry();
}

void HardwareResourceStorage::Reserve(u32 count)
{
    if (static_cast<u32>(allocation.end - start) < count) {
        u32 old_size = end - start;
        HardwareResourceEntry * replacement;
        if (start != 0) {
            replacement = AllocateAndCopy(count, start, end);
            std::destroy(start, end);
            if (start != 0)
                free(start);
        } else {
            replacement = Allocate(count);
        }
        // These offsets describe entries in the newly allocated heap buffer.
        HardwareResourceEntry * new_end = reinterpret_cast<HardwareResourceEntry *>(
            old_size * sizeof(HardwareResourceEntry) + reinterpret_cast<u32>(replacement));
        HardwareResourceEntry * new_capacity_end = reinterpret_cast<HardwareResourceEntry *>(
            count * sizeof(HardwareResourceEntry) + reinterpret_cast<u32>(replacement));
        start = replacement;
        end = new_end;
        allocation.end = new_capacity_end;
    }
}
