#ifndef CHICKEN_HH
#define CHICKEN_HH

#include "prelude.h"

#include "livestock.hh"
#include "unknown_types.hh"

struct ChickenMovementState {
    u16 frames_remaining;
    u8 behavior;
    u8 unknown_high_byte;
};

struct Chicken : public Livestock
{
    enum GrowthStage
    {
        STAGE_0,
        STAGE_1,
    };

    Chicken(char const * name, ActorLocation const & location, u32 age, u32 days_fed);
    Chicken(ActorLocation const & location, u32 age, u32 days_fed);

    GrowthStage GetGrowthStage() const;
    bool method_0809BCC0() const;
    void SetFed();
    ProductRank ConsumeProduct();
    void SetMovementState(ChickenMovementState const * param);
    void SetReaction(AnimalReactionPayload const * param);
    void DayUpdate();

    /* +24 */ u32 unk_24;
    /* +28 */ union {
        UnkBarnAnimal2C unk_28;
        ChickenMovementState movement;
        AnimalReactionPayload reaction;
    };
};

#endif // CHICKEN_HH
