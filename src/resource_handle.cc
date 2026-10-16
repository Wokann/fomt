#include "resource_handle.hh"

EXTERN_C
void __builtin_delete(void *);
void __pure_virtual(void);
EXTERN_C_END

// The two resolver slots are pure virtual in this provider-base table.
extern IndexedResourceProviderVTable const vtable_unk_080E5A28 = {
    { 0 },
    DestroyIndexedResourceProvider,
    reinterpret_cast<IndexedResourceResolver>(__pure_virtual),
    reinterpret_cast<IndexedResourceGroupResolver>(__pure_virtual),
};

void DestroyIndexedResourceProvider(IndexedResourceProvider * provider, int flags)
{
    provider->vtable = &vtable_unk_080E5A28;
    if (flags & 1)
        __builtin_delete(provider);
}

#if defined(REGION_JP)
extern "C" char vtable_unk_080E79B8;
#else
extern "C" char vtable_unk_080E79C8;
#endif

IndexedResourceArchive::IndexedResourceArchive(u8 const * data)
{
#if defined(REGION_JP)
    vtable = reinterpret_cast<IndexedResourceProviderVTable const *>(&vtable_unk_080E79B8);
#else
    vtable = reinterpret_cast<IndexedResourceProviderVTable const *>(&vtable_unk_080E79C8);
#endif

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

        sprite_descriptor_count = *(u16 const *)data;
        data += 4;
        sprite_descriptors = (HardwareSpriteOamRecord *)data;
        data += sprite_descriptor_count * sizeof(HardwareSpriteOamRecord);

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
        sprite_descriptor_count = 0;
        sprite_descriptors = 0;
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

IndexedResourceGroupResult IndexedResourceArchive::GetGroupData(u32 index) const
{
    if (index < group_descriptor_count)
    {
        IndexedResourceArchiveGroupDescriptor const * descriptor = group_descriptors + index;
        u16 sprite_first_index = descriptor->sprite_first_index;
        u16 sprite_count = descriptor->sprite_count;
        u32 fourth_address = descriptor->fourth_first_index << 5;
        fourth_address += (u32)fourth_descriptors;
        u16 fourth_count = descriptor->fourth_count;
        u32 fifth_address = descriptor->fifth_first_index << 5;
        fifth_address += (u32)fifth_descriptors;
        u16 fifth_count = descriptor->fifth_count;
        u16 sixth_first_index = descriptor->sixth_first_index;
        u16 sixth_count = descriptor->sixth_count;
        u32 sprite_address = sprite_first_index * sizeof(HardwareSpriteOamRecord);
        sprite_address += (u32)sprite_descriptors;

        return IndexedResourceGroupResult(
            (HardwareSpriteOamRecord *)sprite_address, sprite_count,
            (IndexedResourceArchiveDescriptor32 *)fourth_address, fourth_count << 5,
            (IndexedResourceArchiveDescriptor32 *)fifth_address, fifth_count << 5,
            sixth_descriptors + sixth_first_index, sixth_count);
    }

    return IndexedResourceGroupResult(0, 0, 0, 0, 0, 0, 0, 0);
}

u16 IndexedResourceArchive::GetGroupDescriptorCount() const
{
    return group_descriptor_count;
}

u16 IndexedResourceArchive::GetEntryDescriptorCount() const
{
    return entry_descriptor_count;
}

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

// Predict a forward/reverse wrap without changing the handle. An entry with
// a zero metric stops traversal before a later boundary can be reached.
extern "C" bool WouldIndexedResourceHandleWrap(IndexedResourceHandle const * handle)
{
    i32 delta = handle->scroll_delta;
    i32 remaining = handle->metric_scaled;
    if (delta != 0 && remaining != 0)
    {
        i32 amount = delta;
        if (delta < 0)
            amount = -delta;
        remaining -= amount;
        if (remaining <= 0)
        {
            u32 index = handle->current_entry_index;
            u32 count = handle->resolved_resource.Count();
            do
            {
                if (delta > 0)
                {
                    ++index;
                    if (index >= count)
                        return true;
                }
                else
                {
                    if (index == 0)
                        return true;
                    --index;
                }
                i32 metric = handle->resolved_resource[index].metric;
                if (metric == 0)
                    return false;
                remaining += metric << 8;
            } while (remaining <= 0);
        }
    }
    return false;
}

extern "C" void TransformIndexedResourceSpritePosition(
    i32 * x, i32 * y, u32 width, u32 height,
    IndexedResourceSpriteMatrix const * matrix)
{
    i32 center_x = (*x + width / 2) * 256;
    i32 center_y = (*y + height / 2) * 256;
    // Keep the renderer's original 17/16 coefficient adjustment and the
    // signed halfword truncation before computing the determinant.
    i16 pa = matrix->pa * 272 / 256;
    i16 pb = matrix->pb * 272 / 256;
    i16 pc = matrix->pc * 272 / 256;
    i16 pd = matrix->pd * 272 / 256;
    i32 determinant = (pa * pd - pb * pc) / 256;
    if (determinant != 0)
    {
        i32 transformed_x = pd * center_x - pb * center_y;
        i32 transformed_y = pa * center_y - pc * center_x;
        i32 position_x;
        i32 position_y;
        if (determinant == 256)
        {
            position_x = transformed_x / 256;
            position_y = transformed_y / 256;
        }
        else if (determinant == -256)
        {
            position_x = transformed_x / -256;
            position_y = transformed_y / -256;
        }
        else
        {
            position_x = transformed_x / determinant;
            position_y = transformed_y / determinant;
        }
        *x += (position_x - center_x) >> 8;
        *y += (position_y - center_y) >> 8;
    }
}
