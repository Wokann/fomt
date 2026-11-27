#ifndef ENTITY_AUXILIARY_SPRITES_HH
#define ENTITY_AUXILIARY_SPRITES_HH

#include "world_runtime.hh"

#pragma interface "entity_auxiliary_sprites.hh"

struct WorldSpriteDrawBuffer;
struct HardwareDmaQueue;

// Three retained resource groups selected by the entity auxiliary render
// profile. The constructor remains native; the last byte is not yet named.
struct EntityAuxiliarySpriteEntry {
    IndexedResourceGroupResult group;
    ObjTileCollectionEntry tiles;
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
    void PrepareResources(HardwareDmaQueue & queue);
    void Draw(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 kind) const;
};



#endif // ENTITY_AUXILIARY_SPRITES_HH
