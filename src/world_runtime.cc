#include "prelude.h"
#include <algorithm>
#pragma implementation "world_runtime.hh"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "game_world.hh"
#include "entity_auxiliary_sprites.hh"
#include "world_sprite_effects.hh"
#include "scene_sprite.hh"

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

inline GameSceneWorldUnk1028::GameSceneWorldUnk1028()
    : unk_04(0, 0), unk_09(0) {}

GameSceneWorldData::GameSceneWorldData(GameSceneWorldMapOwner source)
    : map(source), unk_194(0), actor_archive(gActorIndexedResourceArchive),
#if defined(REGION_JP)
      unk_DE0(gUnk_083ED9FC),
      unk_E10(gUnk_084A5068),
      unk_E40(gUnk_08480BDC),
      unk_E70(gUnk_084A3678),
      unk_EA0(gUnk_084A4F3C),
      unk_ED0(gUnk_084A4E14),
      unk_F00(gUnk_083ED1BC),
      unk_F30(gUnk_084ADBDC),
      unk_F60(gUnk_084ACE34),
      unk_F90(gUnk_084AD4D0),
      unk_FC0(gUnk_084ABF08),
      unk_FF0(gUnk_08479108)
#else
      unk_DE0(gUnk_086678A0),
      unk_E10(gUnk_0871EF00),
      unk_E40(gUnk_086FAA80),
      unk_E70(gUnk_0871D51C),
      unk_EA0(gUnk_0871EDD4),
      unk_ED0(gUnk_0871ECAC),
      unk_F00(gUnk_08667060),
      unk_F30(gUnk_08727A74),
      unk_F60(gUnk_08726CCC),
      unk_F90(gUnk_08727368),
      unk_FC0(gUnk_08725DA0),
      unk_FF0(gUnk_086F2FAC)
#endif
{
    std::fill(entities, EntitiesEnd(), static_cast<AEntity *>(nullptr));
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
