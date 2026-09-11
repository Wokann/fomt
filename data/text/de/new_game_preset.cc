#include "new_game_preset.hh"

// The US animal-name selection is a one-indexed, fixed-stride list. Each
// string remains in its original 14-byte row so the native index × 14 lookup
// and its full-width display-space padding remain exact.
u32 const gUnk_NewGameNameEntryPresetAnimalNamesPrefixValue =
    0x20;

char const gCppRuntimeBadAlloc_NewGameNameEntryPresetNames[] =
    "bad_alloc";

char const gText_NameEntry_PresetAnimalNames
    [NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_COUNT]
    [NEW_GAME_NAME_ENTRY_PRESET_ANIMAL_NAME_WIDTH] ALIGN(1) = {
    "Fido",
    "Sox",
    "Sam",
    "Lady　",
    "Princess　",
    "Ginger　　",
    "Max　　　　",
    "Sam　　",
    "Rocky",
    "Buster　　　",
    "Charlie",
    "Rusty　　",
    "Zoe",
    "Daisy　",
    "Molly　　　",
    "Jess　　",
    "Tricky　　　",
    "Brewster　　",
    "Isis　",
    "Myst　　",
    "Amanda",
    "Amber　　",
    "Panda　",
    "Angel　　　　",
    "Fifi　　",
    "Echo　　　　",
    "Nic",
    "Quartz",
    "Betty",
    "Gertrude　",
};
