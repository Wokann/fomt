#include "world_audio.hh"
#include "game_world.hh"
#include "game_scene.hh"
#include "game_state.hh"
#include "fomt_constants.hh"

EC u32 SelectWorldBackgroundAudio(GameSceneWorldPrefix & world)
{
    GameStateClock const & clock = world.save->clock;
    if (clock.unk_00 == WEATHER_RAIN)
        return AUDIO_AMBIENCE_RAIN;
    if (clock.unk_00 == WEATHER_TYPHOON || clock.unk_00 == WEATHER_SNOWSTORM)
        return AUDIO_AMBIENCE_STORM;

    RecordPlayer * record_player = world.save->farm.farm_house.GetRecordPlayer();
    u32 map = world.vfunc_14();
    if (map >= MAP_SPRING_MINE_FLOOR_0 && map <= MAP_LAKE_MINE_FLOOR_255)
        map = MAP_FARM;
    switch (map) {
    case MAP_MOTHERS_HILL_MIDDLE:
    case MAP_FARM:
    case MAP_FOREST:
    case MAP_MOTHERS_HILL_SUMMIT:
    case MAP_HORSE_STABLE:
    case MAP_CHICKEN_COOP:
    case MAP_MOUNTAIN_COTTAGE:
    case MAP_FARMHOUSE:
    case MAP_BARN:
    case MAP_LAKE_MINE_ENTRANCE:
    {
        u8 hour = clock.calendar.time.clock_hour;
        if (static_cast<u8>(hour - 6) <= 13) {
            if (record_player != nullptr && record_player->HasAlbum())
                return record_player->GetAudioSequenceId();
            switch (static_cast<i32>(func_0800E324(clock.calendar))) {
            case SEASON_SPRING:
            default:
                return AUDIO_BGM_SPRING;
            case SEASON_SUMMER:
                return AUDIO_BGM_SUMMER;
            case SEASON_FALL:
                return AUDIO_BGM_AUTUMN;
            case SEASON_WINTER:
                return AUDIO_BGM_WINTER;
            }
        }
        goto night;
    }
    case MAP_MINERAL_BEACH:
    case MAP_ZACK_HOUSE:
    case MAP_BEACH_HOUSE:
    case MAP_KAI_RESTAURANT:
        return AUDIO_AMBIENCE_BEACH;
    }
    {
        u8 hour = clock.calendar.time.clock_hour;
        if (static_cast<u8>(hour - 6) <= 13)
            return AUDIO_BGM_MINERAL_TOWN;
    }
night:
    return AUDIO_AMBIENCE_NIGHT;
}

EC GameSceneSongPlayerPool & GetWorldSongPlayerPool(GameSceneWorldPrefix & world)
{
    return GetSceneSongPlayerPool(*world.scene);
}

EC void UpdateWorldBackgroundAudio(GameSceneWorldPrefix & world)
{
    GameSceneBgmSettings settings;
    i32 map = world.vfunc_14();
    if ((map >= MAP_SPRING_MINE_FLOOR_0 && map <= MAP_LAKE_MINE_FLOOR_255)
        || map == MAP_LAKE_MINE_ENTRANCE) {
        i32 floor;
        if (map != MAP_LAKE_MINE_ENTRANCE) {
            if (map > MAP_SPRING_MINE_FLOOR_255)
                floor = map - MAP_LAKE_MINE_FLOOR_0;
            else
                floor = map - MAP_SPRING_MINE_FLOOR_0;
        } else {
            floor = 9;
        }
        i32 pitch = settings.pitch;
        settings.pitch = pitch + (-0xA00 - pitch) * (floor + 1) / 0x100;
    }
    i32 fatigue = func_0800E4FC(world.save->farmer);
    if (fatigue > 79) {
        settings.modulation_depth = fatigue - 79;
        settings.lfo_speed = 3;
    }
    GameScene * scene = world.scene;
    u32 sequence = world.GetDefaultAudioSequence();
    scene->PlayBGM(AUDIO_START_WEAK, sequence, settings);
}
