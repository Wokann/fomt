#include "prelude.h"

// func_0803D52C writes four decoded schedule bytes.  Only the final weekday
// byte is needed by this small schedule predicate.
struct DecodedScheduleDate
{
    u8 unknown_00;
    u8 unknown_01;
    u8 unknown_02;
    u8 week_day;
};

// This owner layout is deliberately local: Mary has established the physical
// slot, but not the full object type or the meanings of all slot values.
struct ScheduleGateOwner
{
    u8 unknown_0000[0x10];
    u8 schedule_data[0x2187 - 0x10];
    u8 unknown_2187;
};

EC void func_0803D52C(DecodedScheduleDate * date, u8 const * schedule);

EC u32 func_0803E40C(ScheduleGateOwner const & owner)
{
    DecodedScheduleDate date;
    func_0803D52C(&date, owner.schedule_data);
    u8 const week_day = date.week_day;
    u32 const unknown_slot_319 = (static_cast<u32>(owner.unknown_2187) << 27) >> 30;
    if (unknown_slot_319 == 2 && week_day == 0)
        return 1;
    return 0;
}
