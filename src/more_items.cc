#include "more_items.hh"

#include <new>

MoreItems::MoreItems() : size(0), location(MAP_NONE, 0, 0)
{
}

u32 MoreItems::GetSize() const
{
    return size;
}

u8 * MoreItems::Begin()
{
    return data;
}

u8 * MoreItems::End()
{
    return data + size;
}

Location MoreItems::GetLocation() const
{
    return location;
}

void MoreItems::PushBack(u32 value)
{
    if (size < ARRAY_COUNT(data))
    {
        u8 * destination = (u8 *)this + (offsetof(MoreItems, data) + size);
        new (destination) u8(value);
        size++;
    }
}

void MoreItems::SetLocation(Location const & value)
{
    location = value;
}
