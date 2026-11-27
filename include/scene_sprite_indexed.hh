#ifndef SCENE_SPRITE_INDEXED_HH
#define SCENE_SPRITE_INDEXED_HH

#include "scene_sprite.hh"

#pragma interface "scene_sprite_indexed.hh"

struct GameSceneIndexedSprite : GameSceneSpriteBase {
    GameSceneIndexedSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 const * palette_kinds,
        u32 palette_count, bool unk_3D);
    GameSceneIndexedSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D);

    IndexedResourceHandle handle;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 unk_3F;

    inline void SetResource(IndexedResourceProvider * resource, u32 index);
    inline void SetAnimation(u32 index);
    inline IndexedResourceUpdateResult UpdateAnimation();
    inline void Draw(GameSceneSpriteDrawContext const & context, i32 x, i32 y,
        u32 priorities, u32 sort_key);
};


// These accessors belong to the ordinary sprite interface. They remain
// available for inlining; the native ROM has no separate accessor entries.
#pragma interface "scene_sprite.hh"

inline void GameSceneIndexedSprite::SetResource(IndexedResourceProvider * resource, u32 index)
{
    InitializeIndexedResourceHandle(&handle, resource, index);
    unk_3C = 1;
    unk_3E = 0;
    unk_3F = 1;
}

inline void GameSceneIndexedSprite::SetAnimation(u32 index)
{
    ResolveIndexedResourceHandle(&handle, index);
    unk_3C = 1;
    unk_3E = 0;
    unk_3F = 1;
}

inline IndexedResourceUpdateResult GameSceneIndexedSprite::UpdateAnimation()
{
    if (unk_3F == 0) {
        IndexedResourceUpdateResult result = UpdateIndexedResourceHandle(&handle);
        if (result.flags.group_changed)
            unk_3C = 1;
        return result;
    }
    unk_3F = 0;
    IndexedResourceUpdateResult initial;
    initial.value = INDEXED_RESOURCE_GROUP_CHANGED;
    return initial;
}

inline void GameSceneIndexedSprite::Draw(GameSceneSpriteDrawContext const & context,
    i32 x, i32 y, u32 priorities, u32 sort_key)
{
    IndexedResourceGroupResult const & group = handle.GetGroupData();
    u32 submitted = SubmitGameSceneSprite(this, context.buffer, x, y,
        priorities, sort_key, group.sprites, world);
    if (submitted != 0 && unk_3C) {
        QueueTileUpload(*context.queue, group.tiles);
        if (unk_3D)
            UploadPalettes(group.palettes, 1);
        else if (!unk_3E) {
            UploadPalettes(group.palettes, 1);
            unk_3E = 1;
        }
        unk_3C = 0;
    }
}



#endif // SCENE_SPRITE_INDEXED_HH
