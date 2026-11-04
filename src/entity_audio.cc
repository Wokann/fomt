#include "entity_audio.hh"
#include "game_world.hh"
#include "game_scene.hh"

AudioActorEntity::AudioActorEntity(GameObject * game_object, ActorLocation const & location, u32 animation)
    : AActorEntity(game_object, location, 2, animation), sound_requested(false)
{
}

static inline HardwareMusicPlayerSlot * FindActorSoundPlayer(GameSceneSongPlayerPool const & pool)
{
    HardwareMusicPlayerSlot ** current = pool.begin;
    HardwareMusicPlayerSlot ** end = pool.end;
    for (; current != end; ++current) {
        if (!(*current)->IsUnpaused())
            return *current;
    }
    // Native callers provide a nonempty pool; saturation reuses its last slot.
    return *(end - 1);
}

void AudioActorEntity::RequestSound(u32 song_id)
{
    if (sound_requested || !IsOnCurrentMap())
        return;
    GameSceneSongPlayerPool & pool =
        static_cast<GameSceneWorld *>(game_object)->GetSongPlayerPool();
    FindActorSoundPlayer(pool)->Start(song_id);
    sound_requested = true;
}

Box AudioActorEntity::GetBox() const
{
    return Box(-7, -9, 7, 5, x_q16 >> 16, y_q16 >> 16);
}

void AudioActorEntity::Update(EntityUpdateContext const & context)
{
    sound_requested = false;
    if (animation_countdown != 0)
        --animation_countdown;
    else
        animation_countdown = animation_reload;
    EntityVisualController * visual = unk_10.Get();
    if (visual != nullptr)
        visual->Update();
}

EC Box MakeAudioActorBounds(i32 x, i32 y)
{
    return Box(-7, -9, 7, 5, x, y);
}
