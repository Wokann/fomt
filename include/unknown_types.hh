#ifndef UNKNOWN_TYPES_HH
#define UNKNOWN_TYPES_HH

#include "prelude.h"

#include "fomt_constants.hh"
#include "animal.hh"
#include "map_data.hh"
#include "resource_archive.hh"

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

struct PACKED GameDate
{
    struct PACKED SeasonValue {
        Season value : 2;

        explicit SeasonValue(Season input) : value(input) {}
        SeasonValue & operator-=(u32 seasons)
        {
            value = static_cast<Season>(static_cast<u32>(value) - seasons);
            return *this;
        }
    };

    /* bit 0 */ Season season : 2;
    /* bit 2 */ u8 day : 5;

    GameDate() {}
    // Explicit construction stores the supplied packed day field.
    GameDate(Season season, u32 day)
        : season(season), day(day) {}

    Season GetSeason() const { return season; }
    unsigned int GetDay() const { return day; }
    bool operator==(GameDate const & other) const { return season == other.season && day == other.day; }
    GameDate & operator-=(u32 days)
    {
        u32 remainder;
        u32 seasons;
        if (days < 30) {
            remainder = days;
            seasons = 0;
        } else {
            remainder = days % 30;
            seasons = days / 30;
        }
        u32 current_day = GetDay();
        u32 borrowed_days = remainder - 30;
        u32 previous_day = current_day - borrowed_days;
        if (previous_day < 30)
            ++seasons;
        else
            previous_day -= 30;
        SeasonValue previous_season(GetSeason());
        previous_season -= seasons;
        season = previous_season.value;
        day = previous_day;
        return *this;
    }
    GameDate const operator-(u32 days) const
    {
        return GameDate(*this) -= days;
    }
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


#endif // UNKNOWN_TYPES_HH
