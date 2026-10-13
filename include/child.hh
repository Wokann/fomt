#ifndef CHILD_HH
#define CHILD_HH

#include "npc.hh"
#include "unknown_types.hh"

// The child is an actual Npc subclass at save-image +0x1CD8.
// Birthday, age and walking state agree with Mary variables 48/49, 46 and 47.
struct Child : public Npc
{
    Child();
    Child(GameDate const & birthday, ActorLocation const & location);
    char * GetName();
    u8 GetBirthdayCode() const;
    u8 GetAgeDays() const;
    bool CanWalk() const;
    void SetCanWalk();
    void DayUpdate();
    void SetName(char const * value);

    // Physical storage is 16 bytes; native copies are capped at 12 encoded bytes.
    char name[0x10];
    GameDate birthday;
    u8 age_days;
    bool can_walk : 1;
    u8 : 7;
};

typedef char ChildSizeCheck[sizeof(Child) == 0x28 ? 1 : -1];

typedef char ChildNameOffsetCheck[offsetof(Child, name) == 0x14 ? 1 : -1];
typedef char ChildBirthdayOffsetCheck[offsetof(Child, birthday) == 0x24 ? 1 : -1];
typedef char ChildAgeOffsetCheck[offsetof(Child, age_days) == 0x25 ? 1 : -1];

#endif // CHILD_HH
