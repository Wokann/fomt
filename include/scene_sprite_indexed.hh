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

    inline void SetAnimation(u32 index);
    inline IndexedResourceUpdateResult UpdateAnimation();
};

typedef char GameSceneIndexedSpriteSizeCheck[sizeof(GameSceneIndexedSprite) == 0x40 ? 1 : -1];
typedef char GameSceneIndexedSpriteHandleCheck[offsetof(GameSceneIndexedSprite, handle) == 0x28 ? 1 : -1];
typedef char GameSceneIndexedSpriteFlagsCheck[offsetof(GameSceneIndexedSprite, unk_3C) == 0x3C ? 1 : -1];

// These accessors belong to the ordinary sprite interface. They remain
// available for inlining; the native ROM has no separate accessor entries.
#pragma interface "scene_sprite.hh"

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


#endif // SCENE_SPRITE_INDEXED_HH
