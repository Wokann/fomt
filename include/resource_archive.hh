#ifndef RESOURCE_ARCHIVE_HH
#define RESOURCE_ARCHIVE_HH

#include "prelude.h"
#include "hardware_sprite_buffer.hh"

struct IndexedResourceProvider;

struct IndexedResourceEntry
{
    // Passed to the provider's GetGroupData slot by sprite consumers.
    u16 group_index;
    u16 metric;
};

struct IndexedResourceResult
{
    IndexedResourceEntry & operator[](u32 index) const { return entries[index]; }
    u32 Count() const { return entries ? entry_count : 0; }

    IndexedResourceResult(IndexedResourceEntry * a_entries, u16 a_entry_count)
        : entries(a_entries), entry_count(a_entry_count) {}

    IndexedResourceEntry * entries;
    u16 entry_count;
    u16 unknown_06;
};

struct IndexedResourceArchiveDescriptor8 { u8 unknown_00[8]; };
// A tile offset is measured in 32-byte hardware OBJ tile units. An 8bpp
// tile spans two units; this is not a promise that every tile is 4bpp.
struct IndexedResourceTileUnit { u8 bytes[32]; };
struct IndexedResourcePaletteBank { u16 colors[16]; };

struct IndexedResourceSpriteRange
{
    HardwareSpriteOamRecord * Data() const { return data; }
    u32 Count() const { return data ? count : 0; }

    IndexedResourceSpriteRange(HardwareSpriteOamRecord * a_data, u16 a_count)
        : data(a_data), count(a_count) {}

    HardwareSpriteOamRecord * data;
    u16 count;
};

struct IndexedResourceDescriptor8Range
{
    IndexedResourceArchiveDescriptor8 * Data() const { return data; }
    u32 Count() const { return data ? count : 0; }

    IndexedResourceDescriptor8Range(IndexedResourceArchiveDescriptor8 * a_data, u16 a_count)
        : data(a_data), count(a_count) {}

    IndexedResourceArchiveDescriptor8 * data;
    u16 count;
};

struct IndexedResourceTileRange
{
    IndexedResourceTileRange(IndexedResourceTileUnit * a_data, u16 a_byte_count)
        : data(a_data), byte_count(a_byte_count) {}

    IndexedResourceTileUnit * data;
    u16 byte_count;
};

struct IndexedResourcePaletteRange
{
    IndexedResourcePaletteRange(IndexedResourcePaletteBank * a_data, u16 a_byte_count)
        : data(a_data), byte_count(a_byte_count) {}

    IndexedResourcePaletteBank * data;
    u16 byte_count;
};

// OAM and sixth-range lengths count eight-byte entries. Tile/palette range
// lengths are bytes, not unit/bank counts; the archive descriptor counts are
// converted when resolving a group. The sixth format remains unresolved.
// Each range's trailing two bytes are ABI padding, not stored metadata.
struct IndexedResourceGroupResult
{
    IndexedResourceGroupResult(
        HardwareSpriteOamRecord * sprite_data, u16 sprite_count,
        IndexedResourceTileUnit * tile_data, u16 tile_byte_count,
        IndexedResourcePaletteBank * palette_data, u16 palette_byte_count,
        IndexedResourceArchiveDescriptor8 * sixth_data, u16 sixth_count)
        : sprites(sprite_data, sprite_count), tiles(tile_data, tile_byte_count),
          palettes(palette_data, palette_byte_count), sixth(sixth_data, sixth_count) {}

    IndexedResourceSpriteRange sprites;
    IndexedResourceTileRange tiles;
    IndexedResourcePaletteRange palettes;
    IndexedResourceDescriptor8Range sixth;
};

// Native provider-base and archive tables share the C++ virtual destructor,
// entry resolver and group resolver slots. Only the implementation unit emits
// their standalone methods and vtables; callers may inline cleanup.
#pragma interface "resource_archive.hh"
struct IndexedResourceProvider
{
    virtual ~IndexedResourceProvider() SECTION(".text.indexed_resource_provider_cleanup");
    virtual IndexedResourceResult Resolve(u32 index) const = 0;
    virtual IndexedResourceGroupResult GetGroupData(u32 index) const = 0;
};

inline IndexedResourceProvider::~IndexedResourceProvider() {}

// Resolve an entry index to the group referenced by its first entry.
static inline IndexedResourceGroupResult ResolveIndexedResourceGroup(
    IndexedResourceProvider const * resource, u32 index)
{
    return resource->GetGroupData(resource->Resolve(index)[0].group_index);
}

struct IndexedResourceArchiveEntry
{
    u16 entry_count;
    u16 first_entry_index;
};

struct IndexedResourceArchiveGroupDescriptor
{
    u16 sprite_count;
    u16 sprite_first_index;
    u16 tile_unit_count;
    u16 tile_first_index;
    u16 palette_bank_count;
    u16 palette_first_index;
    u16 sixth_count;
    u16 sixth_first_index;
};

// An archive borrows its payload; destroying it never frees that payload.
struct IndexedResourceArchive : IndexedResourceProvider
{
    // The original destructor is part of the later C++ library block.
    virtual ~IndexedResourceArchive() SECTION(".text.indexed_resource_archive_cleanup");
    IndexedResourceArchive(u8 const * data);

    IndexedResourceArchiveEntry * entry_descriptors;
    IndexedResourceArchiveGroupDescriptor * group_descriptors;
    HardwareSpriteOamRecord * sprite_descriptors;
    IndexedResourceTileUnit * tile_units;
    IndexedResourcePaletteBank * palette_banks;
    IndexedResourceArchiveDescriptor8 * sixth_descriptors;
    IndexedResourceEntry * entries;
    u16 entry_descriptor_count;
    u16 group_descriptor_count;
    u16 sprite_descriptor_count;
    u16 tile_unit_count;
    u16 palette_bank_count;
    u16 sixth_descriptor_count;
    u16 entry_count;

    virtual IndexedResourceResult Resolve(u32 index) const;
    virtual IndexedResourceGroupResult GetGroupData(u32 index) const;
    u16 GetGroupDescriptorCount() const;
    inline u16 GetEntryDescriptorCount() const;
};

inline u16 IndexedResourceArchive::GetEntryDescriptorCount() const
{
    return entry_descriptor_count;
}
#pragma implementation

typedef char IndexedResourceProviderSizeCheck[sizeof(IndexedResourceProvider) == 4 ? 1 : -1];
typedef char IndexedResourceArchiveEntriesOffsetCheck[offsetof(IndexedResourceArchive, entry_descriptors) == 4 ? 1 : -1];
typedef char IndexedResourceArchiveTilesOffsetCheck[offsetof(IndexedResourceArchive, tile_units) == 0x10 ? 1 : -1];
typedef char IndexedResourceArchivePalettesOffsetCheck[offsetof(IndexedResourceArchive, palette_banks) == 0x14 ? 1 : -1];
typedef char IndexedResourceArchiveCountOffsetCheck[offsetof(IndexedResourceArchive, entry_descriptor_count) == 0x20 ? 1 : -1];
typedef char IndexedResourceArchiveSizeCheck[sizeof(IndexedResourceArchive) == 0x30 ? 1 : -1];
typedef char IndexedResourceResultSizeCheck[sizeof(IndexedResourceResult) == 8 ? 1 : -1];
typedef char IndexedResourceGroupDescriptorSizeCheck[sizeof(IndexedResourceArchiveGroupDescriptor) == 16 ? 1 : -1];
typedef char IndexedResourceDescriptor8RangeSizeCheck[sizeof(IndexedResourceDescriptor8Range) == 8 ? 1 : -1];
typedef char IndexedResourceSpriteRangeSizeCheck[sizeof(IndexedResourceSpriteRange) == 8 ? 1 : -1];
typedef char IndexedResourceTileUnitSizeCheck[sizeof(IndexedResourceTileUnit) == 32 ? 1 : -1];
typedef char IndexedResourcePaletteBankSizeCheck[sizeof(IndexedResourcePaletteBank) == 32 ? 1 : -1];
typedef char IndexedResourceTileRangeSizeCheck[sizeof(IndexedResourceTileRange) == 8 ? 1 : -1];
typedef char IndexedResourcePaletteRangeSizeCheck[sizeof(IndexedResourcePaletteRange) == 8 ? 1 : -1];
typedef char IndexedResourceTileByteCountOffsetCheck[offsetof(IndexedResourceTileRange, byte_count) == 4 ? 1 : -1];
typedef char IndexedResourcePaletteByteCountOffsetCheck[offsetof(IndexedResourcePaletteRange, byte_count) == 4 ? 1 : -1];
typedef char IndexedResourceGroupResultSizeCheck[sizeof(IndexedResourceGroupResult) == 32 ? 1 : -1];
typedef char IndexedResourceGroupTilesOffsetCheck[offsetof(IndexedResourceGroupResult, tiles) == 8 ? 1 : -1];
typedef char IndexedResourceGroupPalettesOffsetCheck[offsetof(IndexedResourceGroupResult, palettes) == 16 ? 1 : -1];
typedef char IndexedResourceGroupSixthOffsetCheck[offsetof(IndexedResourceGroupResult, sixth) == 24 ? 1 : -1];

EXTERN_C

// Direct declaration of the existing constructor ABI for assembly-owned lifecycles.
IndexedResourceArchive * ConstructIndexedResourceArchive(IndexedResourceArchive *, u8 const *)
    asm("__22IndexedResourceArchivePCUc");

EXTERN_C_END

inline IndexedResourceArchive::~IndexedResourceArchive()
{
}

#endif // RESOURCE_ARCHIVE_HH
