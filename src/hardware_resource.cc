#include "hardware_resource.hh"

extern void __builtin_delete(void * pointer);

EXTERN_C

extern void func_080073E0(HardwareResourceEntry * entry, u32 handle);
extern void func_08007184(HardwareResourceEntry * entry, u32 flags);
extern HardwareResource * func_08007128(HardwareResource * object);
extern u32 func_0800736C(HardwareResource * object);
extern u32 func_0800745C(HardwareResource * object, u32 handle);
extern u32 func_08007510(HardwareResourceEntry * entry, u32 handle);
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
            func_08007184(cursor, 2);
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
        handle = func_0800736C(this);
    }
}
