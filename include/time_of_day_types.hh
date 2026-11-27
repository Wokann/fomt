#ifndef TIME_OF_DAY_TYPES_HH
#define TIME_OF_DAY_TYPES_HH

#include "unknown_types.hh"

enum TimeOfDayPeriod
{
    TIME_OF_DAY_PERIOD_MORNING,
    TIME_OF_DAY_PERIOD_AFTERNOON,
    TIME_OF_DAY_PERIOD_EVENING,
    TIME_OF_DAY_PERIOD_NIGHT,
    TIME_OF_DAY_PERIOD_COUNT,
};

// The native lookup scans start_minute in ascending order and returns value
// from the last transition not later than the supplied clock time.
struct TimeOfDayTransition
{
    u16 start_minute;
    u8 value;
};

// The calendar and wedding records share this one-byte year encoding.
// Keep their stored byte unchanged; use this view only while decoding it.
// All eight bits belong to the year, including the otherwise-unused low
// value 7. Native readers clamp the decoded value separately when needed.
struct PACKED EncodedGameYear
{
    union PACKED {
        u8 encoded;
        struct PACKED {
            u8 remainder : 3;
            u8 quotient : 5;
        } digits;
    };

    explicit EncodedGameYear(u8 value) : encoded(value) {}
    u32 GetYear() const { return digits.quotient * 7 + digits.remainder; }
};


// Stored at +0x10 in the save image. The first byte encodes the year as
// seven times its high five bits plus its low three bits; the following
// fields are the packed date and clock used by the calendar consumers.
struct GameCalendar
{
    EncodedGameYear year;
    GameDate date;
    GameTime time;

    GameCalendar(u32 year, GameDate const & date, GameTime time)
        : year((year / 7 << 3) | (year % 7)), date(date), time(time) {}

    u32 GetYear() const { return year.GetYear(); }
    inline u32 GetYear(u32 maximum) const;
};


// DayUpdate promotes tomorrow's weather to today before choosing the next forecast.
// Keep both saved words unvalidated, as with the native weather-variable interface.
struct GameStateClock {
    u32 weather_today;
    u32 weather_tomorrow;
    GameCalendar calendar;
    GameStateClock(GameCalendar const & value)
        : weather_today(WEATHER_SUNNY), weather_tomorrow(WEATHER_SUNNY), calendar(value) {}
};

#endif // TIME_OF_DAY_TYPES_HH
