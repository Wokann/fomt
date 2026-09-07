#include "bachelorette.hh"

#include <stdlib.h> // rand

// Each row is indexed by the capped five-stage counter used by the native
// bachelorette update.  The surrounding conditions are not all decoded yet.
extern u8 const gUnk_BacheloretteLoveThresholds00[] ALIGN(1) = {
    0x96, 0xB4, 0xD2, 0xE6, 0xFF,
};

extern u8 const gUnk_BacheloretteLoveThresholds01[] ALIGN(1) = {
    0x1E, 0x3C, 0x5A, 0x78, 0x96,
};

extern u8 const gUnk_BacheloretteLoveThresholds02[] ALIGN(1) = {
    0x14, 0x28, 0x3C, 0x50, 0x64,
};

extern u8 const gUnk_BacheloretteLoveThresholds03[] ALIGN(1) = {
    0x0F, 0x1E, 0x2D, 0x3C, 0x4B,
};

extern u8 const gUnk_BacheloretteLoveThresholds04[] ALIGN(1) = {
    0x0A, 0x14, 0x1E, 0x28, 0x32,
};

extern u8 const gUnk_BacheloretteLoveThresholds05[] ALIGN(1) = {
    0x5A, 0x82, 0xAA, 0xD2, 0xFA,
};

u32 const gMarriageCandidateCharacterIds[MARRIAGE_CANDIDATE_CHARACTER_COUNT]
    SECTION(".rodata.bachelorette_marriage_candidate_character_ids") = {
        3,  // Popuri
        12, // Mary
        19, // Karen
        21, // Elli
        25, // Ann
        31, // Harvest Goddess
    };

Bachelorette::Bachelorette(ActorLocation const & location)
    : Npc(location)
{
    love = 0;
    player_events = 0;
    days_since_player_event = 0;
    rival_events = 0;
    days_since_rival_event = 0;
    unk_17_4 = 0;
}

u32 Bachelorette::GetLove() const
{
    return love;
}

u32 Bachelorette::GetPlayerEventCount() const
{
    return player_events;
}

u32 Bachelorette::GetDaysSincePlayerEvent_bugged() const
{
    return days_since_rival_event;
}

u32 Bachelorette::GetRivalEventCount() const
{
    return rival_events;
}

u32 Bachelorette::GetDaysSinceRivalEvent() const
{
    return days_since_rival_event;
}

u32 Bachelorette::method_0809E4BC() const
{
    return unk_17_4;
}

void Bachelorette::AddLove(int amount)
{
    u32 total = love + amount;

    // Clamps the value between 0 and 0xFFFF
    if ((int)total < 0)
        total = 0;
    else if (0xFFFF < total)
        total = 0xFFFF;

    love = total;
}

void Bachelorette::SubtractLove(int amount)
{
    AddLove(-amount);
}

void Bachelorette::SetLove(int amount)
{
    love = amount;
}

void Bachelorette::PlayerEventUpdate()
{
    if (player_events < 6)
    {
        player_events++;
        days_since_player_event = 0;
    }
}

void Bachelorette::RivalEventUpdate()
{
    if (rival_events < 5)
    {
        rival_events++;
        days_since_rival_event = 0;
    }
}

void Bachelorette::method_0809E550()
{
    if (unk_17_4 < 5)
    {
        unk_17_4++;
    }
}

void Bachelorette::DayUpdate(bool decay_love, u32 arg_01)
{
    if (HasBeenSpokenToToday())
        AddLove(200);

    Npc::DayUpdate(arg_01);

    if (GetDaysSinceLastSpoken() != 0 && arg_01 < 10)
        SubtractLove(200);

    if (decay_love)
    {
        if (player_events > 5)
        {
            if (4 < GetDaysSinceLastSpoken() && (rand() % 100) < 10)
                SubtractLove(1000);
        }
        else
        {
            SubtractLove(100);
        }
    }

    if (days_since_player_event < 7)
        days_since_player_event++;

    if (days_since_rival_event < 7)
        days_since_rival_event++;
}
