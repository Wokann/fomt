#ifndef MAP_CLOCK_STATUS_LIFETIMES_HH
#define MAP_CLOCK_STATUS_LIFETIMES_HH

#include "hardware_dma_copy.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "resource_archive.hh"
#include <string.h>


// Confirmed by both native rendering paths: each buffer uploads eight OBJ
// tiles when dirty and when its DMA node is no longer linked.
// The state entry owns eight OBJ tiles; the DMA link follows its dirty byte.
struct MapClockStatusHudTileBuffer {
    u32 tiles[8][8];
    ObjTileCollectionEntry state;
    u8 dirty;
    HardwareDmaCopyLink upload;

    MapClockStatusHudTileBuffer() : state(3), dirty(1) {}
    void SetTile(u32 (&tile)[8], u8 const * glyph)
    {
        memcpy(tile, glyph, 32);
        dirty = 1;
    }
    void SetTile(u32 index, u8 const * glyph)
    {
        memcpy(tiles[index], glyph, 32);
        dirty = 1;
    }
};

// Full native 0x35C allocation; unresolved selector/value storage stays unk.
struct MapClockStatusHudData {
    IndexedResourceArchive unk_archive_000;
    IndexedResourceArchive unk_archive_030;
    ObjPaletteCollectionEntry palette;
    HardwareDmaCopyLink palette_upload;
    u8 palette_dirty;
    MapClockStatusHudTileBuffer date_tiles;
    MapClockStatusHudTileBuffer time_tiles;
    u8 unk_selector;
    ObjTileCollectionEntry unk_state_2D0;
    HardwareDmaCopyLink unk_dma_2D8;
    u8 unk_selector_dirty;
    u8 unk_value_active;
    u16 unk_value;
    ObjPaletteCollectionEntry unk_pool_2F4;
    HardwareDmaCopyLink unk_dma_2FC;
    ObjTileCollectionEntry unk_state_314;
    HardwareDmaCopyLink unk_dma_31C;
    u8 unk_value_dirty;
    ObjTileCollectionEntry unk_state_338;
    HardwareDmaCopyLink unk_dma_340;
    u8 unk_358;

    ~MapClockStatusHudData();

private:
    friend struct MapClockStatusHudContent;
    MapClockStatusHudData();
};

typedef char MapClockStatusHudDataSize[sizeof(MapClockStatusHudData) == 0x35C ? 1 : -1];
typedef char MapClockStatusBufferSize[sizeof(MapClockStatusHudTileBuffer) == 0x124 ? 1 : -1];
typedef char MapClockStatusBufferStateOffset[offsetof(MapClockStatusHudTileBuffer, state) == 0x100 ? 1 : -1];
typedef char MapClockStatusBufferDirtyOffset[offsetof(MapClockStatusHudTileBuffer, dirty) == 0x108 ? 1 : -1];
typedef char MapClockStatusBufferUploadOffset[offsetof(MapClockStatusHudTileBuffer, upload) == 0x10C ? 1 : -1];
typedef char MapClockStatusDateOffset[offsetof(MapClockStatusHudData, date_tiles) == 0x84 ? 1 : -1];
typedef char MapClockStatusTimeOffset[offsetof(MapClockStatusHudData, time_tiles) == 0x1A8 ? 1 : -1];
typedef char MapClockStatusPaletteUploadOffset[offsetof(MapClockStatusHudData, palette_upload) == 0x68 ? 1 : -1];
typedef char MapClockStatusSelectorOffset[offsetof(MapClockStatusHudData, unk_selector) == 0x2CC ? 1 : -1];
typedef char MapClockStatusSelectorDirtyOffset[offsetof(MapClockStatusHudData, unk_selector_dirty) == 0x2F0 ? 1 : -1];
typedef char MapClockStatusValueActiveOffset[offsetof(MapClockStatusHudData, unk_value_active) == 0x2F1 ? 1 : -1];
typedef char MapClockStatusValueOffset[offsetof(MapClockStatusHudData, unk_value) == 0x2F2 ? 1 : -1];
typedef char MapClockStatusValueDirtyOffset[offsetof(MapClockStatusHudData, unk_value_dirty) == 0x334 ? 1 : -1];

#endif // MAP_CLOCK_STATUS_LIFETIMES_HH
