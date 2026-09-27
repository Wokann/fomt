#include "hardware_state_clear.hh"

#include "hardware_refcount.hh"

extern void func_08007C28(void * entry, void * value);
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
                    func_08007C28(entry, entry->unk_04);
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
