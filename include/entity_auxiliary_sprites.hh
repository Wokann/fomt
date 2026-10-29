#ifndef ENTITY_AUXILIARY_SPRITES_HH
#define ENTITY_AUXILIARY_SPRITES_HH

#include "world_runtime.hh"

#pragma interface "entity_auxiliary_sprites.hh"

struct WorldSpriteDrawBuffer;

// Three retained resource groups selected by the entity auxiliary render
// profile. The constructor remains native; the last byte is not yet named.
struct EntityAuxiliarySpriteEntry {
    IndexedResourceGroupResult group;
    HardwareStateEntry tiles;
    u16 tile_index;
};

struct EntityAuxiliarySprites {
    GameObject * world;
    EntityAuxiliarySpriteEntry entries[3];
    GameScenePaletteIndices indices;
    u8 unk_9C;

    // The shared native constructor implements this real C++ ABI.
    explicit EntityAuxiliarySprites(GameObject * source);
    ~EntityAuxiliarySprites();
    void Draw(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 kind) const;
};

typedef char EntityAuxiliarySpriteEntrySizeCheck[sizeof(EntityAuxiliarySpriteEntry) == 44 ? 1 : -1];
typedef char EntityAuxiliarySpriteEntryTilesCheck[offsetof(EntityAuxiliarySpriteEntry, tiles) == 32 ? 1 : -1];
typedef char EntityAuxiliarySpriteEntryTileIndexCheck[offsetof(EntityAuxiliarySpriteEntry, tile_index) == 40 ? 1 : -1];
typedef char EntityAuxiliarySpritesEntriesCheck[offsetof(EntityAuxiliarySprites, entries) == 4 ? 1 : -1];
typedef char EntityAuxiliarySpritesIndicesCheck[offsetof(EntityAuxiliarySprites, indices) == 0x88 ? 1 : -1];
typedef char EntityAuxiliarySpritesIndexValuesCheck[offsetof(EntityAuxiliarySprites, indices.values) == 0x8C ? 1 : -1];
typedef char EntityAuxiliarySpritesFlagCheck[offsetof(EntityAuxiliarySprites, unk_9C) == 0x9C ? 1 : -1];
typedef char EntityAuxiliarySpritesSizeCheck[sizeof(EntityAuxiliarySprites) == 0xA0 ? 1 : -1];

#endif // ENTITY_AUXILIARY_SPRITES_HH
