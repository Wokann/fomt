#include "game_state.hh"
#include "unknown_types.hh"

// Calendar text begins this physical rodata block.
#include FOMT_TEXT_INCLUDE(game_state_1.cc)

// func_08010F54 scans the first 25 packed season/day entries.  The final
// zero is present in the original bytes but is outside that scan.
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
    SEASON_FALL | DAY_02 << 2,
    SEASON_FALL | DAY_03 << 2,
    SEASON_FALL | DAY_08 << 2,
    SEASON_FALL | DAY_09 << 2,
    SEASON_FALL | DAY_13 << 2,
    SEASON_FALL | DAY_17 << 2,
    SEASON_FALL | DAY_18 << 2,
    SEASON_FALL | DAY_20 << 2,
    SEASON_FALL | DAY_21 << 2,
    SEASON_FALL | DAY_30 << 2,
    SEASON_WINTER | DAY_14 << 2,
    SEASON_WINTER | DAY_24 << 2,
    SEASON_WINTER | DAY_30 << 2,
    0,
};

// The final regional text fragment follows the native byte table.
#include FOMT_TEXT_INCLUDE(game_state_2.cc)
