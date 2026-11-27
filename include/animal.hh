#ifndef ANIMAL_HH
#define ANIMAL_HH

#include "prelude.h"

#include "utility/fixed_str.hh"
#include "actor.hh"

// Shared storage view for the remaining animal state payloads.
struct UnkBarnAnimal2C
{
    /* +00 */ u16 unk_00;
    /* +02 */ u8 unk_02;
    /* +03 */ u8 unk_03;
};

struct UnkBarnAnimal2C_x2
{
    /* +00 */ UnkBarnAnimal2C a;
    /* +04 */ UnkBarnAnimal2C b;
};

// Reaction command: a 240..359-frame timer, a seven-bit value initialized
// to 60, a tool/dog-attack flag, and a cleared high byte.
union AnimalReactionPayload
{
    u32 raw;
    struct Bits
    {
        u32 timer : 16;
        u32 constant : 7;
        u32 kind : 1;
        u32 reserved : 8;
    } bits;
};

// Call/bell response copies both words; known callers set only the duration.
struct AnimalApproachPayload
{
    u32 frames;
    u32 unknown_04;
};

// Returned when an animal has no stored name.
extern char const gText_Animal_Unnamed[];

struct Animal : public Actor
{
    Animal(char const * name, ActorLocation const & location, u32 age);
    Animal(ActorLocation const & location, u32 age);
    Animal & operator=(Animal const & other);

    char const * GetName() const;
    bool IsFestivalWinner() const;
    u32 GetAge() const;
    u32 GetAffection() const;
    bool HasBeenBrushedToday() const;
    bool HasBeenTalkedTo() const;
    void SetName(char const * name);
    void SetFestivalWinner();
    void SetBrushed();
    void SetTalkedTo();
    void AddAffection(int amount);
    void SubtractAffection(int amount);
    void DayUpdate();

    /* +08 */ FixedStr<12> name;
    /* +18 */ u32 age : 10;
    /* +19 */ bool festival_winner : 1;
    /* +19 */ bool brushed : 1;
    /* +19 */ bool talked : 1;
    /* +19 */ u32 affection : 8;
};

#endif // ANIMAL_HH
