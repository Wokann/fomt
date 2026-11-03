#ifndef UNKNOWN_TYPES_HH
#define UNKNOWN_TYPES_HH

#include "prelude.h"

#include "fomt_constants.hh"
#include "map_data.hh"
#include "resource_archive.hh"

// TODO: move elsewhere
struct UnkBarnAnimal2C
{
    /* +00 */ u16 unk_00;
    /* +02 */ u8 unk_02;
    /* +03 */ u8 unk_03;
};

// TODO: move elsewhere
struct UnkBarnAnimal2C_x2
{
    /* +00 */ UnkBarnAnimal2C a;
    /* +04 */ UnkBarnAnimal2C b;
};

// TODO: move elsewhere
struct Box
{
    /* +00 */ i16 x1, y1;
    /* +04 */ i16 x2, y2;

    Box(u32 x, u32 y)
        : x1(x), y1(y), x2(x), y2(y)
    {
    }

    Box(u32 x, u32 y, u32 w, u32 h)
    {
        x1 = x - w / 2;
        y1 = y - h / 2;
        x2 = x + w - w / 2;
        y2 = y + h - h / 2;
    }

    Box(u32 x1, u32 y1, u32 x2, u32 y2, i32 x_off, i32 y_off)
        : x1(x_off + x1), y1(y_off + y1), x2(x_off + x2), y2(y_off + y2)
    {
    }

    Box Moved(i32 x, i32 y) const { return Box(x1, y1, x2, y2, x, y); }
};

// TODO: rename
// TODO: move elsewhere
struct UnkMapBox : public Box
{
    UnkMapBox(Box const & box)
        : Box(box)
    {
    }
};

#include "game_object.hh"

// Calendar day values. Shift these left by two bits when forming a GameDate
// byte, whose low two bits hold a Season.
#define DAY_01 1
#define DAY_02 2
#define DAY_03 3
#define DAY_04 4
#define DAY_05 5
#define DAY_06 6
#define DAY_07 7
#define DAY_08 8
#define DAY_09 9
#define DAY_10 10
#define DAY_11 11
#define DAY_12 12
#define DAY_13 13
#define DAY_14 14
#define DAY_15 15
#define DAY_16 16
#define DAY_17 17
#define DAY_18 18
#define DAY_19 19
#define DAY_20 20
#define DAY_21 21
#define DAY_22 22
#define DAY_23 23
#define DAY_24 24
#define DAY_25 25
#define DAY_26 26
#define DAY_27 27
#define DAY_28 28
#define DAY_29 29
#define DAY_30 30

struct PACKED GameDate
{
    /* bit 0 */ Season season : 2;
    /* bit 2 */ u8 day : 5;

    GameDate() {}
    // Explicit construction stores the supplied packed day field.
    GameDate(Season season, u32 day)
        : season(season), day(day) {}

    Season GetSeason() const { return season; }
    unsigned int GetDay() const { return day; }
    bool operator==(GameDate const & other) const { return season == other.season && day == other.day; }
    void AdvanceDay(u32 days_per_season)
    {
        u32 next_day = day + 1;
        if (next_day == days_per_season) {
            u8 & encoded = *reinterpret_cast<u8 *>(this);
            u32 next_season = GetSeason();
            // Keep the day and reserved high bit while carrying the season.
            i32 preserve_mask = ~3;
            ++next_season;
            next_season &= 3;
            i8 old_bits = static_cast<i8>(encoded) & preserve_mask;
            encoded = old_bits | next_season;
            next_day = 0;
        }
        day = next_day;
    }
};

struct PACKED ALIGN(2) GameTime
{
    /* bit 0 */ u8 clock_hour : 5;
    /* bit 5 */ u8 clock_minute : 6;

    GameTime() {}
    GameTime(u8 hour, u8 minute) : clock_hour(hour), clock_minute(minute) {}

    unsigned int GetHour() const { return clock_hour; }
};

typedef char GameDateSizeCheck[sizeof(GameDate) == 1 ? 1 : -1];
typedef char GameTimeSizeCheck[sizeof(GameTime) == 2 ? 1 : -1];

#endif // UNKNOWN_TYPES_HH
