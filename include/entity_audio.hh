#ifndef ENTITY_AUDIO_HH
#define ENTITY_AUDIO_HH

#include "entity_actor.hh"

// This native actor layer latches one sound request until its next update.
// Its additional virtual interface remains in the original full ROM table.
struct AudioActorEntity : AActorEntity {
    AudioActorEntity(GameObject * game_object, ActorLocation const & location, u32 animation);
    virtual Box GetBox() const;
    virtual void Update(EntityUpdateContext const & context);
    void RequestSound(u32 song_id);

    bool sound_requested;
};

typedef char AudioActorEntityFlagCheck[offsetof(AudioActorEntity, sound_requested) == 0x30 ? 1 : -1];
typedef char AudioActorEntitySizeCheck[sizeof(AudioActorEntity) == 0x34 ? 1 : -1];

EXTERN_C
Box MakeAudioActorBounds(i32 x, i32 y);
EXTERN_C_END

#endif
