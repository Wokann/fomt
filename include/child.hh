#ifndef CHILD_HH
#define CHILD_HH

#include "npc.hh"
#include "utility/fixed_str.hh"
#include "unknown_types.hh"

// The child is an actual Npc subclass at save-image +0x1CD8.
// Birthday, age and walking state agree with Mary variables 48/49, 46 and 47.
struct Child : public Npc
{
    Child();
    Child(GameDate const & birthday, ActorLocation const & location);
    char const * GetName() const;
    GameDate GetBirthday() const;
    u32 GetAgeDays() const;
    bool CanWalk() const;
    void SetCanWalk();
    void DayUpdate();
    void SetName(char const * value);

    // The physical slot is 16 bytes: twelve encoded bytes plus a terminator,
    // then three alignment bytes before the birthday. Input remains capped at 12.
    FixedStr<12> name;
    GameDate birthday ALIGN(4);
    u8 age_days;
    bool can_walk : 1;
    u8 : 7;
};



#endif // CHILD_HH
