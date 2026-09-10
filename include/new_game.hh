#ifndef NEW_GAME_HH
#define NEW_GAME_HH

#include "prelude.h"

// The new-game menu consumes this exact 18-entry pointer order. Text fields
// are regional, while the table preserves the original regional pointer reuse.
extern char const * const gNewGameMenuLabels[18];

extern char const gText_NewGameMenu_Diary[];
extern char const gText_NewGameMenu_Save[];
extern char const gText_NewGameMenu_Load[];
extern char const gText_NewGameMenu_Blank[];
extern char const gText_NewGameMenu_Data1[];
extern char const gText_NewGameMenu_Data2[];
extern char const gText_NewGameMenu_ControlSettings[];
extern char const gText_NewGameMenu_ClockDisplay[];
extern char const gText_NewGameMenu_Yes[];
extern char const gText_NewGameMenu_No[];
extern char const gText_NewGameMenu_FaceDisplay[];
extern char const gText_NewGameMenu_NameDisplay[];

#if defined(REGION_JP)
// The JP menu uses the same ROM strings for its data labels and control
// choices. These are source-level semantic names only: both macros resolve
// directly to the one stored string, without an alias symbol or pointer.
#define gText_NewGameMenu_ControlOption1 gText_NewGameMenu_Data1
#define gText_NewGameMenu_ControlOption2 gText_NewGameMenu_Data2
#else
extern char const gText_NewGameMenu_ControlOption1[];
extern char const gText_NewGameMenu_ControlOption2[];
#endif

// Directly copied status-line fragments and prompts used by asm/new_game.s.
extern char const gText_NewGameStatus_YearSuffix[];
extern char const gText_NewGameStatus_SeasonSeparator[];
extern char const gText_NewGameStatus_DaySuffix[];
extern char const gText_NewGameStatus_OpenParen[];
extern char const gText_NewGameStatus_CloseParen[];
extern char const gText_NewGameStatus_FarmSuffix[];
extern char const gText_NewGameStatus_ReadDiary[];
extern char const gText_NewGameStatus_WriteDiary[];
extern char const gText_NewGameStatus_NoSavedData[];

// Fixed-width help messages selected by the new-game configuration screen.
extern char const gText_NewGameHelp_Controls[];
extern char const gText_NewGameHelp_ClockDisplay[];
extern char const gText_NewGameHelp_FaceDisplay[];
extern char const gText_NewGameHelp_NameDisplay[];

// Save/load result messages and confirmation fields used by the new-game flow.
extern char const gText_NewGameSave_SaveFailed[];
extern char const gText_NewGameSave_LoadFailed[];
extern char const gText_NewGameSave_LoadPrompt[];
extern char const gText_NewGameSave_OverwritePrompt[];
extern char const gCppRuntimeBadAlloc_NewGameSave[];
extern char const gCppRuntimeError_NewGameSave[];

#if defined(REGION_JP)
extern char const gText_NewGameSave_Affirmative[];
extern char const gText_NewGameSave_Negative[];
#endif

// Prefixes and fixed labels shown while initializing a new player record.
extern char const gText_NewGameIdentity_PlayerPrefix[];
extern char const gText_NewGameIdentity_FarmPrefix[];
extern char const gText_NewGameIdentity_DogPrefix[];
extern char const gText_NewGameIdentity_PlayerName[];
extern char const gText_NewGameIdentity_PlayerBirthday[];
extern char const gText_NewGameIdentity_FarmName[];
extern char const gText_NewGameIdentity_DogName[];
extern char const gText_NewGameIdentity_Confirm[];
extern char const gText_NewGameIdentity_Yes[];
extern char const gText_NewGameIdentity_No[];
extern char const gCppRuntimeBadAlloc_NewGameIdentityPrefix[];
extern char const gCppRuntimeBadAlloc_NewGameIdentityLabels[];

#if defined(REGION_JP)
extern char const gText_NewGameIdentity_BirthMonthSuffix[];
extern char const gText_NewGameIdentity_BirthDaySuffix[];
#endif

enum
{
    NEW_GAME_NAME_ENTRY_PAGE_COUNT = 3,
    NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE = 6,
    NEW_GAME_NAME_ENTRY_ROW_COUNT = NEW_GAME_NAME_ENTRY_PAGE_COUNT * NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE,
    NEW_GAME_NAME_ENTRY_ROW_WIDTH = 31
};

// Each row is a fixed-width, single-terminated ROM string.
extern char const gNewGameNameEntryCharacterRows[NEW_GAME_NAME_ENTRY_ROW_COUNT][NEW_GAME_NAME_ENTRY_ROW_WIDTH];

extern char const gText_NewGameNameEntry_Placeholder[];
extern char const gText_NewGameNameEntry_NameLabel[];
extern char const gText_NewGameNameEntry_Confirm[];
extern char const gText_NewGameNameEntry_Yes[];
extern char const gText_NewGameNameEntry_No[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi00[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi01[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi02[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi03[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi04[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi05[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi06[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi07[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi08[];
extern char const gCppRuntimeBadAlloc_NewGameNameEntryUi09[];

// Both regional name-entry UIs consume the first thirteen glyph codes. The
// native fixed storage has different total capacities between the releases.
extern u16 const gNewGameNameEntryUiCharacterCodes[];

#if defined(REGION_JP)
extern char const gText_NewGameNameEntry_ModeKatakana[];
extern char const gText_NewGameNameEntry_ModeSymbols[];
extern char const gText_NewGameNameEntry_ModeHiragana[];
#else
extern char const gText_NewGameNameEntry_EndLatin[];
extern char const gText_NewGameNameEntry_EndFullWidth[];
#endif

#endif // NEW_GAME_HH
