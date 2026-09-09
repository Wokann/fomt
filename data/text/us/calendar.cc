#include "calendar_text.hh"

#include "unknown_types.hh"

// Fixed row widths remain because native calendar code indexes them directly.


// This short row table begins at a two-byte-aligned ROM address while the
// following ordinary data requires four-byte alignment, so it keeps the one
// necessary physical subsection within the shared Calendar source object.
char const gText_Calendar_SeasonNames[4][7] SECTION(".rodata.calendar_season") ALIGN(1) = {
    "Spring",
    "Summer",
    "Fall  ",
    "Winter"
};

char const gText_Calendar_None[] ALIGN(4) =
    "無";

char const gText_Calendar_WeekdayNames[7][5] ALIGN(1) = {
    "Sun.",
    "Mon.",
    "Tue.",
    "Wed.",
    "Thu.",
    "Fri.",
    "Sat."
};

char const gCppRuntimeBadAlloc_CalendarTrailer00[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeBadAlloc_CalendarTrailer01[] ALIGN(4) =
    "bad_alloc";
char const gCppRuntimeError_CalendarTrailer[] ALIGN(4) =
    "Error";
char const gText_CalendarTrailerFallbackNone[] ALIGN(4) =
    "N/A ";
char const gCppRuntimeBadAlloc_CalendarTrailer02[] ALIGN(4) =
    "bad_alloc";
