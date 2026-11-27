#ifndef BARN_ANIMAL_HH
#define BARN_ANIMAL_HH

#include "prelude.h"

#include "livestock.hh"
#include "unknown_types.hh"

// Ordinary movement uses only the first word of the saved state payload.
struct BarnAnimalMovementState
{
    u16 frames_remaining;
    u8 behavior;
    u8 unknown_03;
};

struct BarnAnimal : public Livestock
{
    enum State
    {
        STATE_MOVEMENT,
        STATE_REACTION,
        STATE_APPROACH,
        STATE_PUSHED,
    };

    BarnAnimal(char const * name, ActorLocation const & location, u32 age, u32 days_fed);
    BarnAnimal(ActorLocation const & location, u32 age, u32 days_fed);

    bool IsPregnant() const;
    u32 GetDaysPregnant() const;
    u32 GetDaysPregnantHealthy() const;
    void SetFed();
    void StartPregnancy();
    void ResetPregnancy();
    void SetMovementState(BarnAnimalMovementState const * param);
    void SetReaction(AnimalReactionPayload const * param);
    void SetApproachState(AnimalApproachPayload const * param);
    void SetPushedState(UnkBarnAnimal2C const * command);
    void DayUpdate(LivestockDayUpdateInfo const * info);

    /* +24 */ bool pregnant : 1;
    /* +24 */ u32 days_pregnant : 5;
    /* +24 */ u32 days_pregnant_healthy : 5;
    /* +28 */ u32 state;
    /* +2C */ union {
        BarnAnimalMovementState movement;
        AnimalApproachPayload approach;
        AnimalReactionPayload reaction;
    };
};

#endif // BARN_ANIMAL_HH
