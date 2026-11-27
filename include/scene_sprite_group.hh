#ifndef SCENE_SPRITE_GROUP_HH
#define SCENE_SPRITE_GROUP_HH

#include "scene_sprite.hh"

#pragma interface "scene_sprite_group.hh"

// Both world event icons and entity-owned graphics embed this same group
// sprite. A group is resolved once; the indexed sprite keeps a handle instead.
// Native factories initialize +0x48, but its full meaning remains unknown.
struct GameSceneGroupSprite : GameSceneSpriteBase {
    inline GameSceneGroupSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind);

    IndexedResourceGroupResult group;
    u8 unk_48;

    // No default construction path has been recovered.
private:
    GameSceneGroupSprite();
};


// Construction remains inline at its original callers, without an extra
// standalone constructor in the late cleanup/table owner.
#pragma interface "scene_sprite.hh"

inline GameSceneGroupSprite::GameSceneGroupSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 palette_kind)
    : GameSceneSpriteBase(world, size_shift, palette_kind),
      group(ResolveIndexedResourceGroup(resource, index)), unk_48(1)
{
}


#endif // SCENE_SPRITE_GROUP_HH
