#ifndef TIME_OF_DAY_HH
#define TIME_OF_DAY_HH

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

typedef char EncodedGameYearSizeCheck[sizeof(EncodedGameYear) == 1 ? 1 : -1];

// Stored at +0x10 in the save image. The first byte encodes the year as
// seven times its high five bits plus its low three bits; the following
// fields are the packed date and clock used by the calendar consumers.
struct GameCalendar
{
    u8 encoded_year;
    GameDate date;
    GameTime time;

    GameCalendar(u32 year, GameDate const & date, GameTime time)
        : encoded_year((year / 7 << 3) | (year % 7)), date(date), time(time) {}

    u32 GetYear() const { return EncodedGameYear(encoded_year).GetYear(); }
};

typedef char GameCalendarSizeCheck[sizeof(GameCalendar) == 4 ? 1 : -1];
typedef char GameCalendarDateCheck[offsetof(GameCalendar, date) == 1 ? 1 : -1];
typedef char GameCalendarTimeCheck[offsetof(GameCalendar, time) == 2 ? 1 : -1];

// Calendar date used by daily NPC schedules. The day is one-based, and
// times before 06:00 still belong to the preceding game day.
struct GameDayDate
{
    u8 year;
    u8 season;
    u8 day;
    u8 weekday;
};
typedef char GameDayDateSizeCheck[sizeof(GameDayDate) == 4 ? 1 : -1];
typedef char GameDayDateWeekdayCheck[offsetof(GameDayDate, weekday) == 3 ? 1 : -1];

// Writes the decoded date and returns the supplied output pointer.
extern "C" GameDayDate * DecodeGameDayDate(GameDayDate * output, GameCalendar const * calendar);

// Borrowed ROM label, returned as one word and consumed through its C-string view.
struct CalendarSeasonLabel
{
    char const * value;
    explicit CalendarSeasonLabel(char const * text) : value(text) {}
    operator char const *() const { return value; }
};
typedef char CalendarSeasonLabelSizeCheck[sizeof(CalendarSeasonLabel) == 4 ? 1 : -1];

CalendarSeasonLabel GetCalendarSeasonLabel(Season season);
// Returns a borrowed weekday label, or the calendar fallback for an invalid index.
extern "C" char const * GetCalendarWeekdayLabel(unsigned int week_day);
// The first day before 06:00 still uses the preceding season.
// Keep the original word-sized return ABI for its native callers.
extern "C" u32 GetCalendarEffectiveSeason(GameCalendar const & calendar);
extern "C" u32 GetTimeOfDayTransitionValue(u8 hour, u8 minute, u32 season, TimeOfDayPeriod period);

extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Spring_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Summer_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Autumn_Night[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Morning[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Afternoon[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Evening[];
extern TimeOfDayTransition const gTimeOfDayTransitionRecords_Winter_Night[];

extern TimeOfDayTransition const * const
    gTimeOfDayTransitionTables[NUM_SEASONS][TIME_OF_DAY_PERIOD_COUNT];

#endif // TIME_OF_DAY_HH
