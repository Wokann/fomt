#include "hardware_resource.hh"

#include "hardware_allocator.hh"
#include "new.hh"

#include <memory>
#include <stdlib.h>

extern void __builtin_delete(void * pointer);

EXTERN_C

extern void free(void * pointer);

void func_0800770C(HardwareResource * object)
{
    object->storage = 0;
}

void func_08007714(HardwareResource * object, u32 flags)
{
    if (object->storage != 0) {
        HardwareResourceStorage * storage = object->storage;
        HardwareResourceEntry * end = storage->end;
        HardwareResourceEntry * cursor = storage->start;
        while (cursor != end) {
            func_080073E0(cursor, cursor->handle);
            reinterpret_cast<HardwarePoolOwner *>(cursor)->~HardwarePoolOwner();
            cursor++;
        }
        if (storage->start != 0)
            free(storage->start);
        __builtin_delete(storage);
    }
    if (flags & 1)
        __builtin_delete(object);
}

EXTERN_C_END

HardwareResource::HardwareResource(HardwareResource const & other)
{
    if (other.storage != nullptr) {
        HardwareResourceStorage * current = other.storage;
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
        func_08007128(this);
        handle = func_0800745C(this, cursor->handle);
    } else {
        func_08007128(this);
        handle = AllocateHardwarePoolHandle(this);
    }
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
