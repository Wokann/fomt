#include "calendar_text.hh"

// The section boundaries preserve the original two-byte alignment gaps without
// embedding padding bytes in the authored text.
char const gText_Calendar_SeasonNames[4][3] SECTION(".rodata.calendar.season") ALIGN(1) = {
    "春",
    "夏",
    "秋",
    "冬"
};

char const gText_Calendar_None[] SECTION(".rodata.calendar.none") =
    "無";

char const gText_Calendar_WeekdayNames[7][3] SECTION(".rodata.calendar.weekday") ALIGN(1) = {
    "日",
    "月",
    "火",
    "水",
    "木",
    "金",
    "土"
};
