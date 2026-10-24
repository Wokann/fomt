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

        tile_unit_count = *(u16 const *)data;
        data += 4;
        tile_units = (IndexedResourceTileUnit *)data;
        data += tile_unit_count * 32;

        palette_bank_count = *(u16 const *)data;
        data += 4;
        palette_banks = (IndexedResourcePaletteBank *)data;
        data += palette_bank_count * 32;

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
        tile_unit_count = 0;
        tile_units = 0;
        palette_bank_count = 0;
        palette_banks = 0;
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
        u32 tile_address = descriptor->tile_first_index << 5;
        tile_address += (u32)tile_units;
        u16 tile_unit_count = descriptor->tile_unit_count;
        u32 palette_address = descriptor->palette_first_index << 5;
        palette_address += (u32)palette_banks;
        u16 palette_bank_count = descriptor->palette_bank_count;
        u16 sixth_first_index = descriptor->sixth_first_index;
        u16 sixth_count = descriptor->sixth_count;
        u32 sprite_address = sprite_first_index * sizeof(HardwareSpriteOamRecord);
        sprite_address += (u32)sprite_descriptors;

        return IndexedResourceGroupResult(
            (HardwareSpriteOamRecord *)sprite_address, sprite_count,
            (IndexedResourceTileUnit *)tile_address, tile_unit_count << 5,
            (IndexedResourcePaletteBank *)palette_address, palette_bank_count << 5,
            sixth_descriptors + sixth_first_index, sixth_count);
    }

    return IndexedResourceGroupResult(0, 0, 0, 0, 0, 0, 0, 0);
}

u16 IndexedResourceArchive::GetGroupDescriptorCount() const
{
    return group_descriptor_count;
}
