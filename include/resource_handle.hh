#ifndef RESOURCE_HANDLE_HH
#define RESOURCE_HANDLE_HH

#include "prelude.h"
#include "hardware_display_output.hh"

struct IndexedResourceProvider;

struct IndexedResourceEntry
{
    // Passed to the provider's GetGroupData slot by sprite consumers.
    u16 group_index;
    u16 metric;
};

struct IndexedResourceResult
{
    IndexedResourceEntry & operator[](u32 index) const { return entries[index]; }
    u32 Count() const { return entries ? entry_count : 0; }

    IndexedResourceResult(IndexedResourceEntry * a_entries, u16 a_entry_count)
        : entries(a_entries), entry_count(a_entry_count) {}

    IndexedResourceEntry * entries;
    u16 entry_count;
    u16 unknown_06;
};

struct IndexedResourceArchiveDescriptor8 { u8 unknown_00[8]; };
struct IndexedResourceArchiveDescriptor32 { u8 unknown_00[32]; };

struct IndexedResourceSpriteRange
{
    HardwareSpriteOamRecord * Data() const { return data; }
    u32 Count() const { return data ? count : 0; }

    IndexedResourceSpriteRange(HardwareSpriteOamRecord * a_data, u16 a_count)
        : data(a_data), count(a_count) {}

    HardwareSpriteOamRecord * data;
    u16 count;
};

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

struct IndexedResourceDescriptor8Range
{
    IndexedResourceArchiveDescriptor8 * Data() const { return data; }
    u32 Count() const { return data ? count : 0; }

    IndexedResourceDescriptor8Range(IndexedResourceArchiveDescriptor8 * a_data, u16 a_count)
        : data(a_data), count(a_count) {}

    IndexedResourceArchiveDescriptor8 * data;
    u16 count;
};

struct IndexedResourceDescriptor32Range
{
    IndexedResourceDescriptor32Range(IndexedResourceArchiveDescriptor32 * a_data, u16 a_byte_count)
        : data(a_data), byte_count(a_byte_count) {}

    IndexedResourceArchiveDescriptor32 * data;
    u16 byte_count;
};

// The third table contains native OAM records; the sixth descriptor format
// remains unresolved. Both lengths count eight-byte entries. Fourth/fifth lengths
// are bytes, as consumed by the resource upload routines. The two-byte
// gaps in each range are ordinary ABI padding, not additional stored data.
struct IndexedResourceGroupResult
{
    IndexedResourceGroupResult(
        HardwareSpriteOamRecord * sprite_data, u16 sprite_count,
        IndexedResourceArchiveDescriptor32 * fourth_data, u16 fourth_byte_count,
        IndexedResourceArchiveDescriptor32 * fifth_data, u16 fifth_byte_count,
        IndexedResourceArchiveDescriptor8 * sixth_data, u16 sixth_count)
        : sprites(sprite_data, sprite_count), fourth(fourth_data, fourth_byte_count),
          fifth(fifth_data, fifth_byte_count), sixth(sixth_data, sixth_count) {}

    IndexedResourceSpriteRange sprites;
    IndexedResourceDescriptor32Range fourth;
    IndexedResourceDescriptor32Range fifth;
    IndexedResourceDescriptor8Range sixth;
};

typedef IndexedResourceResult (*IndexedResourceResolver)(IndexedResourceProvider *, u32);
typedef IndexedResourceGroupResult (*IndexedResourceGroupResolver)(IndexedResourceProvider const *, u32);
typedef void (*IndexedResourceDestroyer)(IndexedResourceProvider *, int);

struct IndexedResourceProviderVTable
{
    u8 unknown_00[8];
    IndexedResourceDestroyer destroy;
    IndexedResourceResolver resolve;
    IndexedResourceGroupResolver get_group_data;
};

struct IndexedResourceProvider
{
    IndexedResourceProviderVTable const * vtable;
};

struct IndexedResourceArchiveEntry
{
    u16 entry_count;
    u16 first_entry_index;
};

struct IndexedResourceArchiveGroupDescriptor
{
    u16 sprite_count;
    u16 sprite_first_index;
    u16 fourth_count;
    u16 fourth_first_index;
    u16 fifth_count;
    u16 fifth_first_index;
    u16 sixth_count;
    u16 sixth_first_index;
};

// Native callers inline the entry-count accessor and archive cleanup. Their
// original standalone entries are emitted only by the implementation unit.
#pragma interface "resource_handle.hh"
struct IndexedResourceArchive
{
    ~IndexedResourceArchive();
    IndexedResourceArchive(u8 const * data)
        SECTION(".text.indexed_resource_archive_constructor");

    IndexedResourceProviderVTable const * vtable;
    IndexedResourceArchiveEntry * entry_descriptors;
    IndexedResourceArchiveGroupDescriptor * group_descriptors;
    HardwareSpriteOamRecord * sprite_descriptors;
    IndexedResourceArchiveDescriptor32 * fourth_descriptors;
    IndexedResourceArchiveDescriptor32 * fifth_descriptors;
    IndexedResourceArchiveDescriptor8 * sixth_descriptors;
    IndexedResourceEntry * entries;
    u16 entry_descriptor_count;
    u16 group_descriptor_count;
    u16 sprite_descriptor_count;
    u16 fourth_descriptor_count;
    u16 fifth_descriptor_count;
    u16 sixth_descriptor_count;
    u16 entry_count;

    IndexedResourceResult Resolve(u32 index) const
        SECTION(".text.indexed_resource_archive_resolve");
    IndexedResourceGroupResult GetGroupData(u32 index) const
        SECTION(".text.indexed_resource_archive_get_group_data");
    u16 GetGroupDescriptorCount() const
        SECTION(".text.indexed_resource_archive_get_group_descriptor_count");
    inline u16 GetEntryDescriptorCount() const
        SECTION(".text.indexed_resource_archive_get_entry_descriptor_count");
};

inline u16 IndexedResourceArchive::GetEntryDescriptorCount() const
{
    return entry_descriptor_count;
}
#pragma implementation

struct IndexedResourceHandle
{
    IndexedResourceHandle(IndexedResourceProvider * resource, u32 index, i32 scroll_delta)
        SECTION(".text.indexed_resource_handle_constructor");

    IndexedResourceProvider * resource;
    IndexedResourceResult resolved_resource;
    u16 current_entry_index;
    u16 metric_scaled;
    i16 scroll_delta;
    u8 initialized;
};

typedef char IndexedResourceArchiveSizeCheck[sizeof(IndexedResourceArchive) == 0x30 ? 1 : -1];
typedef char IndexedResourceResultSizeCheck[sizeof(IndexedResourceResult) == 8 ? 1 : -1];
typedef char IndexedResourceHandleSizeCheck[sizeof(IndexedResourceHandle) == 0x14 ? 1 : -1];
typedef char IndexedResourceGroupDescriptorSizeCheck[sizeof(IndexedResourceArchiveGroupDescriptor) == 16 ? 1 : -1];
typedef char IndexedResourceDescriptor8RangeSizeCheck[sizeof(IndexedResourceDescriptor8Range) == 8 ? 1 : -1];
typedef char IndexedResourceSpriteRangeSizeCheck[sizeof(IndexedResourceSpriteRange) == 8 ? 1 : -1];
typedef char IndexedResourceDescriptor32RangeSizeCheck[sizeof(IndexedResourceDescriptor32Range) == 8 ? 1 : -1];
typedef char IndexedResourceGroupResultSizeCheck[sizeof(IndexedResourceGroupResult) == 32 ? 1 : -1];
typedef char IndexedResourceGroupFourthOffsetCheck[offsetof(IndexedResourceGroupResult, fourth) == 8 ? 1 : -1];
typedef char IndexedResourceGroupFifthOffsetCheck[offsetof(IndexedResourceGroupResult, fifth) == 16 ? 1 : -1];
typedef char IndexedResourceGroupSixthOffsetCheck[offsetof(IndexedResourceGroupResult, sixth) == 24 ? 1 : -1];
typedef char IndexedResourceGroupResolverOffsetCheck[offsetof(IndexedResourceProviderVTable, get_group_data) == 0x10 ? 1 : -1];
typedef char IndexedResourceDestroyerOffsetCheck[offsetof(IndexedResourceProviderVTable, destroy) == 8 ? 1 : -1];
typedef char IndexedResourceResolverOffsetCheck[offsetof(IndexedResourceProviderVTable, resolve) == 12 ? 1 : -1];
typedef char IndexedResourceProviderVTableSizeCheck[sizeof(IndexedResourceProviderVTable) == 20 ? 1 : -1];
typedef char IndexedResourceSpriteMatrixSizeCheck[sizeof(IndexedResourceSpriteMatrix) == 8 ? 1 : -1];

EXTERN_C

extern IndexedResourceProviderVTable const vtable_unk_080E5A28;
void DestroyIndexedResourceProvider(IndexedResourceProvider * provider, int flags)
    SECTION(".text.indexed_resource_provider_cleanup");

// The first update reports GROUP_CHANGED and clears the initialized byte.
// A zero metric stops traversal; the other bits describe the whole update,
// including any boundary crossed while consuming more than one entry.
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
IndexedResourceArchive * ConstructIndexedResourceArchive(IndexedResourceArchive *, u8 const *)
    asm("__22IndexedResourceArchivePCUc");
void DestroyIndexedResourceArchive(IndexedResourceArchive *, int)
    asm("_._22IndexedResourceArchive");
IndexedResourceHandle * ConstructIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32, i32)
    asm("__21IndexedResourceHandleP23IndexedResourceProviderUii");

void InitializeIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32)
    SECTION(".text.initialize_indexed_resource_handle");
void ResolveIndexedResourceHandle(IndexedResourceHandle *, u32)
    SECTION(".text.resolve_indexed_resource_handle");
bool WouldIndexedResourceHandleWrap(IndexedResourceHandle const *)
    SECTION(".text.indexed_resource_handle_predict_wrap");
void TransformIndexedResourceSpritePosition(i32 *, i32 *, u32, u32,
    IndexedResourceSpriteMatrix const *)
    SECTION(".text.indexed_resource_sprite_transform");

EXTERN_C_END

// The archive borrows its payload. Its provider view is restored when the
// archive subobject leaves scope; the payload itself is not freed here.
inline IndexedResourceArchive::~IndexedResourceArchive()
{
    vtable = &vtable_unk_080E5A28;
}

#endif // RESOURCE_HANDLE_HH
