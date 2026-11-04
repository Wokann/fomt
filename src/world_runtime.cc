#include "prelude.h"
#pragma implementation "world_runtime.hh"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "game_world.hh"
#include "entity_auxiliary_sprites.hh"
#include "world_sprite_effects.hh"

EC i32 GetWorldSpritePaletteBank(GameSceneWorld & world, u32 index)
{
    GameScenePaletteCache & cache = world.data.palette_cache;
    u8 & encoded = cache.encoded_palette_banks[index];
    i32 bank = encoded - 16;
    if (bank < 0) {
        bank = cache.AcquirePaletteBank(index);
        encoded = bank + 16;
    }
    return bank;
}

EC void ClearWorldSpritePaletteResourceFlag(GameSceneWorld & world, u32 index)
{
    world.data.palette_cache.resources[index].unk_81 = 0;
}

GameSceneWorldData::~GameSceneWorldData()
{
    u32 index = 0;
    AEntity ** current = entities;
    for (; index < ARRAY_COUNT(entities); ++index) {
        delete *current;
        ++current;
    }
}
