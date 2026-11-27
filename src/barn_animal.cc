#include "barn_animal.hh"

BarnAnimal::BarnAnimal(char const * name, ActorLocation const & location, u32 age, u32 days_fed)
    : Livestock(name, location, age, days_fed)
{
    pregnant = false;
    days_pregnant = 0;
    days_pregnant_healthy = 0;
    state = STATE_MOVEMENT;
    movement.frames_remaining = 0;
    movement.behavior = 0;
}

BarnAnimal::BarnAnimal(ActorLocation const & location, u32 age, u32 days_fed)
    : Livestock(location, age, days_fed)
{
    pregnant = false;
    days_pregnant = 0;
    days_pregnant_healthy = 0;
    state = STATE_MOVEMENT;
    movement.frames_remaining = 0;
    movement.behavior = 0;
}

bool BarnAnimal::IsPregnant() const
{
    return pregnant;
}

u32 BarnAnimal::GetDaysPregnant() const
{
    if (!pregnant)
        return 0;
    else
        return days_pregnant;
}

u32 BarnAnimal::GetDaysPregnantHealthy() const
{
    if (!pregnant)
        return 0;
    else
        return days_pregnant_healthy;
}

void BarnAnimal::SetFed()
{
    Livestock::SetFed();
}

void BarnAnimal::StartPregnancy()
{
    pregnant = true;
    days_pregnant = 0;
    days_pregnant_healthy = 0;
}

void BarnAnimal::ResetPregnancy()
{
    pregnant = false;
    days_pregnant = 0;
    days_pregnant_healthy = 0;
}

void BarnAnimal::SetMovementState(BarnAnimalMovementState const * param)
{
    movement = *param;
    state = STATE_MOVEMENT;
}

void BarnAnimal::SetReaction(AnimalReactionPayload const * param)
{
    reaction = *param;
    state = STATE_REACTION;
}

void BarnAnimal::SetApproachState(AnimalApproachPayload const * param)
{
    approach = *param;
    state = STATE_APPROACH;
}

void BarnAnimal::SetPushedState(UnkBarnAnimal2C const *)
{
    state = STATE_PUSHED;
}

void BarnAnimal::DayUpdate(LivestockDayUpdateInfo const * info)
{
    Livestock::DayUpdate(info);

    if (IsPregnant())
    {
        if (days_pregnant < 31)
            days_pregnant++;

        if (!IsSick())
        {
            if (days_pregnant_healthy < 31)
                days_pregnant_healthy++;
        }
    }
}
