#include "obj_palette_pool_storage.hh"

EC ObjPalettePoolEntry * InitializeObjPaletteFreeList(
    ObjPalettePoolEntry * entries, int count,
    ObjPalettePoolEntry * tail)
{
    ObjPalettePoolEntry * cursor = entries + (count - 1);
    cursor->next_free = tail;
    while (cursor != entries)
    {
        ObjPalettePoolEntry * next = cursor;
        --cursor;
        cursor->next_free = next;
    }
    return cursor;
}
