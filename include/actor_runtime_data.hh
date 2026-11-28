#ifndef ACTOR_RUNTIME_DATA_HH
#define ACTOR_RUNTIME_DATA_HH

#include "actor.hh"
#include "animal.hh"

enum WildDogBehaviorState
{
    WILD_DOG_STATE_INACTIVE,
    WILD_DOG_STATE_DEPARTURE,
    WILD_DOG_STATE_CHASE,
    WILD_DOG_STATE_ATTACK,
    WILD_DOG_STATE_REACTION,
};

struct WildDogDepartureState
{
    u16 retarget_frames;
};

struct WildDogAttackState
{
    u16 frames_remaining;
    u8 attacking;
    u8 target_entity;
};

// The chase remembers a target point between direction refreshes.
struct WildDogChaseState
{
    u32 frames_remaining : 16;
    i32 last_target_x : 16;
    i32 last_target_y : 16;
    u32 attempts_remaining : 8;
    u32 target_entity : 8;
};

union WildDogAttackPayload
{
    u32 raw;
    struct Fields {
        u32 frames_remaining : 16;
        u32 attacking : 8;
        u32 target_entity : 8;
    } fields;
};

union WildDogDeparturePayload
{
    u32 raw;
    struct Fields {
        u32 retarget_frames : 16;
    } fields;
};

struct Unk_Actor_0809BFE8 : Actor
{
    Unk_Actor_0809BFE8();

    u32 unk_08_0 : 7;
    u32 behavior_state;
    union {
        u32 unk_10;
        WildDogChaseState chase;
        WildDogDepartureState departure;
        WildDogAttackState attack;
        AnimalReactionPayload reaction;
    };
};


extern "C" {
unsigned int func_0809C060(Unk_Actor_0809BFE8 const & self);
void func_0809C068(Unk_Actor_0809BFE8 & self, int amount);
void SetWildDogInactiveState(Unk_Actor_0809BFE8 & self, u32 const & value);
void SetWildDogDepartureState(Unk_Actor_0809BFE8 & self, WildDogDeparturePayload const & value);
void SetWildDogChaseState(Unk_Actor_0809BFE8 & self, WildDogChaseState const & value);
void SetWildDogAttackState(Unk_Actor_0809BFE8 & self, WildDogAttackPayload const & value);
void SetWildDogReactionState(Unk_Actor_0809BFE8 & self, AnimalReactionPayload const & value);

// Reset the location to MAP_NONE at (0, 0), select state 0, and restore the
// low seven-bit value to 100. Other payload words and high bits are retained.
void ResetActorRuntimeState(Unk_Actor_0809BFE8 & self);
}


#endif // ACTOR_RUNTIME_DATA_HH
