#include "prelude.h"
#include "entity_actor.hh"
#include "world_runtime.hh"

#pragma implementation "scene_sprite.hh"
#include "scene_sprite.hh"

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift,
    i32 const * palette_kinds, u32 palette_count)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()),
      palettes(palette_count)
{
    i32 const * current = palette_kinds;
    for (u32 index = 0; index < palette_count; ++index)
        palettes[index] = source->vfunc_48(*current++);
}

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift, i32 palette_kind)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()), palettes(1)
{
    palettes[0] = source->vfunc_48(palette_kind);
}

GameSceneSpriteBase::~GameSceneSpriteBase()
{
    for (u32 index = 0; index < palettes.count; ++index)
        world->ClearSpritePaletteResourceFlag(palettes[index]);
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 const * palette_kinds,
    u32 palette_count, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kinds, palette_count),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
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
