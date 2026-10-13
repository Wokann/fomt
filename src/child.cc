#include "child.hh"
#include "character_names_empty.hh"

#include <stdlib.h>
#include <string.h>

static inline void CopyChildName(char * destination, char const * source)
{
    u32 length = strlen(source);
    if (length > 12)
        length = 12;
    memcpy(destination, source, length);
    destination[length] = 0;
}

Child::Child()
    : Npc(ActorLocation(Location(MAP_FARMHOUSE, 100, 100), FACING_DOWN))
{
    CopyChildName(name, gText_CharacterName_Empty);
    birthday.season = SEASON_SPRING;
    birthday.day = 0;
    age_days = 0;
    // The default native constructor does not initialize can_walk or tail padding.
}

Child::Child(GameDate const & a_birthday, ActorLocation const & location)
    : Npc(location)
{
    CopyChildName(name, gText_CharacterName_Empty);
    // Native birth initialization copies the entire packed date, including its spare bit.
    birthday = a_birthday;
    age_days = 0;
    can_walk = false;
}

char * Child::GetName()
{
    return name;
}

u8 Child::GetBirthdayCode() const
{
    // The script reader consumes the stored byte, then selects season/day bits.
    return *reinterpret_cast<u8 const *>(&birthday);
}

u8 Child::GetAgeDays() const
{
    return age_days;
}

bool Child::CanWalk() const
{
    return can_walk;
}

void Child::SetCanWalk()
{
    can_walk = true;
}

void Child::DayUpdate()
{
    Npc::DayUpdate(rand() % 100);
    if (age_days < CHILD_AGE_DAYS_SATURATED_MAXIMUM)
        ++age_days;
}

void Child::SetName(char const * value)
{
    CopyChildName(name, value);
}
