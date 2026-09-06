#include "prelude.h"

struct IndexedResourceProvider;

struct IndexedResourceEntry
{
    u16 unknown_00;
    u16 metric;
};

struct IndexedResourceResult
{
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
