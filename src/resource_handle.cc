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
        : entries(a_entries), entry_count(a_entry_count)
    {
    }

    IndexedResourceEntry * entries;
    u16 entry_count;
    u16 unknown_06;
};

typedef IndexedResourceResult (*IndexedResourceResolver)(
    IndexedResourceProvider * provider,
    u32 index);

struct IndexedResourceProviderVTable
{
    u8 unknown_00[0x0C];
    IndexedResourceResolver resolve;
};

struct IndexedResourceProvider
{
    IndexedResourceProviderVTable * vtable;
};

#if defined(REGION_JP)
extern "C" char vtable_unk_080E79B8;
#define INDEXED_RESOURCE_ARCHIVE_VTABLE vtable_unk_080E79B8
#else
extern "C" char vtable_unk_080E79C8;
#define INDEXED_RESOURCE_ARCHIVE_VTABLE vtable_unk_080E79C8
#endif

struct IndexedResourceArchiveEntry
{
    u16 entry_count;
    u16 first_entry_index;
};

struct IndexedResourceArchiveGroupDescriptor
{
    u8 unknown_00[16];
};

struct IndexedResourceArchiveDescriptor8
{
    u8 unknown_00[8];
};

struct IndexedResourceArchiveDescriptor32
{
    u8 unknown_00[32];
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

    u16 GetGroupDescriptorCount() const
        SECTION(".text.indexed_resource_archive_get_group_descriptor_count");

    u16 GetEntryDescriptorCount() const
        SECTION(".text.indexed_resource_archive_get_entry_descriptor_count");
};

IndexedResourceArchive::IndexedResourceArchive(u8 const * data)
{
    vtable = (IndexedResourceProviderVTable *)&INDEXED_RESOURCE_ARCHIVE_VTABLE;

    if (data != 0)
    {
        entry_descriptor_count = *(u16 const *)data;
        data += 4;
        entry_descriptors = (IndexedResourceArchiveEntry *)data;
        data += entry_descriptor_count * 4;

        group_descriptor_count = *(u16 const *)data;
        data += 4;
        group_descriptors = (IndexedResourceArchiveGroupDescriptor *)data;
        data += group_descriptor_count * 16;

        third_descriptor_count = *(u16 const *)data;
        data += 4;
        third_descriptors = (IndexedResourceArchiveDescriptor8 *)data;
        data += third_descriptor_count * 8;

        fourth_descriptor_count = *(u16 const *)data;
        data += 4;
        fourth_descriptors = (IndexedResourceArchiveDescriptor32 *)data;
        data += fourth_descriptor_count * 32;

        fifth_descriptor_count = *(u16 const *)data;
        data += 4;
        fifth_descriptors = (IndexedResourceArchiveDescriptor32 *)data;
        data += fifth_descriptor_count * 32;

        sixth_descriptor_count = *(u16 const *)data;
        data += 4;
        sixth_descriptors = (IndexedResourceArchiveDescriptor8 *)data;
        data += sixth_descriptor_count * 8;

        entry_count = *(u16 const *)data;
        entries = (IndexedResourceEntry *)(data + 4);
    }
    else
    {
        entry_descriptor_count = 0;
        entry_descriptors = 0;
        group_descriptor_count = 0;
        group_descriptors = 0;
        third_descriptor_count = 0;
        third_descriptors = 0;
        fourth_descriptor_count = 0;
        fourth_descriptors = 0;
        fifth_descriptor_count = 0;
        fifth_descriptors = 0;
        sixth_descriptor_count = 0;
        sixth_descriptors = 0;
        entry_count = 0;
        entries = 0;
    }
}

IndexedResourceResult IndexedResourceArchive::Resolve(u32 index) const
{
    if (index < entry_descriptor_count)
    {
        IndexedResourceArchiveEntry const * descriptor = entry_descriptors + index;
        u16 first_entry_index = descriptor->first_entry_index;
        u16 entry_count = descriptor->entry_count;
        u32 entry_address = first_entry_index << 2;

        entry_address += (u32)entries;
        return IndexedResourceResult((IndexedResourceEntry *)entry_address, entry_count);
    }

    return IndexedResourceResult(0, 0);
}

u16 IndexedResourceArchive::GetGroupDescriptorCount() const
{
    return group_descriptor_count;
}

u16 IndexedResourceArchive::GetEntryDescriptorCount() const
{
    return entry_descriptor_count;
}

struct IndexedResourceHandle
{
    IndexedResourceHandle(
        IndexedResourceProvider * resource, u32 index, i32 scroll_delta)
        SECTION(".text.indexed_resource_handle_constructor");

    IndexedResourceProvider * resource;
    IndexedResourceResult resolved_resource;
    u16 current_entry_index;
    u16 metric_scaled;
    i16 scroll_delta;
    u8 initialized;
};

IndexedResourceHandle::IndexedResourceHandle(
    IndexedResourceProvider * a_resource, u32 index, i32 a_scroll_delta)
    : resource(a_resource),
      resolved_resource(a_resource->vtable->resolve(a_resource, index)),
      current_entry_index(0),
      metric_scaled(resolved_resource.entries->metric << 8),
      scroll_delta(a_scroll_delta),
      initialized(1)
{
}

extern "C" void ResolveIndexedResourceHandle(IndexedResourceHandle * handle, u32 index)
    SECTION(".text.resolve_indexed_resource_handle");

extern "C" void InitializeIndexedResourceHandle(
    IndexedResourceHandle * handle, IndexedResourceProvider * resource, u32 index)
    SECTION(".text.initialize_indexed_resource_handle");

extern "C" void InitializeIndexedResourceHandle(
    IndexedResourceHandle * handle, IndexedResourceProvider * resource, u32 index)
{
    handle->resource = resource;
    ResolveIndexedResourceHandle(handle, index);
}

extern "C" void ResolveIndexedResourceHandle(IndexedResourceHandle * handle, u32 index)
{
    IndexedResourceResult resolved = handle->resource->vtable->resolve(handle->resource, index);

    handle->resolved_resource = resolved;
    handle->current_entry_index = 0;
    handle->metric_scaled = handle->resolved_resource.entries->metric << 8;
    handle->initialized = 1;
}
