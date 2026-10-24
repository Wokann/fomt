#include "prelude.h"
#pragma implementation "resource_archive.hh"
#include "resource_archive.hh"

IndexedResourceArchive::IndexedResourceArchive(u8 const * data)
{
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
