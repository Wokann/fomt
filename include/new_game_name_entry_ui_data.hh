#ifndef NEW_GAME_NAME_ENTRY_UI_DATA_HH
#define NEW_GAME_NAME_ENTRY_UI_DATA_HH

#include "prelude.h"

enum
{
    NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT = 30,
#if defined(REGION_JP)
    NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH = 13,
#else
    NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH = 14,
#endif
};

// Both name-entry screens use one-based IDs: names[id - 1]. JP and western
// encodings have different fixed row widths; the rows do not belong to the
// preceding shared UI palette metadata or runtime string.
extern char const gText_NameEntry_PresetAnimalNames[NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT][NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH];

// Runtime string stored immediately before the name rows.
extern char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[];

// The native name-entry path reads the first thirteen glyph codes. The fixed
// storage has seven trailing zero slots in JP and eight in western releases.
extern u16 const gNewGameNameEntryUiCharacterCodes[];

#endif // NEW_GAME_NAME_ENTRY_UI_DATA_HH
