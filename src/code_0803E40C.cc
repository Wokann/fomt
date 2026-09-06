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

// This owner layout is deliberately local: only the schedule date and the
// packed Lou/Ruby introduction state used by this predicate are understood.
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
    // save+0x2187 bits 3..4 are variable slot 318.  Shifting by 27 does not
    // select slot 319's bits 5..6; that getter uses a shift of 25 instead.
    u32 const lou_or_ruby_introduction_state = (static_cast<u32>(owner.unknown_2187) << 27) >> 30;
    if (lou_or_ruby_introduction_state == 2 && week_day == 0)
        return 1;
    return 0;
}
