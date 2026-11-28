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

// A reaction counts down its lifetime, initial retreat and direction refresh.
// The target flag selects a dog instead of the player.
union AnimalReactionPayload
{
    u32 raw;
    struct Bits
    {
        u16 frames_remaining;
        u8 retreat_frames : 7;
        u8 target_is_dog : 1;
        u8 retarget_frames;
    } bits;
    // Some consumers inspect both flags from a single captured state word.
    struct WordBits
    {
        u32 frames_remaining : 16;
        u32 retreat_frames : 7;
        u32 target_is_dog : 1;
        u32 retarget_frames : 8;
    } word_bits;
};

// Call/bell response initializes both counters; target coordinates are
// filled when a new direction is selected.
struct AnimalApproachPayload
{
    u32 frames_remaining : 16;
    u32 retarget_frames : 16;
    i16 last_target_x;
    i16 last_target_y;
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
