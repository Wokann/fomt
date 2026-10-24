#ifndef RESOURCE_HANDLE_HH
#define RESOURCE_HANDLE_HH

#include "resource_archive.hh"

struct IndexedResourceSpriteMatrix
{
    i16 pa;
    i16 pb;
    i16 pc;
    i16 pd;
};

// Native sprite-submit parameters occupy 28 bytes. The renderer does not
// consume the resource-group storage that some callers keep after this prefix.
// Positions are signed pixel offsets; tile and palette offsets wrap in OAM.
struct IndexedResourceSpriteParameters
{
    i16 x;
    i16 y;
    u16 palette_offset;
    u16 tile_offset;
    u16 priority;
    u32 object_mode;
    u8 flips;
    u8 affine_index;
    u32 affine_mode;
    u8 mosaic;

    IndexedResourceSpriteParameters()
        : x(0), y(0), palette_offset(0), tile_offset(0), priority(0),
          object_mode(0), flips(0), affine_index(0), affine_mode(0), mosaic(0) {}
};

typedef char IndexedResourceSpriteParametersSizeCheck[sizeof(IndexedResourceSpriteParameters) == 28 ? 1 : -1];
typedef char IndexedResourceSpritePaletteOffsetCheck[offsetof(IndexedResourceSpriteParameters, palette_offset) == 4 ? 1 : -1];
typedef char IndexedResourceSpriteTileOffsetCheck[offsetof(IndexedResourceSpriteParameters, tile_offset) == 6 ? 1 : -1];
typedef char IndexedResourceSpritePriorityOffsetCheck[offsetof(IndexedResourceSpriteParameters, priority) == 8 ? 1 : -1];
typedef char IndexedResourceSpriteObjectModeOffsetCheck[offsetof(IndexedResourceSpriteParameters, object_mode) == 12 ? 1 : -1];
typedef char IndexedResourceSpriteFlipsOffsetCheck[offsetof(IndexedResourceSpriteParameters, flips) == 16 ? 1 : -1];
typedef char IndexedResourceSpriteAffineIndexOffsetCheck[offsetof(IndexedResourceSpriteParameters, affine_index) == 17 ? 1 : -1];
typedef char IndexedResourceSpriteAffineModeOffsetCheck[offsetof(IndexedResourceSpriteParameters, affine_mode) == 20 ? 1 : -1];
typedef char IndexedResourceSpriteMosaicOffsetCheck[offsetof(IndexedResourceSpriteParameters, mosaic) == 24 ? 1 : -1];

struct IndexedResourceHandle
{
    IndexedResourceHandle(IndexedResourceProvider * resource, u32 index, i32 scroll_delta);

    IndexedResourceProvider * resource;
    IndexedResourceResult resolved_resource;
    u16 current_entry_index;
    u16 metric_scaled;
    i16 scroll_delta;
    u8 initialized;
};

typedef char IndexedResourceHandleSizeCheck[sizeof(IndexedResourceHandle) == 0x14 ? 1 : -1];
typedef char IndexedResourceSpriteMatrixSizeCheck[sizeof(IndexedResourceSpriteMatrix) == 8 ? 1 : -1];

EXTERN_C

// The first update reports GROUP_CHANGED and clears the initialized byte.
// A zero metric stops traversal; the other bits describe the whole update,
// including any boundary crossed while consuming more than one entry.
// Traversal requires a nonempty resolved range and a valid current index;
// inactive handles do not read entries.
enum IndexedResourceUpdateFlag
{
    INDEXED_RESOURCE_ENTRY_ADVANCED = 1,
    INDEXED_RESOURCE_GROUP_CHANGED = 2,
    INDEXED_RESOURCE_WRAPPED = 4,
};

u32 UpdateIndexedResourceHandle(IndexedResourceHandle *);

// Non-affine sprites are clipped to the screen; affine records use the
// selected OAM matrix. Copy attributes only, preserving matrix coefficients.
void DrawIndexedResourceSprites(HardwareSpriteBufferState *, HardwareSpriteOamRecord const *,
    u32 count, IndexedResourceSpriteParameters const *);

// Direct declarations of the existing lifecycle ABI, for owners whose
// remaining lifecycle is still supplied by the original assembly routines.
// These reference real C++ lifecycle entries, not wrapper functions or aliases.
IndexedResourceHandle * ConstructIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32, i32)
    asm("__21IndexedResourceHandleP23IndexedResourceProviderUii");

void InitializeIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32);
void ResolveIndexedResourceHandle(IndexedResourceHandle *, u32);
bool WouldIndexedResourceHandleWrap(IndexedResourceHandle const *);
void TransformIndexedResourceSpritePosition(i32 *, i32 *, u32, u32,
    IndexedResourceSpriteMatrix const *);

EXTERN_C_END

#endif // RESOURCE_HANDLE_HH
