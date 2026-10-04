#ifndef RESOURCE_HANDLE_HH
#define RESOURCE_HANDLE_HH

#include "prelude.h"

struct IndexedResourceProvider;

struct IndexedResourceEntry
{
    u16 unknown_00;
    u16 metric;
};

struct IndexedResourceResult
{
    IndexedResourceEntry & operator[](u32 index) const { return entries[index]; }

    IndexedResourceResult(IndexedResourceEntry * a_entries, u16 a_entry_count)
        : entries(a_entries), entry_count(a_entry_count) {}

    IndexedResourceEntry * entries;
    u16 entry_count;
    u16 unknown_06;
};

struct IndexedResourceArchiveDescriptor8 { u8 unknown_00[8]; };
struct IndexedResourceArchiveDescriptor32 { u8 unknown_00[32]; };

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

// Third/sixth lengths count eight-byte descriptors. Fourth/fifth lengths
// are bytes, as consumed by the resource upload routines. The two-byte
// gaps in each range are ordinary ABI padding, not additional stored data.
struct IndexedResourceGroupResult
{
    IndexedResourceGroupResult(
        IndexedResourceArchiveDescriptor8 * third_data, u16 third_count,
        IndexedResourceArchiveDescriptor32 * fourth_data, u16 fourth_byte_count,
        IndexedResourceArchiveDescriptor32 * fifth_data, u16 fifth_byte_count,
        IndexedResourceArchiveDescriptor8 * sixth_data, u16 sixth_count)
        : third(third_data, third_count), fourth(fourth_data, fourth_byte_count),
          fifth(fifth_data, fifth_byte_count), sixth(sixth_data, sixth_count) {}

    IndexedResourceDescriptor8Range third;
    IndexedResourceDescriptor32Range fourth;
    IndexedResourceDescriptor32Range fifth;
    IndexedResourceDescriptor8Range sixth;
};

typedef IndexedResourceResult (*IndexedResourceResolver)(IndexedResourceProvider *, u32);
typedef IndexedResourceGroupResult (*IndexedResourceGroupResolver)(IndexedResourceProvider const *, u32);

struct IndexedResourceProviderVTable
{
    u8 unknown_00[0x0C];
    IndexedResourceResolver resolve;
    IndexedResourceGroupResolver get_group_data;
};

struct IndexedResourceProvider
{
    IndexedResourceProviderVTable * vtable;
};

struct IndexedResourceArchiveEntry
{
    u16 entry_count;
    u16 first_entry_index;
};

struct IndexedResourceArchiveGroupDescriptor
{
    u16 third_count;
    u16 third_first_index;
    u16 fourth_count;
    u16 fourth_first_index;
    u16 fifth_count;
    u16 fifth_first_index;
    u16 sixth_count;
    u16 sixth_first_index;
};

struct IndexedResourceArchive
{
    IndexedResourceArchive(u8 const * data)
        SECTION(".text.indexed_resource_archive_constructor");

    IndexedResourceProviderVTable * vtable;
    IndexedResourceArchiveEntry * entry_descriptors;
    IndexedResourceArchiveGroupDescriptor * group_descriptors;
    IndexedResourceArchiveDescriptor8 * third_descriptors;
    IndexedResourceArchiveDescriptor32 * fourth_descriptors;
    IndexedResourceArchiveDescriptor32 * fifth_descriptors;
    IndexedResourceArchiveDescriptor8 * sixth_descriptors;
    IndexedResourceEntry * entries;
    u16 entry_descriptor_count;
    u16 group_descriptor_count;
    u16 third_descriptor_count;
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
    u16 GetEntryDescriptorCount() const
        SECTION(".text.indexed_resource_archive_get_entry_descriptor_count");
};

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
typedef char IndexedResourceDescriptor32RangeSizeCheck[sizeof(IndexedResourceDescriptor32Range) == 8 ? 1 : -1];
typedef char IndexedResourceGroupResultSizeCheck[sizeof(IndexedResourceGroupResult) == 32 ? 1 : -1];
typedef char IndexedResourceGroupFourthOffsetCheck[offsetof(IndexedResourceGroupResult, fourth) == 8 ? 1 : -1];
typedef char IndexedResourceGroupFifthOffsetCheck[offsetof(IndexedResourceGroupResult, fifth) == 16 ? 1 : -1];
typedef char IndexedResourceGroupSixthOffsetCheck[offsetof(IndexedResourceGroupResult, sixth) == 24 ? 1 : -1];
typedef char IndexedResourceGroupResolverOffsetCheck[offsetof(IndexedResourceProviderVTable, get_group_data) == 0x10 ? 1 : -1];

EXTERN_C

// Direct declarations of the existing constructor ABI, for owners whose
// remaining lifecycle is still supplied by the original assembly routines.
// These reference the real C++ constructors, not wrapper functions or aliases.
IndexedResourceArchive * ConstructIndexedResourceArchive(IndexedResourceArchive *, u8 const *)
    asm("__22IndexedResourceArchivePCUc");
IndexedResourceHandle * ConstructIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32, i32)
    asm("__21IndexedResourceHandleP23IndexedResourceProviderUii");

void InitializeIndexedResourceHandle(IndexedResourceHandle *, IndexedResourceProvider *, u32)
    SECTION(".text.initialize_indexed_resource_handle");
void ResolveIndexedResourceHandle(IndexedResourceHandle *, u32)
    SECTION(".text.resolve_indexed_resource_handle");

EXTERN_C_END

#endif // RESOURCE_HANDLE_HH
