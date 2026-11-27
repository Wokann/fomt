#include "horse.hh"

Horse::Horse(char const * name, ActorLocation const & location, u32 age)
    : Pet(name, location, age)
{
    unk_20 = 0;
    movement.frames_remaining = 0;
    movement.behavior = 0;
}

Horse::Horse(ActorLocation const & location, u32 age)
    : Pet(location, age)
{
    unk_20 = 0;
    movement.frames_remaining = 0;
    movement.behavior = 0;
}

Horse::GrowthStage Horse::GetGrowthStage() const
{
    return GetAge() < 120 ? STAGE_0 : STAGE_1;
}

void Horse::SetMovementState(HorseMovementState const * param)
{
    movement = *param;
    unk_20 = 0;
}

void Horse::SetApproachState(AnimalApproachPayload const * param)
{
    approach = *param;
    unk_20 = 1;
}

void Horse::SetPushedState(UnkBarnAnimal2C const *)
{
    unk_20 = 2;
}

void Horse::DayUpdate()
{
    Pet::DayUpdate(false);

    unk_20 = 0;
    movement.frames_remaining = 0;
    movement.behavior = 0;
}
