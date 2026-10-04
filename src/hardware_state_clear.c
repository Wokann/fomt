#include "hardware_state_clear.hh"

#include "hardware_refcount.hh"

extern void __builtin_delete(void * pointer);
extern void free(void * pointer);

void func_0800835C(void ** slot)
{
    *slot = 0;
}

void func_08008364(struct HardwareStateOwner * owner, u32 flags)
{
    if (owner->storage != 0) {
        struct HardwareStateStorage * storage = owner->storage;
        struct HardwareStateGroup * group = storage->groups + 8;
        while (storage->groups != group) {
            struct HardwareStateEntry * entry;
            struct HardwareStateEntry * end;
            --group;
            end = group->end;
            entry = group->start;
            if (entry != end) {
                do {
                    ReleaseHardwareSharedStateHandle(entry, (u32)entry->unk_04);
                    func_080079E8(entry, 2);
                    ++entry;
                } while (entry != end);
            }
            if (group->start != 0)
                free(group->start);
        }
        __builtin_delete(storage);
    }
    if (flags & 1)
        __builtin_delete(owner);
}

struct HardwareStateOwner * func_080083D0(
    struct HardwareStateOwner * owner,
    struct HardwareStateStorage * const * storage_ref,
    u32 group_index)
{
    struct HardwareStateStorage * storage = *storage_ref;
    if (storage != 0) {
        struct HardwareStateGroup * group = (struct HardwareStateGroup *)(group_index * sizeof(struct HardwareStateGroup) + (u32)storage);
        struct HardwareStateEntry * end = group->end;
        struct HardwareStateEntry * current = group->cursor;
        if (current != end) {
            struct HardwareStateEntry * first = current;
            do {
                struct HardwareStateEntry * candidate = current;
                ++current;
                if (current == end)
                    current = group->start;
                if (GetHardwareSharedStateReferenceCount(candidate, (u32)candidate->unk_04) == 1) {
                    group->cursor = current;
                    current = candidate;
                    break;
                }
            } while (current != first);
        }
        func_08007874(owner);
        owner->unk_04 = RetainHardwareSharedStateHandle(owner, (u32)current->unk_04);
    } else {
        func_08007874(owner);
        owner->unk_04 = AllocateHardwareSharedStateHandle(owner, group_index);
    }
    return owner;
}
