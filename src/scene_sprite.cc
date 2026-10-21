#include "prelude.h"
#include "entity_actor.hh"
#include "world_runtime.hh"

#pragma implementation "scene_sprite.hh"
#include "scene_sprite.hh"

GameSceneSpriteBase::~GameSceneSpriteBase()
{
    for (u32 index = 0; index < palettes.count; ++index)
        world->ClearSpritePaletteResourceFlag(palettes[index]);
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kind),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
}

// GameSceneGroupSprite deliberately uses its implicit destructor: only the
// real base owns cleanup. The compiler emits the native flag-forwarding entry
// without the extra vptr store of a user-written empty destructor.
