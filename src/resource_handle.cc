#include "prelude.h"

struct IndexedResourceHandle
{
    void * resource;
};

extern "C" void func_0805E860(IndexedResourceHandle * handle, u32 index);

extern "C" void InitializeIndexedResourceHandle(
    IndexedResourceHandle * handle, void * resource, u32 index)
    SECTION(".text.initialize_indexed_resource_handle");

extern "C" void InitializeIndexedResourceHandle(
    IndexedResourceHandle * handle, void * resource, u32 index)
{
    handle->resource = resource;
    func_0805E860(handle, index);
}
