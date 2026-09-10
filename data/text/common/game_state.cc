#include "game_state.hh"
#include "unknown_types.hh"

// GameDate stores the season in bits 0-1 and the day in bits 2-6.
// func_08010F54 scans the first 25 entries as packed GameDate values. The
// final zero is part of the original byte sequence but is not scanned.
u8 const gUnk_080F0566[] ALIGN(1) = {
    SEASON_SPRING | DAY_01 << 2,
    SEASON_SPRING | DAY_17 << 2,
    SEASON_SPRING | DAY_18 << 2,
    SEASON_SPRING | DAY_21 << 2,
    SEASON_SPRING | DAY_22 << 2,
    SEASON_SPRING | DAY_30 << 2,
    SEASON_SUMMER | DAY_01 << 2,
    SEASON_SUMMER | DAY_06 << 2,
    SEASON_SUMMER | DAY_07 << 2,
    SEASON_SUMMER | DAY_19 << 2,
    SEASON_SUMMER | DAY_20 << 2,
    SEASON_SUMMER | DAY_24 << 2,
    SEASON_AUTUMN | DAY_02 << 2,
    SEASON_AUTUMN | DAY_03 << 2,
    SEASON_AUTUMN | DAY_08 << 2,
    SEASON_AUTUMN | DAY_09 << 2,
    SEASON_AUTUMN | DAY_13 << 2,
    SEASON_AUTUMN | DAY_17 << 2,
    SEASON_AUTUMN | DAY_18 << 2,
    SEASON_AUTUMN | DAY_20 << 2,
    SEASON_AUTUMN | DAY_21 << 2,
    SEASON_AUTUMN | DAY_30 << 2,
    SEASON_WINTER | DAY_14 << 2,
    SEASON_WINTER | DAY_24 << 2,
    SEASON_WINTER | DAY_30 << 2,
    0,
};

char const gCppRuntimeBadAlloc_GameState[] =
    "bad_alloc";
