#include "hardware_state_clear.hh"

#include "new.hh"

#include <memory>
#include <stdlib.h>

extern void __builtin_delete(void * pointer);
extern void free(void * pointer);

inline void * HardwareStateGroup::AllocateBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == 0)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline HardwareStateEntry * HardwareStateGroup::Allocate(u32 count)
{
    return count != 0
        ? static_cast<HardwareStateEntry *>(AllocateBytes(count * sizeof(HardwareStateEntry)))
        : 0;
}

inline HardwareStateEntry * HardwareStateGroup::AllocateAndCopy(u32 count,
    HardwareStateEntry * first, HardwareStateEntry * last)
{
    HardwareStateEntry * result = Allocate(count);
    HardwareStateEntry * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return result;
}

void HardwareStateGroup::Reserve(u32 count)
{
    if (static_cast<u32>(capacity_end - start) < count) {
        u32 old_size = end - start;
        HardwareStateEntry * replacement;
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
        HardwareStateEntry * new_end = reinterpret_cast<HardwareStateEntry *>(
            old_size * sizeof(HardwareStateEntry) + reinterpret_cast<u32>(replacement));
        HardwareStateEntry * new_capacity_end = reinterpret_cast<HardwareStateEntry *>(
            count * sizeof(HardwareStateEntry) + reinterpret_cast<u32>(replacement));
        start = replacement;
        end = new_end;
        capacity_end = new_capacity_end;
    }
}

HardwareStateOwner::HardwareStateOwner() : storage(0)
{
}

HardwareStateOwner::~HardwareStateOwner()
{
    if (storage != 0) {
        struct HardwareStateStorage * saved = storage;
        struct HardwareStateGroup * group = saved->groups + 8;
        while (saved->groups != group) {
            struct HardwareStateEntry * entry;
            struct HardwareStateEntry * end;
            --group;
            end = group->end;
            entry = group->start;
            if (entry != end) {
                do {
                    entry->~HardwareStateEntry();
                    ++entry;
                } while (entry != end);
            }
            if (group->start != 0)
                free(group->start);
        }
        __builtin_delete(saved);
    }
}

HardwareStateEntry HardwareStateOwner::Get(u32 group_index) const
{
    HardwareStateStorage * saved = storage;
    if (saved != 0) {
        HardwareStateGroup * group = reinterpret_cast<HardwareStateGroup *>(
            group_index * sizeof(HardwareStateGroup) + reinterpret_cast<u32>(saved));
        struct HardwareStateEntry * end = group->end;
        struct HardwareStateEntry * current = group->cursor;
        if (current != end) {
            struct HardwareStateEntry * first = current;
            do {
                struct HardwareStateEntry * candidate = current;
                ++current;
                if (current == end)
                    current = group->start;
                if (GetHardwareSharedStateReferenceCount(candidate, candidate->handle) == 1) {
                    group->cursor = current;
                    current = candidate;
                    break;
                }
            } while (current != first);
        }
        return *current;
    }
    return HardwareStateEntry(group_index);
}
