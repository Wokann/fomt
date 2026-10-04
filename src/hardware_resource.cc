#include "hardware_resource.hh"

#include "hardware_allocator.hh"
#include "new.hh"

#include <memory>
#include <stdlib.h>

extern void __builtin_delete(void * pointer);

EXTERN_C

extern void free(void * pointer);

EXTERN_C_END

HardwareResource::HardwareResource() : storage(0)
{
}

HardwareResource::~HardwareResource()
{
    if (storage != 0) {
        HardwareResourceStorage * saved = storage;
        HardwareResourceEntry * end = saved->end;
        HardwareResourceEntry * cursor = saved->start;
        while (cursor != end) {
            cursor->~HardwareResourceEntry();
            cursor++;
        }
        if (saved->start != 0)
            free(saved->start);
        __builtin_delete(saved);
    }
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
                if (func_08007510(entry, entry->handle) == 1) {
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

void HardwareResourceStorage::Reserve(u32 count)
{
    if (static_cast<u32>(capacity_end - start) < count) {
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
        capacity_end = new_capacity_end;
    }
}
