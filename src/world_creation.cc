#include "prelude.h"
#include "game_scene.hh"
#include "world_creation.hh"
#include "game_state.hh"
#include "world_sprite_effects.hh"
#include "entity_auxiliary_sprites.hh"
#include "world_lighting.hh"
#include "world_audio.hh"
#include "world_map_sprites.hh"
#include "world_furniture.hh"
#include "world_control.hh"
#include "farm_terrain.hh"

void GameScene::RebuildMapEntitiesForNewDay()
{
    GameSceneState * current = state;
    current->game_object = nullptr;
    current->save->DayUpdate();
    current->game_object = CreateGameWorld(current->save, current->scene, false);
    current->game_object.value->vfunc_138();
    PlayerActor * player = static_cast<PlayerActor *>(current->game_object.value->GetEntity(ENTITY_PLAYER));
    GameScenePreservedPlayerLocation & preserved =
        reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C)->preserved_player_location;
    if (preserved.active != 0) {
        u32 hour = preserved.time.GetHour();
        i32 elapsed = (hour <= 5 ? 6 : 30) - hour;
        player->ChangeStaminaAndFatigue(7 * elapsed, -2 * elapsed);
    }
}

EC GameSceneWorldInstanceOwner CreateGameWorld(GameStateSaveImage * save, GameScene * scene, bool unk)
{
    return GameSceneWorldInstanceOwner(new GameSceneWorld(save, scene,
        GameSceneWorldMapOwner(new GameSceneSavedMap(save)), unk));
}

static inline u32 InitialWorldClockHour(GameCalendar value)
{
    return value.time.clock_hour;
}

static inline u32 InitialWorldPaletteBlend(GameCalendar value,
    GameStateSaveImage * const & save_source, i32 const & period)
{
    u8 hour = value.time.clock_hour;
    u8 minute = value.time.clock_minute;
    u32 season = GetCalendarEffectiveSeason(save_source->clock.calendar);
    return GetTimeOfDayTransitionValue(hour, minute, season,
        static_cast<TimeOfDayPeriod>(period));
}

static inline i32 InitialWorldWeather(MaryMapId map, u32 const & current_weather)
{
    switch (map) {
    case MAP_MOTHERS_HILL_SUMMIT_CLEAR:
    case MAP_MOTHERS_HILL_SUMMIT_RAIN: return WEATHER_SUNNY;
    case MAP_MOTHERS_HILL_SUMMIT_SNOW: return WEATHER_RAIN;
    case MAP_TUTORIAL_FIELD: return WEATHER_SNOW;
    default: return current_weather;
    }
}

GameSceneWorld::GameSceneWorld(GameStateSaveImage * input_save, GameScene * input_scene,
    GameSceneWorldMapOwner input_map, bool unk)
    : data(input_map), save(input_save), updates_suspended(0),
      calendar(save->clock.calendar),
      time_of_day_period(GetWorldTimeOfDayPeriod(*this, InitialWorldClockHour(calendar.Value()))),
      time_palette_blend(InitialWorldPaletteBlend(calendar.Value(), save, time_of_day_period)),
      farm_tile_attributes(new FieldRenderTileAttributes[128 * 88]),
      scene(input_scene), unk_10C8(0)
{
    data.map->SetLocation(save->farmer.GetLocation(), time_of_day_period,
        time_palette_blend, 30 - time_palette_blend);
    if (data.map.value->map != MAP_FARM) {
        InitializeFarmTerrain(farm_tile_attributes, save->farm,
            GetCalendarEffectiveSeason(save->clock.calendar) == SEASON_WINTER);
    }
    if (unk) {
        if (!save->event_state.HasRegisteredEvents() || !scene->IsBackgroundMusicActive())
            UpdateWorldBackgroundAudio(*this);
    }
    data.entity_auxiliary_sprites = new EntityAuxiliarySprites(this);
    data.sprite_effects = nullptr;
    data.sprite_effects = new WorldSpriteEffects(this, data.map.value->map_data_id);
    for (u32 index = 0; index < ARRAY_COUNT(data.entities); ++index)
        RefreshWorldEntitySlot(*this, index);

    WeatherEffectOwner() = nullptr;
    if (GetMapData(data.map.value->map_data_id)->flags == 0) {
        i32 weather = InitialWorldWeather(static_cast<MaryMapId>(data.map.value->map),
            save->clock.weather_today);
        switch (weather) {
        case WEATHER_RAIN:
            SetWorldWeatherEffect(*this, GameSceneWeatherEffect::RAIN);
            break;
        case WEATHER_SNOW:
            SetWorldWeatherEffect(*this, GameSceneWeatherEffect::SNOW);
            break;
        }
    }
    RefreshWorldFireplaceSprite(*this);
    RefreshWorldVase(*this);
    RefreshWorldBeachHouseSprite(*this);
    RefreshWorldHillSeasonalSprites(*this);
    RefreshWorldWinterAndFireplaceSprites(*this);

    GameSceneScriptController * controller = reinterpret_cast<GameSceneScriptController *>(gUnk_0300040C);
    u32 index = 0;
    do {
        GameSceneEventIconRecord const & record = controller->event_icon_records[index];
        if (record.State() == 1 && record.location.map == data.map.value->map) {
            event_icon_sprites[index] = new GameSceneGroupSprite(&data.unk_DE0,
                record.icon_id, this, 2, 0x1B);
        }
    } while (++index < controller->EventIconRecordCount());
    if (input_save->scripted_npc_control != 0) {
        SuspendWorldUpdates(*this);
        ResumeWorldUpdates(*this);
    }
}
