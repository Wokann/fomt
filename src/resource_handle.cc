#include "resource_handle.hh"

IndexedResourceHandle::IndexedResourceHandle(
    IndexedResourceProvider * a_resource, u32 index, i32 a_scroll_delta)
    : resource(a_resource),
      resolved_resource(a_resource->Resolve(index)),
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
    IndexedResourceResult resolved = handle->resource->Resolve(index);

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

static inline IndexedResourceEntry const & GetIndexedResourceEntry(
    IndexedResourceEntry const * data, u32 index)
{
    return data[index];
}

extern "C" IndexedResourceUpdateResult UpdateIndexedResourceHandle(IndexedResourceHandle * handle)
{
    IndexedResourceUpdateFlag result = static_cast<IndexedResourceUpdateFlag>(0);
    if (handle->initialized != 0)
    {
        result = INDEXED_RESOURCE_GROUP_CHANGED;
        handle->initialized = 0;
    }
    i32 delta = handle->scroll_delta;
    i32 remaining = handle->metric_scaled;
    if (delta != 0 && remaining != 0)
    {
        remaining -= delta < 0 ? -delta : delta;
        if (remaining <= 0)
        {
            u32 index = handle->current_entry_index;
            IndexedResourceResult const & entries = handle->resolved_resource;
            u16 previous_group = entries[index].group_index;
            result = static_cast<IndexedResourceUpdateFlag>(
                result | INDEXED_RESOURCE_ENTRY_ADVANCED);
            IndexedResourceEntry * data;
            u32 count;
            // Cache both parts of the borrowed, nullable entry range before
            // walking it. The scoped value is the count returned by that read.
            {
                u32 available = 0;
                data = entries.entries;
                if (data != 0)
                    available = entries.entry_count;
                count = available;
            }
            do
            {
                if (delta > 0)
                {
                    ++index;
                    if (index >= count)
                    {
                        index = 0;
                        result = static_cast<IndexedResourceUpdateFlag>(
                            result | INDEXED_RESOURCE_WRAPPED);
                    }
                }
                else
                {
                    if (index == 0)
                    {
                        index = count;
                        result = static_cast<IndexedResourceUpdateFlag>(
                            result | INDEXED_RESOURCE_WRAPPED);
                    }
                    --index;
                }
                u16 metric = GetIndexedResourceEntry(data, index).metric;
                if (metric != 0)
                {
                    remaining += metric << 8;
                }
                else
                {
                    remaining = 0;
                    break;
                }
            } while (remaining <= 0);
            if (GetIndexedResourceEntry(data, index).group_index != previous_group)
                result = static_cast<IndexedResourceUpdateFlag>(
                    result | INDEXED_RESOURCE_GROUP_CHANGED);
            handle->current_entry_index = index;
        }
        handle->metric_scaled = remaining;
    }
    IndexedResourceUpdateResult status;
    status.value = result;
    return status;
}

static inline IndexedResourceSpriteMatrix ReadIndexedSpriteMatrix(
    HardwareSpriteOamRecord const * records)
{
    IndexedResourceSpriteMatrix result;
    result.pa = records[0].affine_coefficient;
    result.pb = records[1].affine_coefficient;
    result.pc = records[2].affine_coefficient;
    result.pd = records[3].affine_coefficient;
    return result;
}

extern "C" void DrawIndexedResourceSprites(
    HardwareSpriteBufferState * state, HardwareSpriteOamRecord const * sprites,
    u32 count, IndexedResourceSpriteParameters const * parameters)
{
    HardwareSpriteOamRecord const * cursor = sprites;
    HardwareSpriteOamRecord const * end = cursor + count;
    for (; cursor != end; ++cursor)
    {
        HardwareSpriteOamRecord sprite = *cursor;
        u32 const shape = sprite.shape;
        u32 size = sprite.size;
        i32 width, height;
        if (shape == 0)
            width = height = 8 << size;
        else
        {
            u32 large = 8 << (((size + 1) >> 1) + 1);
            u32 small = size == 1 ? 8 : large >> 1;
            if (shape != 1)
            {
                height = large;
                width = small;
            }
            else
            {
                height = small;
                width = large;
            }
        }
        // Decode the bounded relative offsets as signed halfwords, then
        // widen them for the transform's 32-bit coordinate updates.
        i32 x = static_cast<i16>(sprite.x);
        i32 y = static_cast<i16>(sprite.y);
        u32 affine_mode = parameters->affine_mode;
        if (affine_mode == 0)
        {
            if (parameters->flips & 1)
            {
                x = -(x + width);
                sprite.horizontal_flip ^= 1;
            }
            if (parameters->flips & 2)
            {
                y = -(y + height);
                sprite.vertical_flip ^= 1;
            }
        }
        else
        {
            u32 index = parameters->affine_index;
            sprite.affine_index_low = index & 7;
            sprite.horizontal_flip = (index & 8) >> 3;
            sprite.vertical_flip = (index & 16) >> 4;
            HardwareSpriteOamRecord const * matrix_records =
                &state->sprites[(index & 31) * 4];
            IndexedResourceSpriteMatrix matrix = ReadIndexedSpriteMatrix(matrix_records);
            TransformIndexedResourceSpritePosition(&x, &y, width, height, &matrix);
            if (affine_mode == 3)
            {
                x -= width / 2;
                y -= height / 2;
            }
        }
        x += parameters->x;
        y += parameters->y;
        if (affine_mode == 0 &&
            (x + width <= 0 || x > 239 || y + height <= 0 || y > 159))
            continue;
        sprite.y = y;
        sprite.affine_mode = affine_mode;
        sprite.object_mode = parameters->object_mode;
        sprite.mosaic = parameters->mosaic;
        sprite.x = x;
        sprite.tile_index += parameters->tile_offset;
        sprite.priority = parameters->priority;
        sprite.palette_bank += parameters->palette_offset;
        u32 sprite_index = state->sprite_count;
        if (sprite_index < 128)
        {
            HardwareSpriteOamRecord * destination = &state->sprites[sprite_index];
            memcpy(destination, &sprite, offsetof(HardwareSpriteOamRecord, affine_coefficient));
            state->sprite_count = sprite_index + 1;
        }
    }
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
