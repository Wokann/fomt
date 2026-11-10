#ifndef NPC_SCHEDULE_HH
#define NPC_SCHEDULE_HH

#include "prelude.h"

extern u8 const gUnk_080F1A66[];


struct PathPointA
{
    u16 instant;
    i16 coord;
    bool is_y_coord : 1;
};

struct PathPointB
{
    // Native movement reads this map-space coordinate with LDRSH.
    i16 coord;
    u16 speed;
    u16 unk_04; /* duration? */
    u16 facing : 2;
    bool is_y_coord : 1;
};

struct PathInfo
{
    void const * points;
    u16 num_points;
    i16 x_start;
    i16 y_start;
    u32 location_start : 10;
    u32 facing_start : 2;
    bool point_type_select : 1;
};

struct ScheduleEntry
{
    u16 time;
    PathInfo const * path;
};

struct Schedule
{
    u16 num_time_entries;
    ScheduleEntry const * time_entries;
};

struct ScheduleInfo
{
    u32 (*select_schedule)(void const * unk_arg_0);
    u32 num_schedules;
    Schedule const * const * schedules;
};

// Comparators used by the native five-argument STL upper-bound instances.
struct NpcScheduleTimeCompare
{
    bool operator()(u32 const & minute, ScheduleEntry const & entry)
    {
        return minute < entry.time;
    }
};

struct NpcPathTimeCompare
{
    bool operator()(u32 const & minute, PathPointA const & point)
    {
        return minute < point.instant;
    }
};

// Target ABI layout used by both the existing individual records and the
// contiguous NPC schedule storage blocks. Path kind is the thirteenth flag bit.
typedef char PathPointASizeCheck[sizeof(PathPointA) == 8 ? 1 : -1];
typedef char PathPointACoordCheck[offsetof(PathPointA, coord) == 2 ? 1 : -1];
typedef char PathPointBSizeCheck[sizeof(PathPointB) == 8 ? 1 : -1];
typedef char PathPointBSpeedCheck[offsetof(PathPointB, speed) == 2 ? 1 : -1];
typedef char PathPointBUnknown04Check[offsetof(PathPointB, unk_04) == 4 ? 1 : -1];
typedef char PathInfoSizeCheck[sizeof(PathInfo) == 12 ? 1 : -1];
typedef char PathInfoStartXCheck[offsetof(PathInfo, x_start) == 6 ? 1 : -1];
typedef char PathInfoStartYCheck[offsetof(PathInfo, y_start) == 8 ? 1 : -1];
typedef char ScheduleEntrySizeCheck[sizeof(ScheduleEntry) == 8 ? 1 : -1];
typedef char ScheduleEntryPathCheck[offsetof(ScheduleEntry, path) == 4 ? 1 : -1];
typedef char ScheduleSizeCheck[sizeof(Schedule) == 8 ? 1 : -1];
typedef char ScheduleInfoSizeCheck[sizeof(ScheduleInfo) == 12 ? 1 : -1];

struct GameCalendar;

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

extern "C" u32 IsNpcScheduleDateListed(u32 season, u32 day);

struct NpcScheduleDetailEntry
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
};

#endif // NPC_SCHEDULE_HH
