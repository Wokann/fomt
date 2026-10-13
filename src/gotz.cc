#include "gotz.hh"

#include <stdlib.h>

Gotz::Gotz(ActorLocation const & location)
    : Npc(location)
{
    construction = 0;
    days_remaining = 0;
    ordered_today = false;
    at_construction_worksite = false;
}

u32 Gotz::GetConstruction() const
{
    return construction;
}

bool Gotz::IsConstructionComplete() const
{
    return construction != 0 && days_remaining == 0;
}

bool Gotz::IsConstructionOrderedToday() const
{
    return construction != 0 && days_remaining != 0 && ordered_today;
}

void Gotz::OrderConstruction(u32 type)
{
    construction = type;
    days_remaining = 3;
    ordered_today = true;
    at_construction_worksite = false;
}

void Gotz::FinishConstruction()
{
    construction = 0;
    at_construction_worksite = false;
}

void Gotz::DayUpdate()
{
    Npc::DayUpdate(rand() % 100);
    if (ordered_today)
    {
        ordered_today = false;
    }
    else if (at_construction_worksite)
    {
        at_construction_worksite = false;
        if (days_remaining != 0)
            --days_remaining;
    }
}

void Gotz::UpdateConstructionWorksite()
{
    int map = GetLocation().GetMap();
    switch (map)
    {
    default:
        at_construction_worksite = false;
        break;
    case MAP_CHICKEN_COOP:
    case MAP_SOUTH_SIDE_TOWN:
    case MAP_FARMHOUSE:
    case MAP_BARN:
        at_construction_worksite = true;
        break;
    }
}
