#include "prelude.h"
#pragma implementation "world_runtime.hh"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "game_world.hh"

GameSceneWorldUnk1020::~GameSceneWorldUnk1020()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->ClearSpritePaletteResourceFlag(indices[0]);
}

EC i32 GetWorldSpritePaletteBank(GameSceneWorldPrefix & world, u32 index)
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

EC void ClearWorldSpritePaletteResourceFlag(GameSceneWorldPrefix & world, u32 index)
{
    world.data.palette_cache.resources[index].unk_81 = 0;
}
