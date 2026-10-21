#include "game_scene.hh"
#include "scene_audio.hh"
#include "hardware_song.hh"

static inline void StartSceneSong(HardwareMusicPlayerSlot * player, i32 mode, u16 song_id)
{
    switch (mode) {
    case AUDIO_START:
        player->Start(song_id);
        break;
    case AUDIO_START_WEAK:
        player->StartIfChangedOrInactive(song_id);
        break;
    case AUDIO_START_OR_CONTINUE:
        player->StartOrContinue(song_id);
        break;
    }
}

static inline HardwareMusicPlayerSlot * FindAvailableSceneSongPlayer(GameSceneSongPlayerPool & pool)
{
    HardwareMusicPlayerSlot ** it = pool.begin;
    HardwareMusicPlayerSlot ** end = pool.end;
    for (; it != end; ++it) {
        if (static_cast<u8>((*it)->IsActive()) == 0)
            return *it;
    }
    // The native path assumes a nonempty pool and reuses its final entry.
    return *(end - 1);
}

static inline void ApplySceneBgmSettings(GameSceneBgmSettings const & settings, HardwareMusicPlayerSlot * player)
{
    player->InitializeImmediately();
    player->SetTempo(settings.tempo);
    player->SetVolume(settings.volume, 0xFFFF);
    player->SetPitch(settings.pitch, 0xFFFF);
    player->SetPan(settings.pan, 0xFFFF);
    player->SetModulationDepth(settings.modulation_depth, 0xFFFF);
    player->SetLfoSpeed(settings.lfo_speed, 0xFFFF);
}

void GameScene::PlayBGM(i32 mode, u32 sequence, GameSceneBgmSettings const & settings)
{
    GameSceneState * current = state;
    StartSceneSong(&current->bgm_player, mode, static_cast<u16>(sequence));
    ApplySceneBgmSettings(settings, &current->bgm_player);
}

void GameScene::StopBGM()
{
    state->bgm_player.Stop();
}

void GameScene::PlaySong(i32 mode, u32 sequence)
{
    HardwareMusicPlayerSlot * player = FindAvailableSceneSongPlayer(state->song_players);
    StartSceneSong(player, mode, static_cast<u16>(sequence));
}

void GameScene::StopAllSongs()
{
    func_08008DE8();
}

EC GameSceneSongPlayerPool & GetSceneSongPlayerPool(GameScene & scene)
{
    return scene.state->song_players;
}

void GameScene::StartWorldBackgroundMusic()
{
    GameSceneState * current = state;
    HardwareMusicPlayerSlot & player = current->bgm_player;
    u32 sequence = static_cast<GameSceneWorldPrefix *>(current->game_object.value)->GetDefaultAudioSequence();
    player.StartIfChangedOrInactive(static_cast<u16>(sequence));
}

bool GameScene::FadeOutBackgroundMusic()
{
    HardwareMusicPlayerSlot & player = state->bgm_player;
    bool requested;
    if (static_cast<u8>(player.IsActive()) != 0) {
        player.FadeOut(5);
        requested = true;
    } else {
        requested = false;
    }
    return requested;
}

u32 GameScene::IsBackgroundMusicActive()
{
    // Preserve the native word-returning music-player query.
    return state->bgm_player.IsActive();
}
