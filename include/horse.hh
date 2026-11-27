#ifndef HORSE_HH
#define HORSE_HH

#include "prelude.h"

#include "pet.hh"
#include "unknown_types.hh"

// Movement commands preserve the unread upper byte when changing their
// countdown and behavior. Call/bell approach uses a separate eight-byte state.
struct HorseMovementState {
    u32 frames_remaining : 16;
    u32 behavior : 8;
    u32 unknown_high_byte : 8;
};

struct Horse : public Pet
{
    enum GrowthStage
    {
        STAGE_0,
        STAGE_1,
    };

    Horse(char const * name, ActorLocation const & location, u32 age);
    Horse(ActorLocation const & location, u32 age);

    GrowthStage GetGrowthStage() const;
    void SetMovementState(HorseMovementState const * param);
    void SetApproachState(AnimalApproachPayload const * param);
    void SetPushedState(UnkBarnAnimal2C const * command);
    void DayUpdate();

    /* +20 */ u32 unk_20;
    /* +24 */ union {
        HorseMovementState movement;
        AnimalApproachPayload approach;
    };
};

#endif // HORSE_HH
