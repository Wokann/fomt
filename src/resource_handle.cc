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
    IndexedResourceProvider * resource;
    IndexedResourceResult resolved_resource;
    u16 unknown_0C;
    u16 metric_scaled;
    u8 unknown_10[2];
    u8 initialized;
};

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
    handle->unknown_0C = 0;
    handle->metric_scaled = handle->resolved_resource.entries->metric << 8;
    handle->initialized = 1;
}
