#ifndef OBJ_TILE_BITMAP_HH
#define OBJ_TILE_BITMAP_HH

#include "prelude.h"

// The leaves of the OBJ tile tree each track 32 contiguous tiles.
typedef struct ObjTileBitmap32 {
    u32 bits;
#ifdef __cplusplus
    ObjTileBitmap32() : bits(0) {}
    bool IsFull() const { return bits + 1 == 0; }
    bool IsEmpty() const { return bits == 0; }
    // Allocate 2^size_shift tiles, or return 32 when no range is available.
    u32 Allocate(u32 size_shift);
    // The offset remains relative to the tree; only its low five bits matter.
    void Free(u32 offset, u32 size_shift);
#endif
} ObjTileBitmap32;

typedef char ObjTileBitmap32SizeCheck[sizeof(ObjTileBitmap32) == 4 ? 1 : -1];

#endif // OBJ_TILE_BITMAP_HH
