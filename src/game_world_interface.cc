#include "game_world_interface.hh"
#include "game_world.hh"
#include "game_state_types.hh"
#include "world_saved_map.hh"
#include <new>
#include <iterator>

EC GameSceneWorldInstanceOwner CreateGameWorld(GameStateSaveImage * save, GameScene * scene, bool unk)
{
    return GameSceneWorldInstanceOwner(new GameSceneWorld(save, scene,
        GameSceneWorldMapOwner(new GameSceneSavedMap(save)), unk));
}

EC IndexedResourceArchive * func_0801FBDC(GameSceneWorld & world)
{
    return &world.data.unk_FF0;
}

IndexedResourceArchive * GameSceneWorld::vfunc_7C()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_FC0;
}

IndexedResourceArchive * GameSceneWorld::vfunc_78()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_F90;
}

IndexedResourceArchive * GameSceneWorld::vfunc_74()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_F60;
}

IndexedResourceArchive * GameSceneWorld::vfunc_70()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_F30;
}

EC IndexedResourceArchive * GetWorldMapSpriteArchive(GameSceneWorld & world)
{
    return world.data.GetMapSpriteArchive();
}

EC IndexedResourceArchive * func_0801FC24(GameSceneWorld & world)
{
    return &world.data.unk_ED0;
}

EC IndexedResourceArchive * func_0801FC30(GameSceneWorld & world)
{
    return &world.data.unk_EA0;
}

IndexedResourceArchive * GameSceneWorld::vfunc_6C()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_E70;
}

IndexedResourceArchive * GameSceneWorld::vfunc_60()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_E40;
}

IndexedResourceArchive * GameSceneWorld::vfunc_5C()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_E10;
}

IndexedResourceArchive * GameSceneWorld::vfunc_64()
{
    GameSceneWorld & world = *this;
    return &world.data.unk_DE0;
}

IndexedResourceArchive * GameSceneWorld::vfunc_68()
{
    GameSceneWorld & world = *this;
    return &world.data.actor_archive;
}

EC void ClearWorldWeatherEffect(GameSceneWorld & world)
{
    world.weather_effect = nullptr;
}

EC GameSceneWorldMap * func_0801FC9C(GameSceneWorld & world)
{
    return world.data.map.value;
}

EC GameSceneWorldMap * func_0801FCA0(GameSceneWorld & world)
{
    return world.data.map.value;
}

GameStateClock const * GameSceneWorld::GetClock()
{
    GameSceneWorld const & world = *this;
    return &world.save->clock;
}

i32 GameSceneWorld::GetSpritePaletteBank(u32 index)
{
    GameSceneWorld & world = *this;
    GameScenePaletteCache & cache = world.data.palette_cache;
    u8 & encoded = cache.encoded_palette_banks[index];
    i32 bank = encoded - 16;
    if (bank < 0) {
        bank = cache.AcquirePaletteBank(index);
        encoded = bank + 16;
    }
    return bank;
}

void GameSceneWorld::ClearSpritePaletteResourceFlag(u32 index)
{
    GameSceneWorld & world = *this;
    world.data.palette_cache.resources[index].claimed = 0;
}

AEntity * GameSceneWorld::GetEntity(u32 index) const
{
    AEntity * const * first = data.entities;
    std::advance(first, index);
    return *first;
}

AEntity * GameSceneWorld::GetEntity(u32 index)
{
    AEntity ** first = data.entities;
    std::advance(first, index);
    return *first;
}

void GameSceneWorld::vfunc_3C(u32 index)
{
    GameSceneWorld & world = *this;
    AEntity ** entity = world.data.entities;
    std::advance(entity, index);
    if (*entity != nullptr) {
        delete *entity;
        *entity = nullptr;
    }
}

EntityAuxiliarySprites * GameSceneWorld::GetEntityAuxiliarySprites()
{
    GameSceneWorld & world = *this;
    return world.data.entity_auxiliary_sprites.Get();
}

bool GameSceneWorld::IsCameraMovementComplete()
{
    GameSceneWorld const & world = *this;
    return IsWorldMapCameraMovementComplete(world.data.map.value);
}

i32 GameSceneWorld::GetCameraY()
{
    GameSceneWorld const & world = *this;
    return world.data.map.value->y.parts.integer;
}

i32 GameSceneWorld::GetCameraX()
{
    GameSceneWorld const & world = *this;
    return world.data.map.value->x.parts.integer;
}

u32 GameSceneWorld::vfunc_14()
{
    GameSceneWorld const & world = *this;
    return world.data.map.value->map;
}

void GameSceneWorld::PanCameraTo(i32 x, i32 y, u32 speed)
{
    GameSceneWorld & world = *this;
    PanWorldMapCameraTo(world.data.map.value, x, y, speed);
}

void GameSceneWorld::SetCameraPosition(i32 x, i32 y)
{
    GameSceneWorld & world = *this;
    SetWorldMapCameraPosition(world.data.map.value, x, y);
}
