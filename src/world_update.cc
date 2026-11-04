#include "prelude.h"
#include "game_world.hh"
#include "game_scene.hh"
#include "game_state.hh"
#include "world_sprite_effects.hh"
#include "world_lighting.hh"
#include "world_audio.hh"
#include "field_plot_position_rules.hh"
#include "npc_collection.hh"
#include "player_actor.hh"

#if defined(REGION_JP)
#include "data/scripts/jp/fomt_scripts.mary.h"
#elif defined(REGION_US)
#include "data/scripts/us/fomt_scripts.mary.h"
#elif defined(REGION_EU)
#include "data/scripts/eu/fomt_scripts.mary.h"
#else
#include "data/scripts/de/fomt_scripts.mary.h"
#endif

static inline HardwareMusicPlayerSlot * FindWorldUpdateSoundPlayer(GameSceneSongPlayerPool const & pool)
{
    HardwareMusicPlayerSlot ** current = pool.begin;
    HardwareMusicPlayerSlot ** end = pool.end;
    for (; current != end; ++current) {
        if (!(*current)->IsUnpaused())
            return *current;
    }
    return *(end - 1);
}

inline void GameSceneWorldUnk1028::Reset(IndexedResourceProvider * resource, u32 index,
    GameObject * world, Vec2 const & position)
{
    unk_04 = position;
    value = nullptr;
    unk_08 = 0;
    value = new GameSceneIndexedSprite(resource, index, world, 2, 3, false);
}

void GameSceneWorld::Update(GameObjectUpdateContext const & input)
{
    u32 previous_condition = func_0800E4FC(save->farmer);
    if (unk_10C8 != 0) {
        unk_10C8 = 0;
        vfunc_3C(ENTITY_BALL);
        func_0800ED2C(save->farmer);
        Location const & location = save->ball_location;
        if (unk_10C9 == 0) {
            FindWorldUpdateSoundPlayer(GetSongPlayerPool())->Start(AUDIO_SFX_THROWN_ITEM_LANDS);
            if (GetFieldPlotPositionRuleResult(location) != 2) {
                func_080A1484(save->npcs, location, save->event_state);
                Vec2 position(location.x, location.y);
                data.unk_1028.Reset(vfunc_64(), 0x1A9, this, position);
            } else {
                QueueScript(GameSceneScriptRequest(
                    EventScript_NPCEvent_HarvestGoddess_OfferingsAndMatchmakingChoices, 0), 0);
            }
        }
    }

    PlayerActor * player = static_cast<PlayerActor *>(GetEntity(ENTITY_PLAYER));
    data.map->Update();
    u32 map_flags = GetMapData(data.map.value->map_data_id)->flags;
    u32 current_map = data.map.value->map;
    bool minute_advanced = false;
    if (!updates_suspended && !save->scripted_npc_control && map_flags == 0 && !player->IsClockPausedByAction()) {
        if (calendar.Tick(25)) {
            GameCalendar current = calendar.Value();
            u32 hour = current.time.clock_hour;
            u32 minute = current.time.clock_minute;
            if (hour == 6 && minute == 0) {
                if (!player->ChangeStaminaAndFatigue(0, 10)) {
                    QueueScript(GameSceneScriptRequest(
                        EventScript_SystemEvent_ReturnHomeAndAdvanceToNextDay, 0), 2);
                }
            } else {
                UpdateWorldTimeOfDayPalettes(*this, hour, minute, 0);
                if (hour == 20 && minute == 0) {
                    scene->PlaySong(0, AUDIO_SEQUENCE_158);
                    UpdateWorldBackgroundAudio(*this);
                } else if (hour == 0 && minute == 0) {
                    player->ChangeStaminaAndFatigue(0, 3);
                } else if (hour == 2 && minute == 0) {
                    player->ChangeStaminaAndFatigue(0, 4);
                } else if (hour == 4 && minute == 0) {
                    player->ChangeStaminaAndFatigue(0, 5);
                }
            }
            minute_advanced = true;
        }
    }
    AEntity ** entity = data.entities;
    AEntity ** entity_end = data.entities + ARRAY_COUNT(data.entities);
    EntityUpdateContext context(input.input, minute_advanced);
    for (; entity != entity_end; ++entity) {
        AEntity * const value = *entity;
        if (value != nullptr) {
            if (value->IsNormalUpdateSuspended())
                value->UpdateWhileSuspended(context);
            else if (map_flags == 0 || current_map == value->GetMap())
                value->Update(context);
        }
    }
    if (weather_effect.Get() != nullptr)
        weather_effect->UpdateParticles();
    if (data.sprite_effects.Get() != nullptr)
        data.sprite_effects->Update();
    for (u32 index = 0; index < ARRAY_COUNT(hill_seasonal_sprites); ++index) {
        if (hill_seasonal_sprites[index].Get() != nullptr)
            hill_seasonal_sprites[index]->UpdateAnimation();
    }
    for (u32 index = 0; index < ARRAY_COUNT(winter_and_fireplace_sprites); ++index) {
        if (winter_and_fireplace_sprites[index].Get() != nullptr)
            winter_and_fireplace_sprites[index]->UpdateAnimation();
    }
    for (u32 index = 0; index < ARRAY_COUNT(unk_1080); ++index) {
        GameSceneWorldUnk1080Entry & entry = unk_1080[index];
        if (entry.State() != 1)
            continue;
        switch (entry.phase) {
        case 0:
            if (entry.unk_08->UpdateAnimation().flags.wrapped) {
                entry.phase = 1;
                GameSceneIndexedSprite * sprite = entry.unk_08.Get();
                sprite->SetAnimation(0x86B);
                entry.unk_00 = 120;
            }
            break;
        case 1:
            if (--entry.unk_00 == 0) {
                entry.phase = 2;
                GameSceneIndexedSprite * sprite = entry.unk_08.Get();
                sprite->SetAnimation(0x873);
            }
            break;
        case 2:
            if (entry.unk_08->UpdateAnimation().flags.wrapped) {
                entry.state = 0;
                entry.unk_08 = nullptr;
            }
            break;
        }
    }
    if (!updates_suspended) {
        AEntity * player = data.entities[ENTITY_PLAYER];
        SetWorldMapCameraPosition(data.map.value, player->GetQ16X() >> 16, player->GetQ16Y() >> 16);
    }
    if (func_0800E4FC(save->farmer) != previous_condition && scene->IsBackgroundMusicActive()
        && !save->event_state.HasRegisteredEvents())
        UpdateWorldBackgroundAudio(*this);
}
