#include "obj_palette_collection_storage.hh"

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
