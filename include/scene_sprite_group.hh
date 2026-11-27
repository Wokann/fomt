#ifndef SCENE_SPRITE_GROUP_HH
#define SCENE_SPRITE_GROUP_HH

#include "scene_sprite.hh"

#pragma interface "scene_sprite_group.hh"

// Both world event icons and entity-owned graphics embed this same group
// sprite. A group is resolved once; the indexed sprite keeps a handle instead.
// A nonzero visible-record count uploads the tile/palette ranges and clears
// the pending flag; invisible submissions leave it pending.
struct GameSceneGroupSprite : GameSceneSpriteBase {
    inline GameSceneGroupSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind);

    IndexedResourceGroupResult group;
    u8 upload_pending;

    inline void Draw(GameSceneSpriteDrawContext const & context, i32 x, i32 y,
        u32 priorities, u32 sort_key, u8 palette_unknown = 1);

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
      group(ResolveIndexedResourceGroup(resource, index)), upload_pending(1)
{
}

inline void GameSceneGroupSprite::Draw(GameSceneSpriteDrawContext const & context,
    i32 x, i32 y, u32 priorities, u32 sort_key, u8 palette_unknown)
{
    IndexedResourceGroupResult const & data = group;
    u32 submitted = SubmitGameSceneSprite(this, context.buffer, x, y, priorities,
        sort_key, data.sprites, world);
    if (submitted != 0 && upload_pending) {
        QueueTileUpload(*context.queue, data.tiles);
        UploadPalettes(data.palettes, palette_unknown);
        upload_pending = 0;
    }
}


#endif // SCENE_SPRITE_GROUP_HH
