#include "hardware_resource.hh"

extern void func_080073E0(struct HardwareResourceEntry * entry, u32 handle);
extern void func_08007184(struct HardwareResourceEntry * entry, u32 flags);
extern void free(void * pointer);
extern void __builtin_delete(void * pointer);

void func_0800770C(struct HardwareResource * object)
{
    object->storage = 0;
}

void func_08007714(struct HardwareResource * object, u32 flags)
{
    if (object->storage != 0) {
        struct HardwareResourceStorage * storage = object->storage;
        struct HardwareResourceEntry * end = storage->end;
        struct HardwareResourceEntry * cursor = storage->start;
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
