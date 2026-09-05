#ifndef NEW_GAME_SAVE_TEXT_HH
#define NEW_GAME_SAVE_TEXT_HH

#include "prelude.h"

// Save/load result messages and confirmation fields used by the new-game flow.
extern char const gText_NewGameSave_SaveFailed[];
extern char const gText_NewGameSave_LoadFailed[];
extern char const gText_NewGameSave_LoadPrompt[];
extern char const gText_NewGameSave_OverwritePrompt[];

#if defined(REGION_JP)
extern char const gText_NewGameSave_Affirmative[];
extern char const gText_NewGameSave_Negative[];
#endif

#endif // NEW_GAME_SAVE_TEXT_HH
