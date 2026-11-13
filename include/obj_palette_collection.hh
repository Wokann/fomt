#ifndef OBJ_PALETTE_COLLECTION_HH
#define OBJ_PALETTE_COLLECTION_HH

#include "obj_palette_pool.hh"

struct ObjPaletteCollectionStorage;

struct ObjPaletteCollection {
    struct ObjPaletteCollectionStorage * storage;

    explicit ObjPaletteCollection(u8 const & count);
    ObjPaletteCollection();
    ~ObjPaletteCollection();
    // Reuse an entry held only by this collection, retaining it for the caller.
    // If all entries are busy, retain the original cursor entry instead.
    // No storage allocates a fresh entry; allocated storage must not be empty.
    ObjPaletteCollectionEntry Get() const;
private:
    // The collection owns its storage; callers retain entries through Get().
    ObjPaletteCollection(ObjPaletteCollection const &);
    ObjPaletteCollection & operator=(ObjPaletteCollection const &);
};

typedef char ObjPaletteCollectionSizeCheck[sizeof(ObjPaletteCollection) == 4 ? 1 : -1];

#endif // OBJ_PALETTE_COLLECTION_HH
