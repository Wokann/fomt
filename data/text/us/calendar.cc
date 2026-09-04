#include "calendar_text.hh"

// The section boundaries preserve the original two-byte alignment gaps without
// embedding padding bytes in the authored text.
char const gText_Calendar_SeasonNames[4][7] SECTION(".rodata.calendar.season") ALIGN(1) = {
    "Spring",
    "Summer",
    "Fall  ",
    "Winter"
};

char const gText_Calendar_None[] SECTION(".rodata.calendar.none") =
    "無";

char const gText_Calendar_WeekdayNames[7][5] SECTION(".rodata.calendar.weekday") ALIGN(1) = {
    "Sun.",
    "Mon.",
    "Tue.",
    "Wed.",
    "Thu.",
    "Fri.",
    "Sat."
};
