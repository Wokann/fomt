#ifndef NEW_GAME_NAME_ENTRY_TEXT_HH
#define NEW_GAME_NAME_ENTRY_TEXT_HH

#include "prelude.h"

enum
{
    NEW_GAME_NAME_ENTRY_PAGE_COUNT = 3,
    NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE = 6,
    NEW_GAME_NAME_ENTRY_ROW_COUNT = NEW_GAME_NAME_ENTRY_PAGE_COUNT * NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE,
    NEW_GAME_NAME_ENTRY_ROW_WIDTH = 31,
    NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT = 30,
    NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH = 14,
};

// Each row is a fixed-width, single-terminated ROM string.
extern char const gNewGameNameEntryCharacterRows[NEW_GAME_NAME_ENTRY_ROW_COUNT][NEW_GAME_NAME_ENTRY_ROW_WIDTH];

#if defined(REGION_US)
// The US name-entry screen indexes this fixed-width list with values 1..30.
// The original lookup base intentionally sits one row before this array.
extern char const gText_NameEntry_PresetAnimalNames[NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT][NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH];
#endif

#endif // NEW_GAME_NAME_ENTRY_TEXT_HH
