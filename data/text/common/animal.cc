#include "animal_text.hh"

// The fixed eight-byte field ends immediately before livestock day-update
// data.  Its explicit size retains the original filler byte after the terminator.
char const gText_Animal_Unnamed[8] SECTION(".rodata.animal_unnamed") ALIGN(1) =
    "名無し";
