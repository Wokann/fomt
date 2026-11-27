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


struct IndexedResourceHandle
{
    IndexedResourceHandle(IndexedResourceProvider * resource, u32 index, i32 scroll_delta);

    void SetScrollDelta(i16 delta) { scroll_delta = delta; }
    u16 CurrentGroupIndex() const { return resolved_resource[current_entry_index].group_index; }
    IndexedResourceGroupResult GetGroupData() const
    {
        return resource->GetGroupData(CurrentGroupIndex());
    }

    IndexedResourceProvider * resource;
    IndexedResourceResult resolved_resource;
    u16 current_entry_index;
    u16 metric_scaled;
    i16 scroll_delta;
    u8 initialized;
};


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

// All callers share these three bits of one native result word.
union IndexedResourceUpdateResult
{
    u32 value;
    struct {
        bool entry_advanced : 1;
        bool group_changed : 1;
        bool wrapped : 1;
    } flags;
};


IndexedResourceUpdateResult UpdateIndexedResourceHandle(IndexedResourceHandle *);

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
