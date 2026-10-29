#ifndef WORLD_RUNTIME_HH
#define WORLD_RUNTIME_HH

#include "prelude.h"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "resource_archive.hh"
#include "world_map.hh"
#include <string.h>

#pragma interface "world_runtime.hh"

struct AEntity;
struct GameObject;
struct GameSceneWorldPrefix;

// The native palette cache has 22 resource records and 13 retained banks.
// Keep the remaining record bytes and flags opaque until their users are recovered.
struct GameScenePaletteResource {
    u8 unk_00[0x80];
    i8 palette_slot : 8;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
};

struct GameScenePaletteSlot {
    HardwareResourceEntry allocation;
    u8 palette_bank;
    i8 resource_index;
    u8 unk_0A;
    u8 unk_0B;
};

struct GameScenePaletteCache {
    u8 encoded_palette_banks[32];
    GameScenePaletteResource resources[22];
    GameScenePaletteSlot slots[13];
    u8 used_slots;
    u8 unk_C15;

    // Native implementation; returns a retained/new OBJ bank or -1.
    i32 AcquirePaletteBank(u32 index);

    u32 ResourceCount() const { return ARRAY_COUNT(resources); }
};

typedef char GameScenePaletteResourceSizeCheck[sizeof(GameScenePaletteResource) == 132 ? 1 : -1];
typedef char GameScenePaletteResourceFlagOffsetCheck[offsetof(GameScenePaletteResource, unk_81) == 0x81 ? 1 : -1];
typedef char GameScenePaletteSlotSizeCheck[sizeof(GameScenePaletteSlot) == 12 ? 1 : -1];
typedef char GameScenePaletteCacheSlotsCheck[offsetof(GameScenePaletteCache,slots) == 0xB78 ? 1 : -1];
typedef char GameScenePaletteCacheCountCheck[offsetof(GameScenePaletteCache,used_slots) == 0xC14 ? 1 : -1];
typedef char GameScenePaletteCacheSizeCheck[sizeof(GameScenePaletteCache) == 0xC18 ? 1 : -1];

// This one-word owner is passed by value to the native data constructor.
// Transfer clears the source slot; destruction uses the map's real virtual ABI.
struct GameSceneWorldMapOwner {
    GameSceneWorldMap * value;

    explicit GameSceneWorldMapOwner(GameSceneWorldMap * input) : value(input) {}
    GameSceneWorldMap * Release()
    {
        GameSceneWorldMap * result = value;
        value = nullptr;
        return result;
    }
    GameSceneWorldMapOwner(GameSceneWorldMapOwner & source) : value(source.Release()) {}
    ~GameSceneWorldMapOwner() { delete value; }

private:
    GameSceneWorldMapOwner & operator=(GameSceneWorldMapOwner const &);
};

// Only the virtual-destruction prefix is known. Never allocate this view.
struct GameSceneWorldUnkObject {
    u8 unk_00[0x24];
    virtual ~GameSceneWorldUnkObject();

private:
    GameSceneWorldUnkObject();
};

struct GameSceneWorldUnk1028 {
    GameSceneWorldUnkObject * value;
    Vec2 unk_04;
    u8 unk_08;
    u8 unk_09;
};

// This native world member stores three resource groups and a counted
// sixteen-byte index list. The constructor still uses native assembly.
struct GameSceneWorldUnk1020Entry {
    IndexedResourceGroupResult group;
    HardwareStateEntry tiles;
    u16 tile_index;
};

struct GameScenePaletteIndices {
private:
    void Initialize(u32 input_count, u8 const & initial)
    {
        count = 0;
        if (input_count <= ARRAY_COUNT(values)) {
            memset(values, initial, input_count);
            count = input_count;
        }
    }

public:
    GameScenePaletteIndices() : count(0) {}

    GameScenePaletteIndices(GameScenePaletteIndices const & other) : count(0)
    {
        u32 input_count = other.count;
        u8 const * first = other.values;
        u8 * destination = values;
        u8 const * last = first + input_count;
        if (last != first)
            memmove(destination, first, last - first);
        count = input_count;
    }

    explicit GameScenePaletteIndices(u32 input_count)
    {
        Initialize(input_count, 0);
    }

    u32 count;
    union {
        u8 values[16];
        u32 storage[4];
    };

    u8 * End() { return &reinterpret_cast<u8 *>(storage)[count]; }

    u8 & operator[](u32 index) { return values[index]; }
};

typedef char GameScenePaletteIndicesSizeCheck[sizeof(GameScenePaletteIndices) == 20 ? 1 : -1];
typedef char GameScenePaletteIndexValuesCheck[offsetof(GameScenePaletteIndices, values) == 4 ? 1 : -1];

struct GameSceneWorldUnk1020 {
    GameObject * world;
    GameSceneWorldUnk1020Entry entries[3];
    GameScenePaletteIndices indices;
    u8 unk_9C;

    // The shared native constructor implements this real C++ ABI.
    explicit GameSceneWorldUnk1020(GameObject * source);
    ~GameSceneWorldUnk1020();
};

typedef char GameSceneWorldUnk1020EntrySizeCheck[sizeof(GameSceneWorldUnk1020Entry) == 44 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntryTilesCheck[offsetof(GameSceneWorldUnk1020Entry, tiles) == 32 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntryTileIndexCheck[offsetof(GameSceneWorldUnk1020Entry, tile_index) == 40 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntriesCheck[offsetof(GameSceneWorldUnk1020, entries) == 4 ? 1 : -1];
typedef char GameSceneWorldUnk1020IndicesCheck[offsetof(GameSceneWorldUnk1020, indices) == 0x88 ? 1 : -1];
typedef char GameSceneWorldUnk1020IndexValuesCheck[offsetof(GameSceneWorldUnk1020, indices.values) == 0x8C ? 1 : -1];
typedef char GameSceneWorldUnk1020FlagCheck[offsetof(GameSceneWorldUnk1020, unk_9C) == 0x9C ? 1 : -1];
typedef char GameSceneWorldUnk1020SizeCheck[sizeof(GameSceneWorldUnk1020) == 0xA0 ? 1 : -1];

// The native constructor receives this member at world+4, not the complete
// world object. Each archive has its own source and reverse-order destruction.
// The constructor and destructor bodies remain native assembly under their
// real C++ ABI names; declaring them does not count as C++ code recovery.
struct GameSceneWorldData {
    GameSceneWorldMapOwner map;
    AEntity * entities[100];
    u32 unk_194;
    GameScenePaletteCache palette_cache;
    IndexedResourceArchive actor_archive;
    IndexedResourceArchive unk_DE0;
    IndexedResourceArchive unk_E10;
    IndexedResourceArchive unk_E40;
    IndexedResourceArchive unk_E70;
    IndexedResourceArchive unk_EA0;
    IndexedResourceArchive unk_ED0;
    IndexedResourceArchive unk_F00;
    IndexedResourceArchive unk_F30;
    IndexedResourceArchive unk_F60;
    IndexedResourceArchive unk_F90;
    IndexedResourceArchive unk_FC0;
    IndexedResourceArchive unk_FF0;
    GameSceneWorldUnk1020 * unk_1020;
    void * unk_1024;
    GameSceneWorldUnk1028 unk_1028;

    IndexedResourceArchive * GetMapSpriteArchive() { return &unk_F00; }

    GameSceneWorldData(GameSceneWorldMapOwner source);
    ~GameSceneWorldData();

private:
    GameSceneWorldData(GameSceneWorldData const &);
    GameSceneWorldData & operator=(GameSceneWorldData const &);
};

typedef char GameSceneWorldMapOwnerSizeCheck[sizeof(GameSceneWorldMapOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkObjectPrefixSizeCheck[sizeof(GameSceneWorldUnkObject) == 0x28 ? 1 : -1];
typedef char GameSceneWorldUnkRecordSizeCheck[sizeof(GameSceneWorldUnk1028) == 12 ? 1 : -1];
typedef char GameSceneWorldUnkRecordPointCheck[offsetof(GameSceneWorldUnk1028, unk_04) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkRecordFlagCheck[offsetof(GameSceneWorldUnk1028, unk_09) == 9 ? 1 : -1];
typedef char GameSceneWorldDataEntitiesCheck[offsetof(GameSceneWorldData, entities) == 4 ? 1 : -1];
typedef char GameSceneWorldDataPaletteCacheCheck[offsetof(GameSceneWorldData, palette_cache) == 0x198 ? 1 : -1];
typedef char GameSceneWorldArchiveSizeCheck[sizeof(IndexedResourceArchive) == 0x30 ? 1 : -1];
typedef char GameSceneWorldDataActorArchiveCheck[offsetof(GameSceneWorldData, actor_archive) == 0xDB0 ? 1 : -1];
typedef char GameSceneWorldDataLastArchiveCheck[offsetof(GameSceneWorldData, unk_FF0) == 0xFF0 ? 1 : -1];
typedef char GameSceneWorldDataUnknownObjectCheck[offsetof(GameSceneWorldData, unk_1020) == 0x1020 ? 1 : -1];
typedef char GameSceneWorldDataUnkRecordCheck[offsetof(GameSceneWorldData, unk_1028) == 0x1028 ? 1 : -1];
typedef char GameSceneWorldDataSizeCheck[sizeof(GameSceneWorldData) == 0x1034 ? 1 : -1];

EXTERN_C
i32 GetWorldSpritePaletteBank(GameSceneWorldPrefix & world, u32 index);
// The exact role of resource byte +0x81 remains unknown; only clearing is known.
void ClearWorldSpritePaletteResourceFlag(GameSceneWorldPrefix & world, u32 index);
EXTERN_C_END

#endif // WORLD_RUNTIME_HH
