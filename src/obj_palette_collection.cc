#include "obj_palette_collection.hh"
#include "obj_palette_collection_storage.hh"

ObjPaletteCollection::ObjPaletteCollection(u8 const & count)
    : storage(new ObjPaletteCollectionStorage(count))
{
}

ObjPaletteCollection::ObjPaletteCollection() : storage(0)
{
}

ObjPaletteCollection::~ObjPaletteCollection()
{
    if (storage != 0)
        delete storage;
}

ObjPaletteCollectionEntry ObjPaletteCollection::Get() const
{
    if (storage != 0) {
        ObjPaletteCollectionStorage * current = storage;
        ObjPaletteCollectionEntry * end = current->end;
        ObjPaletteCollectionEntry * cursor = current->cursor;
        if (cursor != end) {
            ObjPaletteCollectionEntry * first = cursor;
            do {
                ObjPaletteCollectionEntry * entry = cursor;
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
    return ObjPaletteCollectionEntry();
}
