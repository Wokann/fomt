#include "chicken.hh"
#include "livestock_day_update_data.hh"

#include <stdlib.h> // rand

Chicken::Chicken(char const * name, ActorLocation const & location, u32 age, u32 days_fed)
    : Livestock(name, location, age, days_fed)
{
    unk_24 = 0;
    unk_28.unk_00 = 0;
    unk_28.unk_02 = 0;
}

Chicken::Chicken(ActorLocation const & location, u32 age, u32 days_fed)
    : Livestock(location, age, days_fed)
{
    unk_24 = 0;
    unk_28.unk_00 = 0;
    unk_28.unk_02 = 0;
}

Chicken::GrowthStage Chicken::GetGrowthStage() const
{
    if (GetAge() < 7)
        return STAGE_0;
    else
        return STAGE_1;
}

bool Chicken::method_0809BCC0() const
{
    return GetGrowthStage() == STAGE_1 && !IsSick() && !IsUnhappy();
}

void Chicken::SetFed()
{
    Livestock::SetFed();
}

Livestock::ProductRank Chicken::ConsumeProduct()
{
    ProductRank rank = GetProductRank();

    if (rank == PRODUCT_RANK_4)
    {
        ProductRank temp;

        if (rand() % 255 != 0)
            temp = PRODUCT_RANK_4;
        else
            temp = PRODUCT_RANK_5;

        rank = temp;
    }

    return rank;
}

void Chicken::SetMovementState(ChickenMovementState const * param)
{
    movement = *param;
    unk_24 = 0;
}

void Chicken::SetReaction(AnimalReactionPayload const * param)
{
    reaction = *param;
    unk_24 = 1;
}

void Chicken::DayUpdate()
{
    Livestock::DayUpdate(&gChickenDayUpdateInfo);
}
