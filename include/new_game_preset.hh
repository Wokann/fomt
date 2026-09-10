#ifndef NEW_GAME_PRESET_HH
#define NEW_GAME_PRESET_HH

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

// Both name-entry screens index this fixed-width list with values 1..30.
// The JP and US encodings have different row widths. The native metadata base
// is a separate 14-byte prefix immediately before this array.
extern char const gText_NameEntry_PresetAnimalNames[NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT][NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH];

// Native code dereferences this exact word through the lookup base located
// before the regional fixed-stride name rows. Its high-level role is unknown.
extern u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue;

// Runtime string stored after the prefix word and before the name rows.
extern char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[];

#endif // NEW_GAME_PRESET_HH
