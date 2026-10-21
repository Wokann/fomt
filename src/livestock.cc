#include "livestock.hh"

#include <cstdlib>
#include <algorithm>

Livestock::Livestock(char const * name, ActorLocation const & location, u32 age, u32 days_fed)
    : Animal(name, location, age)
{
    this->days_fed = days_fed;
    fed = false;
    unhappy = false;
    sick = false;
    life_state = LIVESTOCK_LIFE_STATE_ALIVE;
    days_unhappy = 0;
    days_sick = 0;
    current_outdoor_minutes = 0;
    total_outdoor_minutes = 0;
}

Livestock::Livestock(ActorLocation const & location, u32 age, u32 days_fed)
    : Animal(location, age)
{
    this->days_fed = days_fed;
    fed = false;
    unhappy = false;
    sick = false;
    life_state = LIVESTOCK_LIFE_STATE_ALIVE;
    days_unhappy = 0;
    days_sick = 0;
    current_outdoor_minutes = 0;
    total_outdoor_minutes = 0;
}

u32 Livestock::GetDaysFed() const
{
    return days_fed;
}

bool Livestock::HasBeenFed() const
{
    return fed;
}

bool Livestock::IsUnhappy() const
{
    return unhappy;
}

bool Livestock::IsSick() const
{
    return sick;
}

MaryLivestockLifeState Livestock::GetLifeState() const
{
    return static_cast<MaryLivestockLifeState>(life_state);
}

u32 Livestock::GetCurrentOutdoorMinutes() const
{
    return current_outdoor_minutes;
}

u32 Livestock::GetOutdoorMinutes() const
{
    return total_outdoor_minutes;
}

Livestock::ProductRank Livestock::GetProductRank() const
{
    u32 affection = GetAffection();

    // 0-3 Hearts
    if (affection <= 100)
        return PRODUCT_RANK_0;

    // 4-7 Hearts
    if (affection <= 200)
        return PRODUCT_RANK_1;

    // Festival winner + 8-10 Hearts
    if (IsFestivalWinner())
    {
        // 600 outdoor hours
        if (GetOutdoorMinutes() >= 600 * 60)
            return PRODUCT_RANK_4;
        else
            return PRODUCT_RANK_3;
    }

    // 8-10 Hearts
    return PRODUCT_RANK_2;
}

void Livestock::AddOutdoorMinutes(u32 minutes)
{
    // TODO: magic constants

    if (current_outdoor_minutes < 511)
    {
        current_outdoor_minutes = std::min<u32>(current_outdoor_minutes + minutes, 511);
    }

    if (total_outdoor_minutes < 0xFFFF)
    {
        total_outdoor_minutes = std::min<u32>(total_outdoor_minutes + minutes, 0xFFFF);
    }
}

void Livestock::ResetCurrentOutdoorMinutes()
{
    current_outdoor_minutes = 0;
}

void Livestock::SetSick()
{
    sick = true;
}

void Livestock::ResetSick()
{
    sick = false;
    days_sick = 0;
}

void Livestock::SetUnhappy()
{
    unhappy = true;
}

void Livestock::ResetUnhappy()
{
    unhappy = false;
    days_unhappy = 0;
}

void Livestock::SetFed()
{
    if (!fed)
        fed = true;
}

void Livestock::DayUpdate(LivestockDayUpdateInfo const * info)
{
    Animal::DayUpdate();

    bool was_fed = fed;

    if (was_fed)
    {
        if (days_fed < 31)
            days_fed++;

        fed = false;
    }

    current_outdoor_minutes = 0;

    if (unhappy)
    {
        if (was_fed)
        {
            if (rand() % 100 < info->fed_happy_rate)
                unhappy = false;
        }
    }
    else
    {
        if (!was_fed)
        {
            if (rand() % 100 < info->unfed_unhappy_rate)
                unhappy = true;
        }
    }

    if (unhappy)
    {
        u32 tmp = days_unhappy;
        if (tmp < 7)
        {
            tmp++;
            days_unhappy = tmp;
        }
    }
    else
    {
        days_unhappy = 0;
    }

    if (!sick)
    {
        if (unhappy)
        {
            u32 idx;

            if (days_unhappy > 0)
                idx = days_unhappy - 1;
            else
                idx = 0;

            if (6 < idx)
                idx = 6;

            if (rand() % 100 < info->unhappy_sick_rates[idx])
                sick = true;
        }
    }

    if (sick)
    {
        if (days_sick < 7)
            days_sick++;
    }
    else
    {
        days_sick = 0;
    }

    MaryLivestockLifeState next_life_state = LIVESTOCK_LIFE_STATE_ALIVE;

    if (sick)
    {
        u32 idx;

        if (days_sick != 0)
        {
            idx = days_sick - 1;
        }
        else
        {
            idx = 0;
        }

        if (4 < idx)
            idx = 4;

        if (rand() % 100 < info->neglect_death_rates[idx])
            next_life_state = LIVESTOCK_LIFE_STATE_DIED_FROM_NEGLECT;
    }

    if (next_life_state == LIVESTOCK_LIFE_STATE_ALIVE)
    {
        LivestockDayUpdateInfo::AgeDeathRateEntry const * it = info->natural_death_rates;
        LivestockDayUpdateInfo::AgeDeathRateEntry const * end = info->natural_death_rates + 4;

        u32 age = GetAge();

        while (it + 1 != end && ((it + 1)->age <= age))
        {
            it = it + 1;
        }

        if (rand() % 100 < it->death_rate)
            next_life_state = LIVESTOCK_LIFE_STATE_DIED_NATURALLY;
    }

    life_state = next_life_state;
}
