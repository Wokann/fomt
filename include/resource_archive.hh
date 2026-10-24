#ifndef RESOURCE_ARCHIVE_HH
#define RESOURCE_ARCHIVE_HH

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

// Native provider-base and archive tables share the C++ virtual destructor,
// entry resolver and group resolver slots. Only the implementation unit emits
// their standalone methods and vtables; callers may inline cleanup.
#pragma interface "resource_archive.hh"
struct IndexedResourceProvider
{
    virtual ~IndexedResourceProvider() SECTION(".text.indexed_resource_provider_cleanup");
    virtual IndexedResourceResult Resolve(u32 index) const = 0;
    virtual IndexedResourceGroupResult GetGroupData(u32 index) const = 0;
};

inline IndexedResourceProvider::~IndexedResourceProvider() {}

// Resolve an entry index to the group referenced by its first entry.
static inline IndexedResourceGroupResult ResolveIndexedResourceGroup(
    IndexedResourceProvider const * resource, u32 index)
{
    return resource->GetGroupData(resource->Resolve(index)[0].group_index);
}

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

// An archive borrows its payload; destroying it never frees that payload.
struct IndexedResourceArchive : IndexedResourceProvider
{
    // The original destructor is part of the later C++ library block.
    virtual ~IndexedResourceArchive() SECTION(".text.indexed_resource_archive_cleanup");
    IndexedResourceArchive(u8 const * data);

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

    virtual IndexedResourceResult Resolve(u32 index) const;
    virtual IndexedResourceGroupResult GetGroupData(u32 index) const;
    u16 GetGroupDescriptorCount() const;
    inline u16 GetEntryDescriptorCount() const;
};

inline u16 IndexedResourceArchive::GetEntryDescriptorCount() const
{
    return entry_descriptor_count;
}
#pragma implementation

typedef char IndexedResourceProviderSizeCheck[sizeof(IndexedResourceProvider) == 4 ? 1 : -1];
typedef char IndexedResourceArchiveEntriesOffsetCheck[offsetof(IndexedResourceArchive, entry_descriptors) == 4 ? 1 : -1];
typedef char IndexedResourceArchiveCountOffsetCheck[offsetof(IndexedResourceArchive, entry_descriptor_count) == 0x20 ? 1 : -1];
typedef char IndexedResourceArchiveSizeCheck[sizeof(IndexedResourceArchive) == 0x30 ? 1 : -1];
typedef char IndexedResourceResultSizeCheck[sizeof(IndexedResourceResult) == 8 ? 1 : -1];
typedef char IndexedResourceGroupDescriptorSizeCheck[sizeof(IndexedResourceArchiveGroupDescriptor) == 16 ? 1 : -1];
typedef char IndexedResourceDescriptor8RangeSizeCheck[sizeof(IndexedResourceDescriptor8Range) == 8 ? 1 : -1];
typedef char IndexedResourceSpriteRangeSizeCheck[sizeof(IndexedResourceSpriteRange) == 8 ? 1 : -1];
typedef char IndexedResourceDescriptor32RangeSizeCheck[sizeof(IndexedResourceDescriptor32Range) == 8 ? 1 : -1];
typedef char IndexedResourceGroupResultSizeCheck[sizeof(IndexedResourceGroupResult) == 32 ? 1 : -1];
typedef char IndexedResourceGroupFourthOffsetCheck[offsetof(IndexedResourceGroupResult, fourth) == 8 ? 1 : -1];
typedef char IndexedResourceGroupFifthOffsetCheck[offsetof(IndexedResourceGroupResult, fifth) == 16 ? 1 : -1];
typedef char IndexedResourceGroupSixthOffsetCheck[offsetof(IndexedResourceGroupResult, sixth) == 24 ? 1 : -1];

EXTERN_C

// Direct declaration of the existing constructor ABI for assembly-owned lifecycles.
IndexedResourceArchive * ConstructIndexedResourceArchive(IndexedResourceArchive *, u8 const *)
    asm("__22IndexedResourceArchivePCUc");

EXTERN_C_END

inline IndexedResourceArchive::~IndexedResourceArchive()
{
}

#endif // RESOURCE_ARCHIVE_HH
