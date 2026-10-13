#include "saibara.hh"

#include <stdlib.h>

Saibara::Saibara(ActorLocation const & location)
    : Npc(location)
{
    order = BLACKSMITH_ORDER_NONE;
    days_remaining = 0;
    collected_mystrile_sickle = false;
    collected_mystrile_hoe = false;
    collected_mystrile_axe = false;
    collected_mystrile_hammer = false;
    collected_mystrile_watering_can = false;
    collected_mystrile_fishing_rod = false;
}

u32 Saibara::GetOrder() const
{
    return order;
}

bool Saibara::IsOrderComplete() const
{
    return order != BLACKSMITH_ORDER_NONE && days_remaining == 0;
}

bool Saibara::HasCollectedAllMystrileTools() const
{
    u8 count = 0;
    if (collected_mystrile_sickle)
        ++count;
    if (collected_mystrile_hoe)
        ++count;
    if (collected_mystrile_axe)
        ++count;
    if (collected_mystrile_hammer)
        ++count;
    if (collected_mystrile_watering_can)
        ++count;
    if (collected_mystrile_fishing_rod)
        ++count;
    if (count == 6)
        return true;
    else
        return false;
}

void Saibara::CollectOrder()
{
    switch (order)
    {
    case BLACKSMITH_ORDER_SICKLE_MYSTRILE:
        collected_mystrile_sickle = true;
        break;
    case BLACKSMITH_ORDER_HOE_MYSTRILE:
        collected_mystrile_hoe = true;
        break;
    case BLACKSMITH_ORDER_AXE_MYSTRILE:
        collected_mystrile_axe = true;
        break;
    case BLACKSMITH_ORDER_HAMMER_MYSTRILE:
        collected_mystrile_hammer = true;
        break;
    case BLACKSMITH_ORDER_WATERING_CAN_MYSTRILE:
        collected_mystrile_watering_can = true;
        break;
    case BLACKSMITH_ORDER_FISHING_ROD_MYSTRILE:
        collected_mystrile_fishing_rod = true;
        break;
    }
    order = BLACKSMITH_ORDER_NONE;
}

void Saibara::PlaceOrder(u32 a_order, u32 days)
{
    order = a_order;
    days_remaining = days;
}

void Saibara::DayUpdate()
{
    Npc::DayUpdate(rand() % 100);
    if (days_remaining != 0)
        --days_remaining;
}
