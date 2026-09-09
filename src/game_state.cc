#include "game_state.hh"

// Calendar rows and labels occupy the native run immediately before this
// game-state record.
#if defined(REGION_JP)
#include "data/text/jp/calendar.cc"
#else
#include "data/text/us/calendar.cc"
#endif

// Keep the native order and trailing sentinel. Its higher-level event role
// remains undecoded, so the original ROM-address label is retained.
Unk_080F0566Data const gUnk_080F0566 = {
    {
        0x04, 0x44, 0x48, 0x54, 0x58, 0x78, 0x05, 0x19, 0x1D,
        0x4D, 0x51, 0x61, 0x0A, 0x0E, 0x22, 0x26, 0x36, 0x46,
        0x4A, 0x52, 0x56, 0x7A, 0x3B, 0x63, 0x7B, 0x00,
    },
    "bad_alloc",
};

// These strings are consumed by the still-assembly game-state memorial flow.
// The linker places the grouped text run after the Help localization island.
#define FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE SECTION(".rodata.animal_memorial")
#if defined(REGION_JP)
#include "data/text/jp/animal_memorial.cc"
#else
#include "data/text/us/animal_memorial.cc"
#endif
#undef FOMT_ANIMAL_MEMORIAL_TEXT_ATTRIBUTE
