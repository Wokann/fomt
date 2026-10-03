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
    IndexedResourceResult(IndexedResourceEntry * a_entries, u16 a_entry_count)
        : entries(a_entries), entry_count(a_entry_count) {}

    IndexedResourceEntry * entries;
    u16 entry_count;
    u16 unknown_06;
};

typedef IndexedResourceResult (*IndexedResourceResolver)(IndexedResourceProvider *, u32);

struct IndexedResourceProviderVTable
{
    u8 unknown_00[0x0C];
    IndexedResourceResolver resolve;
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

struct IndexedResourceArchiveGroupDescriptor { u8 unknown_00[16]; };
struct IndexedResourceArchiveDescriptor8 { u8 unknown_00[8]; };
struct IndexedResourceArchiveDescriptor32 { u8 unknown_00[32]; };

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
